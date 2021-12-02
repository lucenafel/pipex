/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:53:38 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/02 19:47:24 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_vars vars;

	vars.doc = 0;
	if (argc > 5)
	{
		ft_init_vars(&vars, argc, argv, envp);
		while (vars.idx < argc - 1)
		{
			ft_fork(&vars);
			ft_free(vars.cmd_args);
			vars.idx++;
		}
	}
	else
		printtf("Wrong num of parameters\n"); // error handling function ?
	return (0);
}