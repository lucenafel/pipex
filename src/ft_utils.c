/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:23:36 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/18 06:23:37 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1)[i] - (unsigned char)(s2)[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	ptr = malloc(s_len);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, s_len);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	max_len;

	s_len = ft_strlen(s);
	if (start < s_len)
		max_len = s_len - start;
	else
		max_len = 0;
	if (max_len > len)
		max_len = len;
	ptr = (char *)malloc(max_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, max_len + 1);
	return (ptr);
}
