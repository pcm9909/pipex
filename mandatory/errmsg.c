#include "../header/pipex.h"

void error_exit(char *msg)
{
    perror(msg);
    exit(1);
}

void errmsg_exit(char *msg)
{
    ft_putstr_fd(msg, 2);
    exit(1);
}