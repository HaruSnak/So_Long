/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:01:15 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 14:55:48 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

// Function that retrieves the coordinates of the coins
// and stores them in an array
void	ft_coords_coin(t_map *map, int i, int j)
{
	static bool	one_time;
	static int	k;

	if (map->p_map[i][j] == 'C' && !one_time && k < map->c_lines)
	{
		if (!map->player->pos_s_y)
		{
			map->player->pos_s_y = malloc(sizeof(int) * map->c_lines);
			ft_malloc_error(map->player->pos_s_y);
		}
		if (!map->player->pos_s_x)
		{
			map->player->pos_s_x = malloc(sizeof(int) * map->c_lines);
			ft_malloc_error(map->player->pos_s_x);
		}
		map->player->pos_s_y[k] = i;
		map->player->pos_s_x[k] = j;
		map->player->coin_max++;
		k++;
	}
	if (i == map->c_collumns - 1 && j == map->c_lines - 1)
		one_time = true;
}

// Function that removes an element from an array
// and reduces the size of the array
void	ft_remove_index(int **arr, int *size, int index_to_remove)
{
	int	*new_arr;
	int	i;
	int	j;

	if (index_to_remove < 0 || index_to_remove >= *size)
		return ;
	new_arr = (int *)malloc((*size - 1) * sizeof(int));
	ft_malloc_error(new_arr);
	i = 0;
	j = 0;
	while (i < *size)
	{
		if (i != index_to_remove)
		{
			new_arr[j] = (*arr)[i];
			j++;
		}
		i++;
	}
	free(*arr);
	*arr = new_arr;
}

// Toggle rotate between 2 images
void	ft_update_coin_bis(int *toggle, int i, t_map *map)
{
	if (*toggle == 0 && map->player->coin_max != 0)
	{
		while (i != map->player->coin_max)
		{
			ft_draw_img(map->p_init_xpm_img[3],
				map->player->pos_s_x[i] * 64,
				map->player->pos_s_y[i] * 64, map);
			i++;
		}
		*toggle = 1;
	}
	else
	{
		while (i != map->player->coin_max)
		{
			ft_draw_img(map->p_init_xpm_img[2],
				map->player->pos_s_x[i] * 64,
				map->player->pos_s_y[i] * 64, map);
			i++;
		}
		*toggle = 0;
	}
}

// Function that updates the coins by applying an animation effect
// using the clock.h library
void	ft_update_coin(t_map *map)
{
	struct timeval			current_time;
	static struct timeval	last_coin_update;
	static int				toggle;
	double					time_since_last_update;
	int						i;

	gettimeofday(&current_time, NULL);
	time_since_last_update = (current_time.tv_sec - last_coin_update.tv_sec)
		+ (current_time.tv_usec - last_coin_update.tv_usec) / 1000000.0;
	i = 0;
	if (time_since_last_update >= COIN_ANIM_DELAY)
	{
		ft_update_coin_bis(&toggle, i, map);
		last_coin_update = current_time;
	}
}

// Function that checks if the player is on a coin
// If so, it removes the coin by updating the frame
bool	ft_player_is_on_coin(t_map *map, int i, int j)
{
	int	k;

	k = 0;
	if (fabs(map->player->x - j * 64) <= COLLISION_OBJ
		&& fabs(map->player->y - i * 64) <= COLLISION_OBJ
		&& map->p_map[i][j] == 'C')
	{
		map->p_map[i][j] = '0';
		while (k < map->player->coin_max && map->player->pos_s_y[k] != i
			&& map->player->pos_s_x[k] != j)
			k++;
		ft_remove_index(&map->player->pos_s_y, &map->player->coin_max, k);
		ft_remove_index(&map->player->pos_s_x, &map->player->coin_max, k);
		map->player->coin_max--;
		map->player->coin_ply++;
		return (true);
	}
	return (false);
}
