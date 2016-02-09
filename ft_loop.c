/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:38:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/09 14:43:26 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_key_esc(int keycode, t_data *ptr)
{
	if (keycode == 53)
		exit(0);
	(keycode == 123) ? ptr->angles[0] += 0.1 : 0;
	(keycode == 124) ? ptr->angles[0] -= 0.1 : 0;
	(keycode == 126) ? ptr->angles[1] += 0.1 : 0;
	(keycode == 125) ? ptr->angles[1] -= 0.1 : 0;
	(keycode == 34) ? ptr->scale += 1 : 0;
	(keycode == 31) ? ptr->scale -= 1 : 0;
	mlx_clear_window(ptr->mlx, ptr->win);
	ft_draw_vert(ptr);
	ft_draw(ptr);
	return (0);
}

void	ft_loop(t_data *ptr)
{
	ptr->angles = (float *)malloc(sizeof(float) * 2);
	ptr->scale = 100 / ((ptr->width + ptr->index) / 5);
	ptr->angles[0] = 3.14;
	ptr->angles[1] = M_PI_2;
	ptr->tmp_color = 2000000000;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1000, 1000, "fdf");
	ft_draw_vert(ptr);
	ft_draw(ptr);
	mlx_key_hook(ptr->win, ft_key_esc, ptr);
	mlx_loop(ptr->mlx);
}
