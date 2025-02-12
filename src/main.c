/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:05:36 by jbolanho          #+#    #+#             */
/*   Updated: 2024/02/28 11:05:36 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_so_long	data;
	size_t		i;

	if (argc != 2)
	{
		ft_printf("Error! Wrong arg!\n");
		return (1);
	}
	initialize_struct(&data);
	i = 0;
	check_arg(argv[1]);
	check_map(&data, argv[1]);
	copy_map(&data, argv[1]);
	check_matrix(&data);
	check_path(&data);
	ft_mlx(&data);
	return (0);
}
