/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:14:18 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/08 01:18:42 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error_exit("pipe() failed\n");
		pid = fork();
		if (pid == -1)
			error_exit("fork() failed\n");
		if (pid == 0)
			execute_child(fd, argv[4], argv[3], envp);
		else if (pid > 0)
			execute_parent(fd, argv[1], argv[2], envp);
	}
	else
	{
		ft_putstr_fd("invalid number of argc", 2);
		exit(1);
	}
}
