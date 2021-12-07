/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:32:38 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/07 02:37:40 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> // remove

void	ft_here_doc(char *deli, int *fd)
{
	char	*ret;
	size_t	len;

	close(fd[0]);
	while(1) 
	{
		write(1, "here_doc> ", 10);
		ret = get_next_line(0);
		len = ft_strlen(ret);
		if (!ft_strncmp(ret, deli, len - 1))
		{
			close(fd[1]);
			free(ret);
			exit(0);
		}
		else
		{
			write(fd[1], ret, len);
			free(ret);
		}
	}
}

void	ft_exec_doc(t_vars *vars)
{
	int	pipefd[2];
	int	pid;

	if (pipe(pipefd) == -1)
		printf("PIPE ERROR"); // change for message error
	pid = fork();
	if (pid < 0)
		printf("fork ERROR"); // change for message error 
	if (pid == 0)
		ft_here_doc(vars->argv[vars->idx], pipefd);
	else
		wait(NULL);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	close(pipefd[1]);
	vars->doc = 0;
}