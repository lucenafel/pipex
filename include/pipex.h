/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:20:09 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/04 16:49:34 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_get_path(char **envp);
char	*ft_strdup(const char *s);

#endif
