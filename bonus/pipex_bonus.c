/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:17:09 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/08 04:18:20 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

int	handle_files(int argc, char **argv, int *infile, int *outfile)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (*outfile == -1)
			error_exit("open() failed\n");
		here_docs(argc, argv[2]);
		return (3);
	}
	else
	{
		*infile = open(argv[1], O_RDONLY);
		if (*infile == -1)
			perror("open() failed\n");
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*outfile == -1)
			error_exit("open() failed\n");
		return (2);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc >= 5)
	{
		i = handle_files(argc, argv, &infile, &outfile);
		while (i < argc - 2)
			execute(argv[i++], envp);
		execute_last(argv[i], envp, outfile);
	}
	else
		errmsg_invailded_input();
}
