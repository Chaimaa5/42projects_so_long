/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:09:47 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/06/01 13:33:02 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_down(t_data *data, int moves)
{
	if (g_map[data->py + 1][data->px] != '1'
		&& g_map[data->py + 1][data->px] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_zero, data->px * 50, data->py * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_p, data->px * 50, (data->py + 1) * 50);
		data->py++;
		if (g_map[data->py][data->px] == 'C')
			eat(data);
		if (g_map[data->ey][data->ex] == 'P')
			winner();
		ft_putnbr_fd(moves, 1);
		ft_putchar_fd('\n', 1);
		moves++;
		return (moves);
	}
	return (moves);
}

int	move_up(t_data *data, int moves)
{
	if (g_map[data->py - 1][data->px] != '1'
		&& g_map[data->py - 1][data->px] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_zero, data->px * 50, data->py * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_p, data->px * 50, (data->py - 1) * 50);
		data->py--;
		if (g_map[data->py][data->px] == 'C')
			eat(data);
		if (g_map[data->ey][data->ex] == 'P')
			winner();
		ft_putnbr_fd(moves, 1);
		ft_putchar_fd('\n', 1);
		moves++;
		return (moves);
	}
	return (moves);
}

int	move_left(t_data *data, int moves)
{
	if (g_map[data->py][data->px - 1] != '1'
		&& g_map[data->py][data->px - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_zero, data->px * 50, data->py * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_p, (data->px - 1) * 50, (data->py) * 50);
		data->px--;
		if (g_map[data->py][data->px] == 'C')
			eat(data);
		if (g_map[data->ey][data->ex] == 'P')
			winner();
		ft_putnbr_fd(moves, 1);
		ft_putchar_fd('\n', 1);
		moves++;
		return (moves);
	}
	return (moves);
}

int	move_right(t_data *data, int moves)
{
	if (g_map[data->py][data->px + 1] != '1'
		&& g_map[data->py][data->px + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_zero, data->px * 50, data->py * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_p, (data->px + 1) * 50, (data->py) * 50);
		data->px++;
		if (g_map[data->py][data->px] == 'C')
			eat(data);
		if (g_map[data->ey][data->ex] == 'P')
			winner();
		ft_putnbr_fd(moves, 1);
		ft_putchar_fd('\n', 1);
		moves++;
		return (moves);
	}
	return (moves);
}
