/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:08:00 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/03 21:09:54 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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

int	put_enemy(t_so_long *data, int i, int j)
{
	if (mlx_image_to_window(data->mlx, data->enemy_data->img,
			(j * 64), (i * 64)) < 0)
		ft_error();
	return (0);
}

int	put_counter(t_so_long *data)
{
	if (mlx_image_to_window(data->mlx, data->counter_data->img, 0, 0) < 0)
		ft_error();
	data->txt_steps = mlx_put_string(data->mlx, "Steps:", 23, 22);
	put_steps(data);
	return (0);
}

void	put_steps(t_so_long *data)
{
	char	*steps;

	if (data->steps)
		mlx_delete_image(data->mlx, data->steps);
	steps = ft_itoa(data->count_moves);
	data->steps = mlx_put_string(data->mlx, steps, 85, 23);
	free(steps);
}
