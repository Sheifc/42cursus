/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:27:51 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/02 00:50:31 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point size, \
	t_point begin, t_map_status *status)
{
	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return ;
	if (tab[begin.y][begin.x] == '1')
		return ;
	if (tab[begin.y][begin.x] == 'C')
		status->collectible_collected++;
	if (tab[begin.y][begin.x] == 'E')
		status->exit_count++;
	tab[begin.y][begin.x] = '1';
	flood_fill(tab, size, (t_point){begin.x - 1, begin.y}, status);
	flood_fill(tab, size, (t_point){begin.x + 1, begin.y}, status);
	flood_fill(tab, size, (t_point){begin.x, begin.y - 1}, status);
	flood_fill(tab, size, (t_point){begin.x, begin.y + 1}, status);
}

void	check_flood_fill(t_game *game)
{
	flood_fill(game->map.copy_map, \
		(t_point){game->map.width, game->map.height}, \
		game->player.position, &game->status);
	if (game->status.collectible_collected == game->status.total_collectible \
		&& game->status.exit_count == 1)
	{
		ft_printf("All collectibles collected and exit is reachable.\n");
		return ;
	}
	else
		ft_error("Map invalid or incomplete.\n");
}

void	check_game(t_game *game)
{
	copy_map(&game->map);
	check_flood_fill(game);
	free_map(game->map.copy_map, game->map.height);
}
