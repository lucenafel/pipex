/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:01:41 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/16 17:00:59 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> // remove

char	*get_cmd(char *arg)
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

int main(void)
{
}
