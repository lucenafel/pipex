/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:14:58 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/03 15:37:48 by lfelipe-         ###   ########.fr       */
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
	if (!vars->cmd_path && !vars->doc)
	{
		perror("ERROR"); // fix error output
		exit(0);
	}
	if (!vars->doc)
		execve(vars->cmd_path, vars->cmd_args, vars->envp); // treat erros
	else
		ft_exec_doc(vars, pipefd);
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
	pid = fork();
	if (pid == 0)
		ft_child(vars, pipefd);
	else
		ft_parent(pipefd, pid);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
}
