/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:16:48 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/08 04:49:32 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

pid_t create_pipe_and_fork(int fd[])
{
    if (pipe(fd) == -1)
        error_exit("pipe() failed\n");
    pid_t pid = fork();
    if (pid == -1)
        error_exit("fork() failed\n");
    return pid;
}

void execute_child_process(char *command, char **envp, int fd[])
{
    char **cmd = ft_split(command, ' ');
    char *path = get_path(envp);
    close(fd[0]);
    dup2(fd[1], 1);
    if ((execve(get_cmd_path(cmd[0], path), cmd, NULL)) == -1)
    {
        free(path);
        errmsg_command_not_found("execve() failed");
    }
}

void execute_parent_process(int fd[], pid_t pid)
{
    close(fd[1]);
    dup2(fd[0], 0);
    waitpid(pid, NULL, 0);
}

void execute(char *command, char **envp)
{
    int fd[2];
    pid_t pid = create_pipe_and_fork(fd);
    if (pid == 0)
        execute_child_process(command, envp, fd);
    else
        execute_parent_process(fd, pid);
}
void execute_last(char *command, char **envp, int outfile)
{
    pid_t pid;
    char **cmd;
    char *path;

    pid = fork();
    if (pid == -1)
        error_exit("fork() failed\n");
    if (pid == 0)
    {
        cmd = ft_split(command, ' ');
        path = get_path(envp);
        dup2(outfile, 1);
        if ((execve(get_cmd_path(cmd[0], path), cmd, NULL)) == -1)
        {
            free(path);
            errmsg_command_not_found("execve() failed");
        }
    }
    else
        waitpid(pid, NULL, 0);
}
