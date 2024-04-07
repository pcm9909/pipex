/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 03:16:27 by chunpark          #+#    #+#             */
/*   Updated: 2024/04/08 03:16:27 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void error_exit(char *msg)
{
    perror(msg);
    exit(1);
}

void errmsg_exit(char *msg)
{
    ft_putstr_fd(msg, 2);
    exit(1);
}