/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:09:27 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/28 12:55:51 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function that checks if the file has a valid size
void	ft_v_size_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if ((map->c_collumns < 3 && map->c_lines < 5)
		|| (map->c_collumns < 5 && map->c_lines < 3)
		|| map->c_collumns == map->c_lines)
		ft_errors_map("size");
	while (map->p_map[i])
	{
		j = 0;
		while (map->p_map[i][j] != '\0')
		{
			j++;
		}
		i++;
		if (j != map->c_lines)
			ft_errors_map("size");
	}
}

// Function that checks if the file is well structured
void	ft_v_struct_bis(t_map *map, int i, int j)
{
	if ((map->p_map[i][j] == 'E' && map->b_pos_exit == true)
		|| (map->p_map[i][j] == 'P' && map->b_pos_start == true))
		ft_errors_map("map");
	if (map->p_map[i][j] == 'E')
		map->b_pos_exit = true;
	else if (map->p_map[i][j] == 'C')
		map->b_pos_collect = true;
	else if (map->p_map[i][j] == 'P')
		map->b_pos_start = true;
}

// Function that checks if the file is well structured
// 1. The map must be surrounded by walls
// 2. The map must contain a single exit, a single start
// , and collectibles or indexes stored in the structure
void	ft_v_struct_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->b_pos_exit = false;
	map->b_pos_start = false;
	map->b_pos_collect = false;
	while (map->p_map[++i] != NULL)
	{
		j = -1;
		while (map->p_map[i][++j] != '\0' && map->p_map[i][j] != '\n')
		{
			if (map->p_map[0][j] != '1'
			|| map->p_map[map->c_collumns - 1][j] != '1')
				ft_errors_map("map");
			if (map->p_map[i][0] != '1'
			|| map->p_map[i][map->c_lines - 1] != '1')
				ft_errors_map("map");
			ft_v_struct_bis(map, i, j);
		}
	}
	if (map->b_pos_exit == false || map->b_pos_start == false
		|| map->b_pos_collect == false)
		ft_errors_map("map");
}

// Function that parses the coordinates of the map
void	ft_parse_coords(char **argv, t_map *map)
{
	char	*line;
	char	*tmp;

	map->c_collumns = 0;
	map->fd = open(argv[1], O_RDONLY);
	ft_error_base(map->fd);
	ft_check_character(argv[1]);
	line = get_next_line(map->fd);
	if (line == NULL)
		ft_errors_map("map empty");
	map->p_map = malloc(sizeof(char *) * (ft_count_col(argv[1]) + 1));
	ft_malloc_error(map->p_map);
	while (line != NULL)
	{
		tmp = ft_strtrim(line, "\n");
		free(line);
		map->p_map[map->c_collumns] = tmp;
		map->c_collumns++;
		line = get_next_line(map->fd);
	}
	map->p_map[map->c_collumns] = NULL;
	map->c_lines = ft_strlen(map->p_map[0]);
}

int	ft_parse_base(int argc, char **argv, t_map *map)
{
	t_node	start;
	t_node	goal;

	if (argc != 2)
	{
		ft_printf("Error: Invalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
	{
		ft_printf("Error: Invalid file extension\n");
		return (EXIT_FAILURE);
	}
	ft_parse_coords(argv, map);
	ft_v_size_map(map);
	ft_v_struct_map(map);
	ft_find_start_end(map, &start, &goal);
	ft_bfs(map, &start, &goal);
	return (0);
}
