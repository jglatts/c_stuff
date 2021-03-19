/*
	CIS3207 Lab2 Shell
	Author: John Glatts

	Implementation file for the shell program
*/
#include "myshell.h"
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <sys/wait.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>

/*
	Shell global variables
	These are initliazed as the shell exectues 
*/
MultiParallel* multi_parallel[CMD_LIMIT];	
Built_In       built_in;
char*	       cmd_strings[CMD_LIMIT];
char*	       shell_paths[CMD_LIMIT];
char*		   parallel_cmds[CMD_LIMIT];	
char           cwd[PATH_MAX];
char           file_name[PATH_MAX];
char           input_file_name[PATH_MAX];
char           append_file_name[PATH_MAX];
int            cmd_count;
int            path_list_count;
int            multi_count;
int            input_pos;
int		       output_pos;
int	           append_pos;
int            pipe_pos;
int            background_pos;
bool           input_redirect;
bool           output_redirect;
bool           append_redirect;
bool           externel_check;
bool           multi_background;
bool           background;
bool           batch;
bool           check_pipe;

/*
	Shell Program Entry Point
	Will call run_shell to begin shell execution 
*/
int main(int argc, char** argv, char** envp) {
	run_shell(argc, argv, envp);
	return 0;
}

/*
	Initialize the shell program 
	Checks if a batch file has been provided
	If we get a batch file, the shell will run in batch mode
	and just print to stdout and then return to quit the program
	If no batch file is provided, we continue in interactive mode 
*/
bool init_shell(int argc, char** argv) {
	if (argc >= 2) {
		int fd = open(argv[1], O_RDONLY);
		if (fd > 0) {
			batch = true;
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		else return false;
	}
	else batch = false;
	return true;
}

/*
	Main loop to drive the shell program
	Runs a forever loop that only exits when the user enters "exit"
	In each iteration, we parse the user input and then 
	check for any file redirection
	It then calls run_user_cmd to run the appropriate shell command
	Once the command execution is done it will reset all necessary parameters 
*/
bool run_shell(int argc, char** argv, char** envp) {
	if (!init_shell(argc, argv)) return false;
	while (1) {
		if (!batch) print_prompt();
		parse_cmd_line();
		check_file_io();
		run_user_cmd(envp);
		reset_redirect();
	}
	return true;
}

/*
	Run the appropriate shell command provided by the user
	First checks if we should run multiple commands in parrallel,
	which is a special case
	It will then check if we need to run a built or an external command 
*/
void run_user_cmd(char** envp) {
	if (multi_count > 1) {
		run_parrallel_cmds(envp);
		return;
	}
	if (check_for_built_in(cmd_strings[0])) {
		if (background) run_built_in_background(envp);
		else run_built_in(envp);
	}
	else {
		run_external();
	}
}

/*
	Prints the shell prompt each iteration of main loop
	Will print the current working directory 
*/
void print_prompt() {
	printf("\nshell=");
	printf(GREEN);
	printf("%s", getcwd(cwd, sizeof(cwd)));
	printf(RESET);
	printf("/myshell-> ");
}

/*
	Reset all necessary shell parameters
	This ensures the global variables will be correct
	each iteration of the main loop
*/
void reset_redirect() {
	int i;
	multi_count = 0;
	input_redirect = false;
	output_redirect = false;
	append_redirect = false;
	multi_background = false;
	background = false;
	check_pipe = false;
	externel_check = false;
	strcpy(file_name, "");
	strcpy(input_file_name, "");
	strcpy(append_file_name, "");
	for (i = 0; i < CMD_LIMIT; ++i) {
		cmd_strings[i] = NULL;
	}
	for (i = 0; i < CMD_LIMIT; ++i) {
		parallel_cmds[i] = NULL;
	}
	for (i = 0; i < multi_count; ++i) {
		free(multi_parallel[i]);
	}
}

/*
	First step of parsing user input
	Tokenizes the input, splitting commands up by whitespace
	It then adds them to the cmd_strings array which is where
	we store the commands to be run 
*/
void parse_cmd_line() {
	char* token = NULL;
	char* cmd_buff = NULL;
	int i = 0;
	size_t len = 0;
	size_t count = 0;
	cmd_count = 0;
	getline(&cmd_buff, &len, stdin);
	token = strtok(cmd_buff, " ");
	if (token == NULL && batch) exit(1);
	while (token != NULL) {
		// trim the cmd buffer of new line characters
		if ((strcmp(token, "\n")) == 0) return;
		int len;
		// not working with multiple white spaces and tabs
		for (len = 0; token[len] != '\n' && token[len] != '\0' && token[len] != ' ' && token[len] != '\t'; ++len);
		token[len] = '\0';
		cmd_strings[count++] = token;
		cmd_count++;
		token = strtok(NULL, " ");
	}
	// reset the rest of the cmd strings not in use
	for (i = cmd_count; i < CMD_LIMIT; ++i) {
		cmd_strings[i] = NULL;
	}
}

/*
	Second step of parsing user input 
	Checks for any file redirection
	If we find a special i/o character,
	we then save the appropriate file name 
	to a shell variable
	Will also check if we need to run multiple
	commands in parrallel
*/
void check_file_io() {
	int i, old_pos;
	multi_count = 0;
	for (i = 0; cmd_strings[i] != NULL; ++i) {
		if (strcmp(cmd_strings[i], "<") == 0) {
			input_redirect = true;
			input_pos = i;
			char* name = cmd_strings[i + 1];
			strcpy(input_file_name, name);
		}
		if (strcmp(cmd_strings[i], ">") == 0) {
			output_redirect = true;
			output_pos = i;
			char* name = cmd_strings[i + 1];
			strcpy(file_name, name);
		}
		if (strcmp(cmd_strings[i], ">>") == 0) {
			append_redirect = true;
			append_pos = i;
			char* name = cmd_strings[i + 1];
			strcpy(append_file_name, name);
		}
		if (strcmp(cmd_strings[i], "|") == 0) {
			check_pipe = true;
			pipe_pos = i;
			break;
		}
		if (strcmp(cmd_strings[i], "&") == 0) {
			// send this to a helper fn()
			background = true;
			background_pos = i;
			if (multi_count == 0) {
				multi_parallel[multi_count] = (MultiParallel*)malloc(sizeof(MultiParallel));
				int j;
				int count = 0;
				for (j = 0; j < background_pos; ++j, ++count) {
					multi_parallel[multi_count]->cmd[count] = cmd_strings[j];
				}
				multi_parallel[multi_count]->args = count;
				multi_parallel[multi_count++]->cmd[count + 1] = NULL;
			}
			else {
				multi_parallel[multi_count] = (MultiParallel*)malloc(sizeof(MultiParallel));
				int j;
				int count = 0;
				for (j = old_pos; j < background_pos; ++j,  ++count) {
					multi_parallel[multi_count]->cmd[count] = cmd_strings[j];
				}
				multi_parallel[multi_count]->args = count;
				multi_parallel[multi_count++]->cmd[count + 1] = NULL;
			}
			old_pos = background_pos + 1;
		}
	}
}

/*
	Third step of parsing user input 
	Checks if the cmd supplied by the user
	is a built in
	It then sets the built_in global to 
	the appropriate type to be used by 
	other parts of the program 
	Retruns false if it's not a built in 
*/
bool check_for_built_in(char* cmd) {
	if (strcmp(cmd, "cd") == 0) {
		built_in = CD;
		return true;
	}
	if (strcmp(cmd, "clear") == 0) {
		built_in = CLR;
		return true;
	}
	if (strcmp(cmd, "dir") == 0) {
		built_in = DIR_CMD;
		return true;
	}
	if (strcmp(cmd, "echo") == 0) {
		built_in = ECHO;
		return true;
	}
	if (strcmp(cmd, "pause") == 0) {
		built_in = PAUSE;
		return true;
	}
	if (strcmp(cmd, "path") == 0) {
		built_in = PATH;
		return true;
	}
	if (strcmp(cmd, "help") == 0) {
		built_in = HELP;
		return true;
	}
	if (strcmp(cmd, "environ") == 0) {
		built_in = ENVIORN;
		return true;
	}
	if (strcmp(cmd, "exit") == 0) {
		exit(1);
	}
	return false;
}

/*
	Runs the appropriate built in command 
	First checks if any file redirection is 
	needed, and will set them up if necessary
	Also checks if any pipes need to be setup 
*/
void run_built_in(char** envp) {
	int i;
	int save = dup(1);
	if (output_redirect) {
		int fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0755);
		if (fd > 0) {
			dup2(fd, STDOUT_FILENO);
			close(fd);
			for (i = output_pos; cmd_strings[i] != NULL; ++i) {
				cmd_strings[i] = NULL;
			}
		}
		else return;
	}
	if (append_redirect) {
		int fd = open(append_file_name, O_WRONLY | O_APPEND, 0755);
		if (fd > 0) {
			dup2(fd, STDOUT_FILENO);
			close(fd);
			for (i = append_pos; cmd_strings[i] != NULL; ++i) {
				cmd_strings[i] = NULL;
			}
		}
		else return;
	}
	if (check_pipe) {
		run_built_in_with_pipe(envp);
		waitpid(0, NULL, 0);
		return;
	}
	call_built_in(cmd_strings[0], cmd_strings, envp);
	dup2(save, STDOUT_FILENO);
}

