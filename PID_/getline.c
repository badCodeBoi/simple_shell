#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$ ");
    fflush(stdout);

    if ((read = getline(&line, &len, stdin)) == -1) {
        printf("Error: getline() failed\n");
        exit(EXIT_FAILURE);
    }

    printf("You entered: %s", line);

    free(line);
    exit(EXIT_SUCCESS);
}
