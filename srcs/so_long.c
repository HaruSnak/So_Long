/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:50:35 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 15:05:51 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_update_key_press(int keycode, t_map *map)
{
	ft_input_player(keycode, map);
	ft_destroy_escape(keycode, map->game);
	return (0);
}

void	ft_module_load(t_map *map)
{
	ft_load_xpm(map);
	ft_init_player(map);
	ft_draw_map(map);
}

void	ft_hook(t_game *game, t_map *map)
{
	mlx_mouse_hook(game->p_mlx_window, &ft_mouse_click, map);
	mlx_hook(game->p_mlx_window, 3, (1L << 1), &ft_update_key_press, map);
	mlx_hook(game->p_mlx_window, 17, 0, &ft_destroy_cross, game);
	mlx_hook(game->p_mlx_window, 12, (1L << 17), &ft_resize_window, map);
}

void	ft_init_map(t_map *map)
{
	map->game->b_menu = false;
	map->map_x = 0;
	map->map_y = 0;
	map->p_map = NULL;
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_player	player;
	t_monster	monster;

	map.game = &game;
	map.player = &player;
	map.monster = &monster;
	ft_init_map(&map);
	if (ft_parse_base(argc, argv, &map) == 1)
		exit(EXIT_FAILURE);
	game.p_mlx_init = mlx_init();
	if (!game.p_mlx_init)
		return (EXIT_FAILURE);
	game.p_mlx_window = mlx_new_window(game.p_mlx_init, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_TITLE);
	if (!game.p_mlx_window)
	{
		return (EXIT_FAILURE);
	}
	ft_module_load(&map);
	mlx_loop_hook(game.p_mlx_init, &ft_update_game, &map);
	ft_hook(&game, &map);
	mlx_loop(game.p_mlx_init);
	return (0);
}
