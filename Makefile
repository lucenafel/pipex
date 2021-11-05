# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 01:39:35 by lfelipe-          #+#    #+#              #
#    Updated: 2021/11/05 22:18:55 by lfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS	= main.c \
		  ft_get_path.c \
		  ft_utils.c \
		  ft_utils2.c \
		  ft_check_cmd.c

SDIR	= ./src/

ODIR	= ./obj/

OBJS	= $(addprefix $(ODIR), $(SRCS:.c=.o))

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

$(ODIR)%.o:	$(SDIR)%.c
			@mkdir -p $(ODIR)
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(ODIR)

fclean:		clean
			$(RM) $(NAME) $(OBJS) $(ODIR)

re:			fclean all

.PHONY= all clean fclean re
