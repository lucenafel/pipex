/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:39:11 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/14 22:55:28 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_vars(t_vars *vars, int argc, char **argv, char **envp)
{
	vars->infile = -1;
	if (!vars->doc)
		vars->infile = open(argv[1], O_RDONLY);
	if (!vars->doc)
		vars->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	else
		vars->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0666);
	if (vars->infile < 0 && !vars->doc)
	{
		ft_error(argv[1], 2);
		exit(1);
	}
	vars->idx = 2;
	vars->argc = argc;
	vars->argv = argv;
	vars->envp = envp;
}

static void	ft_exit(t_vars *vars, char **path)
{
	ft_error(vars->cmd_args[0], 1);
	ft_free(vars->cmd_args);
	ft_free(path);
	exit(127);
}

void	ft_init_args(t_vars *vars)
{
	char	*cmd;
	char	**path;

	vars->cmd_args = ft_split_args(vars->argv[vars->idx], ' ');
	path = ft_get_path(vars->envp);
	if (!ft_check_slash(vars->cmd_args[0]))
	{
		cmd = ft_check_cmd(path, vars->cmd_args[0]);
		if (cmd)
		{
			free(vars->cmd_args[0]);
			vars->cmd_args[0] = cmd;
		}
		else
			ft_exit(vars, path);
	}
	else if (access(vars->cmd_args[0], X_OK < 0))
		ft_exit(vars, path);
	ft_free(path);
}
