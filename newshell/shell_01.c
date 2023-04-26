#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - entry of command Shell.
 *
 * return: 0 on success
 */


int main(void)
{
char *buffer = NULL;
size_t bufsize = 0;
pid_t pid;

while (1)
{
printf("$ ");
fflush(stdout);
if (getline(&buffer, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
printf("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}
buffer[strcspn(buffer, "\n")] = '\0';
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
	/* child process */
if (execlp(buffer, buffer, (char *) NULL) == -1)
{
perror("execlp\n");
exit(EXIT_FAILURE);
}
}
else
{
	/* parent process */
wait(NULL);
}
}
free(buffer);
buffer = NULL;

return (0);
}
