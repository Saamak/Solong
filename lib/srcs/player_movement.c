/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:46:46 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/17 17:48:42 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	put_player_movement(t_game *game)
{
	game->tile_i = 0;
	game->tile_y = 0;
	game->tile_x = 0;
	game->tile_j = 0;
	while (game->lines_stored[game->tile_x])
	{
		while (game->lines_stored[game->tile_x][game->tile_y] != '\0')
		{
			if_on_p(game);
			game->tile_y++;
			game->tile_i = game->tile_i + 64;
		}
		game->tile_y = 0;
		game->tile_i = 0;
		game->tile_j = game->tile_j +64;
		game->tile_x++;
	}
}

void	if_on_p(t_game *game)
{
	if (game->lines_stored[game->tile_x][game->tile_y] == 'P')
		put_player_new(game);
}

void	put_floor_after(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("../../visuals_elements/floor/wood_floor.png");
	if (!texture)
		error_display(game->mlx);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		error_display(game->mlx);
	if (game->rotate == 2)
		mlx_image_to_window(game->mlx, img, game->tile_i + 64, game->tile_j);
	if (game->rotate == 1)
		mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j + 64);
	if (game->rotate == 3)
		mlx_image_to_window(game->mlx, img, game->tile_i - 64, game->tile_j);
	if (game->rotate == 4)
		mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j - 64);
	mlx_delete_texture(texture);
}
