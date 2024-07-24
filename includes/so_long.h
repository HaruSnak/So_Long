/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:33:02 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/23 17:52:33 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WINDOW_TITLE "so_long"
# define WINDOW_WIDTH 2200
# define WINDOW_HEIGHT 1080
# define MAX_QUEUE_SIZE 1000
# define NUM_XPM_FILES 49
// MACOS: 1.5 LINUX: 0.007
# define GRAVITY 0.007
# define COIN_ANIM_DELAY 0.4
# define MONSTER_ANIM_DELAY 0.8
# define COLLISION_OBJ 48
/*	ft_init_img_index	draw.c
0 pour un emplacement vide	index_IMG = 1
1: Wall						index_IMG = 2
C: Item collect				index_IMG = 3
E: Exit						index_IMG = 4
P: Player start				index_IMG = 5
L: Left Grass				index_IMG = 6
R: Right Grass				index_IMG = 7
D: Down Grass				index_IMG = 8
G: Center Grass				index_IMG = 9
7: Left side grass			index_IMG = 10
8: Right side grass			index_IMG = 11
J: Platform					index_IMG = 12
W: Water up					index_IMG = 13
Z: Water down				index_IMG = 14
F: Flag						index_IMG = 15
S: Sign						index_IMG = 16
4: Tree decoration			index_IMG = 17
5: Mushroom ""				index_IMG = 18
6: Snowman					index_IMG = 19
U: Cloud left				index_IMG = 20
I: Cloud center				index_IMG = 21
O: Cloud right				index_IMG = 22
M: Monster					index_IMG = 19
*/
# define IMG_BG "assets/tiles/bg.xpm"
# define IMG_WALL "assets/tiles/wall.xpm"
# define IMG_COIN "assets/tiles/coin.xpm"
# define IMG_COIN_R "assets/tiles/coin_r.xpm"
# define IMG_EXIT "assets/tiles/exit.xpm"
# define IMG_START "assets/tiles/start.xpm"
# define IMG_G_LEFT "assets/tiles/grass_left.xpm"
# define IMG_G_RIGHT "assets/tiles/grass_right.xpm"
# define IMG_G_DOWN "assets/tiles/grass.xpm"
# define IMG_G_CENTER "assets/tiles/grass_center.xpm"
# define IMG_G_L_C "assets/tiles/grass_l_c.xpm"
# define IMG_G_R_C "assets/tiles/grass_r_c.xpm"
# define IMG_PLATFORM "assets/tiles/platform.xpm"
# define IMG_W_UP "assets/tiles/water_up.xpm"
# define IMG_W_DOWN "assets/tiles/water_down.xpm"
# define IMG_FLAG "assets/tiles/flag.xpm"
# define IMG_SIGN "assets/tiles/sign_right.xpm"
# define IMG_TREE "assets/tiles/other_1.xpm"
# define IMG_MUSHROOM "assets/tiles/other_2.xpm"
# define IMG_SNOWMAN "assets/tiles/other_3.xpm"
# define IMG_CLOUD_L "assets/tiles/cloud_left.xpm"
# define IMG_CLOUD_R "assets/tiles/cloud_right.xpm"
# define IMG_CLOUD_C "assets/tiles/cloud_center.xpm"
# define IMG_HEART "assets/heart/heart.xpm"
# define IMG_HEART_EMPTY "assets/heart/heart_empty.xpm"
# define IMG_PLY_BASE "assets/player/ply_base.xpm"
# define IMG_PLY_BASE_R "assets/player/ply_base_r.xpm"
# define IMG_PLY_WALK1 "assets/player/ply_walk1.xpm"
# define IMG_PLY_WALK2 "assets/player/ply_walk2.xpm"
# define IMG_PLY_WALK3 "assets/player/ply_walk3.xpm"
# define IMG_PLY_WALK1_R "assets/player/ply_walk1_r.xpm"
# define IMG_PLY_WALK2_R "assets/player/ply_walk2_r.xpm"
# define IMG_PLY_JUMP "assets/player/ply_jump.xpm"
# define IMG_PLY_JUMP_R "assets/player/ply_jump_r.xpm"
# define IMG_PLY_DPS "assets/player/ply_base_dps.xpm"
# define IMG_MONSTER_B "assets/monsters/monster_b.xpm"
# define IMG_MONSTER_W "assets/monsters/monster_w.xpm"
# define IMG_UI_WALK "assets/ui/walk.xpm"
# define IMG_UI_1_COIN "assets/ui/one_coin.xpm"
# define IMG_UI_2_COIN "assets/ui/two_coin.xpm"
# define IMG_UI_3_COIN "assets/ui/three_coin.xpm"
# define IMG_UI_4_COIN "assets/ui/four_coin.xpm"
# define IMG_UI_5_COIN "assets/ui/five_coin.xpm"
# define IMG_UI_6_COIN "assets/ui/six_coin.xpm"
# define IMG_UI_7_COIN "assets/ui/seven_coin.xpm"
# define IMG_UI_8_COIN "assets/ui/eight_coin.xpm"
# define IMG_UI_9_COIN "assets/ui/nine_coin.xpm"
# define IMG_UI_10_COIN "assets/ui/ten_coin.xpm"
# define IMG_MAIN_MENU "assets/ui/main_menu.xpm"

