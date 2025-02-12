/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:45:22 by jbolanho          #+#    #+#             */
/*   Updated: 2024/02/28 08:45:22 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_so_long *data, char *map_name)
{
	int		fd;
	int		r;

	fd = open_file(map_name);
	r = read(fd, data->map.c, 1);
	while (r > 0)
	{
		data->map.size++;
		find_player_exit_collect(data);
		r = read(fd, data->map.c, 1);
	}
	close(fd);
	check_player_exit_collect(data);
}

void	find_player_exit_collect(t_so_long *data)
{
	if (data->map.c[0] == 'P')
		data->player.find_p += 1;
	else if (data->map.c[0] == 'E')
		data->map.find_e += 1;
	else if (data->map.c[0] == 'C')
		data->collectible.total_leaves += 1;
	else if (data->map.c[0] == '\n')
		data->map.line += 1;
	else if (!(data->map.c[0] == 'C' || data->map.c[0] == 'P'
			|| data->map.c[0] == 'E' || data->map.c[0] == '1'
			|| data->map.c[0] == '0' || data->map.c[0] == '\n'
			|| data->map.c[0] == '\0' || data->map.c[0] == '\r'))
		data->map.wrong_slot++;
}

int	open_file(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file");
		exit(1);
	}
	return (fd);
}

void	check_player_exit_collect(t_so_long *data)
{
	if (data->collectible.total_leaves == 0)
	{
		ft_printf("Error. There are no colletibles.\n");
		exit(1);
	}
	if (data->player.find_p != 1)
	{
		ft_printf("Error. There is not just one player.\n");
		exit(1);
	}
	if (data->map.find_e != 1)
	{
		ft_printf("Error. There is not just one exit.\n");
		exit(1);
	}
	if (data->map.size < 17)
	{
		ft_printf("Error. Map is wrong.\n");
		exit(1);
	}
	if (data->map.wrong_slot != 0)
	{
		ft_printf("Error. Wrong slot.\n");
		exit(1);
	}
}
