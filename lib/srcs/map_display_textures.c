/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:32:54 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/17 18:00:20 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	put_wall(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("../../visuals_elements/wall/tile_307.png");
	if (!texture)
		error_display(game->mlx);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		error_display(game->mlx);
	mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j);
	mlx_delete_texture(texture);
}

void	put_floor(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("../../visuals_elements/floor/wood_floor.png");
	if (!texture)
		error_display(game->mlx);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		error_display(game->mlx);
	mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j);
	mlx_delete_texture(texture);
}

void	put_gem(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("../../visuals_elements/collectibles/gem.png");
	if (!texture)
		error_display(game->mlx);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		error_display(game->mlx);
	mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j);
	mlx_delete_texture(texture);
}

void	put_exit(t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("../../visuals_elements/exit/exit.png");
	if (!texture)
		error_display(game->mlx);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		error_display(game->mlx);
	mlx_image_to_window(game->mlx, img, game->tile_i, game->tile_j);
	mlx_delete_texture(texture);
}

void	put_player(t_game *game)
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
}
