/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:15:27 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/03 21:22:45 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	display_window(t_so_long *data)
{
	int	i;
	int	j;

	i = 0;
	if (mlx_image_to_window(data->mlx, data->bg_data->img, 0, 0) < 0)
		ft_error();
	while (data->map.matrix[i])
	{
		j = 0;
		while (data->map.matrix[i][j])
		{
			if (data->map.matrix[i][j] == 'E')
				put_exit(data, i, j);
			if (data->map.matrix[i][j] == '1')
				put_wall(data, i, j);
			if (data->map.matrix[i][j] == 'C')
				put_collectible(data, i, j);
			if (data->map.matrix[i][j] == 'A')
				put_enemy(data, i, j);
			j++;
		}
		i++;
	}
	put_counter(data);
	put_player(data);
}

int	put_collectible(t_so_long *data, int i, int j)
{
	data->collected++;
	data->remove_collected++;
	if (mlx_image_to_window(data->mlx, data->collect_data->img,
			(j * 64), (i * 64)) < 0)
		ft_error();
	return (0);
}

int	put_wall(t_so_long *data, int i, int j)
{
	if (j == 0 || j == (int)(data->map.wid - 1)
	|| i == 0 || i == (int)(data->map.hei - 1))
	{
		if (mlx_image_to_window(data->mlx, data->walledge_data->img,
				(j * 64), (i * 64)) < 0)
			ft_error();
	}
	else
	{
		if (mlx_image_to_window(data->mlx, data->wall_data->img,
				(j * 64), (i * 64)) < 0)
			ft_error();
	}
	return (0);
}

int	put_player(t_so_long *data)
{
	if (mlx_image_to_window(data->mlx, data->player_r1_data->img,
			(data->player.x * 64), (data->player.y * 64)) < 0)
		ft_error();
	if (mlx_image_to_window(data->mlx, data->player_l1_data->img,
			(data->player.x * 64), (data->player.y * 64)) < 0)
		ft_error();
	if (mlx_image_to_window(data->mlx, data->player_r2_data->img,
			(data->player.x * 64), (data->player.y * 64)) < 0)
		ft_error();
	if (mlx_image_to_window(data->mlx, data->player_l2_data->img,
			(data->player.x * 64), (data->player.y * 64)) < 0)
		ft_error();
	data->player_r1_data->x = data->player.x;
	data->player_r1_data->y = data->player.y;
	data->player_l1_data->x = data->player.x;
	data->player_l1_data->y = data->player.y;
	data->player_r2_data->x = data->player.x;
	data->player_r2_data->y = data->player.y;
	data->player_l2_data->x = data->player.x;
	data->player_l2_data->y = data->player.y;
	put_player_leaf(data);
	return (0);
}

int	put_player_leaf(t_so_long *data)
{
	if (mlx_image_to_window(data->mlx, data->player_cr1_data->img,
			(data->player.x * 64), (data->player.y * 64)) < 0)
		ft_error();
	if (mlx_image_to_window(data->mlx, data->player_cl1_data->img,
			(data->player.x * 64), (data->player.y * 64)) < 0)
		ft_error();
	if (mlx_image_to_window(data->mlx, data->player_cr2_data->img,
			(data->player.x * 64), (data->player.y * 64)) < 0)
		ft_error();
	if (mlx_image_to_window(data->mlx, data->player_cl2_data->img,
			(data->player.x * 64), (data->player.y * 64)) < 0)
		ft_error();
	data->player_cr1_data->x = data->player.x;
	data->player_cr1_data->y = data->player.y;
	data->player_cl1_data->x = data->player.x;
	data->player_cl1_data->y = data->player.y;
	data->player_cr2_data->x = data->player.x;
	data->player_cr2_data->y = data->player.y;
	data->player_cl2_data->x = data->player.x;
	data->player_cl2_data->y = data->player.y;
	return (0);
}
