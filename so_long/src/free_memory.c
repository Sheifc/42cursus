/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:34:29 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/02 11:34:55 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
