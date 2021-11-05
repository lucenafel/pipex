/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:37:00 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/05 22:18:52 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_cmd(char **path, char *cmd)
{
	int		i;
	char	*join;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin("/", cmd);
	while (path[i])
	{
		join = ft_strjoin(path[i], tmp);
		if (!access(join, 1))
			break;
		else
			free(join);
		i++;
	}
	free(tmp);
	return (join);
}
