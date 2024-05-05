/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:06:14 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/05 12:15:48 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = allocate_memory();
		check_arg(argv[1], game);
		init_status(game);
		read_map(argv[1], game);
		check_wall(game);
		check_game(game);
		init_game(game);
		mlx_key_hook(game->mlx, &init_key_hook, game);
		mlx_loop(game->mlx);
		free_map(game->map.grid, game->map.height);
		free(game);
		mlx_terminate(game->mlx);
	}
	else
		ft_error("The number of arguments is not valid");
	return (0);
}
