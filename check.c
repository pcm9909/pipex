#include "pipex.h"

void check_argc(int argc)
{
    if (argc != 5)
    {
        perror("wrong number of arguments");
        exit(1);
    }
}

void check_file(char *file1, char *file2)
{
    if (access(file1, F_OK) == -1)
    {
        perror("infile does not exist");
        exit(1);
    }
    if (access(file2, F_OK) == -1)
    {
        perror("outfile does not exist\n");
        exit(1);
    }
}

void check_pipe(int *fd)
{
    if (pipe(fd) == -1)
    {
        perror("pipe() failed\n");
        exit(1);
    }
}

void check_fork(pid_t pid)
{
    if (pid == -1)
    {
        perror("fork() failed\n");
        exit(1);
    }
}

void ensure_preconditions(int argc, char *f1, char *f2, int *fd)
{
    check_argc(argc);
    check_file(f1, f2);
    check_pipe(fd);
}

