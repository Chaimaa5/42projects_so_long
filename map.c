#include "so_long.h"

char **read_map()
{
    char    *tm;
    char    *p;
    char    **map;
	int	fd;
    int i;
    int len;

    i = 0;
    p = ft_strdup("");
	fd = open("map.ber", O_RDONLY);
    tm = get_next_line(fd);
    len = ft_strlen(tm);
    if (tm[len - 2] != '1' || tm[0] != '1')
        return (0);
    while(tm)
	{
        p = ft_strjoin(p, tm);
		tm = get_next_line(fd);
        if (tm && (tm[len - 2] != '1' || tm[0] != '1'))
            return (0);
        i++;
	}
    if (check_first_line(p) && check_last_line(p, i))
    {
        map = ft_split(p, '\n');
        return (map);
    }
    return (0);
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

 int check_last_line(char *temp, int len)
{
    int     i;
    char    **map;
    int     leng;
    int     j;

    i = 0;
    map = ft_split(temp, '\n');
    leng = ft_strlen(map[len - 1]);
    while (i < leng)
    {
        if (map[len - 1][i] != '1')
            return (0);
        i++;
    }
    j = 0;
    while (map[j])
        j++;
    while(map[j][0] == '1')
        j--;
    while(map[j][i] == '1')
        j--;
    if (i == leng && j == 0)
        return (1);
    return (0);
}

char	**check_map()
{
	char	**map;
    int     i;
    int     x;
    int     p;
    int     c;

    x = 0;
    i = 0;
    c = 0;
    p = 0;
	map = read_map();
    while (map[i])
    {
        x = 0;
        while (map[i][x])
        {                
            if (map[i][x] == 'E')
                p++;
            if (map[i][x] == 'P')
                p++;
            if (map[i][x] == 'C')
                c++;
            x++;
        }
        i++;
    }
	if (read_map() ==  NULL || p != 2 || c == 0)
	{
		printf("map not valid");
		exit(1);
	}
	return(map);
}