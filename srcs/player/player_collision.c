/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:42:58 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 15:04:53 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function that checks if the player is on the floor
float	ft_is_floor(t_map *map, float new_x, float new_y)
{
	int	i;
	int	l1;
	int	l2;

	i = 0;
	l1 = (int)floor((new_x) / 64);
	l2 = (int)ceil((new_x) / 64);
	while (i < map->c_collumns)
	{
		i++;
		if (((map->p_map[i][l1] == 'G' || map->p_map[i][l1] == 'L'
			|| map->p_map[i][l1] == 'R' || map->p_map[i][l1] == 'J'
		|| map->p_map[i][l1] == '1') || (map->p_map[i][l2] == 'G'
		|| map->p_map[i][l2] == 'L' || map->p_map[i][l2] == 'R'
		|| map->p_map[i][l2] == 'J' || map->p_map[i][l2] == '1'
		|| map->p_map[i][l2] == 'P'))
		&& (int)round(new_y / 64) < i)
		{
			return ((i * 64) - 64);
		}
	}
	return (0);
}

void	ft_col_suit_condition(t_map *map, float new_x, float new_y, char c_map)
{
	if (c_map == '0' || c_map == 'S' || c_map == '5'
		|| c_map == 'C' || c_map == 'E' || c_map == 'M' || c_map == 'F'
		|| c_map == '4' || c_map == '6')
	{
		map->player->x = (int)new_x;
		map->player->y = (int)new_y;
		ft_draw_map(map);
	}
}

void	ft_condition_cols(t_map *map, char c_map, float new_x, float new_y)
{
	if (map->map_y >= 0 && map->map_y < map->c_collumns
		&& map->map_x >= 0 && map->map_x < map->c_lines)
	{
		c_map = map->p_map[map->map_y][map->map_x];
		ft_col_suit_condition(map, new_x, new_y, c_map);
	}
}

// Function that manages player collisions
void	ft_collision(t_map *map, float new_x, float new_y, int keycode)
{
	char	c_map;

	c_map = '\0';
	if (keycode == KEY_LEFT || keycode == KEY_ARROW_LEFT)
	{
		map->map_y = (int)floor((new_y + 32) / 64);
		map->map_x = (int)ceil((new_x - 32) / 64);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_ARROW_DOWN)
	{
		map->map_y = (int)ceil((new_y - 5) / 64);
		map->map_x = (int)round((new_x) / 64);
	}
	else if (keycode == KEY_UP || keycode == KEY_ARROW_UP)
	{
		map->map_y = (int)ceil((new_y - 64) / 64);
		map->map_x = (int)round((new_x) / 64);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_ARROW_RIGHT)
	{
		map->map_y = (int)ceil((new_y - 32) / 64);
		map->map_x = (int)floor((new_x + 32) / 64);
	}
	ft_condition_cols(map, c_map, new_x, new_y);
}
