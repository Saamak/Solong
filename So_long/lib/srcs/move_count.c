/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:56:21 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/18 09:15:50 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_put_string(t_game *game)
{
	char			*str;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	if (game->count_input >= 1)
	{
		texture
			= mlx_load_png("../../visuals_elements/wall/tile_306.png");
		if (!texture)
			error_display(game->mlx);
		img = mlx_texture_to_image(game->mlx, texture);
		ft_printf("numbers of movements : %d\n", game->count_input);
		if (game->count_input > 1000)
			mlx_image_to_window(game->mlx, img, 32, 0);
		mlx_image_to_window(game->mlx, img, 0, 0);
		mlx_delete_texture(texture);
	}
	str = ft_itoa(game->count_input);
	mlx_put_string(game->mlx, str, 0, 0);
	free(str);
}
