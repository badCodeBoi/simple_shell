#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **environ)
{
    char **envp = environ;

    while (*envp != NULL) {
        printf("%s\n", *envp);
        envp++;
    }

    char *home = getenv("HOME");
    if (home != NULL) {
        printf("HOME=%s\n", home);
    }

    return 0;
}
