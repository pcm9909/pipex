/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:16:35 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/08 03:16:35 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"

//errmsg_bonus.c
void	errmsg_command_not_found();
void	error_exit(char *msg);
void	errmsg_invailded_input();

//here_doc.c
void	write_to_pipe(int fd[], char *limiter);
void	read_from_pipe(int fd[]);
void	here_docs(int argc, char *limiter);

//make_cmd_bonus.c
char	*get_path(char **envp);
void	check_cmd(char *cmd_path);
char	*check_path(char *cmd);
char	*search_path(char *cmd, char *path);
char	*get_cmd_path(char *cmd, char *path_env_var);

//execute_bonus.c
void	execute_child_process(char *command, char **envp, int fd[]);
pid_t	create_pipe_and_fork(int fd[]);
void	execute_parent_process(int fd[], pid_t pid);
void	execute(char *command, char **envp);
void	execute_last(char *command, char **envp, int outfile);

#endif
