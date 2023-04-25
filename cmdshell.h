#ifndef _CMDSHELL_H
#define _CMDSHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;


int maiN(void);
void execute_command(void);
void initialize_environment(void);


void print_prompt(void);
char *read_input(void);
/*int execute_command(char *command);*/
char **parse_line(char *line);

int execmd(char **args);

/* exit_terminal*/
void exit_terminal(void);
void process_input(char *buffer);

#endif /* _CMDSHELL_H */
