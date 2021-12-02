/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:14:58 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/02 19:21:20 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> //remover

static void	ft_parent(int *pipefd, int pid)
{
	int	status;

	close(pipefd[1]);
	waitpid(pid, &status, 0);
}

static void	ft_child(t_vars *vars, int *pipefd)
{
	if (vars->idx == vars->argc - 2)
	{
		dup2(vars->outfile, 1);
		close(vars->outfile);
	}
	else
	{
		dup2(pipefd[1], 1);
		close(pipefd[1]);
	}
	close(pipefd[0]);
	if (!vars->cmd_path)
	{
		perror("ERROR"); // fix error output
		exit(0);
	}
	execve(vars->cmd_path, vars->cmd_args, vars->envp);
}

void	ft_fork(t_vars *vars)
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		printf("PIPE ERROR\n"); // fix error output
	if (vars->idx == 2 && !vars->doc)
	{
		dup2(vars->infile, 0);
		close(vars->infile);
	}
	else if (vars->doc)
	{
		writte(pipefd[1], vars->doc_str, ft_strlen(vars->doc_str));
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	pid = fork();
	if (pid == 0)
		ft_child(vars, pipefd);
	else
		ft_parent(pipefd, pid);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
}
