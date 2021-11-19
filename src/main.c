/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:01:41 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/18 22:18:45 by lfelipe-         ###   ########.fr       */
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
	char	*tmp;
	int		i;

	i = 0;
	trim = ft_strtrim(rawarg, " ");
	while (trim[i] != ' ')
		i++;
	tmp = trim;
	trim = ft_strjoin("./pipex ", trim + i);
	free(tmp);
	args = ft_split(trim, ' ');
	return (args);
}

int main(int argc, char *argv[])
{
	char *test1;
	char **test2;

	if (argc > 1000)
		printf("%d\n", argc);
	test1 = get_cmd(argv[1]);
	test2 = get_args(argv[1]);
	printf("cmd: %s\n", test1);
	while (*test2)
	{
		printf("%s\n", *test2);
		test2++;
	}
}
