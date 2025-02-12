/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:54:08 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/01 14:54:08 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	initialize_struct(t_so_long *data)
{
	data->player.x = 0;
	data->player.y = 0;
	data->player.find_p = 0;
	data->collectible.collectible_leaves = 0;
	data->collectible.total_leaves = 0;
	data->map.hei = 0;
	data->map.wid = 0;
	data->map.size = 0;
	data->map.c[0] = 0;
	data->map.line = 1;
	data->map.wrong_slot = 0;
	data->map.find_e = 0;
	data->collected = 0;
	data->remove_collected = 0;
	data->count_moves = 0;
	data->side = 0;
	data->enemyqtt = 0;
	initial_struct2(data);
}

void	initial_struct2(t_so_long *data)
{
	data->player_r1_data = NULL;
	data->player_l1_data = NULL;
	data->player_r2_data = NULL;
	data->player_l2_data = NULL;
	data->player_cr1_data = NULL;
	data->player_cl1_data = NULL;
	data->player_cr2_data = NULL;
	data->player_cl2_data = NULL;
	data->wall_data = NULL;
	data->walledge_data = NULL;
	data->bg_data = NULL;
	data->collect_data = NULL;
	data->exit_data = NULL;
	data->exitopen_data = NULL;
	data->enemy_data = NULL;
	data->counter_data = NULL;
	data->txt_steps = NULL;
	data->steps = NULL;
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
