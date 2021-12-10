# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfelipe- <lfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 01:39:35 by lfelipe-          #+#    #+#              #
#    Updated: 2021/12/10 05:52:12 by lfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

BNAME	= pipex_bonus

MPIPE	= pipex.c

BPIPE	= pipex_bonus.c

SRCS	= ft_get_path.c \
		  ft_check_cmd.c \
		  ft_fork.c \
		  ft_inits.c \
		  ft_free.c \
		  ft_here_doc.c \
		  ft_splitter.c \
		  ft_error.c \
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
		  ft_putendl_fd.c \
		  get_next_line.c

SDIR	= ./src/

ODIR	= ./obj/

ADIR	= aux/

AUD		= $(addprefix $(ADIR), $(AUX))

OBJS	= $(addprefix $(ODIR), $(SRCS:.c=.o))

MOBJ	= $(addprefix $(ODIR), $(MPIPE:.c=.o))

BOBJ	= $(addprefix $(ODIR), $(BPIPE:.c=.o))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

INCLUDE = -I ./include

RM		= rm -rf

$(ODIR)%.o:	$(SDIR)%.c
			@mkdir -p $(ODIR)
			@mkdir -p $(ODIR)/$(ADIR)
			$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(MOBJ)
			$(CC) $(INCLUDE) $(CFLAGS) $(MOBJ) $(OBJS) -o $(NAME)

$(BNAME):	$(OBJS) $(BOBJ)
			$(CC) $(INCLUDE) $(CFLAGS) $(BOBJ) $(OBJS) -o $(BNAME)

bonus:		$(BNAME)

clean:
			$(RM) $(OBJS) $(ODIR)

fclean:		clean
			$(RM) $(NAME) $(BNAME) $(OBJS) $(ODIR)

re:			fclean all

.PHONY= all clean fclean re
