#include "../include/cub3d.h"

// PARSING DE LA  MAP

static void	arg_error(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
	{
		printf("Error\nMap is not .cub\n");
		exit(EXIT_FAILURE);
	}
}

static void	assign_texture(void *texture, char *path)
{
	if (texture == NULL)
	{
		texture = path;
		printf("Path = %s\n", path);
	}
	else
	{
		printf("Error: Textures not valid.\n");
		exit(EXIT_FAILURE);
	}
}
static int	len_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static void	get_texture(t_texture *texture, char *line)
{
	char **split;

	split = ft_split(line, ' ');
	if (len_split(split) != 2)
	{
		printf("%s\n", line);
		printf("Texture path is not valid.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(split[0], "NO", ft_strlen(split[0])) == 0)
			assign_texture(texture->north, split[1]);
	else if (ft_strncmp(split[0], "SO", ft_strlen(split[0])) == 0)
			assign_texture(texture->south, split[1]);
	else if (ft_strncmp(split[0], "WE", ft_strlen(split[0])) == 0)
			assign_texture(texture->west, split[1]);
	else if (ft_strncmp(split[0], "EA", ft_strlen(split[0])) == 0)
			assign_texture(texture->east, split[1]);
	else if (ft_strncmp(split[0], "F", ft_strlen(split[0])) == 0)
		printf("ceci est un F\n");
	else if (ft_strncmp(split[0], "C", ft_strlen(split[0])) == 0)
		printf("ceci est un C\n");
}

static void	get_data(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line)
	{
		while (line[0] == '\n')
			line = get_next_line(game->fd);
		get_texture(&game->texture, line);
		if (line)
			line = get_next_line(game->fd);
	}
	// fonction qui check si toutes les donnees sont bien presentes dans la struct
	// pendant le parsing fonction qui check si on ne remplit pas plusieurs fois la meme donnees
}

static void	init_textures(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
}

t_game *init_game(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->map = NULL;
	game->fd = 0;
	init_textures(&game->texture);
	return (game);
}

int	parsing(int argc, char **argv, t_game *game)
{
	arg_error(argc, argv);
	init_game(game);
	if ((game->fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Error: Can't open file.\n");
		exit(1);
	}
	get_data(game);
	close(game->fd); // va avec fd = open
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	parsing(argc, argv, &game);
	return (0);
}

/**************************************************/
void	init_mlx(t_display *display, t_image_data *img)
{
	display->mlx = mlx_init();
		exit(1);
	display->window = mlx_new_window(display->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	display->img.img = mlx_new_image(display->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->address = mlx_get_data_addr(display->img.img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_image_data *img, int color, int coord_x, int coord_y)
{
	int	x;
	int y;
	int	size;

	size = 50;
	y = coord_y;
	while (y < coord_y + size)
	{
		x = coord_x;
		while (x < coord_x + size)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

void print_map(char **map)
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			printf("%c", map[j][i]);
		}
		printf("\n");
	}
}

char	**get_map(void)
{
	char **map;

	map = malloc(sizeof(char*) * 5);
	for (int i = 0; i < 6; i++)
		map[i] = malloc(sizeof(char) * 7);
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 6; i++)
			map[j][i] = '0';
	}
	for (int i = 0; i < 7; i++)
	{
		map[0][i] = '1';
		map[4][i] = '1';
	}
	for (int i = 0; i < 5; i++)
	{
		map[i][0] = '1';
		map[i][6] = '1';
	}
	map[1][3] = '1';
	map[3][4] = 'N';
	return (map);
}
/*
int main(void)
{
	char **map;

	map = get_map();
	print_map(map);
	return (0);
}
*/

/*
int	main(void)
{
	t_image_data img;
	t_display display;

	int i = ft_isalnum(14);
	i += 1;
	init_mlx(&display, &img);
	draw_square(&img, RED, 200, 200);
	mlx_put_image_to_window(display.mlx, display.window, display.img.img, 0, 0);
	ft_mlx_hooks(&display);
	mlx_loop(display.mlx);
	return (0);
}
*/
