/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:21:18 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/06 23:17:11 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **envp)
{
	char	**split;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			path = ft_strdup(envp[i]);
		i++;
	}
	tmp = path;
	path = ft_strdup(tmp + 5);
	free(tmp);
	split = ft_split(path, ':');
	free(path);
	return (split);
}