/*
	Call the appropriate built in command
	Switches on the global built_in type that
	has been set earlier in the third step of parsing 
*/
void call_built_in(char* cmd, char** cmd_args, char** envp) {
	switch (built_in)
	{
	case CD:
		myshell_cd(cmd_args);
		break;
	case CLR:
		myshell_clear_screen();
		break;
	case DIR_CMD:
		myshell_dir();
		break;
	case ENVIORN:
		myshell_env(envp);
		break;
	case ECHO:
		myshell_echo(cmd_args);
		break;
	case PATH:
		myshell_path(cmd_strings[1]);
		break;
	case HELP:
		myshell_help();
		break;
	case PAUSE:
		myshell_pause();
		break;
	case EXIT:
		myshell_exit();
		break;
	default:
		break;
	}
}

/*
	Run multipile commands in parrallel
	We fork different processes that have
	been supplied by the user, and than wait 
	for them to complete
	After forking, we check if a built in or 
	external command needs to be run 
*/
void run_parrallel_cmds(char** envp) {
	int i;
	for (i = 0; i < multi_count; ++i) {
		pid_t pid;
		if ((pid = fork()) < 0) return;
		if (pid == 0) {
			if (check_for_built_in(multi_parallel[i]->cmd[0])) {
				call_built_in(multi_parallel[i]->cmd[0], multi_parallel[i]->cmd, envp);
				exit(0);
			}
			else {
				execvp(multi_parallel[i]->cmd[0], multi_parallel[i]->cmd);
			}
		}
		waitpid(-1, NULL, 0);
	}
}

