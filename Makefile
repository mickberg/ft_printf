# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 17:10:30 by mberglun          #+#    #+#              #
#    Updated: 2020/01/17 15:32:19 by mikaelber        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := ft_printf

# Directories, library
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/
LIB_DIR := ./libft/
INC_DIR := ./includes/ 

# libft archive file name
LIB := ft

# Files, library
SRC_FILES := \
	main.c \
	ft_printf.c \
	parse/parse.c \
	parse/parse_flags.c \
	parse/parse_width.c \
	parse/parse_precision.c \
	parse/parse_length.c \
	parse/parse_specifier.c \
	parse/parse_number.c

SRCS := $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))
OBJS := $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -I ${INC_DIR} -I ${LIB_DIR} -L${LIB_DIR} -l${LIB}

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -g -o $@ -I ${INC_DIR} -I ${LIB_DIR}

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
