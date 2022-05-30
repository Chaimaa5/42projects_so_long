/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:42:13 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/05/30 21:45:57 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img_E_closed, data->h, data->w);
	data->ex = x;
	data->ey = y;
}

void	draw_player(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img_P, data->h, data->w);
	data->px = x;
	data->py = y;
}

void	draw_collectables(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img_C, data->h, data->w);
	data->c++;
}

void	xpm(t_data	*data)
{
	int	x;
	int	y;

	data->img_zero = mlx_xpm_file_to_image(data->mlx, "./xpm/0.xpm", &x, &y);
	data->img_one = mlx_xpm_file_to_image(data->mlx, "./xpm/1.xpm", &x, &y);
	data->img_C = mlx_xpm_file_to_image(data->mlx, "./xpm/c.xpm", &x, &y);
	data->img_P = mlx_xpm_file_to_image(data->mlx, "./xpm/p.xpm", &x, &y);
	data->img_E_open = mlx_xpm_file_to_image(data->mlx,
			"./xpm/Eopen.xpm", &x, &y);
	data->img_E_closed = mlx_xpm_file_to_image(data->mlx,
			"./xpm/Eclosed.xpm", &x, &y);
}

void	put_background(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->h = 0;
	data->w = 0;
	while (g_map[y])
	{
		x = 0;
		data->h = 0;
		while (g_map[y][x])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->img_zero, data->h, data->w);
			x++;
			data->h += 50;
		}
		y++;
		data->w += 50;
	}
}
