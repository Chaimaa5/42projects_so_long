#include "so_long.h"

int	keys(int key, t_data *data)
{
	static int	moves;

	if (key == 53)
		exit(0);
	else if (key == 126 || key == 13)
		moves = move_up(data, moves);
	else if (key == 125 || key == 1)
		moves = move_down(data, moves);
	else if (key == 123 || key == 0)
		moves = move_left(data, moves);
	else if (key == 124 || key == 2)
		moves = move_right(data, moves);
	return (0);
}

void	winner(void)
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
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_E_open, data->ex * 50, data->ey * 50);
		g_map[data->ey][data->ex] = 'C';
	}
}