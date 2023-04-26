#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _setenv - Changes or adds an environment variable
 * @name: The name of the environment variable to set
 * @value: The value to set the environment variable to
 * @overwrite: Whether or not to overwrite the variable if it already exists
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
        int i, namelen, valuelen;
        char **envp, *newenvvar;

        if (name == NULL || value == NULL)
                return (-1);

        namelen = _strlen(name);
        valuelen = _strlen(value);

        for (envp = environ; *envp != NULL; envp++)
        {
                if (_strncmp(name, *envp, namelen) == 0 && (*envp)[namelen] == '=')
                {
                        if (overwrite)
                        {
                                newenvvar = malloc(namelen + valuelen + 2);
                                if (newenvvar == NULL)
                                        return (-1);

                                _strncpy(newenvvar, name, namelen);
                                newenvvar[namelen] = '=';
                                _strncpy(newenvvar + namelen + 1, value, valuelen);
                                newenvvar[namelen + valuelen + 1] = '\0';

                                free(*envp);
                                *envp = newenvvar;
                                return (0);
                        }
                        else
                        {
                                return (0);
                        }
                }
        }

        newenvvar = malloc(namelen + valuelen + 2);
        if (newenvvar == NULL)
                return (-1);

        _strncpy(newenvvar, name, namelen);
        newenvvar[namelen] = '=';
        _strncpy(newenvvar + namelen + 1, value, valuelen);
        newenvvar[namelen + valuelen + 1] = '\0';

        *envp = newenvvar;
        *(envp + 1) = NULL;

        return (0);
}
