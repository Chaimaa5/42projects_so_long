#include "so_long.h"

void	xpm(t_data	*data)
{
	int x;
	int y;

	data->img_zero = mlx_xpm_file_to_image(data->mlx, "./xpm/0.xpm", &x, &y);
	data->img_one = mlx_xpm_file_to_image(data->mlx, "./xpm/1.xpm", &x, &y);
	data->img_C = mlx_xpm_file_to_image(data->mlx, "./xpm/c.xpm", &x, &y);
	data->img_P = mlx_xpm_file_to_image(data->mlx, "./xpm/p.xpm", &x, &y);
}

void	put_background(t_data *data)
{
	int		x;
	int		y;
	int		h;
	int		w;

	x = 0;
	y = 0;
	h = 0;
	w = 0;
	while(g_map[y])
	{
		x = 0;
		h = 0;
		while (g_map[y][x])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_zero, h, w);
			x++;
			h += 50;
		}
		y++;
		w += 50;
	}
}

void	draw(t_data *data)
{
	int		x;
	int		y;
	int		h;
	int		w;
	x = 0;
	y = 0;
	h = 0;
	w = 0;
	while(g_map[y])
	{
		x = 0;
		h = 0;
		while (g_map[y][x])
		{
			if (g_map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_C, h, w);
			if (g_map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_P, h, w);
			if (g_map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_one, h, w);
			x++;
			h += 50;
		}
		y++;
		w += 50;
	}
}
void	win(t_data *data)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(g_map[0]);
	while (g_map[j])
		j++;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, i * 50, j * 50, "Hello mf!");
	xpm(data);
	put_background(data);
	draw(data);
	mlx_loop(data->mlx);
} 

int	main(int ac, char **av)
{	
	int i;
	t_data	*data;
	
	if (ac == 2)
	{
		i = open(av[1], O_RDONLY);
		g_map = check_map(i);
		if(g_map == NULL)
			printf("map not valid");
		data = malloc(sizeof(t_data));

		win(data);
	}
}