/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:16:59 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/09 17:21:37 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

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

char	*check_path(char *cmd)
{
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) != -1)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	return (NULL);
}

char	*search_path(char *cmd, char *path)
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

char	*get_cmd_path(char *cmd, char *path)
{
	char	*cmd_path;

	cmd_path = check_path(cmd);
	if (cmd_path != NULL)
		return (cmd_path);
	return (search_path(cmd, path));
}
