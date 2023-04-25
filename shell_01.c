#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
/**
 * main - interpretr for commandline
 *
 * Return: 0 on success, non-zero on failure
 */

int main(void)
{
char buffer[BUFFER_SIZE];
char *args[2];
pid_t pid;
int status;

while (1)
{
	printf("$ ");
	fflush(stdout);

if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
{
	printf("\n");
	break;
}

buffer[strcspn(buffer, "\n")] = '\0'; /* remove newline character */

args[0] = buffer;
args[1] = NULL;

pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if
(pid == 0) {
	execvp(args[0], args);
	perror("execvp");
	exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
}
}
return (0);
}

