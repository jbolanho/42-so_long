/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:53:53 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/01 14:53:53 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_path(t_so_long *data)
{
	find_player(data);
	ft_flood_fill(data, data->player.x, data->player.y);
	if (ft_check_flood_fill(data->map.map_copy) == 1)
	{
		ft_printf("Error. Floodfill.");
		ft_free_matrix(data->map.map_copy);
		ft_free_matrix(data->map.matrix);
		exit(1);
	}
	ft_free_matrix(data->map.map_copy);
}

void	find_player(t_so_long *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map.map_copy[i] != NULL)
	{
		j = 0;
		while (data->map.map_copy[i][j] != '\0')
		{
			if (data->map.map_copy[i][j] == 'P')
			{
				data->player.x = i;
				data->player.y = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_so_long *data, int y, int x)
{
	int	height;
	int	widht;

	height = data->map.hei;
	widht = data->map.wid;
	if ((x > 0 && y > 0 && x < widht && y < height
			&& data->map.map_copy[y][x] != '1'
		&& data->map.map_copy[y][x] != 'X'
		&& data->map.map_copy[y][x] != 'A'))
	{
		data->map.map_copy[y][x] = 'X';
		ft_flood_fill(data, y + 1, x);
		ft_flood_fill(data, y - 1, x);
		ft_flood_fill(data, y, x + 1);
		ft_flood_fill(data, y, x - 1);
	}
}

int	ft_check_flood_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E'
				|| map[i][j] == 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
