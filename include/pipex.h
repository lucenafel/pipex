/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:24:10 by lfelipe-          #+#    #+#             */
/*   Updated: 2021/12/08 17:55:02 by lfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

# define BUFFER_SIZE 1

typedef struct s_vars
{
	int		infile;
	int		outfile;
	int		argc;
	int		idx;
	int		doc;
	char	**argv;
	char	**cmd_args;
	char	**envp;
}	t_vars;

int		ft_check_slash(char *cmd);
char	**ft_get_path(char **envp);
char	*ft_check_cmd(char **path, char *cmd);
void	ft_free(char **str);
void	ft_fork(t_vars *vars);
void	here_doc(char *deli, int *fd);
void	ft_exec_doc(t_vars *vars);
void	ft_init_args(t_vars *vars);
void	ft_init_vars(t_vars *vars, int argc, char **argv, char **envp);
void	ft_error(char *str, int code);
char	**ft_split_args(char const *args, char splitter);

/* aux functions */

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
