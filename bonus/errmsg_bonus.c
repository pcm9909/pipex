/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:16:43 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/08 04:48:21 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(1);
}

void	errmsg_command_not_found(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" : Command not found\n", 2);
	exit(1);
}

void	errmsg_invalid_input(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}
