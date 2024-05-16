/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:42:57 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/03 13:35:36 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_key_hook(mlx_key_data_t keydata, void *game)
{
	t_game	*aux;

	aux = game;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		ft_move(aux, UP, aux->player.position.y - 1, aux->player.position.x);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		ft_move(aux, DOWN, aux->player.position.y + 1, aux->player.position.x);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_move(aux, RIGHT, aux->player.position.y, aux->player.position.x + 1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_move(aux, LEFT, aux->player.position.y, aux->player.position.x - 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}
