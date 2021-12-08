/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:32:26 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/08 17:56:13 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, int code)
{
	if (code == 1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (code == 2)
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (code == 3)
		ft_putendl_fd("pipe error", 2);
	else
		ft_putendl_fd("fork error", 2);
}
