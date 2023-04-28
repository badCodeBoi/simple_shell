#include <stdio.h>
/**
* main -
*
* @prompt: prints > "#cisfun" to output.
* @cmdshell: cmdshell is the commandline[Maxline]
*/

void prompt()
{
    printf("#cisfun$ ");
}

int main()
{
    prompt();

    // Wait for user input and print the command
    char cmdshell[100];

    scanf("%s", cmdshell);
    printf("You entered: %s\n", cmdshell);

    return (0);
}
