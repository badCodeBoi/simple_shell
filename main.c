#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define CMDSHELL_MAXLINE 100

void prompt()
{
printf("#cisfun$ ");
}

int read_command(char* cmdshell)
{
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

cmdshell[strcspn(cmdshell, "\n")] = '\0';
return 0;
}

int execute_command(char* cmdshell)
{
pid_t pid = fork();
int cmd_stat;

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(cmdshell, cmdshell, NULL);
perror("execlp");
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);

if (WIFEXITED(status))
{
cmd_stat = WEXITSTATUS(status);
}
else
{
cmd_stat = -1;
perror("waitpid");
}
}

if (cmd_stat == -1)
{
perror("system");
exit(EXIT_FAILURE);
}

return 0;
}

int main(void)
{
char cmdshell[CMDSHELL_MAXLINE];

while (1)
{
prompt();
read_command(cmdshell);
execute_command(cmdshell);
}

return 0;
}
