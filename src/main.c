/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:24:02 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/26 18:29:43 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> // remove

char	*get_cmd(char *arg)
{
	int		count;
	int		i;
	char	*trim;
	char	*cmd;

	i = 0;
	count = 0;
	trim = ft_strtrim(arg, " ");
	while (trim[count] != ' ')
		count++;
	cmd = (char *)malloc(count + 1);
	while (i < count)
	{
		cmd[i] = trim[i];
		i++;
	}
	cmd[i] = '\0';
	free(trim);
	return (cmd);
}

char	**get_args(char *rawarg)
{
	char	**args;
	char	*trim;
	int		i;

	i = 0;
	trim = ft_strtrim(rawarg, " ");
	args = ft_split(trim, ' ');
	free(trim);
	return (args);
}

void	call_f(t_vars *vars)
{
	char	*cmd;
	char	**path;

	vars->cmd_args = get_args(vars->argv[vars->idx]);
	cmd = get_cmd(vars->argv[vars->idx]);
	path = ft_get_path(vars->envp);
	vars->cmd_path = ft_check_cmd(path, cmd);
	free(cmd);
	free(path);
}

void	ft_child(t_vars *vars, int *pipefd)
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
	call_f(vars);
	if (!vars->cmd_path)
	{
		perror("ERROR");
		exit(1);
	}
	execve(vars->cmd_path, vars->cmd_args, vars->envp);
	free(vars->cmd_path);
	free(vars->cmd_args);
}

void	ft_parent(int *pipefd, int pid)
{
	int	status;

	close(pipefd[1]);
	waitpid(pid, &status, 0);
}

void	ft_fork(t_vars *vars)
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		printf("PIPE ERROR\n");
	pid = fork();
	if (pid == 0)
		ft_child(vars, pipefd);
	else
		ft_parent(pipefd, pid);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	if (argc >= 5)
	{
		vars.infile = open(argv[1], O_RDONLY, 0666);
		vars.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
		vars.argc = argc;
		vars.argv = argv;
		vars.envp = envp;
		vars.idx = 2;
		while (vars.idx < argc - 1)
		{
			ft_fork(&vars);
			vars.idx++;
		}
	}
	else
	{
		printf("Wrong num of parameters");
		exit(1);
	}
}
