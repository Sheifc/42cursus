/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:23:09 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/02 00:49:52 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ismap_ber(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (ft_strncmp(argv + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

static void	check_dimensions(char *argv, t_game	*game)
{
	char	*line;
	int		fd;

	game->map.height = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Could not open the file");
	line = get_next_line(fd);
	if (line == NULL)
		ft_error("Map is empty");
	game->map.width = ft_strlen_sl(line);
	while (line)
	{
		if (game->map.width != ft_strlen_sl(line))
			ft_error("Width is not valid");
		game->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	check_arg(char *argv, t_game *game)
{
	if (ismap_ber(argv) == 0)
		ft_error("The map is not .ber");
	check_dimensions(argv, game);
}
