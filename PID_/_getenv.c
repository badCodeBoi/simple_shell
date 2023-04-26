#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name) {
    extern char **environ;
    int i = 0;
    char *p = NULL;
    while (environ[i] != NULL) {
        if (strncmp(name, environ[i], strlen(name)) == 0) {
            p = environ[i] + strlen(name) + 1;
            break;
        }
        i++;
    }
    return p;
}

int main(void) {
    char *path = _getenv("PATH");
    if (path != NULL) {
        printf("PATH=%s\n", path);
    }
    return 0;
}
