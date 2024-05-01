/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:40:20 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/02 00:46:07 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game, int direction)
{
	if (game->status.total_collectible == 0)
	{
		move_player(game, direction);
		ft_printf("Game Over");
		free_all(game);
		exit(EXIT_SUCCESS);
	}
}
