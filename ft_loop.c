/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:38:11 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/04 16:11:25 by pcrosnie         ###   ########.fr       */
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
//	void	*im;

	angles = (float *)malloc(sizeof(float) * 2);
	angles[0] = 1;
	angles[1] = 0.5;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "fdf");
//	im = mlx_new_image(im, 1000, 1000);
	ft_draw_vert(ptr, mlx, win);
	ft_draw(ptr, mlx, win);
	mlx_key_hook(win, ft_key_esc, ptr);
//	mlx_put_image_to_window(mlx, win, im, 0, 0);
	mlx_loop(mlx);
}
