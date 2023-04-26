#include <stdlib.h>
#include <string.h>

/**
 * _unsetenv - deletes the variable name from the environment
 *
 * @name: name of the variable to delete
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
        int i, j, len;
        extern char **environ;

        /* get length of name */
        len = strlen(name);

        /* loop through environment variables */
        for (i = 0; environ[i] != NULL; i++)
        {
                /* if name matches variable name */
                if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
                {
                        /* shift environment variables to the left to remove variable */
                        for (j = i; environ[j] != NULL; j++)
                        {
                                environ[j] = environ[j + 1];
                        }

                        return (0);
                }
        }

        return (-1);
}
