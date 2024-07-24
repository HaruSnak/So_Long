NAME = so_long
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
LIBFTDIR = includes/libft/
OBJ_DIR = obj/
SRC_DIR = srcs/
MLX_DIR = minilibx-linux/
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

SRC_1 = srcs/so_long.c \

SRC_2 =	srcs/errors/errors.c \
		srcs/game/settings.c \
		srcs/map/draw.c \
		srcs/map/path_include.c \
		srcs/parsing/parsing.c \
		srcs/parsing/parsing_utils.c \
		srcs/parsing/path_bfs.c \
		srcs/parsing/path_valid.c \
		srcs/player/player_animation.c \
		srcs/player/player_collision.c \
		srcs/player/player_gravity.c \
		srcs/player/player.c \
		srcs/ui/hud.c \
		srcs/ui/main_menu.c \

BONUS = srcs/bonus/monster/monster.c \
		srcs/bonus/player_bonus/player_coin.c \
			
OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}
BONUS_OBJ =${BONUS:.c=.o}

INCLUDE = -L $(LIBFTDIR) -lft

INCLUDES = -I/usr/include -Imlx

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@

${NAME}: ${OBJ_1} ${OBJ_2} ${BONUS_OBJ}
	@echo "Compiling libft..."
	@make -C $(LIBFTDIR)
	@echo "Compiling $(NAME)..."
	@${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} -o ${NAME} ${INCLUDE} ${INCLUDES} ${MLX_FLAGS}
	@echo "$(NAME) compiled successfully."

$(MLX_LIB):
	@echo "Compiling mlx..."
	@make -C $(MLX_DIR)
	@echo "mlx compiled successfully."

all: $(MLX_LIB) ${NAME}

clean:
	@echo "Cleaning object files..."
	@${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@echo "Object files cleaned."

fclean: clean
	@echo "Cleaning executable..."
	@${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@echo "Executable cleaned."

re: clean all

.PHONY: all clean fclean re