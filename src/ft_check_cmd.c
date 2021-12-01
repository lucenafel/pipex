/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:22:28 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/01 18:58:13 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_args(char *rawarg)
{
	char	**args;
	char	*trim;

	trim = ft_strtrim(rawarg, " ");
	args = ft_split(trim, ' ');
	free(trim);
	return (args);
}

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

char	*ft_get_cmd(char *arg)
{
	int		count;
	int		i;
	char	*trim;
	char	*cmd;

	i = 0;
	count = 0;
	trim = ft_strtrim(arg, " ");
	while (trim[count] != ' ')
		count++;
	cmd = (char *)malloc(count + 1);
	while (i < count)
	{
		cmd[i] = trim[i];
		i++;
	}
	cmd[i] = '\0';
	free(trim);
	return (cmd);
}
