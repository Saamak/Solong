/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:18:08 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/19 15:41:39 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	argc_error(t_game *game)
{
	ft_printf(MAGENTA"  Error\n");
	ft_printf(RED"  Please insert the name of the map to load\n\n"RESET);
	ft_printf(GREEN"\n======================================="RESET);
	free(game);
	exit(EXIT_FAILURE);
}

void	map_exist_error(t_game *game)
{
	ft_printf(MAGENTA"  Error\n");
	ft_printf(RED"  MAP does not exist\n"RESET);
	ft_printf(GREEN"\n======================================="RESET);
	free_before(game);
	exit(EXIT_FAILURE);
}

void	map_isrectangle_error(int len_line, int nb_line, t_game *game)
{
	if (len_line == nb_line || len_line < 3)
	{
		ft_printf(MAGENTA"  Error\n");
		ft_printf(RED"  MAP is NOT Rectangle Or impossible\n"RESET);
		ft_printf(GREEN"\n======================================="RESET);
		free_before(game);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	map_isrectangle_error2(t_game *game)
{
	ft_printf(MAGENTA"  Error\n");
	ft_printf(RED"  MAP is NOT Rectangle Or impossible \n"RESET);
	ft_printf(GREEN"\n======================================="RESET);
	free_before(game);
	exit(EXIT_FAILURE);
}

void	map_iswalled_error(t_game *game)
{
	ft_printf(MAGENTA"  Error\n");
	ft_printf(RED"  MAP is NOT Surrounded by Walls \n"RESET);
	ft_printf(GREEN"\n======================================="RESET);
	free_before(game);
	exit(EXIT_FAILURE);
}
