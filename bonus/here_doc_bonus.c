/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:16:53 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/09 17:57:49 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

void	write_to_pipe(int fd[], char *limiter)
{
	char	*here_docs;

	close(fd[0]);
	here_docs = get_next_line(0);
	while (here_docs)
	{
		if (ft_strncmp(here_docs, limiter, ft_strlen(here_docs)) == 0 \
				&& ft_strlen(here_docs) != 0)
			exit(0);
		write(fd[1], here_docs, ft_strlen(here_docs));
		write(fd[1], "\n", 1);
		free(here_docs);
		here_docs = get_next_line(0);
	}
}

void	read_from_pipe(int fd[])
{
	close(fd[1]);
	dup2(fd[0], 0);
	wait(NULL);
}

void	here_docs(int argc, char *limiter)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
		errmsg_invalid_input("Invalid number of argc");
	if (pipe(fd) == -1)
		error_exit("pipe() failed");
	pid = fork();
	if (pid == 0)
		write_to_pipe(fd, limiter);
	else
		read_from_pipe(fd);
}
