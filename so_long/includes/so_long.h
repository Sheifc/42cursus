/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:07:34 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/02 01:16:43 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "structures.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"

// ------------ UTILS -------------------------------------
void	ft_error(char *msg);
int		ft_strlen_sl(char *s);
int		open_file(char *argv);
void	copy_map(t_map *map);
void	free_map(char **grid, int height);
void	free_map_txt(t_game *game);
void	free_all(t_game	*game);

// ------------ CHECKS ------------------------------------
void	check_arg(char *argv, t_game *game);
void	init_status(t_game *game);
void	check_map_content(t_game *game, char cell, int i, int j);
void	read_map(char *argv, t_game	*game);
void	check_wall(t_game *game);
void	check_game(t_game *game);
void	flood_fill(char **tab, t_point size, \
			t_point begin, t_map_status *status);
void	check_flood_fill(t_game *game);

// ----------- GAME ----------------------------
void	save_player_position(t_game *game, int i, int j);
t_game	*allocate_memory(void);
void	init_game(t_game *game);
void	ft_exit(t_game *game, int direction);

// ----------- MLX ----------------------------------------
void	load_img(t_game *game);
void	ft_move(t_game *game, int direction, int y, int x);
void	init_key_hook(mlx_key_data_t keydata, void *game);
void	move_player(t_game *game, int direction);
void	reload_player(t_game *game);


#endif