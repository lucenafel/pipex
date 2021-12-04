/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:41:55 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/02 23:28:15 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> // remover

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	if (argc == 5)
	{
		vars.doc = 0;
		ft_init_vars(&vars, argc, argv, envp);
		while (vars.idx < argc - 1)
		{
			ft_call_args(&vars);
			ft_fork(&vars);
			ft_free(vars.cmd_args);
			vars.idx++;
		}
	}
	else
		printf("Wrong num of parameters\n"); // error handling function ?
	return (0);
}