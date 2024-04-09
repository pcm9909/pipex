/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:52:51 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/09 17:52:53 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

int	handle_files(int argc, char **argv, int *infile, int *outfile)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (*outfile == -1)
			error_exit("open() failed");
		here_docs(argc, argv[2]);
		return (3);
	}
	else
	{
		*infile = open(argv[1], O_RDONLY);
		if (*infile == -1)
			perror("open() failed");
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*outfile == -1)
			error_exit("open() failed");
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
		errmsg_invalid_input("Invalid number of argc");
}