/*
KEY_LEFT: 97 == "A" key on the keyboard.
KEY_RIGHT: 100 == "D" key on the keyboard.
KEY_UP: 119 == "W" key on the keyboard.
KEY_DOWN: 115 == "S" key on the keyboard.
KEY_ACTION: 101 == "E" key on the keyboard.
KEY_ARROW_LEFT: 65361 == left arrow key.
KEY_ARROW_RIGHT: 65363 == right arrow key.
KEY_ARROW_UP: 65362 == up arrow key.
KEY_ARROW_DOWN: 65364 == down arrow key.
KEY_SPACE_BAR: 32 == space bar on the keyboard.
KEY_ESC: 65307 == "ESC" (escape) key on the keyboard.
*/
# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define OS "linux"
#  define KEY_LEFT		97
#  define KEY_RIGHT		100
#  define KEY_UP       	119
#  define KEY_DOWN		115
#  define KEY_ARROW_LEFT	 	65361
#  define KEY_ARROW_RIGHT		65363
#  define KEY_ARROW_UP			65362
#  define KEY_ARROW_DOWN		65364
#  define KEY_ESC				65307
# elif __APPLE__
#  include "../minilibx_opengl_20191021/mlx.h"
#  define OS "macos"
#  define KEY_LEFT       0
#  define KEY_RIGHT      2
#  define KEY_UP 		13
#  define KEY_DOWN		1
#  define KEY_ARROW_LEFT		123
#  define KEY_ARROW_RIGHT		124
#  define KEY_ARROW_UP			126
#  define KEY_ARROW_DOWN		125
#  define KEY_ESC				53
# endif

# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <sys/time.h>
# include <math.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

// GAME STRUCTURE
typedef struct s_game
{
	void	*p_mlx_init;
	void	*p_mlx_window;
	bool	b_menu;
}	t_game;

// PLAYER STRUCTURE
typedef struct s_player
{
	int		step;
	int		life;
	bool	hit;
	int		coin_max;
	int		coin_ply;
	int		*pos_s_y;
	int		*pos_s_x;
	float	x;
	float	y;
	float	vy;
	bool	axe;
}	t_player;

// MONSTER STRUCTURE
typedef struct s_monster
{
	int		*pos_s_y;
	int		*pos_s_x;
	int		*old_pos_s_y;
	int		*old_pos_s_x;
	int		*save_pos_x;
	int		monster_max;
	float	x;
	float	y;
	bool	axe;
	bool	*path;
}	t_monster;