/*
	Run an external shell command 
	First checks if any pipes need to be setup
	Then will check if any file i/o is needed or if
	the command should run in background
	We then fork() a child process and use execvp()
	to run the command
*/
void run_external() {
	int i;
	int in_save = dup(0);
	int out_save = dup(1);
	if (check_pipe) {
		run_external_with_pipe();
		waitpid(0, NULL, 0);
		return;
	}
	// create a new process and execute the cmd
	pid_t pid = fork();
	if (pid == 0) {
		if (input_redirect) {
			int fd = open(input_file_name, O_RDONLY);
			if (fd > 0) {
				dup2(fd, STDIN_FILENO);
				close(fd);
				for (i = input_pos; cmd_strings[i] != NULL; ++i) {
					cmd_strings[i] = NULL;
				}
			}
			else return;
		}
		if (output_redirect) {
			int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0755);
			if (fd > 0) {
				dup2(fd, STDOUT_FILENO);
				close(fd);
				for (i = output_pos; cmd_strings[i] != NULL; ++i) {
					cmd_strings[i] = NULL;
				}
			}
			else return;
		}
		if (append_redirect) {
			int fd = open(append_file_name, O_WRONLY | O_APPEND, 0755);
			if (fd > 0) {
				dup2(fd, STDOUT_FILENO);
				close(fd);
				for (i = append_pos; cmd_strings[i] != NULL; ++i) {
					cmd_strings[i] = NULL;
				}
			}
			else return;
		}
		if (background) {
			run_ext_cmd_background();
		}
		execvp(cmd_strings[0], cmd_strings);
		exit(0);
	}
	else {
		int ret;
		dup2(in_save, STDIN_FILENO);
		dup2(out_save, STDOUT_FILENO);
		if (background) return;
		else waitpid(pid, &ret, 0);
	}
}

