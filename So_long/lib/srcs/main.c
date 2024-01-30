/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:26:50 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/25 16:20:29 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

// -------MY STRUCTURE INITIALIZATION-----------
t_game	*init_data(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->e_count = 0;
	game->p_spwn_c = 0;
	game->c_cnt = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->collecting = 0;
	game->len_line = 0;
	game->nb_line = 0;
	game->lines_stored = NULL;
	game->flood = NULL;
	game->map_path = "../../Map/";
	game->tile_i = 0;
	game->tile_y = 0;
	game->tile_x = 0;
	game->tile_j = 0;
	game->rotate = 0;
	game->mlx = NULL;
	game->count_input = 0;
	game->i = 0;
	return (game);
}

//----------------CORE-MAIN-------------------------------
int	main(int argc, char **argv)
{
	t_game	*game;

	ft_printf(GREEN"\n======================================="RESET);
	ft_printf(MAGENTA"[Program Starting]\n"RESET);
	game = init_data();
	if (argc != 2)
		argc_error(game);
	check_map_exist(argv[1], game);
	map_isplayable(game);
	game->mlx
		= mlx_init(game->len_line * 64, game->nb_line * 64, "GOBLOX", true);
	if (!game->mlx)
		return (1);
	map_gen(game);
	game->collecting = 0;
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop(game->mlx);
	ft_printf(MAGENTA"\n\n[Program Exit Correctly]"RESET);
	ft_printf(GREEN"=======================================\n"RESET);
	escape(game);
	return (0);
}
