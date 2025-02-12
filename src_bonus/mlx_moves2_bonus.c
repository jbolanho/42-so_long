/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:29:04 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/08 11:37:19 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	player_moves(t_so_long *data, char mov)
{
	if (mov == 's')
	{
		data->player_r1_data->img->instances[0].y += 64;
		data->player_l1_data->img->instances[0].y += 64;
		data->player_r2_data->img->instances[0].y += 64;
		data->player_l2_data->img->instances[0].y += 64;
		data->player_cr1_data->img->instances[0].y += 64;
		data->player_cl1_data->img->instances[0].y += 64;
		data->player_cr2_data->img->instances[0].y += 64;
		data->player_cl2_data->img->instances[0].y += 64;
	}
	else if (mov == 'w')
	{
		data->player_r1_data->img->instances[0].y -= 64;
		data->player_l1_data->img->instances[0].y -= 64;
		data->player_r2_data->img->instances[0].y -= 64;
		data->player_l2_data->img->instances[0].y -= 64;
		data->player_cr1_data->img->instances[0].y -= 64;
		data->player_cl1_data->img->instances[0].y -= 64;
		data->player_cr2_data->img->instances[0].y -= 64;
		data->player_cl2_data->img->instances[0].y -= 64;
	}
	player_moves2(data, mov);
}

void	player_moves2(t_so_long *data, char mov)
{
	if (mov == 'a')
	{
		data->side = 'l';
		data->player_r1_data->img->instances[0].x -= 64;
		data->player_l1_data->img->instances[0].x -= 64;
		data->player_r2_data->img->instances[0].x -= 64;
		data->player_l2_data->img->instances[0].x -= 64;
		data->player_cr1_data->img->instances[0].x -= 64;
		data->player_cl1_data->img->instances[0].x -= 64;
		data->player_cr2_data->img->instances[0].x -= 64;
		data->player_cl2_data->img->instances[0].x -= 64;
	}
	else if (mov == 'd')
	{
		data->side = 'r';
		data->player_r1_data->img->instances[0].x += 64;
		data->player_l1_data->img->instances[0].x += 64;
		data->player_r2_data->img->instances[0].x += 64;
		data->player_l2_data->img->instances[0].x += 64;
		data->player_cr1_data->img->instances[0].x += 64;
		data->player_cl1_data->img->instances[0].x += 64;
		data->player_cr2_data->img->instances[0].x += 64;
		data->player_cl2_data->img->instances[0].x += 64;
	}
	put_player_again(data);
}

void	put_player_again(t_so_long *data)
{
	if (data->collected == data->remove_collected)
	{
		put_player_again2(data);
	}
	put_player_again3(data);
}

void	put_player_again2(t_so_long *data)
{
	if (data->side == 'r')
	{
		data->player_r1_data->img->enabled = 1;
		data->player_r2_data->img->enabled = 0;
		data->player_l1_data->img->enabled = 0;
		data->player_l2_data->img->enabled = 0;
		data->player_cr1_data->img->enabled = 0;
		data->player_cl1_data->img->enabled = 0;
		data->player_cr2_data->img->enabled = 0;
		data->player_cl2_data->img->enabled = 0;
	}	
	else if (data->side == 'l')
	{
		data->player_r1_data->img->enabled = 0;
		data->player_r2_data->img->enabled = 0;
		data->player_l1_data->img->enabled = 1;
		data->player_l2_data->img->enabled = 0;
		data->player_cl1_data->img->enabled = 0;
		data->player_cl2_data->img->enabled = 0;
		data->player_cr1_data->img->enabled = 0;
		data->player_cr2_data->img->enabled = 0;
	}
}

void	put_player_again3(t_so_long *data)
{
	if (data->collected != data->remove_collected)
	{
		if (data->side == 'r')
		{
			data->player_r1_data->img->enabled = 0;
			data->player_r2_data->img->enabled = 0;
			data->player_l1_data->img->enabled = 0;
			data->player_l2_data->img->enabled = 0;
			data->player_cr1_data->img->enabled = 1;
			data->player_cr2_data->img->enabled = 0;
			data->player_cl1_data->img->enabled = 0;
			data->player_cl2_data->img->enabled = 0;
		}
		else if (data->side == 'l')
		{
			data->player_r1_data->img->enabled = 0;
			data->player_r2_data->img->enabled = 0;
			data->player_l1_data->img->enabled = 0;
			data->player_l2_data->img->enabled = 0;
			data->player_cl1_data->img->enabled = 1;
			data->player_cl2_data->img->enabled = 0;
			data->player_cr1_data->img->enabled = 0;
			data->player_cr2_data->img->enabled = 0;
		}
	}
}