// MAP STRUCTURE FUNCTIONS AND VEIRIFICATIONS
typedef struct s_map
{
	int			fd;
	int			c_collumns;
	int			c_lines;
	int			map_y;
	int			map_x;
	double		draw_x;
	double		draw_y;
	bool		b_pos_exit;
	bool		b_pos_start;
	bool		b_pos_collect;
	char		**p_map;
	void		*p_init_xpm_img[NUM_XPM_FILES];
	t_game		*game;
	t_player	*player;
	t_monster	*monster;
}	t_map;

// NODE STRUCTURE BFS QUEUE
typedef struct s_node
{
	int				x;
	int				y;
}	t_node;

// BFS QUEUE STRUCTURE
typedef struct s_queue
{
	t_node	*nodes[MAX_QUEUE_SIZE];
	int		front;
	int		rear;
}	t_queue;

// ERRORS FUNCTIONS		errors.c
void	ft_error_base(int value);
void	ft_errors_map(char *str);
void	ft_free_void(void ***arr);
void	ft_free_visited(bool ***visited, int size);
void	ft_bfs(t_map *map, t_node *start, t_node *goal);
void	ft_find_start_end(t_map *map, t_node *start, t_node *goal);
void	ft_malloc_error(void *ptr);
void	ft_check_character(char *argv);

// PATH BFS FUNCTIONS (MAP)		path_bfs.c path_valid.c
t_node	*ft_dequeue(t_queue *q);
bool	ft_is_empty(t_queue *q);
void	ft_enqueue(t_queue *q, int x, int y);
void	ft_direction(t_node node, int i, int *n_x, int *n_y);
void	ft_visited_init(t_map *map, bool ***visited);

// PARSING FUNCTIONS (MAP)		parsing.c
int		ft_parse_base(int argc, char **argv, t_map *map);
int		ft_count_col(char *path);

// MAP DRAW FUNCTIONS		draw.c + path_include.c
void	ft_draw_img(void *img, int x, int y, t_map *map);
int		ft_draw_map(t_map *map);
void	ft_load_xpm(t_map *map);
char	**ft_path_xpm(void);
int		*ft_init_img_index(void);

// PLAYER FUNCTIONS		player.c
int		ft_input_player(int keycode, t_map *map);
int		ft_init_player(t_map *map);
void	ft_exit_player(t_map *map);

// PLAYER COLLISION FUNCTIONS		player_collision.c
float	ft_is_floor(t_map *map, float new_x, float new_y);
void	ft_collision(t_map *map, float new_x, float new_y, int keycode);

// PLAYER GRAVITY FUNCTIONS		player_gravity.c
void	ft_gravity_player(t_map *map);

// PLAYER ANIMATION FUNCTIONS		player_animation.c
void	ft_anim_player_w(t_map *map);
void	ft_anim_jump(t_map *map);
void	ft_refresh_frame(t_map *map, int time);
void	ft_image_to_window(t_map *map, int img);

// PLAYER COIN FUNCTIONS		player_coin.c
bool	ft_player_is_on_coin(t_map *map, int i, int j);
void	ft_coords_coin(t_map *map, int i, int j);
void	ft_update_coin(t_map *map);

// MONSTER FUNCTIONS		monster.c
void	ft_init_monster(t_map *map);
void	ft_coords_monster(t_map *map, int i, int j);
void	ft_col_monster(t_map *map);

// UI HUD FUNCTIONS		hud.c // main_menu.c
void	ft_hud_player(t_map *map);
void	ft_main_menu(t_map *map);
int		ft_mouse_click(int button, int x, int y, t_map *map);

// SETTINGS/CONDITIONS GAME FUNCTIONS		game.c
int		ft_destroy_escape(int keysim, t_game *game);
int		ft_destroy_cross(t_game *game);
int		ft_resize_window(t_map *map);
int		ft_update_game(t_map *map);

#endif