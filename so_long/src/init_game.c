/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:10 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/03 16:24:02 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*allocate_memory(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Failed to allocate memory for the game");
	return (game);
}

void	load_img(t_game *game)
{
	load_png(game);
	texture_to_img(game);
	img_to_window(game);
	load_player(game);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map.width * 64, \
		game->map.height * 64, "so_long", false);
	if (!game->mlx)
		ft_error("Failed to initialise the mlx");
	load_img(game);
}
