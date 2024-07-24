/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:56:52 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 14:58:32 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function that loads xpm images into the map structure.
void	ft_load_xpm(t_map *map)
{
	char		**path_xpm;
	int			size;
	int			i;

	i = 0;
	size = 64;
	path_xpm = ft_path_xpm();
	while (i < NUM_XPM_FILES)
	{
		if (path_xpm[i] == NULL || map->game->p_mlx_init == NULL)
			ft_errors_map("path XPM invalid");
		map->p_init_xpm_img[i] = mlx_xpm_file_to_image(
				map->game->p_mlx_init, path_xpm[i], &size, &size);
		if (map->p_init_xpm_img[i] == NULL)
			ft_errors_map("path XPM invalid");
		i++;
	}
	ft_free_void((void ***)&path_xpm);
}

// Function that draws an image at a given position
void	ft_draw_img(void *img, int x, int y, t_map *map)
{
	mlx_put_image_to_window(map->game->p_mlx_init,
		map->game->p_mlx_window, img, x, y);
}

// Function that draws images based on the map and map coordinates
void	ft_draw_condition(t_map *map, int i, int j, int *img_index)
{
	bool	monster_on_tile;
	int		k;

	monster_on_tile = false;
	k = 0;
	map->draw_x = j * 64;
	map->draw_y = i * 64;
	ft_coords_coin(map, i, j);
	ft_coords_monster(map, i, j);
	ft_player_is_on_coin(map, i, j);
	ft_hud_player(map);
	while (k < map->monster->monster_max)
	{
		if (i == map->monster->pos_s_y[k] && j == map->monster->pos_s_x[k])
		{
			monster_on_tile = true;
			break ;
		}
		k++;
	}
	if (map->p_map[i][j] != 'C' && map->p_map[i][j] != 'M' && !monster_on_tile)
		ft_draw_img(map->p_init_xpm_img[img_index[(int)map->p_map[i][j]]],
			map->draw_x, map->draw_y, map);
}

// Function that draws the map using ft_draw_condition
int	ft_draw_map(t_map *map)
{
	int		*img_index;
	int		i;
	int		j;

	i = 0;
	j = 0;
	img_index = ft_init_img_index();
	while (i != map->c_collumns)
	{
		j = 0;
		while (j != map->c_lines)
		{
			ft_draw_condition(map, i, j, img_index);
			if (map->p_map[i][j] == 'M')
				map->p_map[i][j] = '0';
			j++;
		}
		i++;
	}
	free(img_index);
	return (0);
}
