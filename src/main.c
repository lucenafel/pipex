/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:01:41 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/15 21:49:36 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
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
	int pid;
	int pipefd[2];
	char **s = NULL;
	pid = 0;

	if (pid)
		printf("%d\n", argc);
	if (pipe(pipefd) == -1)
		return (-1);

	s[0] = "./pipex";
	s[1] = "pid";
	s[2] = 0;
	pid = fork();

	if (pid > 0)
	{
		execve("cat", argv, envp);
		dup2(pipefd[1], 1);
	}
	else
	{
		wait(NULL);
		dup2(pipefd[0], 0);
		printf("segunda execução");
		execve("grep", s, envp);
	}
}
