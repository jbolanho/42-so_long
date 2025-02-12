/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:01:58 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/08 15:03:17 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_matrix(t_so_long *data)
{
	int	i;

	i = 0;
	while (data->map.matrix[i] != NULL)
	{
		check_rectangle(data);
		check_wall(data);
		i++;
	}
}

void	check_rectangle(t_so_long *data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_len(data->map.matrix[0]);
	data->map.wid = len;
	while (data->map.matrix[i] != NULL)
	{
		if ((ft_len(data->map.matrix[i])) != len)
		{
			ft_printf("Error. No rectangle.\n");
			ft_free_matrix(data->map.matrix);
			ft_free_matrix(data->map.map_copy);
			exit(1);
		}	
		else
			i++;
	}
	data->map.hei = i;
}

size_t	ft_len(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n' && str[i] != '\r')
		i++;
	return (i);
}

void	check_wall(t_so_long *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.matrix[i])
	{
		if (data->map.matrix[i][0] != '1')
			ft_error_wall(data);
		if (data->map.matrix[i][data->map.wid - 1] != '1')
			ft_error_wall(data);
		i++;
	}
	while (j < data->map.wid)
	{
		if (data->map.matrix[0][j] != '1')
			ft_error_wall(data);
		if (data->map.matrix[data->map.hei - 1][j] != '1')
			ft_error_wall(data);
		j++;
	}
}

void	ft_error_wall(t_so_long *data)
{
	ft_free_matrix(data->map.matrix);
	ft_free_matrix(data->map.map_copy);
	ft_printf("Error. Wall error.\n");
	exit(1);
}
