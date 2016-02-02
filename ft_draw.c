/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:44:54 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/02 16:00:17 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_data *ptr, void *mlx, void *win, float *angles)
{
	float *x;
	float *y;
	int i;
	int j;

	i = 0;
	x = (float *)malloc(sizeof(float) * 2);
	y = (float *)malloc(sizeof(float) * 2);
	while (i < ptr->index)
	{
		j = 0;
		while (j + 1 < ptr->width)
		{
			x[0] = 500 + 3 * (cos(angles[0]) * i * 10 + (sin(angles[1]) * j * 10));
			x[1] = 500 + 3 * (cos(angles[0]) * i * 10 + (sin(angles[1]) * (j + 1) * 10));
			y[0] = 500 + 3 * (sin(angles[1]) * ((sin(angles[0]) * i * 10) + (cos(angles[0]) * j * 10)) - (cos(angles[1]) * ptr->entry[i][j]));
			y[1] = 500 + 3 * (sin(angles[1]) * ((sin(angles[0]) * i * 10) + (cos(angles[0]) * (j + 1) * 10)) - (cos(angles[1]) * ptr->entry[i][j + 1]));
			ft_connect(x, y, mlx, win);
			j++;
		}
		i++;
	}
}

void    ft_draw_vert(t_data *ptr, void *mlx, void *win, float *angles)
{
	float *x;
	float *y;
	int i;
	int j;

	i = 0;
	x = (float *)malloc(sizeof(float) * 2);
	y = (float *)malloc(sizeof(float) * 2);
	while (i + 1 < ptr->index)
	{
		j = 0;
		while (j < ptr->width)
		{
			x[0] = 500 + 3 * (cos(angles[0]) * i * 10 + (sin(angles[1]) * j * 10));
			x[1] = 500 + 3 * (cos(angles[0]) * (i + 1) * 10 + (sin(angles[1]) * j * 10));
			y[0] = 500 + 3 * (sin(angles[1]) * ((sin(angles[0]) * i * 10) + (cos(angles[0]) * j * 10)) - (cos(angles[1]) * ptr->entry[i][j]));
			y[1] = 500 + 3 * (sin(angles[1]) * ((sin(angles[0]) * (i + 1) * 10) + (cos(angles[0]) * j * 10)) - (cos(angles[1]) * ptr->entry[i + 1][j]));
			ft_connect(x, y, mlx, win);
			j++;
		}
		i++;
	}
}
