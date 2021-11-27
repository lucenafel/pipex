/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:24:10 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/11/25 20:02:18 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_vars
{
	int		infile;
	int		outfile;
	int		argc;
	int		idx;
	char	**argv;
	char	**cmd_args;
	char	*cmd_path;
	char	**envp;
}	t_vars;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	**ft_get_path(char **envp);
char	*ft_check_cmd(char **path, char *cmd);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **str);

#endif
