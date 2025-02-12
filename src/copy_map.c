/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:49:14 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/01 10:56:59 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	copy_map(t_so_long *data, char *argv)
{
	int		fd;
	int		buff;
	char	*temp;

	fd = open_file(argv);
	data->map.ptr = ft_strdup("");
	buff = read(fd, data->buffer, 10);
	if (buff == -1)
		ft_printf("Error reading file");
	while (buff > 0)
	{
		data->buffer[buff] = '\0';
		temp = ft_strjoin(data->map.ptr, data->buffer);
		free(data->map.ptr);
		data->map.ptr = temp;
		buff = read(fd, data->buffer, 10);
	}
	if (buff == -1)
		error_map(data);
	data->map.matrix = ft_split(data->map.ptr, '\n');
	data->map.map_copy = ft_split(data->map.ptr, '\n');
	close(fd);
	free(data->map.ptr);
}

void	error_map(t_so_long *data)
{
	ft_printf("The map has an error.\n");
	free(data->map.ptr);
	exit(1);
}
