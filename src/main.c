/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:01:41 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/08 20:36:16 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

char	**parse_cmd(char *argv)
{
	char **split;

	split = ft_split(argv, ' ');
	return (split);
}

int main(int argc, char *argv[], char *envp[])
{
	char **split;
	char **split2;
	char *cmd;
	/* char *exec = "/usr/bin/ls"; */
	char *test[] = {"./pipex", "-l", 0};

	cmd = NULL;
	split2 = NULL;
	if (cmd)
	{
		printf("%s\n", argv[0]);
		printf("%d\n", argc);
	}
	split = ft_get_path(envp);
	if (argc >= 3)
	{
		split2 = parse_cmd(argv[2]);
		printf("%s\n", split2[0]);
	}
	if (argc >= 3)
		cmd = ft_check_cmd(split, split2[0]);
	printf("%s\n", cmd);
	execve(cmd, test, envp);
	/* if (!cmd) */
	/* 	printf("invalid command\n"); */
	/* else */
	/* 	printf("cmd %s\n", cmd); */
	ft_free(split);
	ft_free(split2);
	if (cmd)
		free(cmd);
	return (0);
}
