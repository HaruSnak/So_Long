/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:09:27 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 14:59:54 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function that counts the number of lines in the map
int	ft_count_col(char *path)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(path, O_RDONLY);
	ft_error_base(fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close(fd);
	return (count + 1);
}

// Function that checks if there are no characters other than the basic ones
void	ft_check_character(char *argv)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	ft_error_base(fd);
	str = get_next_line(fd);
	if (str == NULL)
		ft_errors_map("map");
	while (str != NULL)
	{
		i = -1;
		while (str[++i] != '\0')
		{
			if (!ft_strchr("01CEPLRDG78JWZFS456UIOM\n", str[i]))
				ft_errors_map("map");
		}
		free(str);
		str = NULL;
		str = get_next_line(fd);
	}
	free(str);
	str = NULL;
	close(fd);
}
