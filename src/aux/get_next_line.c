/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:03:07 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/02 20:46:23 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_split_line(char **save, int ret);
static void	ft_strdel(char **str);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*tmp;
	int			ret;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!save)
			save = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(save, buffer);
			free(save);
			save = tmp;
		}
		if (ft_strchr(save, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_split_line(&save, ret));
}

static char	*ft_split_line(char **save, int ret)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	if (ret < 0 || BUFFER_SIZE < 1 || !*save || *save[i] == '\0')
		return (0);
	while (*(*save + i) != '\n' && *(*save + i))
		i++;
	if (ft_strchr(*save, '\n'))
	{
		line = ft_substr(*save, 0, i + 1);
		tmp = ft_strdup(*save + i + 1);
		ft_strdel(save);
		*save = tmp;
		return (line);
	}
	line = ft_substr(*save, 0, i);
	ft_strdel(save);
	return (line);
}

static void	ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = 0;
	}
}
