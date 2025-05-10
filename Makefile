NAME		= so_long

LIBFT_DIR	= libs/libft

LIBFT		= -L./$(LIBFT_DIR) -lft

MLX_DIR		= libs/minilibx-linux

MLX			= -L./$(MLX_DIR) -lmlx -lm -lX11 -lXext

INCLUDES	= -I./includes -I./$(LIBFT_DIR) -I./$(MLX_DIR)

HEADER		= ./includes/so_long.h

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./src

SRC			= src/main.c src/draw.c src/end_window.c src/free.c src/handle_enemy.c \
				src/handle_input.c src/handle_player.c src/init_game.c src/init_map.c \
				src/is_valid.c src/load_enemy.c src/map_validation.c src/moves.c \
				src/run_game.c src/utilities.c src/valid_path.c

OBJ			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

BUILD_DIR	= ./build

all: build lib minilibx $(NAME)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c Makefile $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a Makefile
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBFT) $(MLX)

lib:
	make -C $(LIBFT_DIR)

minilibx:
	make -C $(MLX_DIR)

build:
	mkdir -p ${BUILD_DIR}

clean:
	rm -rf $(BUILD_DIR)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
	make -C $(LIBFT_DIR) re

.PHONY:	all fclean clean re lib build minilibx