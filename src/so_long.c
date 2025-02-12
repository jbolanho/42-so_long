/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:44:12 by jbolanho          #+#    #+#             */
/*   Updated: 2024/02/29 09:44:12 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initialize_struct(t_so_long *data)
{
	data->collectible.collectible_leaves = 0;
	data->collectible.total_leaves = 0;
	data->map.find_e = 0;
	data->player.find_p = 0;
	data->map.hei = 0;
	data->map.wid = 0;
	data->map.line = 1;
	data->map.size = 0;
	data->map.c[0] = 0;
	data->map.wrong_slot = 0;
	data->player.x = 0;
	data->player.y = 0;
	data->count_moves = 0;
	data->collected = 0;
	data->remove_collected = 0;
}

void	check_arg(char *argv)
{
	int		i;
	char	*tmp;

	tmp = argv;
	i = ft_strlen(tmp) - 4;
	if (ft_strncmp((".ber"), &tmp[i], 4) != 0)
	{
		ft_printf("Error! Wrong arg! Try another map name.\n");
		exit(1);
	}
}

void	ft_error(void)
{
	ft_printf("The window has an error.\n");
	exit(1);
}

void	ft_free_matrix(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
