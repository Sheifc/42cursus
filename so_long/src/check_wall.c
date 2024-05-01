/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:04:47 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/28 10:11:21 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_top_wall(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' && map->grid[0][i] != '\n')
			ft_error("Top wall is not valid");
		i++;
	}
}

static void	check_bottom_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[map->height - 1][i] != '1' \
			&& map->grid[map->height - 1][i] != '\n')
			ft_error("Bottom wall is not valid");
		i++;
	}
}

static void	check_left_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1')
			ft_error("Left wall is not valid");
		i++;
	}
}

static void	check_right_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][map->width - 1] != '1')
			ft_error("Right wall is not valid");
		i++;
	}
}

void	check_wall(t_game *game)
{
	check_top_wall(&game->map);
	check_bottom_wall(&game->map);
	check_left_wall(&game->map);
	check_right_wall(&game->map);
}
