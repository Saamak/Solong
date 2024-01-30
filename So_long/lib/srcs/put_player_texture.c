/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:48:54 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/18 13:40:32 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	put_player_new(t_game *game)
{
	if (game->rotate == 1)
		put_up(game);
	else if (game->rotate == 2)
		put_left(game);
	else if (game->rotate == 3)
		put_right(game);
	else if (game->rotate == 4)
		put_back(game);
}

void	put_up(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture
		= mlx_load_png("../../visuals_elements/characters/manBlue/man_3.png");
	if (!texture)
		error_display(game->mlx);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		error_display(game->mlx);
	mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j);
	mlx_delete_texture(texture);
	put_floor_after(game);
}

void	put_left(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture
		= mlx_load_png("../../visuals_elements/characters/manBlue/man_4.png");
	if (!texture)
		error_display(game->mlx);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		error_display(game->mlx);
	mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j);
	mlx_delete_texture(texture);
	put_floor_after(game);
}

void	put_right(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture
		= mlx_load_png("../../visuals_elements/characters/manBlue/man_1.png");
	if (!texture)
		error_display(game->mlx);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		error_display(game->mlx);
	mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j);
	mlx_delete_texture(texture);
	put_floor_after(game);
}

void	put_back(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture
		= mlx_load_png("../../visuals_elements/characters/manBlue/man_2.png");
	if (!texture)
		error_display(game->mlx);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		error_display(game->mlx);
	mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j);
	mlx_delete_texture(texture);
	put_floor_after(game);
}
