/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:26:18 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/25 16:20:06 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	error_utils(int x, int y, t_game *game)
{
	if (!(game->lines_stored[x][y] == '1'
		|| game->lines_stored[x][y] == '0'))
	{
		ft_printf(MAGENTA"Error\n");
		ft_printf(RED"  MAP NEED 1 SPAWN 1 EXIT AND 1 COLLECTIBLE MIN \n"RESET);
		ft_printf(GREEN"\n======================================="RESET);
		free_before(game);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	error_playable(t_game *game)
{
	ft_printf(MAGENTA"Error\n");
	ft_printf(RED"  MAP NOT PLAYABLE\n\n"RESET);
	ft_printf(GREEN"\n======================================="RESET);
	free_before(game);
	exit(EXIT_FAILURE);
}

void	error_display(t_game *game)
{
	ft_printf(MAGENTA"Error\n");
	ft_printf(RED"  MAP DISPLAY ERROR\n\n"RESET);
	free_before(game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}
