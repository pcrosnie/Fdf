/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:38:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/02 14:09:11 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     ft_key_esc(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_loop(void)
{
	void	*mlx;
	void	*win;
	float *x;
	float *y;

	x = (float *)malloc(sizeof(float) * 2);
	y = (float *)malloc(sizeof(float) * 2);
	x[0] = 800;
	x[1] = 387;
	y[0] = 100;
	y[1] = 100;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "fdf");
	ft_connect(x, y, mlx, win);
	mlx_key_hook(win, ft_key_esc, 0);
	mlx_loop(mlx);
}
