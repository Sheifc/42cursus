/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:56:22 by sheferna          #+#    #+#             */
/*   Updated: 2024/05/01 21:05:14 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "../MLX42/include/MLX42/MLX42.h"

// Window dimensions
# define WIDTH 800
# define HEIGHT 600
// sprite dimension
# define IMG 64

typedef enum e_move
{
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
}	t_move;

// flood fill
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_point		x_door;
	t_point		y_door;
	char		**copy_map;
}	t_map;

typedef struct s_player
{
	t_point	position;
	int		move_count;
}	t_player;

typedef struct s_map_status
{
	int	has_player;
	int	has_exit;
	int	total_collectible;
	int	collectible_collected;
	int	exit_count;
}	t_map_status;

typedef struct s_game
{
	t_map			map;
	t_player		player;
	t_map_status	status;
	mlx_t			*mlx;
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*player_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*collect_img;
	mlx_texture_t	*floor_tex;
	mlx_texture_t	*wall_tex;
	mlx_texture_t	*player_tex;
	mlx_texture_t	*exit_tex;
	mlx_texture_t	*collect_tex;
}	t_game;

#endif