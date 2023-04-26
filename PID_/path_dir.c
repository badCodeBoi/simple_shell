#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path_directories() {
    char *path = getenv("PATH");
    if (path == NULL) {
        fprintf(stderr, "PATH environment variable not set\n");
        return;
    }
    char *p = strtok(path, ":");
    while (p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, ":");
    }
}

int main()
{
    print_path_directories();
    return 0;
} 
/**
 * This function first gets the value of the PATH environment variable using getenv. If the variable is not set, it prints an error message and returns. Otherwise, it uses strtok to split the value into directories using the colon (:) as the delimiter. Each directory is printed on a separate line using printf.
 */
