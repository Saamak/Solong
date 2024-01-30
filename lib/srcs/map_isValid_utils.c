/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isValid_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:41:48 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/17 23:24:37 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

char	*ft_strjoined(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		len_all;
	int		j;

	j = 0;
	i = 0;
	len_all = 0;
	if (!s1 || !s2)
		return (NULL);
	len_all = ft_strlenn(s1) + ft_strlenn(s2);
	result = malloc(sizeof(char) * len_all + 1);
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

//-----------------------SPLIT LINE INTO TABS---------------------------
int	count_words(char const *s, char c)
{
	int	c_w;
	int	tmp;

	tmp = 0;
	c_w = 0;
	while (*s != '\0')
	{
		if (tmp == 1 && *s == c)
			tmp = 0;
		if (tmp == 0 && *s != c)
		{
			tmp = 1;
			c_w++;
		}
		s++;
	}
	return (c_w);
}

char	**ft_split(char *s, char c, t_game *game)
{
	char	**dest;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (s[0] == c)
			s++;
		else
		{
			game->i = 0;
			while (s[game->i] != '\0' && s[game->i] != c)
				game->i++;
			dest[x++] = ft_substr(s, 0, game->i);
			s = s + game->i;
		}
	}
	dest[x] = NULL;
	return (dest);
}

//------------------STRLEN OF MAP LINE------------------------------
int	map_line_strlen(t_game *game)
{
	int	i;

	i = 0;
	while (game->lines_stored[0][i] != '\0')
	{
		i++;
	}
	return (i);
}
