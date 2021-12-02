/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:39:11 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/02 17:23:29 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	ft_init_vars(t_vars *vars, int argc, char **argv, char **envp)
{
	vars->infile = open(argv[1], O_RDONLY);
	vars->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (vars->infile < 0)
	{
		printf("no such file or directory: %s\n", argv[1]);
		exit(-1);
	}
	vars->argc = argc;
	vars->argv = argv;
	vars->envp = envp;
	vars->idx = 2;
}

void	ft_call_args(t_vars *vars)
{
	char	*cmd;
	char	**path;

	vars->cmd_args = ft_get_args(vars->argv[vars->idx]);
	/* IMPORTANT check for full paths before doing the access check */
	cmd = ft_get_cmd(vars->argv[vars->idx]); //
	path = ft_get_path(vars->envp);
	vars->cmd_path = ft_check_cmd(path, cmd);
	free(vars->cmd_args[0]);
	vars->cmd_args[0] = vars->cmd_path;
	free(cmd);
	ft_free(path);
}