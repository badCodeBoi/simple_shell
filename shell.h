#ifndef CMDSHELL_STDIO_H
#define CMDSHELL_STDIO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define CMDSHELL_MAXLINE 100

void prompt(void);
char *read_command(void);
void execute_command(char *cmdshell);

/* parse */
int parse_args(char *str, char **args);

#endif /* CMDSHELL_STDIO_H */

