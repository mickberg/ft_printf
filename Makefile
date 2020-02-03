# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 17:10:30 by mberglun          #+#    #+#              #
#    Updated: 2020/02/03 04:18:27 by mikaelber        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a

# Directories, library
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/
LIB_DIR := ./libft/
INC_DIR := ./includes/

# libft archive file name
LIB := ft
FTLIB := $(LIB_DIR)libft.a

# Files, library
SRC_FILES := \
	ft_printf.c \
	parse/parse.c \
	parse/parse_flags.c \
	parse/parse_width.c \
	parse/parse_precision.c \
	parse/parse_length.c \
	parse/parse_specifier.c \
	parse/parse_number.c \
	formatters/format_router.c \
	formatters/format_int.c \
	formatters/format_uint.c \
	formatters/format_hex.c \
	formatters/format_ptr.c \
	formatters/format_octal.c \
	formatters/format_float.c \
	formatters/format_char.c \
	formatters/format_str.c \
	formatters/format_perc.c \
	formatters/format_width.c \
	utils/number_arguments.c \
	utils/number_utils.c \
	utils/base_conversion.c

SRCS := $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))
OBJS := $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(FTLIB):
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(FTLIB) $(INC_DIR)ft_printf.h $(INC_DIR)ft_printf_types.h
	@cp $(FTLIB) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

test: $(NAME) tests/main.c
	$(CC) $(CFLAGS) -o printf_test tests/main.c -I$(LIB_DIR) -I $(INC_DIR) -L./ -lftprintf

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -g -o $@ -I ${INC_DIR} -I ${LIB_DIR}

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
