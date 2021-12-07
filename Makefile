# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 01:39:35 by lfelipe-          #+#    #+#              #
#    Updated: 2021/12/07 01:51:13 by lfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS	= pipex_bonus.c \
		  ft_get_path.c \
		  ft_check_cmd.c \
		  ft_fork.c \
		  ft_inits.c \
		  ft_free.c \
		  ft_here_doc.c \
		  $(AUD)

AUX		= ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_strjoin.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strncmp.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_putstr_fd.c \
		  get_next_line.c

SDIR	= ./src/

ODIR	= ./obj/

ADIR	= aux/

AUD	= $(addprefix $(ADIR), $(AUX))

OBJS	= $(addprefix $(ODIR), $(SRCS:.c=.o))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

INCLUDE = -I ./include

RM		= rm -rf

$(ODIR)%.o:	$(SDIR)%.c
			@mkdir -p $(ODIR)
			@mkdir -p $(ODIR)/$(ADIR)
			$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(INCLUDE) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(ODIR)

fclean:		clean
			$(RM) $(NAME) $(OBJS) $(ODIR)

re:			fclean all

.PHONY= all clean fclean re
