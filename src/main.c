/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:01:41 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/10/30 22:33:58 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
	int pid;
	int fd[2];
	char buf[5];
	char *pin;

	char *args[2];

	args[0] = "/usr/bin/ls";
	args[1] = "-la";
	int i = 0;
	int fd2 = open("test.txt", O_RDWR | O_CREAT, 0666);
	if (i == 1000000)
	{
		printf("%d\n", argc);
		printf("%s\n", argv[0]);
	}


	/* printf("%d\n", X_OK); */
	/* printf("%d\n", W_OK); */
	/* printf("%d\n", R_OK); */

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
		execve(args[0], argv, envp);
	}
	if (pid > 0)
	{
		wait(NULL);
		close(fd[1]);
		read(fd[0], buf, 5);
		close(fd[0]);
		printf("PIN ID: %s\n", buf);
		dup2(fd2, 1);
		printf("TESTING DUP FUNCTION\n");
		printf("NEW LINE \nNEW LINE\n");
		printf("REESCRITA\n");
		printf("REESCRITA ");
		printf("nao printa sem o new line \n");
		printf("test");
		printf("\n");

		execve(args[0], argv, envp);
	}
	return (EXIT_SUCCESS);
}
