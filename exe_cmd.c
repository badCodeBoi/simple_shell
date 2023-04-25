#include <stdio.h>
#include "cmdshell.h"

/**
* exe_cmd - Execute a command.
*
* @args: An array of arguments passed to the command.
*
* Return: 0 on success, 1 on failure.
*/

int execmd(char **args)
{
/*Execute the command using the execvp() function */
if (execvp(args[0], args) == -1)
{
/* If the execvp() function returns -1, there was an error */

/* Print an error message with the name of the cmdshell program */
perror("cmdshell");
/* Return 1 to indicate failure */
return (1);
}
/*Return 0 to indicate success */
return (0);
}
