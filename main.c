#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> /* added for waitpid() */

#define CMDSHELL_MAXLINE 100

void prompt()
{
printf("#cisfun$ ");
}

int main(void)
{
char cmdshell[CMDSHELL_MAXLINE];
int cmd_stat;

while (1)
{
prompt();
if (fgets(cmdshell, CMDSHELL_MAXLINE, stdin) == NULL) {
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

/* Execute the command */
pid_t pid = fork(); // create a child process
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
{ /* check if child process exited normally */
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

return (0);
}
