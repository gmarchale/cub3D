#include "../include/cub3d.h"

int	len_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

int	rgb_to_hex(t_game *game, int red, int green, int blue)
{
	int	res;

	res = -2;
	if (red < 0 || red > 255)
		error_manager(game, "Not RGB");
	else if (green < 0 || green > 255)
		error_manager(game, "Not RGB");
	else if (blue < 0 || blue > 255)
		error_manager(game, "Not RGB");
	else
		res = (red << 16) | (green << 8) | blue;
	return (res);
}

float	deg_to_rad(float degrees)
{
	return (degrees * (M_PI / 180));
}

char	*skip_empty_line(int fd, char *line)
{
	while (line && line[0] == '\n')
		line = next_line(fd, line);
	return (line);
}

void	replace_threes(char **map)
{
	int	i, j;
	i = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '3')
				map[i][j] = '0';
			j++;
		}
		printf("\n");
		i++;
	}
}

char	*next_line(int fd, char *line)
{
	free(line);
	return (get_next_line(fd));
}
