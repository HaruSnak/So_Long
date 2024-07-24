/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_gravity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:56:41 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 15:05:06 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function that applies gravity to the player
// If the player is not on the ground, they fall
// If the player is on the ground, they stay on the ground
void	ft_gravity_player(t_map *map)
{
	static bool	refresh_frame;

	if (map->player->y != ft_is_floor(map, map->player->x, map->player->y))
	{
		refresh_frame = false;
		map->player->vy = GRAVITY;
		map->player->y += map->player->vy;
	}
	if (map->player->y >= ft_is_floor(map, map->player->x, map->player->y))
	{
		if (!refresh_frame)
		{
			refresh_frame = true;
		}
		map->player->y = ft_is_floor(map, map->player->x, map->player->y);
		map->player->vy = 0;
	}
}
