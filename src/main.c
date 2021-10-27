/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:01:41 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/26 22:13:22 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int pid;
	// int fd[2];
	int i = 0;
	char buf[2];

	pid = fork();

	if (pid == 0)
	{
		i = 10;
		printf("%d\n", i);
	}
	else
	{
		printf("%d\n", i);
		printf("%s\n", buf);
	}
	fork();
	printf("TESTE 2\n");
	fork();
	printf("TESTE 3\n");
	
}
