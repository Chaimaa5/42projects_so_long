/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:11:36 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/05/30 22:17:22 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_elements(char **map, int i, int x, int p)
{
	int	c;
	int	e;

	c = 0;
	e = 0;
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (map[i][x] == 'E')
				e++;
			if (map[i][x] == 'P')
				p++;
			if (map[i][x] == 'C')
				c++;
			x++;
		}
		i++;
	}
	if (p == 1 && c >= 1 && e == 1)
		return (1);
	return (0);
}

int	check_len(char **map)
{
	int	len;
	int	new_len;
	int	y;

	y = 0;
	len = ft_strlen(map[0]);
	while (map[y])
	{
		new_len = ft_strlen(map[y]);
		if (new_len != len)
			return (0);
		y++;
	}
	return (1);
}

void	check_shape(int len, int x, int y)
{
	if (len == x - 1 && len == y - 1)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

int	check_wall(char **map, int len, int x, int y)
{
	int	j;

	j = len;
	if (check_len(map))
	{
		while (map[0][x] == '1' && map[0][x])
			x++;
		while (map[len][y] == '1' && map[len][y])
			y++;
		check_shape(len, x, y);
		if (x == (int)ft_strlen(map[0]) && x == y)
		{			
			while (map[j - 1][0] == '1' && map[len - 1][y - 1] == '1')
			{
				j--;
				len--;
				if (j == 0 && len == j)
					return (1);
			}
		}
	}
	return (0);
}

char	**check_map(int i)
{
	char	*map;
	char	*mapp;
	char	**p;
	int		y;

	y = 0;
	mapp = ft_strdup("");
	map = get_next_line(i);
	while (map)
	{
		mapp = ft_strjoin(mapp, map);
		free(map);
		map = get_next_line(i);
		y++;
	}
	p = ft_split(mapp, '\n');
	free(mapp);
	if (check_wall(p, y - 1, 0, 0) && check_elements(p, 0, 0, 0))
		return (p);
	return (NULL);
}
