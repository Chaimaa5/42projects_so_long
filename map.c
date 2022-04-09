#include "so_long.h"

// char **read_map()
// {
//     char    *tm;
//     char    *p;
//     char    **map;
// 	int	fd;
//     int i;
//     int len;

//     i = 0;
//     p = ft_strdup("");
// 	fd = open("map.ber", O_RDONLY);
//     tm = get_next_line(fd);
//     len = ft_strlen(tm);
//     if (tm[len - 2] != '1' || tm[0] != '1')
//         return (0);
//     while(tm)
// 	{
//         p = ft_strjoin(p, tm);
// 		tm = get_next_line(fd);
//         if (tm && (tm[len - 2] != '1' || tm[0] != '1'))
//             return (0);
//         i++;
// 	}
//     if (check_first_line(p) && check_last_line(p, i))
//     {
//         map = ft_split(p, '\n');
//         return (map);
//     }
//     return (0);
// }

// int check_first_line(char *temp)
// {
//     int     i;
//     char    **map;
//     int     len;

//     i = 0;
//     map = ft_split(temp, '\n');
//     len = ft_strlen(map[0]);
//     while (i < len)
//     {
//         if (map[0][i] != '1')
//             return (0);
//         i++;
//     }
//     if (i == len )
//         return (1);
//     return (0);
// }
// int check_len(char  **map, int  len)
// {
//     int i;
//     int j;

//     j = 0;
//     i = 0;
//     while (map[j])
//         j++;
//     i = j;
//     while (map[j][0] == '1')
//         j--;
//     while (map[i][len] == '1')
//         i--;
//     if (i == 0 && j == 0)
//         return (1);
//     return (0);
// }
//  int check_last_line(char *temp, int len)
// {
//     int     i;
//     char    **map;
//     int     leng;

//     i = 0;
//     map = ft_split(temp, '\n');
//     leng = ft_strlen(map[len - 1]);
//     while (i < leng)
//     {
//         if (map[len - 1][i] != '1')
//             return (0);
//         i++;
//     }
//     if (i == leng && check_len(map, leng))
//         return (1);
//     return (0);
// }



// char	**check_map()
// {
// 	char	**map;
//     int     i;
//     int     x;
//     int     p;
//     int     c;

//     x = 0;
//     i = 0;
//     c = 0;
//     p = 0;
// 	map = read_map();
//     while (map[i])
//     {
//         x = 0;
//         while (map[i][x])
//         {                
//             if (map[i][x] == 'E')
//                 p++;
//             if (map[i][x] == 'P')
//                 p++;
//             if (map[i][x] == 'C')
//                 c++;
//             x++;
//         }
//         i++;
//     }
// 	if (read_map() ==  NULL || p != 2 || c == 0)
// 	{
// 		printf("map not valid");
// 		exit(1);
// 	}
// 	return(map);
// }
int check_wall(char **map, int len)
{
    int i;
    int j;
    //int x;
    int y;

    y = 0;
    i = 0;
    j = len;
    while(map[0][i] && map[0][i] == '1' )
        i++;
    while(map[len][y] == '1')
        y++;
    while (map[len][0] == '1' && len > 0)
        len--;
    while (map[j][i - 1] == '1' && j > 0)
        j--;
    
    if(i == (int)ft_strlen(map[0]) && i == y && j == len)
        return (1);
    return (0);
    
    
    
    
}
char **check_map(int i)
{
    char    *map;
    char    *mapp;
    char     **p;
    int     y;

    y = 0;
    mapp = ft_strdup("");
    map = get_next_line(i);
    while (map)
    {    		   
        mapp = ft_strjoin(mapp, map);
        map = get_next_line(i);
        y++;
    }
    p = ft_split(mapp, '\n');
    free(mapp);
    if(check_wall(p, y - 1))
        return(p);
    return(NULL);
}