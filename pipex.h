/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:16:24 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/02 03:06:06 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

// libft
void	ft_putstr_fd(char *s, int fd);
int		ft_count_words(const char *s, char c);
char	**ft_free_arr(char **arr, size_t i);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

// pipex
void    error_exit(char *msg);
char	*get_path(char **envp);
char	*get_cmd_path(char *cmd, char *path_env_var);
void    execute_child(int *fd, char *file, char *command, char **envp);
void    execute_parent(int *fd, char *file, char *command, char **envp);
#endif
