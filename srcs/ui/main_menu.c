/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:21:22 by shmoreno          #+#    #+#             */
/*   Updated: 2024/03/29 15:31:14 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

//Fonction qui gère le clic de la souris
int	ft_mouse_click(int button, int x, int y, t_map *map)
{
	if (button == 1 && !map->game->b_menu && x >= 0 && x <= 1600
		&& y >= 0 && y <= 900)
	{
		map->game->b_menu = true;
		mlx_clear_window(map->game->p_mlx_init, map->game->p_mlx_window);
		return (0);
	}
	return (1);
}

//Draw the main menu
void	ft_main_menu(t_map *map)
{
	if (!map->game->b_menu)
	{
		ft_draw_img(map->p_init_xpm_img[48], 0, 0, map);
	}
}
