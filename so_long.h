#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "inc/libft/libft.h"
#include "inc/gnl/get_next_line.h"


typedef struct	s_data {
	void	*img_P;
	void 	*img_C;
	void 	*img_E;
	void	*img_zero;
	void	*img_one;
	void	*mlx;
	void	*mlx_win;
}				t_data;

char **read_map();
int check_first_line(char *temp);
int check_last_line(char *temp, int len);
char	**check_map();
void	win(t_data *data);
void	draw(t_data *data);
void	put_background(t_data *data);

#endif