/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:17:08 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/01 10:59:04 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	ft_strlen_sl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Could not open the file");
	return (fd);
}

void	copy_map(t_map *map)
{
	int		i;

	i = 0;
	map->copy_map = malloc(sizeof(char *) * map->height);
	if (!map->copy_map)
		ft_error("Failed to allocate memory for map copy");
	while (i < map->height)
	{
		map->copy_map[i] = ft_strdup(map->grid[i]);
		if (!map->copy_map[i])
			ft_error("Failed to allocate memory for map row");
		i++;
	}
}

void	free_map(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

void	free_map_txt(t_game *game)
{
	if (game->collect_tex)
		mlx_delete_texture(game->collect_tex);
	if (game->floor_tex)
		mlx_delete_texture(game->floor_tex);
	if (game->wall_img)
		mlx_delete_texture(game->wall_tex);
	if (game->player_tex)
		mlx_delete_texture(game->player_tex);
	if (game->exit_tex)
		mlx_delete_texture(game->exit_tex);
	if (game->exit_img)
		mlx_delete_image(game->mlx, game->exit_img);
	if (game->wall_img)
		mlx_delete_image(game->mlx, game->exit_img);
	if (game->floor_img)
		mlx_delete_image(game->mlx, game->exit_img);
	if (game->collect_img)
		mlx_delete_image(game->mlx, game->exit_img);
	if (game->player_img)
		mlx_delete_image(game->mlx, game->player_img);
}

void	free_all(t_game	*game)
{
	if (game)
	{
		if (game->map.grid)
			free_map(game->map.grid, game->map.height);
		if (game)
			free_map_txt(game);
		free(game);
	}
}
