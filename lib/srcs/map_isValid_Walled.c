/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isWalled.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:45:26 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/17 22:16:08 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

//------------------CHECK IF INLINES ARE SURROUNDED BY WALLS-----------------
int	check_map_iswalled_inlines(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 1;
	while (x < game->nb_line -1)
	{
		while (game->lines_stored[x][y] != '\0')
		{
			if (game->lines_stored[x][0] != '1' ||
				game->lines_stored[x][game->len_line - 1] != '1')
				map_iswalled_error(game);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

//------------------CHECK IF OUTLINES ARE SURROUNDED BY WALLS-----------------
int	check_map_iswalled_outlines(t_game *game)
{
	int	y;

	y = 0;
	while (game->lines_stored[0][y] != '\0')
	{
		if (game->lines_stored[0][y] != '1')
			map_iswalled_error(game);
		y++;
	}
	y = 0;
	while (game->lines_stored[game->nb_line - 1][y] != '\0')
	{
		if (game->lines_stored[game->nb_line - 1][y] != '1')
			map_iswalled_error(game);
		y++;
	}
	return (0);
}
