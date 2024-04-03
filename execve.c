/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:07:58 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/03 19:09:35 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void execute_child(int *fd, char *file, char *command, char **envp)
{
	char **cmd;
	int outfile;

	outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		if (errno == EACCES)
			perror("open() failed");
		else
			perror("open() failed");
	}
	cmd = ft_split(command, ' ');
	dup2(outfile, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	if ((execve(get_cmd_path(cmd[0], get_path(envp)), cmd, NULL)) == -1)
	{
		if (errno == EACCES)
			error_exit("execve() failed");
		else
			error_exit("execve() failed");
	}
}

void execute_parent(int *fd, char *file, char *command, char **envp)
{
	char **cmd;
	int infile;

	infile = open(file, O_RDONLY);
	if (infile == -1)
	{
		if (errno == EACCES)
			perror("open() failed");
		else
			perror("open() failed");
	}
	cmd = ft_split(command, ' ');
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	if ((execve(get_cmd_path(cmd[0], get_path(envp)), cmd, NULL)) == -1)
	{
		if (errno == EACCES)
			error_exit("execve() failed");
		else
			error_exit("execve() failed");
	}
}
