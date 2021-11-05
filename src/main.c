/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:01:41 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/05 22:18:54 by lfelipe-         ###   ########.fr       */
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
	char *r;
	char **split;
	char *cmd;
	int i;

	i = 0;
	printf("%s\n", argv[0]);
	printf("%d\n", argc);
	r = ft_get_path(envp);
	printf("%s\n", r);
	split = ft_split(r, ':');
	while (split[i])
		printf("%s\n", split[i++]);
	free(r);
	i = 0;
	cmd = ft_check_cmd(split, "ls");
	printf("cmd %s\n", cmd);

	while (split[i])
		free(split[i++]);
	free(split);
	free(cmd);
	return (0);
}
