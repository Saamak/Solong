/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:49:13 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/25 16:16:36 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define RED   "\x1b[31m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32m"
# define BLUE  "\x1b[94m"
# define MAGENTA  "\x1b[35m"

typedef struct s_game
{
	int		e_count;
	int		p_spwn_c;
	int		c_cnt;
	int		pos_x;
	int		pos_y;
	int		collecting;
	int		nb_line;
	int		len_line;
	char	**lines_stored;
	char	**flood;
	char	*map_path;
	int		tile_i;
	int		tile_j;
	int		tile_y;
	int		tile_x;
	int		rotate;
	void	*mlx;
	int		count_input;
	int		i;
}	t_game;

void	my_keyhook(mlx_key_data_t keydata, void *param);

//CHECK MAP
void	check_map_exist(char *map_name, t_game *game);
void	check_map_storing(int fd, t_game *game);

int		check_map_isrect(int nb_line, t_game *game);
int		check_map_iswalled(t_game *game);
int		check_map_iswalled_outlines(t_game *game);
int		check_map_iswalled_inlines(t_game *game);

//ERRORS
void	map_isrectangle_error(int len_line, int nb_line, t_game *game);
void	map_isrectangle_error2(t_game *game);
void	argc_error(t_game *game);
void	error_playable(t_game *game);
void	error_utils(int x, int y, t_game *game);
void	map_exist_error(t_game *game);
void	map_iswalled_error(t_game *game);
void	free_before(t_game *game);
void	error_display(t_game *game);

//PARSING
int		map_isplayable(t_game *game);
int		find_utilities(t_game *game);

void	flood_fill(t_game *game, int x, int y);
//UTILS
int		count_words(char const *s, char c);
int		map_line_strlen(t_game *game);
char	**ft_split(char *s, char c, t_game *game);
int		ft_strnstr(const char *big, const char *ber);
int		nb_line_strlen(t_game *game);
char	*ft_strjoined(char *s1, char *s2);
void	escape(t_game *game);
void	find_utilities_two(t_game *game, int x, int y);
void	ft_put_string(t_game *game);
int		stlen(long int n);
char	*ft_itoa(int n);

//DISPLAY
void	map_gen(t_game *game);
void	if_on(t_game *game);
void	put_wall(t_game *game);
void	put_floor(t_game *game);
void	put_gem(t_game *game);
void	put_exit(t_game *game);
void	put_player(t_game *game);

//MOVEMENT
void	m_forward(t_game *game);
void	m_left(t_game *game);
void	m_right(t_game *game);
void	m_back(t_game *game);
void	put_player_movement(t_game *game);
void	put_player_new(t_game *game);
void	if_on_p(t_game *game);
void	put_up(t_game *game);
void	put_left(t_game *game);
void	put_right(t_game *game);
void	put_back(t_game *game);
void	exit_success(t_game *game);

void	put_floor_after(t_game *game);
#endif
