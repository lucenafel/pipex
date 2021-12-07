/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:53:38 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/07 02:16:23 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> // remove

int	main(int argc, char *argv[], char *envp[])
{
	t_vars vars;

	vars.doc = 0;
	if (!ft_strncmp(argv[1], "here_doc", 8))
		vars.doc = 1;
	if (argc >= 5)
	{
		ft_init_vars(&vars, argc, argv, envp);
		while (vars.idx < argc - 1)
		{
			if (!vars.doc)
			{
				ft_call_args(&vars);
				ft_fork(&vars);
				ft_free(vars.cmd_args);
			}
			else
				ft_exec_doc(&vars);
			vars.idx++;
		}
	}
	else
		printf("Wrong num of parameters\n"); // error handling function ?
	return (0);
}