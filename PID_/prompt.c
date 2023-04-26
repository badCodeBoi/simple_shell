#include <stdio.h>

void prompt()
{
    printf("...$ ");
}

int main() {
    prompt();

    // Wait for user input and print the command
    char command[100];
    scanf("%s", command);
    printf("You entered: %s\n", command);

    return (0);
}
