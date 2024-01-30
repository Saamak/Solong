/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:22:41 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/18 09:44:50 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	free_before(t_game *game)
{
	int	i;

	i = 0;
	if (game->lines_stored != NULL)
	{
		while (game->lines_stored[i])
		{
			free(game->lines_stored[i++]);
		}
	}
	i = 0;
	if (game->flood != NULL)
	{
		while (game->flood[i])
		{
			free(game->flood[i++]);
		}
	}
	free(game->map_path);
	free(game->lines_stored);
	free(game->flood);
	free(game->mlx);
	free(game);
}

void	exit_success(t_game *game)
{
	int	i;

	i = 0;
	ft_printf(GREEN"\n\n          ====| YOU WIN |===\n\n"RESET);
	if (game->lines_stored != NULL)
	{
		while (game->lines_stored[i])
		{
			free(game->lines_stored[i++]);
		}
	}
	i = 0;
	if (game->flood != NULL)
	{
		while (game->flood[i])
			free(game->flood[i++]);
	}
	free(game->map_path);
	free(game->lines_stored);
	free(game->flood);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}

void	escape(t_game *game)
{
	int	i;

	i = 0;
	ft_printf(GREEN"\n\n          ====| GAME CLOSED |===\n\n"RESET);
	if (game->lines_stored != NULL)
	{
		while (game->lines_stored[i])
		{
			free(game->lines_stored[i++]);
		}
	}
	i = 0;
	if (game->flood != NULL)
	{
		while (game->flood[i])
			free(game->flood[i++]);
	}
	free(game->map_path);
	free(game->lines_stored);
	free(game->flood);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}
