#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int file[2];
    pid_t pid;

    file[0] = open(argv[1], O_RDONLY);
    file[1] = open(argv[4], O_WRONLY | O_TRUNC);
    ensure_preconditions(argc, argv[1], argv[4], fd);
    pid = fork();
    if (pid == 0)
        execute_child(fd, file, argv[3], envp);
    else if (pid > 0)
        execute_parent(fd, file, argv[2], envp);
    else
        check_fork(pid);
}