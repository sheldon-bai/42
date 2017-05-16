# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/24 11:32:42 by xbai              #+#    #+#              #
#    Updated: 2017/03/24 11:32:47 by xbai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# - - - - - - - - - - - - - - - - - - - - - - - - - - 
# COLORES
# - - - - - - - - - - - - - - - - - - - - - - - - - - 
	RESET=\033[0m
	GREEN=\033[32m

# - - - - - - - - - - - - - - - - - - - - - - - - - - 
# VARIABLES
# - - - - - - - - - - - - - - - - - - - - - - - - - - 

.PHONY: all clean fclean re build lib libclean

NAME = fillit

FILE	+= main.c
FILE	+= reader.c
FILE	+= check_neighbor.c
FILE	+= solver.c
FILE	+= solvemap.c

SDIR = srcs/
ODIR = objs/
LDIR = lib/libft/
SRCS = $(addprefix $(SDIR),$(FILE))
OBJS = $(addprefix $(ODIR),$(FILE:.c=.o))

CFLAGS = -Wall -Wextra -Werror -I includes -g

all: $(NAME)

$(NAME): build $(OBJS)
	@echo "\n[${GREEN}$(NAME) done${RESET}.]"
	@make -C $(LDIR)
	gcc $(CFLAGS) $(OBJS) -o $(NAME) -L $(LDIR) -lft

build:
	mkdir -p $(ODIR)

$(ODIR)%.o: $(SDIR)%.c
	gcc $(CFLAGS) -o $@ -c $<
	@echo -n .
lib:
	make -C $(LDIR) re

libclean:
	make -C $(LDIR) fclean

clean:
	rm -rf $(ODIR)

fclean: clean libclean
	rm -rf $(NAME)

re: fclean all
