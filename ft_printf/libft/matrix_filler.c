#include "libft.h"

char	**matrix_filler(char **map, char c, int map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			map[i][j] = c;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}
