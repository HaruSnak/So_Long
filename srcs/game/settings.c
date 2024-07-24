/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:01:59 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 14:57:33 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function to quit the game when the ESC key is pressed
int	ft_destroy_escape(int keysim, t_game *game)
{
	if (keysim == KEY_ESC)
	{
		mlx_destroy_window(game->p_mlx_init, game->p_mlx_window);
		game->p_mlx_window = NULL;
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// Function to quit the game when the red cross is pressed
int	ft_destroy_cross(t_game *game)
{
	mlx_destroy_window(game->p_mlx_init, game->p_mlx_window);
	game->p_mlx_window = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_resize_window(t_map *map)
{
	ft_draw_map(map);
	return (0);
}

// Function to update the game
int	ft_update_game(t_map *map)
{
	if (!map->game->b_menu)
		ft_main_menu(map);
	else
	{
		ft_gravity_player(map);
		ft_anim_player_w(map);
		ft_update_coin(map);
		ft_anim_jump(map);
		ft_exit_player(map);
		ft_init_monster(map);
		ft_col_monster(map);
	}
	return (0);
}
