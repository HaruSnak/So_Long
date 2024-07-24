/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:09:29 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/23 18:47:20 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Fonction qui affiche le nombre de pas/icone du joueur
void	ft_ui_walk(t_map *map)
{
	char	*string;

	string = ft_itoa(map->player->step);
	ft_draw_img(map->p_init_xpm_img[37], 128, 256, map);
	mlx_string_put(map->game->p_mlx_init,
		map->game->p_mlx_window, 128 + 60, 256 + 20, 0x000000, string);
	free(string);
}

// Fonction qui affiche le nombre d'icone du joueur
void	ft_ui_coin(t_map *map)
{
	int	i;
	int	img_index;

	i = 0;
	img_index = 37 + map->player->coin_ply;
	while (i < map->player->coin_ply && map->player->coin_ply != 0)
	{
		if (map->player->coin_ply >= 1 && map->player->coin_ply <= 10)
		{
			ft_draw_img(map->p_init_xpm_img[img_index], 128, 192, map);
		}
		i++;
	}
}

//Fonction qui affiche le nombre de vie du joueur
void	ft_ui_life(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->player->life)
	{
		ft_draw_img(map->p_init_xpm_img[23], 128 + j, 128, map);
		j += 64;
		i++;
	}
	while (i < 3)
	{
		ft_draw_img(map->p_init_xpm_img[24], 128 + j, 128, map);
		j += 64;
		i++;
	}
}

void	ft_hud_player(t_map *map)
{
	if (map->c_collumns > 10 && map->c_lines > 20)
	{
		ft_ui_life(map);
		ft_ui_coin(map);
		ft_ui_walk(map);
	}
}
