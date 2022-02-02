# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 16:51:50 by jakira-p          #+#    #+#              #
#    Updated: 2022/02/02 02:29:24 by jakira-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/

UTILS_DIR = utils/

DIST_DIR = dist/

SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)new_game.c \
			$(SRC_DIR)key_handlers.c \
			$(SRC_DIR)handle_close.c \
			$(SRC_DIR)parse_map.c \
			$(SRC_DIR)load_sprites.c \
			$(SRC_DIR)load_map_sprites.c \
			$(UTILS_DIR)pointer_utils.c \
			$(UTILS_DIR)get_next_line.c \
			$(UTILS_DIR)map_utils.c \
			$(UTILS_DIR)struct_utils.c \
			$(UTILS_DIR)error_utils.c \
			$(UTILS_DIR)line_parsing_utils.c \
			$(UTILS_DIR)image_utils.c \

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

norm: $(NAME)
	norminette -R CheckForbiddenSourceHeader ./includes
	norminette -R CheckForbiddenSourceHeader ./libft
	norminette -R CheckForbiddenSourceHeader ./src
	norminette -R CheckForbiddenSourceHeader ./utils

$(NAME): $(OBJS) libft mlx
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $@

$(DIST_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(DIST_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(DIST_DIR)$(notdir $@)

$(DIST_DIR)%.o: $(UTILS_DIR)%.c
	@mkdir -p $(DIST_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(DIST_DIR)$(notdir $@)

clean:
	rm -rf $(DIST_DIR)
	@echo "[ ] Cleaning up libft..."
	@$(MAKE) -s -C ./libft clean
	@echo "[X] libft cleaned successfully"
	@echo "[ ] Cleaning up MiniLibX..."
	$(MAKE) -s -C ./mlx clean
	@echo "[X] MiniLibX cleaned successfully"


fclean: clean
	rm -rf $(NAME)
	@echo "[ ] Cleaning up libft..."
	@$(MAKE) -s -C ./libft fclean
	@echo "[X] libft cleaned successfully"
	@echo "[ ] Cleaning up MiniLibX..."
	$(MAKE) -s -C ./mlx clean
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

.PHONY: all clean fclean re mlx libft val
