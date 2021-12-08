/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 04:03:31 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/08 17:56:27 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_args_count(char *args, char c)
{
	int	i;
	int	not_cnt;
	int	args_count;

	i = 0;
	not_cnt = 0;
	args_count = 0;
	while (args[i])
	{
		if (!not_cnt && args[i] != c && (i == 0 || args[i - 1] == c))
			args_count++;
		if (args[i] == '\'')
			not_cnt = !not_cnt;
		i++;
	}
	return (args_count);
}

static char	**ft_get_args_address(char *args, char c, int args_count)
{
	int		i;
	int		j;
	int		not_cnt;
	char	**addresses;

	i = 0;
	j = 0;
	not_cnt = 0;
	addresses = (char **)malloc((args_count + 1) * sizeof(char *));
	while (args[i])
	{
		if (!not_cnt && args[i] != c && (i == 0 || args[i - 1] == c))
		{
			addresses[j] = &args[i];
			if (i != 0)
				args[i - 1] = '\0';
			j++;
		}
		if (args[i] == '\'')
			not_cnt = !not_cnt;
		i++;
	}
	addresses[j] = 0;
	return (addresses);
}

char	**ft_split_args(char const *args, char splitter)
{
	int		i;
	int		args_count;
	char	*args_copy;
	char	**args_address;
	char	**args_split;

	i = 0;
	args_copy = ft_strdup(args);
	args_count = ft_args_count(args_copy, splitter);
	args_address = ft_get_args_address(args_copy, splitter, args_count);
	args_split = (char **)malloc((args_count + 1) * sizeof(char *));
	while (i < args_count)
	{
		args_split[i] = ft_strtrim(args_address[i], " ");
		i++;
	}
	args_address[i] = 0;
	free(args_copy);
	free(args_address);
	return (args_split);
}
