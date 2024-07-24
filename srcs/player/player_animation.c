/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:58:04 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 15:04:11 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function that refreshes the frame
void	ft_refresh_frame(t_map *map, int time)
{
	int	i;

	i = 0;
	while (i != time)
	{
		mlx_do_sync(map->game->p_mlx_init);
		i++;
	}
}

void	ft_image_to_window(t_map *map, int img)
{
	mlx_put_image_to_window(map->game->p_mlx_init, map->game->p_mlx_window,
		map->p_init_xpm_img[img], map->player->x, map->player->y);
}

// Function that manages the player's jumping animation
void	ft_anim_player_w(t_map *map)
{
	static float	old_x;

	if (old_x < map->player->x
		&& map->player->y == ft_is_floor(map, map->player->x, map->player->y))
	{
		ft_image_to_window(map, 26);
		ft_image_to_window(map, 27);
		ft_refresh_frame(map, 4500);
		ft_image_to_window(map, 28);
		ft_refresh_frame(map, 4500);
	}
	else if (old_x > map->player->x
		&& map->player->y == ft_is_floor(map, map->player->x, map->player->y))
	{
		ft_image_to_window(map, 29);
		ft_image_to_window(map, 30);
		ft_refresh_frame(map, 4500);
		ft_image_to_window(map, 31);
		ft_refresh_frame(map, 4500);
	}
	if (map->player->axe == false)
		ft_image_to_window(map, 25);
	else
		ft_image_to_window(map, 26);
	old_x = map->player->x;
}

// Function that manages the player's jumping animation
void	ft_anim_jump(t_map *map)
{
	if (map->player->y != ft_is_floor(map, map->player->x, map->player->y))
	{
		ft_image_to_window(map, 32);
		mlx_do_sync(map->game->p_mlx_init);
	}
}
