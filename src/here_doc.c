/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:43:33 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/03 15:32:24 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *deli, int fd)
{
	char	*ret;
	size_t	len;

	while(1) 
	{
		ret = get_next_line(0);
		len = ft_strlen(ret);
		if (!ft_strncmp(ret, deli, len - 1))
		{
			free(ret);
			break ;
		}
		else
		{
			write(fd, ret, len);
			free(ret);
		}
	}
}

void	ft_exec_doc(t_vars *vars, int *fd)
{
	here_doc(vars->argv[2], fd[1]);
	close(fd[0]);
	close(fd[1]);
	vars->doc = 0;
}