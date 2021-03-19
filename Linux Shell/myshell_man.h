/*
	CIS3207 Lab2 Shell
	Author: John Glatts

	Header file for the shell program help function 
	Contains info regarding each built in command
*/
#ifndef MYSHELL__MAN__H
#define MYSHELL__MAN__H	

/* Info about cd */
const char man_cd[] =
"Name:\n\tcd\n"
"Usage:\n\tcd <path>\n"
"Description:\n\twill change the current directory to 'path', if it exists\n"
"\t              does not change current directory if it fais\n";

/* Info about clear */
const char man_clr[] =
"Name:\n\tclear\n"
"Usage:\n\tclear\n"
"Description:\n\twill clear all contents of stdout screen\n";

/* Info about dir */
const char man_dir[] =
"Name:\n\tdir\n"
"Usage:\n\tdir\n"
"Description:\n\tprint everything in the current working directory\n";

/* Info about environ */
const char man_envp[] =
"Name:\n\tenvp\n"
"Usage:\n\tenvp\n"
"Description:\n\tprint the current shell enviorment strings\n";

/* Info about echo */
const char man_echo[] =
"Name:\n\techo\n"
"Usage:\n\techo 'cmd'\n"
"Description:\n\tprints 'cmd' to stdout\n";

/* Info about path */
const char man_path[] =
"Name:\n\tpath\n"
"Usage:\n\tpath 'path_name'\n"
"\tpath\n"
"Description:\n\tprints the current shell path list if no path arg is supplied\n"
"\twill add 'path_name' to path list if arg is supplied\n";

/* Info about help */
const char man_help[] =
"Name:\n\thelp\n"
"Usage:\n\thelp 'cmd'\n"
"Description:\n\tprints usefull info about the 'cmd'\n";

/* Info about pause */
const char man_pause[] =
"Name:\n\tpause\n"
"Usage:\n\tpause\n"
"Description:\n\tpause unitl user hits enter key\n";

/* Info about exit */
const char man_exit[] =
"Name:\n\texit\n"
"Usage:\n\texit\n"
"Description:\n\texit the shell program\n";

#endif // MYSHELL__MAN__H