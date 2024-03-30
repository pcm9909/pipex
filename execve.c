#include "pipex.h"

void execute_child(int *fd, int *file, char *command, char **envp)
{
    char **cmd;
    cmd = ft_split(command, ' ');
    dup2(file[1], 1);
    close(fd[1]);
    dup2(fd[0], 0);
    execve(get_cmd_path(cmd[0], get_path(envp)), cmd, NULL);
    perror("execve failed");
    exit(1);
}

void execute_parent(int *fd, int *file, char *command, char **envp)
{
    char **cmd;
    
    cmd = ft_split(command, ' ');
    dup2(file[0], 0);
    close(fd[0]);
    dup2(fd[1], 1);
    execve(get_cmd_path(cmd[0], get_path(envp)), cmd, NULL);
    perror("execve failed");
    exit(1);
}