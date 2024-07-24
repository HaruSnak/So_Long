/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_include.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:46:59 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/24 14:58:58 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Function that returns an array of char* containing the paths of the xpm images.
// The paths are retrieved from the so_long.h file.
char	**ft_path_xpm(void)
{
	char	*line;
	char	**tmp;
	char	**path_xpm;
	int		fd;

	path_xpm = malloc(sizeof(char *) * (NUM_XPM_FILES + 1));
	ft_malloc_error(path_xpm);
	fd = open("includes/so_long.h", O_RDONLY);
	line = get_next_line(fd);
	if (fd == -1 || !line)
		ft_errors_map("path XPM");
	while (line)
	{
		if (ft_strncmp(line, "# define IMG_", 13) == 0)
		{
			tmp = ft_split(line, ' ');
			*path_xpm = ft_strtrim(tmp[3], "\"\t\n");
			path_xpm++;
			ft_free_void((void ***)&tmp);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (*path_xpm = NULL, path_xpm - NUM_XPM_FILES);
}

void	ft_img_index_bis(int *img_index)
{
	img_index['Z'] = 14;
	img_index['F'] = 15;
	img_index['S'] = 16;
	img_index['4'] = 17;
	img_index['5'] = 18;
	img_index['6'] = 19;
	img_index['U'] = 20;
	img_index['I'] = 21;
	img_index['O'] = 22;
}

// Function that initializes an integer array containing the indexes of the xpm images.
// This makes it easier to automate the rest of the process
int	*ft_init_img_index(void)
{
	int	*img_index;

	img_index = malloc(sizeof(int) * NUM_XPM_FILES * 2);
	ft_malloc_error(img_index);
	ft_memset(img_index, -1, sizeof(int) * NUM_XPM_FILES * 2);
	img_index['0'] = 0;
	img_index['1'] = 1;
	img_index['C'] = 2;
	img_index['E'] = 4;
	img_index['P'] = 5;
	img_index['L'] = 6;
	img_index['R'] = 7;
	img_index['D'] = 8;
	img_index['G'] = 9;
	img_index['7'] = 10;
	img_index['8'] = 11;
	img_index['J'] = 12;
	img_index['W'] = 13;
	ft_img_index_bis(img_index);
	return (img_index);
}
