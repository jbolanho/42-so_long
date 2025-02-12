/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves_valid_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:33:02 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/03 21:03:33 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	valid_moves(t_so_long *data, char position, char op)
{
	int	result;

	result = 0;
	if (position == 'x')
		result = valid_position_x(data, op);
	else if (position == 'y')
		result = valid_position_y(data, op);
	return (result);
}

int	valid_position_x(t_so_long *data, char op)
{
	if (op == '+'
		&& data->map.matrix[data->player.y][data->player.x + 1] != '1')
	{
		data->player.x++;
		data->count_moves++;
		ft_printf("Steps:%d\n", data->count_moves);
		put_steps(data);
		return (0);
	}
	else if (op == '-'
		&& data->map.matrix[data->player.y][data->player.x - 1] != '1')
	{
		data->player.x--;
		data->count_moves++;
		ft_printf("Steps:%d\n", data->count_moves);
		put_steps(data);
		return (0);
	}
	else
		return (1);
}

int	valid_position_y(t_so_long *data, char op)
{
	if (op == '+'
		&& data->map.matrix[data->player.y + 1][data->player.x] != '1')
	{
		data->player.y++;
		data->count_moves++;
		ft_printf("Steps:%d\n", data->count_moves);
		put_steps(data);
		return (0);
	}
	else if (op == '-'
		&& data->map.matrix[data->player.y - 1][data->player.x] != '1')
	{
		data->player.y--;
		data->count_moves++;
		ft_printf("Steps:%d\n", data->count_moves);
		put_steps(data);
		return (0);
	}
	else
		return (1);
}
