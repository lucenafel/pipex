/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:01:41 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/07 20:35:37 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
	char **split;
	char *cmd;
	int i;

	cmd = NULL;
	printf("%s\n", argv[1]);
	char *a = ft_strdup(argv[1]);
	printf("%s\n", a);
	if (cmd)
	{
		printf("%s\n", argv[0]);
		printf("%d\n", argc);
	}
	split = ft_get_path(envp);
	i = 0;
	cmd = ft_check_cmd(split, argv[1]);
	if (!cmd)
		printf("invalid command\n");
	else
		printf("cmd %s\n", cmd);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	if (cmd)
		free(cmd);
	return (0);
}
