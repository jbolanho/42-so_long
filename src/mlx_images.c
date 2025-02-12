/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:12:25 by jbolanho          #+#    #+#             */
/*   Updated: 2024/04/03 20:55:15 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	all_images(t_so_long *data)
{
	data->player_data = init_images(data, "./textures/t_F1.png");
	data->wall_data = init_images(data, "./textures/wall.png");
	data->walledge_data = init_images(data, "./textures/walledge.png");
	data->exit_data = init_images(data, "./textures/exitclosed.png");
	data->exitopen_data = init_images(data, "./textures/exitopen.png");
	data->exitopen_data->img->enabled = 0;
	data->bg_data = init_images(data, "./textures/background.png");
	data->collect_data = init_images(data, "./textures/leaf.png");
	mlx_resize_image(data->bg_data->img, (64 * data->map.wid),
		(64 * data->map.hei));
	mlx_resize_image(data->exit_data->img, 32, 64);
	mlx_resize_image(data->exitopen_data->img, 128, 64);
	mlx_resize_image(data->collect_data->img, 64, 64);
	mlx_resize_image(data->wall_data->img, 64, 64);
	mlx_resize_image(data->walledge_data->img, 64, 64);
	mlx_resize_image(data->player_data->img, 64, 64);
}

t_sprites	*init_images(t_so_long *data, char *path)
{
	t_sprites	*sprite;

	sprite = ft_calloc(sizeof(t_sprites), 1);
	if (!sprite)
		return (NULL);
	sprite->texture = mlx_load_png(path);
	sprite->img = mlx_texture_to_image(data->mlx, sprite->texture);
	if (!sprite->img)
		return (NULL);
	return (sprite);
}
