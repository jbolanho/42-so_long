/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:54:33 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/03 19:11:14 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_animation(void *param)
{
	t_so_long	*data;
	int			time;

	data = (t_so_long *)param;
	time = (int)(mlx_get_time() * 100);
	player_animation(data, time);
}

void	player_animation(t_so_long *data, int time)
{
	if (time % 13 == 1)
	{
		if (data->side == 'r')
			side_right(data);
		else if (data->side == 'l')
			side_left(data);
	}
}

void	side_right(t_so_long *data)
{
	if (data->player_r1_data->img->enabled == 1)
	{
		data->player_r1_data->img->enabled = 0;
		data->player_r2_data->img->enabled = 1;
	}
	else if (data->player_r2_data->img->enabled == 1)
	{
		data->player_r2_data->img->enabled = 0;
		data->player_r1_data->img->enabled = 1;
	}
	else if (data->player_cr1_data->img->enabled == 1)
	{
		data->player_cr1_data->img->enabled = 0;
		data->player_cr2_data->img->enabled = 1;
	}
	else if (data->player_cr2_data->img->enabled == 1)
	{
		data->player_cr2_data->img->enabled = 0;
		data->player_cr1_data->img->enabled = 1;
	}
}

void	side_left(t_so_long *data)
{
	if (data->player_l1_data->img->enabled == 1)
	{
		data->player_l1_data->img->enabled = 0;
		data->player_l2_data->img->enabled = 1;
	}
	else if (data->player_l2_data->img->enabled == 1)
	{
		data->player_l2_data->img->enabled = 0;
		data->player_l1_data->img->enabled = 1;
	}
	else if (data->player_cl1_data->img->enabled == 1)
	{
		data->player_cl1_data->img->enabled = 0;
		data->player_cl2_data->img->enabled = 1;
	}
	else if (data->player_cl2_data->img->enabled == 1)
	{
		data->player_cl2_data->img->enabled = 0;
		data->player_cl1_data->img->enabled = 1;
	}
}
