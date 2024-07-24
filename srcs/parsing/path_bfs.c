/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:00:19 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 15:02:22 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function that finds the start(P) and goal(E) positions
void	ft_find_start_end(t_map *map, t_node *start, t_node *goal)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->c_collumns)
	{
		j = 0;
		while (j < map->c_lines && map->p_map[i][j] != '\0')
		{
			if (map->p_map[i][j] == 'P')
			{
				start->x = i;
				start->y = j;
			}
			else if (map->p_map[i][j] == 'E')
			{
				goal->x = i;
				goal->y = j;
			}
			j++;
		}
		i++;
	}
}

// Function that verifies if the new position is valid
// If the new position is valid, it is added to the queue
// If the new position is outside the map/wall, it is ignored
void	ft_verify_new_pos(t_node *node, t_map *map,
	t_queue *q, bool **visited)
{
	int		i;
	int		n_x;
	int		n_y;

	i = 0;
	while (i < 4)
	{
		ft_direction(*node, i, &n_x, &n_y);
		if (n_x >= 0 && n_x < map->c_collumns && n_y >= 0
			&& n_y < map->c_lines && map->p_map[n_x][n_y] != '1'
			&& map->p_map[n_x][n_y] != 'G' && map->p_map[n_x][n_y] != 'R'
			&& map->p_map[n_x][n_y] != 'L' && map->p_map[n_x][n_y] != 'J'
			&& map->p_map[n_x][n_y] != '7' && map->p_map[n_x][n_y] != '8'
			&& map->p_map[n_x][n_y] != 'D' && !visited[n_x][n_y])
		{
			visited[n_x][n_y] = true;
			ft_enqueue(q, n_x, n_y);
		}
		i++;
	}
}

// Function that finds the shortest path
// We use the breadth-first search algorithm
// We use a queue to store the positions to be checked
// We use a boolean array to store the visited positions
// We check the 4 possible directions for each position
// If the position is valid, we add it to the queue
// If the position is the goal position, we stop the search
void	ft_initialize_bfs(t_map *map, t_node *start,
	t_queue *q, bool ***visited)
{
	t_node	*start_node;

	q->front = 0;
	q->rear = 0;
	ft_visited_init(map, visited);
	(*visited)[start->x][start->y] = true;
	start_node = malloc(sizeof(t_node));
	ft_malloc_error(start_node);
	*start_node = *start;
	ft_enqueue(q, start_node->x, start_node->y);
	free(start_node);
}

void	ft_perform_bfs(t_map *map, t_node *goal, t_queue *q, bool **visited)
{
	t_node	*node;

	while (!ft_is_empty(q))
	{
		node = ft_dequeue(q);
		if (node->x == goal->x && node->y == goal->y)
		{
			ft_free_visited(&visited, map->c_collumns);
			while (q->front != q->rear)
			{
				free(q->nodes[q->front]);
				q->front = (q->front + 1) % MAX_QUEUE_SIZE;
			}
			free(node);
			return ;
		}
		ft_verify_new_pos(node, map, q, visited);
		free(node);
	}
	ft_free_visited(&visited, map->c_collumns);
	ft_errors_map("path");
}

void	ft_bfs(t_map *map, t_node *start, t_node *goal)
{
	t_queue		q;
	bool		**visited;

	ft_initialize_bfs(map, start, &q, &visited);
	ft_perform_bfs(map, goal, &q, visited);
}
