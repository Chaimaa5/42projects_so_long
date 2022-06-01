/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:12:20 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/05/30 21:58:47 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "inc/libft/libft.h"
# include "inc/gnl/get_next_line.h"

typedef struct s_data{
	void	*img_p;
	void	*img_c;
	void	*img_e_open;
	void	*img_e_closed;
	void	*img_zero;
	void	*img_one;
	void	*mlx;
	void	*mlx_win;
	int		w;
	int		h;
	int		ex;
	int		ey;
	int		px;
	int		py;
	int		c;

}				t_data;

typedef struct s_position{
	int	x;
	int	y;
}	t_position;

char	**g_map;
char	**read_map(void);
int		check_first_line(char *temp);
int		check_last_line(char *temp, int len);
char	**check_map(int i);
void	win(t_data *data);
void	draw(t_data *data, int x, int y);
void	put_background(t_data *data);
int		move_down(t_data *data, int moves);
int		move_up(t_data *data, int moves);
int		move_right(t_data *data, int moves);
int		move_left(t_data *data, int moves);
int		keys(int key, t_data *data);
void	win(t_data *data);
void	xpm(t_data	*data);
void	put_background(t_data *data);
void	draw_exit(t_data *data, int x, int y);
void	draw_player(t_data *data, int x, int y);
void	draw_collectables(t_data *data);
void	winner(void);
void	eat(t_data *data);

#endif
