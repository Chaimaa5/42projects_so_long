/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:12:12 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/04/11 08:12:15 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *data, int x, int y)
{
	data->h = 0;
	data->w = 0;
	data->c = 0;
	while (g_map[y])
	{
		x = 0;
		data->h = 0;
		while (g_map[y][x])
		{
			if (g_map[y][x] == 'C')
				draw_collectables(data);
			if (g_map[y][x] == 'E')
				draw_exit(data, x, y);
			if (g_map[y][x] == 'P')
				draw_player(data, x, y);
			if (g_map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_one, data->h, data->w);
			x++;
			data->h += 50;
		}
		y++;
		data->w += 50;
	}
}

int	mouse(int mouse)
{
	(void)mouse;
	exit (0);
	return (0);
}

void	win(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(g_map[0]);
	while (g_map[j])
		j++;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, i * 50, j * 50, "Hello mf!");
	xpm(data);
	put_background(data);
	draw(data, 0, 0);
	mlx_key_hook(data->mlx_win, keys, data);
	mlx_hook(data->mlx_win, 17, 0L, mouse, data->mlx);
	system("Leaks so_long");
	mlx_loop(data->mlx);
}

int	file_check(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: file not found", 1);
		exit (0);
	}
	return (fd);
}

int	main(int ac, char **av)
{	
	int		fd;
	t_data	*data;

	if (ac == 2)
	{
		if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		{
			fd = file_check(av[1]);
			g_map = check_map(fd);
			if (!g_map)
				ft_putstr_fd("Error: map not valid", 1);
			data = malloc(sizeof(t_data));
			if (g_map)
				win(data);
		}
		else
			ft_putstr_fd("Error: map file should have .ber extenssion", 1);
	}
}
