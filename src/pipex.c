/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:41:55 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/08 17:58:58 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	if (argc == 5)
	{
		ft_init_vars(&vars, argc, argv, envp);
		while (vars.idx < argc - 1)
		{
			ft_fork(&vars);
			vars.idx++;
		}
	}
	else
		ft_putendl_fd("wrong num of parameters", 1);
	return (0);
}
