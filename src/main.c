/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:01:41 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/30 01:10:53 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int pid;
	int fd[2];
	char buf[5];
	char *pin;

	printf("%d\n", X_OK);
	printf("%d\n", W_OK);
	printf("%d\n", R_OK);

	if (!access("/usr/bin/", 1))
		printf("OK\n");
	else
		printf("FAIL\n");

	if (pipe(fd) == -1)
	{
		perror("PIPE ERROR");
		exit(EXIT_FAILURE);
	}
	pid = fork();


	if (pid == 0)
	{
		pin = "4123\0";
		close(fd[0]);
		write(fd[1], pin, 5);
		printf("Generation PID PIN\n");
	}
	if (pid > 0)
	{
		wait(NULL);
		close(fd[1]);
		read(fd[0], buf, 5);
		close(fd[0]);
		printf("PIN ID: %s\n", buf);
	}
	return (EXIT_SUCCESS);
	
}
