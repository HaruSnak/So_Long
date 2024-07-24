/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:22:27 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 14:55:49 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

// Function that allocates memory for the monster's position
void	ft_malloc_pos_monster(t_map *map)
{
	if (!map->monster->pos_s_y)
	{
		map->monster->pos_s_y = malloc(sizeof(int) * map->c_lines);
		ft_malloc_error(map->monster->pos_s_y);
	}
	if (!map->monster->pos_s_x)
	{
		map->monster->pos_s_x = malloc(sizeof(int) * map->c_lines);
		ft_malloc_error(map->monster->pos_s_x);
	}
	if (!map->monster->save_pos_x)
	{
		map->monster->save_pos_x = malloc(sizeof(int) * map->c_lines);
		ft_malloc_error(map->monster->save_pos_x);
	}
}

// Function that retrieves the coordinates of the monsters
void	ft_coords_monster(t_map *map, int i, int j)
{
	static bool	one_time;
	static int	k;

	if (map->p_map[i][j] == 'M' && !one_time)
	{
		ft_malloc_pos_monster(map);
		map->monster->pos_s_y[k] = i;
		map->monster->pos_s_x[k] = j;
		map->monster->save_pos_x[k] = map->monster->pos_s_x[k];
		map->monster->monster_max++;
		k++;
	}
	if (i == map->c_collumns - 1 && j == map->c_lines - 1)
		one_time = true;
}

// Function that checks if the player is on a monster
// If the player is on a monster, they lose a life
void	ft_col_monster(t_map *map)
{
	int	i;

	i = 0;
	while (i != map->monster->monster_max)
	{
		if (fabs(map->player->x - map->monster->pos_s_x[i] * 64) < COLLISION_OBJ
			&& fabs(map->player->y - map->monster->pos_s_y[i] * 64)
			< COLLISION_OBJ)
		{
			map->player->life--;
			sleep(1);
			ft_image_to_window(map, 34);
			ft_refresh_frame(map, 4500);
		}
		i++;
	}
}

// Function that moves the monster
// The monster moves in a straight line
void	ft_movement_monster(t_map *map, int i, int toggle)
{
	if (!map->monster->path)
	{
		map->monster->path = malloc(sizeof(bool) * map->monster->monster_max);
		ft_malloc_error(map->monster->path);
	}
	if (map->monster->save_pos_x[i] + 2 == map->monster->pos_s_x[i])
		map->monster->path[i] = true;
	else if (map->monster->save_pos_x[i] == map->monster->pos_s_x[i])
		map->monster->path[i] = false;
	if (map->monster->save_pos_x[i] + 2 >= map->monster->pos_s_x[i]
		&& !map->monster->path[i])
		map->monster->pos_s_x[i] += 1;
	else if (map->monster->path[i])
		map->monster->pos_s_x[i] -= 1;
	if (toggle == 1)
		ft_draw_img(map->p_init_xpm_img[35],
			map->monster->pos_s_x[i] * 64,
			map->monster->pos_s_y[i] * 64, map);
	else
		ft_draw_img(map->p_init_xpm_img[36],
			map->monster->pos_s_x[i] * 64,
			map->monster->pos_s_y[i] * 64, map);
}

void	ft_init_monster(t_map *map)
{
	struct timeval			current_time;
	static struct timeval	last_monster_update;
	static int				toggle;
	double					time_since_last_update;
	int						i;

	gettimeofday(&current_time, NULL);
	time_since_last_update = (current_time.tv_sec - last_monster_update.tv_sec)
		+ (current_time.tv_usec - last_monster_update.tv_usec) / 1000000.0;
	i = 0;
	if (time_since_last_update >= MONSTER_ANIM_DELAY)
	{
		while (i != map->monster->monster_max)
		{
			ft_movement_monster(map, i, toggle);
			i++;
		}
		ft_draw_map(map);
		toggle = !toggle;
		last_monster_update = current_time;
	}
}