/*
	Run an external command with a pipe 
	First setup the pipe and verify setup was ok
	Then run the first command and output to the second command
	We then wait for the processes to finish and then close the pipe
*/
void run_external_with_pipe() {
	int p[2];
	pid_t pid_one, pid_two;
	if (pipe(p) < 0) exit(1);
	if ((pid_one = fork()) < 0) {
		exit(-1);
	}
	if (pid_one == 0) {
		close(p[0]);
		dup2(p[1], STDOUT_FILENO);
		close(p[1]);
		char* s[CMD_LIMIT];
		int i;
		for (i = 0; i != pipe_pos; ++i) {
			s[i] = cmd_strings[i];
		}
		s[i] = NULL;
		execvp(s[0], s);
	}
	if ((pid_two = fork()) < 0) {
		exit(-1);
	}
	if (pid_two == 0) {
		close(p[1]);
		dup2(p[0], STDIN_FILENO);
		close(p[0]);
		int i;
		// clear the strings up to pipe_pos
		for (i = 0; i <= pipe_pos; ++i) {
			cmd_strings[i] = NULL;
		}
		// reset the cmd strings and args for the second end of pipe
		int count = 0;
		for (i = pipe_pos + 1; i < CMD_LIMIT; ++i, ++count) {
			cmd_strings[count] = cmd_strings[i];
		}
		execvp(cmd_strings[0], cmd_strings);
	}
	// only wait for children in same process group to finish
	// does not wait for any background processes
	waitpid(0, NULL, 0);	
	close(p[0]);
	close(p[1]);
}

/*
	Run a built in command with a pipe
	Will setup the pipe and do all neccessary checks
	We also have to do a few extra checks because we 
	could have to run an external command as well
	We call check_for_built_in to handle this 
*/
void run_built_in_with_pipe(char** envp) {
	int p[2];
	pid_t pid_one, pid_two;
	if (pipe(p) < 0) exit(1);
	if ((pid_one = fork()) < 0) {
		exit(-1);
	}
	if (pid_one == 0) {
		close(p[0]);
		dup2(p[1], STDOUT_FILENO);
		close(p[1]);
		call_built_in(cmd_strings[0], cmd_strings, envp);
		exit(0);
	}
	if ((pid_two = fork()) < 0) {
		exit(-1);
	}
	if (pid_two == 0) {
		close(p[1]);
		dup2(p[0], STDIN_FILENO);
		close(p[0]);
		int i;
		// clear the strings up to pipe_pos
		for (i = 0; i <= pipe_pos; ++i) {
			cmd_strings[i] = NULL;
		}
		// reset the cmd strings and args for the second end of pipe
		int count = 0;
		for (i = pipe_pos + 1; i < CMD_LIMIT; ++i, ++count) {
			cmd_strings[count] = cmd_strings[i];
		}
		execvp(cmd_strings[0], cmd_strings);
	}
	// only wait for children in same process group to finish
	// does not wait for any background processes
	waitpid(0, NULL, 0);
	close(p[0]);
	close(p[1]);
}

