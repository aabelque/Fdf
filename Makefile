# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabelque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 12:34:03 by aabelque          #+#    #+#              #
#    Updated: 2018/04/23 18:32:56 by aabelque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS =-framework OpenGL -framework AppKit

NAME = fdf

CC = gcc

CFLAG = -O3 -Wall -Werror -Wextra -g 

MAKE = make
SRC = srcs/main.c \
	  srcs/parse.c \
	  srcs/error.c \
	  srcs/init_mlx.c \

OBJS = $(SRC:%.c=%.o)
	INCDIR = include/
	INCFILE = fdf.h
	INC = $(addprefix $(INCDIR), $(INCFILE))

LIBPATH = libs/

LFTDIR = libft/
LFTPATH = $(addprefix $(LIBPATH), $(LFTDIR))
LIBFT = libft.a
FTLK = ft

LMLXDIR = minilibx/
LMLXPATH = $(addprefix $(LIBPATH), $(LMLXDIR))
LIBMLX = libmlx.a
MLXLK = mlx

ALLINCS = -I$(LFTPATH) -I$(LMLXPATH) -I$(INCDIR)

all: $(NAME)

$(NAME): $(LFTPATH)$(LIBFT) $(LMLXPATH)$(LIBMLX) $(OBJS) $(INC)
	@$(CC) -O3 -o $(NAME) $(ALLINCS) -L$(LFTPATH) -l$(FTLK) -L$(LMLXPATH) -l$(MLXLK) $(FRAMEWORKS) $(OBJS)
	-@echo "\033[32m Fdf ready.\033[0m"

%.o: %.c $(INC)
	@$(CC) $(CFLAG) -o $@ $(ALLINCS) -c $<

$(LFTPATH)$(LIBFT):
	$(MAKE) -C $(LFTPATH)

$(LMLXPATH)$(LIBMLX):
	$(MAKE) -C $(LMLXPATH)

clean:
	$(MAKE) -C $(LFTPATH) clean
	@rm -rf $(INCDIR)/*.h.gch
	@rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	$(MAKE) -C $(LMLXPATH) clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
