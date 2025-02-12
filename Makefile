NAME = so_long
NAME_BONUS = so_long_bonus

SRC = ./src/map_check.c       \
      ./src/so_long.c         \
	  ./src/path_check.c      \
	  ./src/copy_map.c        \
	  ./src/matrix_check.c    \
	  ./src/mlx_game.c        \
	  ./src/mlx_images.c      \
	  ./src/mlx_window.c      \
	  ./src/mlx_moves.c       \
	  ./src/mlx_moves_valid.c \
	  ./src/main.c


SRC_BONUS = ./src_bonus/map_check_bonus.c       \
			./src_bonus/so_long_bonus.c         \
			./src_bonus/path_check_bonus.c      \
			./src_bonus/copy_map_bonus.c        \
			./src_bonus/matrix_check_bonus.c    \
			./src_bonus/mlx_game_bonus.c        \
			./src_bonus/mlx_images_bonus.c      \
			./src_bonus/mlx_window_bonus.c      \
			./src_bonus/mlx_window2_bonus.c     \
			./src_bonus/mlx_moves_bonus.c       \
			./src_bonus/mlx_moves2_bonus.c      \
			./src_bonus/mlx_moves_valid_bonus.c \
			./src_bonus/mlx_animation_bonus.c   \
			./src_bonus/main_bonus.c

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBMLX = ./MLX42
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)/libft.a

HEADERS	= -I ./include/so_long.h -I ./include/so_long_bonus.h -I $(LIBMLX)/include -I $(LIBFT_PATH)/include

LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

bonus: libmlx libft $(NAME_BONUS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

%.o: %.c
	@$(CC) -g3 $(FLAGS) -o $@ -c $< $(HEADERS) 
#excluir -g3 depois

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -g3 $(OBJ) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)
	@echo "Compilation complete!"
#excluir -g3 depois

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	@$(CC) -g3 $(OBJ_BONUS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME_BONUS)
	@echo "Compilation complete with bonus!"
#excluir -g3 depois

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT_PATH)
	@echo "Cleaning completed!"

re: fclean all

.PHONY: all clean fclean re libmlx


#$(NAME): $(OBJ)
#	@cc  $(OBJ)  -Wall -Wextra -Werror  -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

# $(OBJ): $(SRC)
# 	@gcc -Wall -Wextra -Werror -c $(SRC)


#$(CC) $(FLAGS) -I/usr/include -lmlx_linux -03 -c $< -o $@

#bonus: $(OBJ_BONUS)
#	@cc	$(OBJ_BONUS) $(FLAGS) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

#MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib - Imlx_linux -lXext -lX11
#SRC_BONUS = so_long_bonus/images_bonus.c so_long_bonus/so_long_utils_bonus.c so_long_bonus/check_map_bonus.c so_long_bonus/check_path_bonus.c so_long_bonus/ft_check_and_disply_bonus.c so_long_bonus/ft_display_bonus.c so_long_bonus/so_long_bonus.c so_long_bonus/all_move_and_animation_bonus.c so_long_bonus/utils_functions/check_map_2_bonus.c so_long_bonus/utils_functions/check_path_2_bonus.c so_long_bonus/utils_functions/ft_display_bonus_2.c so_long_bonus/utils_functions/ft_check_and_display_2_bonus.c so_long_bonus/utils_functions/ft_check_and_disply_3_bonus.c so_long_bonus/utils_functions/ft_itoa_bonus.c so_long_bonus/utils_functions/get_next_line_bonus.c so_long_bonus/utils_functions/get_next_line_utils_bonus.c so_long_bonus/utils_functions/all_move_and_animation_2_bonus.c ft_printf/ft_printf.c ft_printf/ft_putadres.c ft_printf/ft_putchar.c ft_printf/ft_putnbr_base.c ft_printf/ft_putnbr_uns.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c
#OBJ_BONUS = $(SRC_BONUS:.c=.o)