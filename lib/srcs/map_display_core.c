/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:33:32 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/17 17:33:54 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	map_gen(t_game *game)
{
	while (game->lines_stored[game->tile_x])
	{
		while (game->lines_stored[game->tile_x][game->tile_y] != '\0')
		{
			if_on(game);
			game->tile_y++;
			game->tile_i = game->tile_i + 64;
		}
		game->tile_y = 0;
		game->tile_i = 0;
		game->tile_j = game->tile_j +64;
		game->tile_x++;
	}
}

//------------CHECKING WHERE AM I TO PLACE TEXTURES CORRECTLY----------------
void	if_on(t_game *game)
{
	if (game->lines_stored[game->tile_x][game->tile_y] == '1')
		put_wall(game);
	if (game->lines_stored[game->tile_x][game->tile_y] == '0')
		put_floor(game);
	if (game->lines_stored[game->tile_x][game->tile_y] == 'C')
		put_gem(game);
	if (game->lines_stored[game->tile_x][game->tile_y] == 'E')
		put_exit(game);
	if (game->lines_stored[game->tile_x][game->tile_y] == 'P')
		put_player(game);
}
