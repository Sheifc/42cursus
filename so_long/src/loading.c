/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:04:08 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/02 01:10:17 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_png(t_game *game)
{
	game->floor_tex = mlx_load_png("./sprites/floor.png");
	game->exit_tex = mlx_load_png("./sprites/exit.png");
	game->player_tex = mlx_load_png("./sprites/player.png");
	game->wall_tex = mlx_load_png("./sprites/wall.png");
	game->collect_tex = mlx_load_png("./sprites/collect.png");
	if (!game->floor_tex || !game->exit_tex \
		|| !game->player_tex || !game->wall_tex \
		|| !game->collect_tex)
		return ;
}

static void	texture_to_img(t_game *game)
{
	game->floor_img = mlx_texture_to_image(game->mlx, game->floor_tex);
	game->exit_img = mlx_texture_to_image(game->mlx, game->exit_tex);
	game->player_img = mlx_texture_to_image(game->mlx, game->player_tex);
	game->wall_img = mlx_texture_to_image(game->mlx, game->wall_tex);
	game->collect_img = mlx_texture_to_image(game->mlx, game->collect_tex);
	if (!game->floor_img || !game->exit_img
		|| !game->player_img || !game->wall_img || !game->collect_img)
		return ;
}

static void	check_cell(t_game *game, int *x, int *y)
{
	if (game->map.grid[*y][*x] == '0' || game->map.grid[*y][*x] == 'C'
		|| game->map.grid[*y][*x] == 'P')
		mlx_image_to_window(game->mlx, game->floor_img, \
		*x * IMG, *y * IMG);
	if (game->map.grid[*y][*x] == '1')
		mlx_image_to_window(game->mlx, game->wall_img, \
		*x * IMG, *y * IMG);
	if (game->map.grid[*y][*x] == 'C')
		mlx_image_to_window(game->mlx, game->collect_img, \
		*x * IMG, *y * IMG);
	if (game->map.grid[*y][*x] == 'E')
		mlx_image_to_window(game->mlx, game->exit_img, \
		*x * IMG, *y * IMG);
}

static void	img_to_window(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			check_cell(game, &x, &y);
			x++;
		}
		y++;
	}
}

static void	load_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player_img, \
					x * IMG, y * IMG);
			x++;
		}
		y++;
	}
}

void	load_img(t_game *game)
{
	load_png(game);
	texture_to_img(game);
	img_to_window(game);
	load_player(game);
}
