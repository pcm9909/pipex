/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:10:40 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/02 11:38:29 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	check_cmd(char *cmd_path)
{
	if (!cmd_path)
	{
		perror("command not found");
		exit(1);
	}
}

char	*get_cmd_path(char *cmd, char *path)
{
	char	**paths;
	char	*cmd_path;
	char	*tmp;
	int		i;

	paths = ft_split(path, ':');
	cmd_path = NULL;
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) != -1)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (cmd_path);
}
