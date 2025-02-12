/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:11:10 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/03 20:56:01 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_key_press(mlx_key_data_t keydata, void *param)
{
	t_so_long	*data;

	data = (t_so_long *)param;
	if (key_pressed(keydata, MLX_KEY_ESCAPE, MLX_KEY_ESCAPE))
	{
		close_hook(data);
		return ;
	}
	if (key_pressed(keydata, MLX_KEY_W, MLX_KEY_UP))
		if (valid_moves(data, 'y', '-') == 0)
			data->player_data->img->instances[0].y -= 64;
	if (key_pressed(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		if (valid_moves(data, 'y', '+') == 0)
			data->player_data->img->instances[0].y += 64;
	if (key_pressed(keydata, MLX_KEY_A, MLX_KEY_LEFT))
		if (valid_moves(data, 'x', '-') == 0)
			data->player_data->img->instances[0].x -= 64;
	if (key_pressed(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
		if (valid_moves(data, 'x', '+') == 0)
			data->player_data->img->instances[0].x += 64;
	put_collectible_again(data);
	put_exit_again(data);
	return ;
}

int	key_pressed(mlx_key_data_t keydata, keys_t k1, keys_t k2)
{
	return ((keydata.key == k1 || keydata.key == k2)
		&& keydata.action == MLX_PRESS);
}	

void	put_exit_again(t_so_long *data)
{
	if (data->remove_collected == 0)
	{
		mlx_delete_image(data->mlx, data->exit_data->img);
		data->exitopen_data->img->enabled = 1;
	}
	if ((data->player_data->img->instances->x
			== data->exitopen_data->img->instances->x)
		&& (data->player_data->img->instances->y
			== data->exitopen_data->img->instances->y)
		&& data->exitopen_data->img->enabled == 1)
		close_hook(data);
}

void	put_collectible_again(t_so_long *data)
{
	int	i;

	i = 0;
	while (i < data->collected)
	{
		if ((data->player_data->img->instances->x
				== data->collect_data->img->instances[i].x)
			&& (data->player_data->img->instances->y
				== data->collect_data->img->instances[i].y))
		{
			if (data->collect_data->img->instances[i].enabled)
			{
				data->collect_data->img->instances[i].enabled = false;
				data->remove_collected--;
			}
		}
		i++;
	}
}
