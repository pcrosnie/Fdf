/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:38:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/02 16:02:27 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     ft_key_esc(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_loop(t_data *ptr)
{
	void	*mlx;
	void	*win;
	float	*angles;

	angles = (float *)malloc(sizeof(float) * 2);
	angles[0] = 1.45;
	angles[1] = 0.23;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "fdf");
	ft_draw(ptr, mlx, win, angles);
	ft_draw_vert(ptr, mlx, win, angles);
	mlx_key_hook(win, ft_key_esc, 0);
	mlx_loop(mlx);
}
