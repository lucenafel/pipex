/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:22:28 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/09 17:43:54 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_cmd(char **path, char *cmd)
{
	int		i;
	char	*join;
	char	*tmp;

	i = 0;
	join = 0;
	if (cmd)
	{
		tmp = ft_strjoin("/", cmd);
		while (path[i])
		{
			join = ft_strjoin(path[i], tmp);
			if (!access(join, X_OK))
				break ;
			else
			{
				free(join);
				join = 0;
			}
			i++;
		}
		free(tmp);
	}
	return (join);
}

int	ft_check_slash(char *cmd)
{
	int	i;
	int	signal;

	i = 0;
	signal = 0;
	if (cmd)
	{
		while (cmd[i])
		{
			if (cmd[i] == '/')
			{
				signal = 1;
				break ;
			}
			i++;
		}
	}
	return (signal);
}
