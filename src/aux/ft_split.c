/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:00:53 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/02 20:08:09 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	counts(char const *s, char c)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] != c && s[i])
			i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		start;
	int		end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	r = (char **)malloc((counts(s, c) + 1) * sizeof(char *));
	if (!s || !r)
		return (NULL);
	while (i < counts(s, c))
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end])
			end++;
		r[i] = ft_substr(s + start, 0, end - start);
		i++;
	}
	r[i] = 0;
	return (r);
}
