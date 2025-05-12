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

SRC			= $(SRC_DIR)/main.c $(SRC_DIR)/draw.c $(SRC_DIR)/end_window.c $(SRC_DIR)/free.c $(SRC_DIR)/handle_enemy.c \
				$(SRC_DIR)/handle_input.c $(SRC_DIR)/handle_player.c $(SRC_DIR)/init_game.c $(SRC_DIR)/init_map.c \
				$(SRC_DIR)/is_valid.c $(SRC_DIR)/load_enemy.c $(SRC_DIR)/map_validation.c $(SRC_DIR)/moves.c \
				$(SRC_DIR)/run_game.c $(SRC_DIR)/utilities.c $(SRC_DIR)/valid_path.c

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

.PHONY:	all fclean clean re lib build minilibx