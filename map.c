#include "so_long.h"

char *read_map()
{
    char    *tm;
    char *p;
	int	fd;
    int i; 

    i = 0;
    tm = NULL;
    p = ft_strdup("");
	fd = open("map.ber", O_RDONLY);
    tm = get_next_line(fd);
    while(tm)
	{
        p = ft_strjoin(p, tm);
		tm = get_next_line(fd);
	}
    return (p);
}

int check_first_line(char *temp)
{
    int     i;
    char    **map;
    int     len;

    i = 0;
    map = ft_split(temp, '\n');
    len = ft_strlen(map[0]);
    while (i < len)
    {
        if (map[0][i] != '1')
            return (0);
        i++;
    }
    if (i == len )
        return (1);
    return (0);
}

int check_last_line(char *temp)
{
    int     i;
    char    **map;
    int     len;

    i = 0;
    map = ft_split(temp, '\n');
    len = ft_strlen(map[0]);
    while (i < len)
    {
        if (map[0][i] != '1')
            return (0);
        i++;
    }
    if (i == len )
        return (1);
    return (0);
}

int check_length(char *temp)
{
    int     i;
    char    **map;
    int     len;
    int     next_len;

    i = 1;
    next_len = 0;
    map = ft_split(temp, '\n');
    len = ft_strlen(map[0]);
    while (map[i])
    {
        next_len = ft_strlen(map[i]);
        if (len != next_len)
            return (0);
        i++;
    }
    if (len != next_len)
        return (1);
    return (0);
}