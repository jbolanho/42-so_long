/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:38:18 by jbolanho          #+#    #+#             */
/*   Updated: 2024/02/28 16:38:18 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/include/get_next_line.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct player
{
	int			x;
	int			y;
	int			find_p;
}				t_player;

typedef struct collect
{
	int			total_leaves;
	int			collectible_leaves;
}				t_collect;

typedef struct sprites
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int32_t			x;
	int32_t			y;
}	t_sprites;

typedef struct map
{
	char		**matrix;
	char		**map_copy;
	char		*ptr;
	size_t		wid;
	size_t		hei;
	int			size;
	char		c[1];
	size_t		line;
	int			wrong_slot;
	int			find_e;
}				t_map;

typedef struct so_long
{
	t_player	player;
	t_map		map;
	t_collect	collectible;
	t_sprites	sprites;
	char		buffer[11];
	mlx_t		*mlx;
	t_sprites	*player_r1_data;
	t_sprites	*player_l1_data;
	t_sprites	*player_r2_data;
	t_sprites	*player_l2_data;
	t_sprites	*player_cr1_data;
	t_sprites	*player_cl1_data;
	t_sprites	*player_cr2_data;
	t_sprites	*player_cl2_data;
	t_sprites	*wall_data;
	t_sprites	*walledge_data;
	t_sprites	*bg_data;
	t_sprites	*collect_data;
	t_sprites	*exit_data;
	t_sprites	*exitopen_data;
	t_sprites	*enemy_data;
	t_sprites	*counter_data;
	int			collected;
	int			remove_collected;
	int			count_moves;
	char		side;
	int			enemyqtt;
	mlx_image_t	*txt_steps;
	mlx_image_t	*steps;
}				t_so_long;

void		initialize_struct(t_so_long *data);
void		check_arg(char *argv);
void		error_map(t_so_long *data);
void		ft_error(void);
void		ft_free_matrix(char **map);
void		check_map(t_so_long *data, char *map_name);
void		find_player_exit_collect(t_so_long *data);
void		check_player_exit_collect(t_so_long *data);
int			open_file(char *argv);
void		copy_map(t_so_long *data, char *argv);
void		check_matrix(t_so_long *data);
void		check_rectangle(t_so_long *data);
void		check_wall(t_so_long *data);
size_t		ft_len(const char *str);
void		ft_error_wall(t_so_long *data);
void		check_path(t_so_long *data);
void		find_player(t_so_long *data);
void		ft_flood_fill(t_so_long *data, int y, int x);
int			ft_check_flood_fill(char **map);
void		ft_mlx(t_so_long *data);
void		close_hook(void *param);
void		free_sprite(t_so_long *data, t_sprites *sprite);
void		all_images(t_so_long *data);
t_sprites	*init_images(t_so_long *data, char *path);
void		display_window(t_so_long *data);
int			put_collectible(t_so_long *data, int i, int j);
int			put_wall(t_so_long *data, int i, int j);
int			put_player(t_so_long *data);
int			put_exit(t_so_long *data, int i, int j);
void		ft_key_press(mlx_key_data_t keydata, void *param);
int			key_pressed(mlx_key_data_t keydata, keys_t k1, keys_t k2);
void		put_exit_again(t_so_long *data);
void		put_collectible_again(t_so_long *data);
int			valid_moves(t_so_long *data, char position, char op);
int			valid_position_x(t_so_long *data, char op);
int			valid_position_y(t_so_long *data, char op);
void		ft_animation(void *param);
int			put_counter(t_so_long *data);
void		player_animation(t_so_long *data, int time);
void		side_right(t_so_long *data);
void		side_left(t_so_long *data);
void		put_steps(t_so_long *data);
int			put_enemy(t_so_long *data, int i, int j);
int			touch_enemy(t_so_long *data);
void		player_moves(t_so_long *data, char mov);
void		put_player_again(t_so_long *data);
void		put_player_again2(t_so_long *data);
void		put_player_again3(t_so_long *data);
int			put_player_leaf(t_so_long *data);
void		resize_images(t_so_long *data);
void		player_moves2(t_so_long *data, char mov);
void		initial_struct2(t_so_long *data);

#endif