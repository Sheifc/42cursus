/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:11:29 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/29 09:59:22 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_content(t_game *game, char cell, int i, int j)
{
	if (cell == 'P')
	{
		if (!game->status.has_player)
		{
			save_player_position(game, i, j);
			game->status.has_player = 1;
		}
		else
			ft_error("Multiple playes found");
	}
	else if (cell == 'C')
		game->status.total_collectible += 1;
	else if (cell == 'E')
	{
		if (!game->status.has_exit)
			game->status.has_exit = 1;
		else
			ft_error("Multiple exits found");
	}
}
