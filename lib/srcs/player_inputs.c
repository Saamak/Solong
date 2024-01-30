/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:19:36 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/25 16:19:39 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		m_forward(param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		m_back(param);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		m_left(param);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		m_right(param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		escape(param);
}

void	m_forward(t_game *game)
{
	if (game->lines_stored[game->pos_x -1][game->pos_y] == 'E')
	{
		if (game->collecting == game->c_cnt)
			exit_success(game);
		return ;
	}
	if (game->lines_stored[game->pos_x - 1][game->pos_y] != '1')
	{
		game->lines_stored[game->pos_x][game->pos_y] = '0';
		game->pos_x--;
		if (game->lines_stored[game->pos_x][game->pos_y] == 'C')
			game->collecting++;
		game->lines_stored[game->pos_x][game->pos_y] = 'P';
		game->rotate = 1;
	}
	else
		return ;
	game->count_input++;
	ft_put_string(game);
	put_player_movement(game);
}

void	m_left(t_game *game)
{
	if (game->lines_stored[game->pos_x][game->pos_y - 1] == 'E')
	{
		if (game->collecting == game->c_cnt)
			exit_success(game);
		return ;
	}
	if (game->lines_stored[game->pos_x][game->pos_y - 1] != '1')
	{
		game->lines_stored[game->pos_x][game->pos_y] = '0';
		game->pos_y--;
		if (game->lines_stored[game->pos_x][game->pos_y] == 'C')
			game->collecting++;
		game->lines_stored[game->pos_x][game->pos_y] = 'P';
		game->rotate = 2;
	}
	else
		return ;
	game->count_input++;
	ft_put_string(game);
	put_player_movement(game);
}

void	m_right(t_game *game)
{
	if (game->lines_stored[game->pos_x][game->pos_y + 1] == 'E')
	{
		if (game->collecting == game->c_cnt)
			exit_success(game);
		return ;
	}
	if (game->lines_stored[game->pos_x][game->pos_y + 1] != '1')
	{
		game->lines_stored[game->pos_x][game->pos_y] = '0';
		game->pos_y++;
		if (game->lines_stored[game->pos_x][game->pos_y] == 'C')
			game->collecting++;
		game->lines_stored[game->pos_x][game->pos_y] = 'P';
		game->rotate = 3;
	}
	else
		return ;
	game->count_input++;
	ft_put_string(game);
	put_player_movement(game);
}

void	m_back(t_game *game)
{
	if (game->lines_stored[game->pos_x + 1][game->pos_y] == 'E')
	{
		if (game->collecting == game->c_cnt)
			exit_success(game);
		return ;
	}
	if (game->lines_stored[game->pos_x + 1][game->pos_y] != '1')
	{
		game->lines_stored[game->pos_x][game->pos_y] = '0';
		game->pos_x++;
		if (game->lines_stored[game->pos_x][game->pos_y] == 'C')
			game->collecting++;
		game->lines_stored[game->pos_x][game->pos_y] = 'P';
		game->rotate = 4;
	}
	else
		return ;
	game->count_input++;
	ft_put_string(game);
	put_player_movement(game);
}
