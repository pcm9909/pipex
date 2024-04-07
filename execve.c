/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:07:58 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/06 16:25:36 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_child(int *fd, char *file, char *command, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;
	char	*cmd_path;
	
	outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("open() failed");
		exit(1);
	}
	path = get_path(envp);
	cmd = ft_split(command, ' ');
	cmd_path = get_cmd_path(cmd[0], path);
	dup2(outfile, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	if ((execve(cmd_path, cmd, NULL)) == -1)
		error_exit("execve() failed");
}

void	execute_parent(int *fd, char *file, char *command, char **envp)
{
	char	**cmd;
	char	*path;
	char	*cmd_path;
	int		infile;
	
	infile = open(file, O_RDONLY);
	if (infile == -1)
	{
		perror("open() failed");
		exit(1);
	}
	path = get_path(envp);
	cmd = ft_split(command, ' ');
	cmd_path = get_cmd_path(cmd[0], path);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	if ((execve(cmd_path, cmd, NULL)) == -1)
		error_exit("execve() failed");
}
