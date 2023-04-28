#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_INPUT_LEN 1024

int main(void)
{
char input[MAX_INPUT_LEN];
Command cmd;

cmd.background = false;

while (true) {
printf("> ");
fflush(stdout);

if (fgets(input, MAX_INPUT_LEN, stdin) == NULL) {
printf("\n");
break;
}

parse_cmd(input, &cmd);
execute_cmd(&cmd);
}

return (EXIT_SUCCESS);
}
