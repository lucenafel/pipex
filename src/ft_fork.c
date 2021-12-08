/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:14:58 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/08 17:50:31 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_parent(int *pipefd, int pid)
{
	int	status;

	close(pipefd[1]);
	waitpid(pid, &status, 0);
}

static void	ft_dup(t_vars *vars, int *pipefd)
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
}

static void	ft_child(t_vars *vars, int *pipefd)
{
	ft_dup(vars, pipefd);
	ft_init_args(vars);
	if (execve(vars->cmd_args[0], vars->cmd_args, vars->envp) == -1)
	{
		ft_error(vars->cmd_args[0], 1);
		ft_free(vars->cmd_args);
		exit(0);
	}
}

void	ft_fork(t_vars *vars)
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		ft_error(NULL, 3);
	//if (vars->idx == 2 && !vars->doc) caso de ruim 
	if (vars->idx == 2)
	{
		dup2(vars->infile, 0);
		close(vars->infile);
	}
	pid = fork();
	if (pid < 0)
		ft_error(NULL, 4);
	if (pid == 0)
		ft_child(vars, pipefd);
	else
		ft_parent(pipefd, pid);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
}
