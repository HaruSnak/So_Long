/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:47:08 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 14:56:46 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_error_base(int value)
{
	if (value == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

void	ft_errors_map(char *str)
{
	ft_printf("Error: Invalid %s\n", str);
	exit(EXIT_FAILURE);
}

// Function that serves to free the memory of a double pointer array
void	ft_free_void(void ***arr)
{
	void	**inner;

	inner = *arr;
	while (*inner)
	{
		free(*inner);
		inner++;
	}
	free(*arr);
	*arr = NULL;
}

// Function that serves to free the memory of a boolean array
void	ft_free_visited(bool ***visited, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free((*visited)[i]);
		i++;
	}
	free(*visited);
}

// Function that serves to secure mallocs
void	ft_malloc_error(void *ptr)
{
	if (ptr == NULL)
	{
		perror("Malloc error: ");
		exit(EXIT_FAILURE);
	}
}
