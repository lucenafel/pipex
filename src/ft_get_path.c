/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:23:00 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/23 20:53:16 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **envp)
{
	char	**split;
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			path = ft_strdup(envp[i] + 5);
		i++;
	}
	split = ft_split(path, ':');
	free(path);
	return (split);
}