/*
	Run an external command in the background 
	We first change the file mode mask and then create
	create a new session to run the process in
	This allows the process to break away from the calling process's grou
	We then check for any file i/o and close the appropriate file descriptors
*/
void run_ext_cmd_background() {
	pid_t sid;
	umask(0);
	if ((sid = setsid()) > 0) {
		if (!input_redirect && !output_redirect && !append_redirect) {
			close(STDIN_FILENO);
			close(STDOUT_FILENO);
			close(STDERR_FILENO);
		}
		if (output_redirect) {
		
		}
	}
}

/*
	Run an built in command in the background
	Same concept as running an external command 
	in background
	We simply call run_built_in instead of execvp 
*/
void run_built_in_background(char** envp) {
	pid_t pid, sid;
	if ((pid = fork()) < 0) return;
	if (pid == 0) {
		umask(0);
		if ((sid = setsid()) > 0) {
			if (!output_redirect && !append_redirect) {
				close(STDOUT_FILENO);
				close(STDERR_FILENO);
			}
			run_built_in(envp);
			exit(0);
		}
		// background process failed
		else exit(1);
	}
}

/*
	Built In Command
	Changes the current working directory of the shell 
*/
void myshell_cd(char** cmd_args) {
	chdir(cmd_args[1]);
}

/*
	Built In Command
	Clears the screen using escape codes
*/
void myshell_clear_screen() {
	printf("\x1b[H\x1b[J");	
}

/*
	Built In Command
	Prints the contents of the current working directory 		
*/
void myshell_dir() {
	struct dirent* dir = NULL;
	DIR* d = NULL;
	if ((d = opendir(".")) != NULL) {
		while ((dir = readdir(d)) != NULL) {
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}

/*
	Built In Command
	Displays the user input to stdout 
	Can also print to file depending on file i/o flags
*/
void myshell_echo(char** cmd) {
	int i;
	puts(" ");
	for (i = 1; i < CMD_LIMIT && cmd[i] != NULL; i++) {
		printf("%s ", cmd[i]);
	}
	puts(" ");
}

/*
	Built In Command
	Will pause the shell program until the user hits the
	"enter" key
*/
void myshell_pause() {
	while (1) {
		char* cmd_buff = NULL;
		size_t len = 0;
		if (getline(&cmd_buff, &len, stdin)) return;
	}
}

/*
	Built In Command
	Will print info about the built in command supplied by user
	We call check_for_built_in in order to check the command we
	need info on
*/
void myshell_help() {
	if (built_in == HELP && cmd_strings[1] == NULL) {
		printf("%s", man_help);
		return;
	}
	check_for_built_in(cmd_strings[1]);
	switch (built_in)
	{
	case CD:
		printf("%s", man_cd);
		break;
	case CLR:
		printf("%s", man_clr);
		break;
	case DIR_CMD:
		printf("%s", man_dir);
		break;
	case ENVIORN:
		printf("%s", man_envp);
		break;
	case ECHO:
		printf("%s", man_echo);
		break;
	case PATH:
		printf("%s", man_path);
		break;
	case PAUSE:
		printf("%s", man_pause);
		break;
	case EXIT:
		printf("%s", man_exit);
		break;
	default:
		break;
	}
}

/*
	Built In Command
	Prints the current values of the shell path
*/
void myshell_path(char* path_name) {
	int i;
	if (shell_paths[0]) {
		printf("%s ", "path");
		for (i = 0; shell_paths[i] != NULL; ++i) {
			printf("%s ", shell_paths[i]);
		}
		if (i < CMD_LIMIT) {
			shell_paths[i] = path_name;
		}
		else {
			fprintf(stderr, "path limit has been reached\n");
		}
	}
	else shell_paths[0] = path_name;
}

/*
	Built In Command
	Prints all the shell environment variables 
*/
void myshell_env(char** envp) {
	int i;
	for (i = 0; envp[i] != NULL; ++i) {
		printf("%s\n", envp[i]);
	}
}

/*
	Built In Command
	Gracefully exit the shell ;)
*/
void myshell_exit() {
	exit(1);
}
