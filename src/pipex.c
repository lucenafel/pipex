/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:41:55 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/01 20:04:55 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> // remover

int main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	if (argc == 5)
	{	vars.infile = open(argv[1], O_RDONLY);
		vars.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
		vars.argc = argc;
		vars.argv = argv;
		vars.envp = envp;
		vars.idx = 2;
		while (vars.idx < argc - 1)
		{
			call_args(&vars);
			ft_fork(&vars);
			free(vars.cmd_path);
			ft_free(vars.cmd_args);
			vars.idx++;
		}
	}
	else
	{
		printf("Wrong num of parameters");
		exit(0);
	}
}