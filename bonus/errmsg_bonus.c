#include "../header/pipex_bonus.h"

void error_exit(char *msg)
{
    perror(msg);
    exit(1);
}

void errmsg_command_not_found()
{
    ft_putstr_fd("execuve() failed\n", 2);
    ft_putstr_fd(": Command not found\n",2);
    exit(1);
}

void errmsg_invailded_input()
{
    ft_putstr_fd("input error\n", 2);
    ft_putstr_fd(": Invalid number of argc\n", 2);
    exit(1);
}