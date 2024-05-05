/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:17:08 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/03 17:06:11 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	ft_strlen_sl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Could not open the file");
	return (fd);
}

void	copy_map(t_map *map)
{
	int		i;

	i = 0;
	map->copy_map = malloc(sizeof(char *) * map->height);
	if (!map->copy_map)
		ft_error("Failed to allocate memory for map copy");
	while (i < map->height)
	{
		map->copy_map[i] = ft_strdup(map->grid[i]);
		if (!map->copy_map[i])
			ft_error("Failed to allocate memory for map row");
		i++;
	}
}
