/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reloading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:43:20 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/02 00:43:34 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reload_player(t_game *game)
{
	mlx_delete_texture(game->player_tex);
	mlx_delete_image(game->mlx, game->player_img);
	game->player_tex = mlx_load_png("./sprites/player.png");
	game->player_img = mlx_texture_to_image(game->mlx, game->player_tex);
	if (!game->player_img)
		return ;
	mlx_image_to_window(game->mlx, game->player_img,
		game->player.position.x * 64, game->player.position.y * 64);
}
