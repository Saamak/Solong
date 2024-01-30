/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isValid_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:43:38 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/17 23:20:39 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

//-----1--------------CHECK IF MAP IS OPENABLE---------------------------
void	check_map_exist(char *map_name, t_game *game)
{
	int		fd;

	game->map_path = ft_strjoined(game->map_path, map_name);
	fd = open(game->map_path, O_RDONLY);
	ft_printf(BLUE"\n ~ Checking map validity...\n"RESET);
	if (fd == -1)
		map_exist_error(game);
	ft_printf(GREEN" |- MAP exist [OK]\n"RESET);
	close(fd);
	check_map_storing(fd, game);
	check_map_iswalled(game);
}

//-----2--------------STOCK EACH LINE IN TAB------------------------------
void	check_map_storing(int fd, t_game *game)
{
	char	*line;
	char	*all_lines;
	int		nb_line;

	nb_line = 0;
	all_lines = malloc(sizeof(char) * 1);
	all_lines[0] = '\0';
	fd = open(game->map_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		nb_line ++;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	game->lines_stored = ft_split(all_lines, '\n', game);
	game->flood = ft_split(all_lines, '\n', game);
	free(all_lines);
	check_map_isrect(nb_line, game);
	free(line);
	close(fd);
}

//---------------------CHECK IF MAP IS RECTANGLE AND BASICALLY POSSIBLE----
int	check_map_isrect(int nb_line, t_game *game)
{
	int	len_line;
	int	x;
	int	y;

	x = 0;
	y = 0;
	len_line = 0;
	len_line = map_line_strlen(game);
	map_isrectangle_error(len_line, nb_line, game);
	y = 0;
	while (x != nb_line)
	{
		while (game->lines_stored[x][y] != '\0')
			y++;
		if (y != len_line)
			map_isrectangle_error2(game);
		y = 0;
		x++;
	}
	ft_printf(GREEN" |- MAP is Rectangle and Possible [OK]\n"RESET);
	return (0);
}

//------------------CHECK IF MAP IS WALLED-----------------------
int	check_map_iswalled(t_game *game)
{
	game->nb_line = nb_line_strlen(game);
	game->len_line = map_line_strlen(game);
	check_map_iswalled_outlines(game);
	check_map_iswalled_inlines(game);
	ft_printf(GREEN" |- MAP walled [OK]\n"RESET);
	return (0);
}

int	nb_line_strlen(t_game *game)
{
	int	i;

	i = 0;
	if (game->lines_stored != NULL)
	{
		while (game->lines_stored[i] != NULL)
			i++;
	}
	return (i);
}
