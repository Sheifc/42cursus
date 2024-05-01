/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:15:37 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/02 00:47:25 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	calculate_new_position(t_game *game, int direction, \
	int	*new_x, int	*new_y)
{
	*new_x = game->player.position.x;
	*new_y = game->player.position.y;
	if (direction == UP)
		(*new_y)--;
	else if (direction == DOWN)
		(*new_y)++;
	else if (direction == RIGHT)
		(*new_x)++;
	else if (direction == LEFT)
		(*new_x)--;
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	char	cell;

	if (new_x < 0 || new_x >= game->map.width || new_y < 0 \
		|| new_y >= game->map.height)
		return ;
	cell = game->map.grid[new_y][new_x];
	if (cell == '1')
		return ;
	if (cell == 'C')
	{
		game->status.collectible_collected++;
		game->map.grid[new_y][new_x] = '0';
	}
	game->map.grid[game->player.position.y][game->player.position.x] = '0';
	game->player.position.x = new_x;
	game->player.position.y = new_y;
	game->map.grid[new_y][new_x] = 'P';
	game->player_img->instances[0].x = new_x * IMG;
	game->player_img->instances[0].y = new_y * IMG;
	game->player.move_count++;
}

void	move_player(t_game *game, int direction)
{
	int	new_x;
	int	new_y;

	calculate_new_position(game, direction, &new_x, &new_y);
	update_player_position(game, new_x, new_y);
}

void	ft_move(t_game *game, int direction, int y, int x)
{
	if (y < game->map.height && x < game->map.width && y >= 0 && x >= 0)
	{
		if (game->map.grid[y][x] == '1')
			return ;
		else if (game->map.grid[y][x] == 'C')
		{
			game->map.grid[y][x] = '0';
			game->status.total_collectible--;
			if (mlx_image_to_window(game->mlx,
					game->floor_img, x * IMG, y * IMG) < 0)
				ft_error("Failed rendering floor.");
			if (game->status.total_collectible == 0)
				game->status.exit_count = 1;
			reload_player(game);
			move_player(game, direction);
		}
		else if (game->map.grid[y][x] == 'E')
			ft_exit(game, direction);
		else
			move_player(game, direction);
	}
}
