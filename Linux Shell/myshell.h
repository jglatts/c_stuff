/*
	CIS3207 Lab2 Shell
	Author: John Glatts

	Header file for the shell program
	Contains all neccessary data structures and function prototypes
	Please see myshell.c for implementation 
*/
#ifndef MYSHELL__H
#define MYSHELL__H	

#include "myshell_man.h"
#include <stdbool.h>

/* MyShell defines */
#define CMD_LIMIT 15
#define GREEN  "\033[0;32m"
#define RESET  "\033[0m"

/*
	MultiParallel Data Structure to hold info 
	about the commands to run in parrallel
	Only gets used if the "&" character is used more than once and is valid 
*/
typedef struct MultiParallel {
	char* cmd[CMD_LIMIT];
	int args;
}MultiParallel;

/*
	Enum of Built-In Shell commands
	These are the current valid built in commands 
*/
typedef enum Built_In {
	CD,
	CLR,
	DIR_CMD,
	ENVIORN,
	ECHO,
	PATH,
	HELP,
	PAUSE,
	EXIT
} Built_In;

/* 
	Shell Functions 
	Please see myshell.c for details 
*/
bool init_shell(int, char**);
bool run_shell(int, char**, char**);
bool check_for_built_in(char*);
void check_file_io();
void call_built_in(char*, char**, char** envp);
void reset_redirect();
void run_user_cmd(char**);
void run_built_in(char**);
void run_external();
void run_external_with_pipe();
void run_parrallel_cmds(char**);
void run_built_in_with_pipe(char**);
void run_ext_cmd_background();
void run_built_in_background(char**);
void parse_cmd_line();
void print_prompt();
void myshell_cd(char**);
void myshell_clear_screen();
void myshell_dir();
void myshell_echo(char**);
void myshell_pause();
void myshell_help();
void myshell_path(char*);
void myshell_env(char**);
void myshell_exit();

#endif // MYSHELL__H