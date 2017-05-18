# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 11:48:48 by sflinois          #+#    #+#              #
#    Updated: 2017/05/15 16:47:45 by sflinois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CCRED =	"\033[0;31m"
CCYELLOW = "\033[0;33m"
CCGREEN = "\033[0;32m"
CCEND = "\033[0m"

SRC_PATH = srcs
SRC_NAME = ft_btree_create_node.c ft_btree_apply_prefix.c \
		ft_btree_apply_infix.c ft_btree_apply_suffix.c \
		ft_atoi.c ft_base2base.c ft_base2dec.c ft_pow.c \
		ft_isalpha.c ft_isalnum.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_isneg.c \
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
		ft_lstiter.c ft_lstmap.c ft_lstnew.c \
		ft_lstdelone_cmp.c ft_bzero.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memdel.c ft_memmove.c ft_memset.c \
		ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
		ft_putstr.c ft_putstr_fd.c ft_strnochr.c \
		ft_itoa.c ft_strcat.c ft_strchr.c ft_strrev.c \
		ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strndup.c \
		ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c \
		ft_strncmp.c ft_strncpy.c ft_strnequ.c \
		ft_strnew.c ft_strnstr.c ft_strrchr.c \
		ft_strsplit.c ft_strstr.c ft_strsub.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c \
		ft_itoa_base.c ft_digit_to_char.c \
		ft_imttoa.c ft_imttoa_base.c get_next_line.c \
		ft_retwchar.c ft_retwstr.c ft_retnwstr.c \
		
S_PRINTF_PATH = $(SRC_PATH)/printf
S_PRINTF_NAME = ft_printf.c fct_printf_type_args.c fct_expr.c \
		fct_printf_min_width.c fct_printf_precision.c \
		fct_printf_flags.c fct_printf_spflags.c fct_printf_cs_args.c \
		fct_printf_length.c fct_printf_parsing.c \

OBJ_PATH = objs
CPPFLAGS = -Iincludes

LDFLAGS = -Llibft
LDLIBS = -lft

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)
O_PRINTF_NAME = $(S_PRINTF_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
S_PRINTF = $(addprefix $(S_PRINTF_PATH)/,$(S_PRINTF_NAME))
O_PRINTF = $(addprefix $(OBJ_PATH)/,$(O_PRINTF_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(O_PRINTF)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo $(CCGREEN) Libft OK $(CCEND)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o : $(S_PRINTF_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@echo $(CCRED)
	@rm -fv $(OBJ)
	@rm -fv $(O_PRINTF)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rmdir $(O_PRINTF_PATH) 2> /dev/null || true
	@echo $(CCEND)

fclean: clean
	@echo $(CCRED)
	@rm -fv $(NAME)
	@echo $(CCEND)

re: fclean all

norme:
	norminette $(S_PRINTF)
	norminette $(SRC)
	norminette $(INC_PATH)*.h
