/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:15:27 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/03 20:52:53 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	display_window(t_so_long *data)
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
			j++;
		}
		i++;
	}
	put_player(data);
	return (0);
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
	if (mlx_image_to_window(data->mlx, data->player_data->img,
			(data->player.x * 64), (data->player.y * 64)) < 0)
		ft_error();
	data->player_data->x = data->player.x;
	data->player_data->y = data->player.y;
	return (0);
}

int	put_exit(t_so_long *data, int i, int j)
{
	if (mlx_image_to_window(data->mlx, data->exit_data->img,
			(j * 64), (i * 64)) < 0)
		ft_error();
	if (mlx_image_to_window(data->mlx, data->exitopen_data->img,
			(j * 64), (i * 64)) < 0)
		ft_error();
	return (0);
}
