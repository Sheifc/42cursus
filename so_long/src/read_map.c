/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:03:06 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/02 01:11:32 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	allocate_grid_memory(t_game	*game)
{
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		ft_error("Failed to allocate memory for grid");
}

static void	check_status(t_game *game)
{
	if (!game->status.has_player || !game->status.total_collectible || \
	!game->status.has_exit)
		ft_error("Map does not contain all required elements");
}

static void	copy_line(t_game *game, char *line, int i)
{
	game->map.grid[i] = ft_strdup(line);
	if (!game->map.grid[i])
		ft_error("Failed to duplicate line");
}

void	read_map(char *argv, t_game	*game)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	allocate_grid_memory(game);
	fd = open_file(argv);
	line = get_next_line(fd);
	while (line)
	{
		copy_line(game, line, i);
		j = 0;
		while (j < game->map.width)
		{
			check_map_content(game, game->map.grid[i][j], i, j);
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map.grid[i] = NULL;
	check_status(game);
	close(fd);
}
