#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> /* added for waitpid() */

#define CMDSHELL_MAXLINE 100

/**
 * prompt - prints prompt string to stdout
 *
 * Return: void
 */
void prompt(void)
{
printf("#cisfun$ ");
}

/**
 * read_command - reads a command from stdin
 *
 * Return: pointer to command string
 */
char *read_command(void)
{
char *cmdshell = malloc(CMDSHELL_MAXLINE);
if (fgets(cmdshell, CMDSHELL_MAXLINE, stdin) == NULL)
{
if (feof(stdin))
{
printf("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("fgets");
exit(EXIT_FAILURE);
}
}
/* remove trailing newline character */
cmdshell[strcspn(cmdshell, "\n")] = '\0';

return (cmdshell);
}

/**
 * execute_command - executes a command using fork() and execlp()
 * @cmdshell: command to execute
 *
 * Return: void
 */
void execute_command(char *cmdshell)
{
int cmd_stat;
/* Execute the command */
pid_t pid = fork(); /* create a child process*/
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* child process */
execlp(cmdshell, cmdshell, NULL); /* execute the command */
perror("execlp");
exit(EXIT_FAILURE);
}
else
{
/* parent process */
int status;
waitpid(pid, &status, 0); /* wait for child process to finish */

if (WIFEXITED(status))
{
/* check if child process exited normally */
cmd_stat = WEXITSTATUS(status); /* get the exit status of child process */
}
else
{
cmd_stat = -1;
perror("waitpid");
}
}
/* Check for errors */
if (cmd_stat == -1)
{
perror("system");
exit(EXIT_FAILURE);
}
}

/**
 * main - entry point
 *
 * Return: 0 on success
 */
int main(void)
{
while (1)
{
prompt();
char *cmdshell = read_command();
execute_command(cmdshell);
parse_args();
free(cmdshell);
}

return (0);
}
