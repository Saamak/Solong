/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isPlayable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:50:41 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/25 16:16:54 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

//-----------------CHECK IF MAP IS PLAYBLE CORE-----------------------
int	map_isplayable(t_game *game)
{
	int		x_spawn;
	int		y_spawn;

	x_spawn = 0;
	y_spawn = 0;
	ft_printf(BLUE"\n    ~ Checking if map is playable...\n"RESET);
	find_utilities(game);
	ft_printf(GREEN"    |- Existing Spawn [OK]\n"RESET);
	ft_printf(GREEN"    |- Existing Collectables items [OK]\n"RESET);
	ft_printf(GREEN"    |- Existing Exit [OK]\n"RESET);
	x_spawn = game->pos_x;
	y_spawn = game->pos_y;
	game->flood[x_spawn][y_spawn] = '0';
	flood_fill(game, x_spawn, y_spawn);
	if (!(game->c_cnt == game->collecting && game->e_count == 2))
		error_playable(game);
	ft_printf(GREEN"    |- Map Playable [OK]\n"RESET);
	return (0);
}

//-------------CHECK IF EXISITING EXIT, SPAWN, COLLECTIBLES AND TAKE SPAWN COORD
int	find_utilities(t_game *game)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (x < game-> nb_line)
	{
		while (game->lines_stored[x][y] != '\0')
		{
			if (game->lines_stored[x][y] == 'P')
				find_utilities_two(game, x, y);
			else if (game->lines_stored[x][y] == 'C')
				game->c_cnt++;
			else if (game->lines_stored[x][y] == 'E')
				game->e_count++;
			else
				error_utils(x, y, game);
			y++;
		}
		y = 0;
		x++;
	}
	if (game->p_spwn_c != 1 || game->e_count != 1 || game->c_cnt < 1)
		error_playable(game);
	return (0);
}

//--------------------FLOOD_FILL_CHECKING---------------------------
void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->nb_line || y < 0 || y >= game->len_line
		|| game->flood[x][y] == '1' || game->flood[x][y] == 'V')
		return ;
	if (game->flood[x][y] == 'C')
		game->collecting++;
	if (game->flood[x][y] == 'E')
		game->e_count++;
	game->flood[x][y] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	find_utilities_two(t_game *game, int x, int y)
{
	game->pos_x = x;
	game->pos_y = y;
	game->p_spwn_c++;
}
