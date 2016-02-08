/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:38:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/08 14:29:28 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int     ft_key_esc(int keycode, t_data *ptr)
{
	if (keycode == 53)
		exit(0);
	(keycode == 123) ? ptr->angles[0] += 0.1 : 0;
	(keycode == 124) ? ptr->angles[0] -= 0.1 : 0;
	(keycode == 125) ? ptr->angles[1] += 0.1 : 0;
	(keycode == 126) ? ptr->angles[1] -= 0.1 : 0;
	if (ptr->angles[0] < 0.1)
		ptr->angles[0] = 2 * M_PI;
	if (ptr->angles[1] < 0.1)
		ptr->angles[1] = 2 * M_PI;
	printf("%f !! %f\n", cos(ptr->angles[0]), cos(ptr->angles[1]));
	mlx_clear_window(ptr->mlx, ptr->win);
	ft_draw_vert(ptr, ptr->mlx, ptr->win, ptr->angles);
	ft_draw(ptr, ptr->mlx, ptr->win, ptr->angles);
	return (0);
}

void	ft_loop(t_data *ptr)
{
	ptr->angles = (float *)malloc(sizeof(float) * 2);
	ptr->angles[0] = 3.14;
	ptr->angles[1] = M_PI_2;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1000, 1000, "fdf");
	ft_draw_vert(ptr, ptr->mlx, ptr->win, ptr->angles);
	ft_draw(ptr, ptr->mlx, ptr->win, ptr->angles);
	mlx_key_hook(ptr->win, ft_key_esc, ptr);
	mlx_loop(ptr->mlx);
}
