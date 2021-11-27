/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:22:28 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/25 16:30:02 by lfelipe-         ###   ########.fr       */
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
