/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:23:55 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/29 10:23:13 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_status(t_game *game)
{
	game->status.has_player = 0;
	game->status.has_exit = 0;
	game->status.total_collectible = 0;
	game->status.collectible_collected = 0;
	game->status.exit_count = 0;
}
