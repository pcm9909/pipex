/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:16:24 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/07 23:58:03 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "../utils/libft/libft.h"

// errmsg.c
void error_exit(char *msg);
void errmsg_exit(char *msg);

// make_cmd.c
char	*get_path(char **envp);
void	check_cmd(char *cmd_path);
char	*check_path(char *cmd);
char	*search_path(char *cmd, char *path);
char	*get_cmd_path(char *cmd, char *path_env_var);

// execve.c
void	execute_child(int *fd, char *file, char *command, char **envp);
void	execute_parent(int *fd, char *file, char *command, char **envp);

#endif
