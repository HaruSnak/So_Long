/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:50:32 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 15:05:43 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function that includes user inputs
void	ft_player_movement(int keycode, float *new_x, float *new_y, t_map *map)
{
	if (keycode == KEY_UP || keycode == KEY_ARROW_UP)
	{
		if (map->player->y == ft_is_floor(map, *new_x, *new_y))
			*new_y -= 98;
		map->player->step += 98;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_ARROW_DOWN)
	{
		if (map->player->y != ft_is_floor(map, *new_x, *new_y))
			*new_y += 10;
		map->player->step += 10;
	}
	else if (keycode == KEY_LEFT || keycode == KEY_ARROW_LEFT)
	{
		*new_x -= 32;
		map->player->axe = true;
		map->player->step += 32;
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_ARROW_RIGHT)
	{
		*new_x += 32;
		map->player->axe = false;
		map->player->step += 32;
	}
	ft_printf("Step: %d\n", map->player->step);
}

int	ft_input_player(int keycode, t_map *map)
{
	float	new_x;
	float	new_y;

	new_x = map->player->x;
	new_y = map->player->y;
	ft_player_movement(keycode, &new_x, &new_y, map);
	ft_collision(map, new_x, new_y, keycode);
	return (0);
}

// Function that initializes the player
int	ft_init_player(t_map *map)
{
	t_node	start;
	t_node	goal;

	ft_find_start_end(map, &start, &goal);
	map->player->x = start.y * 64;
	map->player->y = start.x * 64;
	map->player->axe = false;
	map->player->hit = false;
	map->player->life = 3;
	map->player->step = 0;
	map->player->coin_ply = 0;
	map->player->coin_max = 0;
	map->player->pos_s_y = NULL;
	map->player->pos_s_x = NULL;
	map->monster->monster_max = 0;
	map->monster->pos_s_y = NULL;
	map->monster->pos_s_x = NULL;
	map->monster->save_pos_x = NULL;
	map->monster->old_pos_s_y = NULL;
	map->monster->old_pos_s_x = NULL;
	map->monster->path = NULL;
	ft_draw_img(map->p_init_xpm_img[25], map->player->x, map->player->y, map);
	return (0);
}

// Function that checks if the player has won or lost
void	ft_exit_player(t_map *map)
{
	t_node	start;
	t_node	goal;
	int		hitbox;

	hitbox = 32;
	ft_find_start_end(map, &start, &goal);
	if (fabs(map->player->x - goal.y * 64) <= hitbox
		&& fabs(map->player->y - goal.x * 64) <= hitbox
		&& map->player->coin_max == 0)
	{
		ft_printf("You won with a total of %d coins\n", map->player->coin_ply);
		mlx_destroy_window(map->game->p_mlx_init, map->game->p_mlx_window);
		exit(EXIT_SUCCESS);
	}
	if (map->player->life == 0)
	{
		ft_printf("You lost with a total of %d coins\n", map->player->coin_ply);
		mlx_destroy_window(map->game->p_mlx_init, map->game->p_mlx_window);
		exit(EXIT_SUCCESS);
	}
}
