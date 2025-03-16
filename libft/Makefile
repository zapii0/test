# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 11:30:58 by mzapora           #+#    #+#              #
#    Updated: 2025/01/28 14:59:21 by mzapora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

SRC = ft_bzero.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_strlcat.c ft_strlcpy.c \
ft_toupper.c ft_tolower.c ft_strrchr.c ft_strncmp.c ft_strchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_atoi.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_putchar_p.c ft_puthex_p.c \
ft_putuint_p.c ft_putdigit_p.c ft_putstr_p.c \

BONUS = ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS =	${SRC:.c=.o}

OBJSB = ${BONUS:.c=.o}

NAME = libft.a

AR = ar rcs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) 

bonus/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

bonus: $(OBJS) $(OBJSB)
	$(AR) $(NAME) $(OBJS) $(OBJSB)

all:	$(NAME)

clean:
	rm -f	$(OBJS) $(OBJSB)

fclean: clean
	rm -f	$(NAME)

re: fclean	all

.PHONY: all clean fclean re bonus
