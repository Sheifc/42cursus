/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:40:20 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/03 17:18:42 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game, int direction)
{
	move_player(game, direction);
	if (game->status.total_collectible == 0)
	{
		ft_printf("You are a winner");
		free_all(game);
		exit(EXIT_SUCCESS);
	}
}
