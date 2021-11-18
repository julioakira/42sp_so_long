# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 05:29:35 by jakira-p          #+#    #+#              #
#    Updated: 2021/09/28 03:06:35 by jakira-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

AR_RCS = ar -rcs

DIST_DIR = dist

RM_F = rm -f

SRC = ft_atoi.c \
				ft_calloc.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_memcpy.c \
				ft_memcmp.c \
				ft_memmove.c \
				ft_strchr.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strnstr.c \
				ft_tolower.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_memchr.c \
				ft_memset.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_toupper.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_litoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

BONUS_SRC = ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstclear.c \
				ft_lstdelone.c \
		 		ft_lstiter.c \
		 		ft_lstmap.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR_RCS) $(NAME) $(OBJS)

clean:
	$(RM_F) ${OBJS} $(BONUS_OBJS)

fclean: clean
	$(RM_F) ${NAME}

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR_RCS) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY = clean fclean all re bonus
