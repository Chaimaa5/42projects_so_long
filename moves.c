/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:09:47 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/04/11 08:10:09 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keys(int key, t_data *data)
{
	static int moves;

	if(key == 53)
		exit(0);
	else if (key == 126 || key == 13)
		moves = move_up(data, moves);
	else if (key == 125 || key == 1)
		moves = move_down(data, moves);
	else if (key == 123 || key == 0)
		moves = move_left(data, moves);
	else if (key == 124 || key == 2)
		moves = move_right(data, moves);
	return 0;
}

void	winner()
{
	ft_putstr_fd("You win", 1);
	exit(0);
}

void	eat(t_data *data)
{
	g_map[data->py][data->px] = 'P';
	data->c--;	
	if (data->c == 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_E_open, data->ex * 50, data->ey * 50);
		g_map[data->ey][data->ex] = 'C';
	}
}

int	move_down(t_data *data, int moves)
{
	if (g_map[data->py + 1][data->px] != '1' && g_map[data->py + 1][data->px] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_zero, data->px * 50, data->py * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_P, data->px * 50, (data->py + 1) * 50);
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
	if (g_map[data->py - 1][data->px] != '1' && g_map[data->py - 1][data->px] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_zero, data->px * 50, data->py * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_P, data->px * 50, (data->py - 1) * 50);
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
	if (g_map[data->py][data->px - 1] != '1' && g_map[data->py][data->px - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_zero, data->px * 50, data->py * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_P, (data->px - 1) * 50, (data->py) * 50);
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
	if (g_map[data->py][data->px + 1] != '1' && g_map[data->py][data->px + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_zero, data->px * 50, data->py * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_P, (data->px + 1) * 50, (data->py) * 50);
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

