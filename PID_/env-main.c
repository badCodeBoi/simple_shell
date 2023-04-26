#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av)
{
    int i = 0;
    char *env = *environ;

    while (env != NULL) {
        printf("%s\n", env);
        env = *(environ + ++i);
    }

    return (0);
}

