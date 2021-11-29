# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 16:51:50 by jakira-p          #+#    #+#              #
#    Updated: 2021/11/29 16:59:55 by jakira-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/

DIST_DIR = dist/

SRC_FILES = $(SRC_DIR)test.c \

OBJS = $(addprefix $(DIST_DIR),$(notdir $(SRC_FILES:.c=.o)))

LINKER_FLAGS = -Xlinker --verbose

INCLUDES = -I ./includes -I ./libft -I ./mlx

LIBS = -L ./libft -lft -L ./mlx -lmlx


MLX_FLAGS = -lXext -lX11

all: $(NAME)

val: $(NAME)
	valgrind \
	--leak-check=full --tool=memcheck \
	--show-reachable=yes \
	--track-fds=yes \
	--errors-for-leak-kinds=all \
	--show-leak-kinds=all ./${NAME}

$(NAME): $(OBJS) libft mlx
	$(CC) $(CFLAGS) $< $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $@

$(DIST_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(DIST_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(DIST_DIR)$(notdir $@)

clean:
	rm -rf $(DIST_DIR)
	@echo "[ ] Cleaning up libft..."
	@$(MAKE) -s -C ./libft clean
	@echo "[X] libft cleaned successfully"
	@echo "[ ] Cleaning up MiniLibX..."
	$(MAKE) -C ./mlx clean
	@echo "[X] MiniLibX cleaned successfully"


fclean: clean
	rm -rf $(NAME)
	@echo "[ ] Cleaning up libft..."
	@$(MAKE) -C ./libft fclean
	@echo "[X] libft cleaned successfully"
	@echo "[ ] Cleaning up MiniLibX..."
	$(MAKE) -C ./mlx clean
	@echo "[X] MiniLibX cleaned successfully"

re:
	fclean all

libft:
	@echo "[ ] Compiling libft..."
	@$(MAKE) -s -C ./libft
	@echo "[X] libft compiled successfully"

mlx:
	@echo "[ ] Compiling MiniLibX..."
	@$(MAKE) -s -C ./mlx
	@echo "[X] MiniLibX compiled successfully"

.PHONY: all clean fclean re mlx libft
