#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 1024

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
        char *path_env = getenv("PATH");
        char *path = strtok(path_env, ":");
        char filepath[MAX_PATH_LENGTH];
        int found = 0;

        if (argc != 2)
        {
                fprintf(stderr, "Usage: %s filename\n", argv[0]);
                return (1);
        }

        while (path != NULL)
        {
                snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", path, argv[1]);
                if (access(filepath, F_OK) == 0)
                {
                        printf("%s\n", filepath);
                        found = 1;
                        break;
                }
                path = strtok(NULL, ":");
        }

        if (!found)
        {
                printf("%s: command not found\n", argv[1]);
                return (1);
        }

        return (0);
}
