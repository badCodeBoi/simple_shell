#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

void parse_cmd(char* cmd_str, Command* cmd)
{
int i = 0;
char* token = strtok(cmd_str, " \t\n");
while (token != NULL)
{
if (strcmp(token, "&") == 0) {

cmd->background = true;

break;
  
}

  cmd->args[i++] = token;
  
  token = strtok(NULL, " \t\n");
  
}

  cmd->args[i] = NULL;

}


void execute_cmd(Command* cmd) {

  pid_t pid = fork();
  
  if (pid == 0) {
  
    execvp(cmd->args[0], cmd->args);
    
    perror("execvp");
    
    exit(EXIT_FAILURE);
    
  }
  else if (pid > 0)
  {
  
    if (!cmd->background) {
    
      int status;
      
      waitpid(pid, &status, 0);
      
    }
    
  }
  else
  {
perror("fork");
exit(EXIT_FAILURE);
}
}
