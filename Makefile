# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manumart <manumart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 15:38:55 by manumart          #+#    #+#              #
#    Updated: 2023/10/11 20:10:17 by manumart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRCS_NAME =	main.c \
			utils.c
			

CC = cc
CFLAGS = -Wall -Werror -Wextra  -g #-fsanitize=thread

RM = rm -rf

SRC_PATH = ./

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c 
	mkdir -p objects
	$(CC) $(CFLAGS)	-c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re