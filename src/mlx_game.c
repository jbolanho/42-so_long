/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:13:08 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/01 15:23:09 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_mlx(t_so_long *data)
{
	int	wid;
	int	hei;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	wid = 64 * data->map.wid;
	hei = 64 * data->map.hei;
	data->mlx = mlx_init(wid, hei, "Poporo", true);
	if (!data->mlx)
	{
		ft_printf("Error. MLX init error.\n");
		exit(1);
	}
	all_images(data);
	display_window(data);
	mlx_key_hook(data->mlx, ft_key_press, data);
	mlx_close_hook(data->mlx, close_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

void	close_hook(void *param)
{
	t_so_long	*data;

	data = (t_so_long *)param;
	ft_free_matrix(data->map.matrix);
	free_sprite(data, data->bg_data);
	free_sprite(data, data->player_data);
	free_sprite(data, data->collect_data);
	free_sprite(data, data->exit_data);
	free_sprite(data, data->exitopen_data);
	free_sprite(data, data->wall_data);
	free_sprite(data, data->walledge_data);
	mlx_close_window(data->mlx);
}

void	free_sprite(t_so_long *data, t_sprites *sprite)
{
	mlx_delete_image(data->mlx, sprite->img);
	mlx_delete_texture(sprite->texture);
	free(sprite);
}
