/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:44:54 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/04 16:11:03 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_data *ptr, void *mlx, void *win)
{
	float *x;
	float *y;
	int i;
	int j;

	i = 0;
	x = (float *)malloc(sizeof(float) * 2);
	y = (float *)malloc(sizeof(float) * 2);
	x[0] = 370;
	x[1] = 390;
	y[0] = 420;
	y[1] = 420;
	ptr->tmpX = x[0];
	ptr->tmpY = y[0];
	while (i < ptr->index)
	{
		ft_putnbr(i);
		x[0] = ptr->tmpX;
		x[1] = x[0] + 20;
		y[0] = ptr->tmpY;
		y[1] = y[0];
		j = 0;
		while (j + 1 < ptr->width)
		{
			x[0] += 20;
			x[1] += 20;
			ft_putchar('S');
			y[0] -= (ptr->entry[i][j] * 3);
			y[1] -= (ptr->entry[i][j + 1] * 3);
			ft_putchar('T');
			ft_putchar('\n');
			ft_putnbr(x[0]);
			ft_putchar('\n');
			ft_putnbr(y[0]);
			ft_putchar('\n');
			ft_putnbr(x[1]);
				ft_putchar('\n');
			ft_putnbr(y[1]);
			ft_putchar('\n');

			ft_connect(x, y, mlx, win);
		ft_putchar('Q');
			y[0] += (ptr->entry[i][j] * 3);
			y[1] += (ptr->entry[i][j + 1] * 3);
			j++;
			ft_putchar('W');
		}
		ft_putchar('A');
		ptr->tmpX -= 10;
		ptr->tmpY += 20;
		i++;
	}
}

void    ft_draw_vert(t_data *ptr, void *mlx, void *win)
{
	float *x;
	float *y;
	int i;
	int j;

	i = 0;
	x = (float *)malloc(sizeof(float) * 2);
	y = (float *)malloc(sizeof(float) * 2);
	x[0] = 400;
	x[1] = 390;
	y[0] = 400;
	y[1] = 420;
	ptr->tmpX = x[0];
	ptr->tmpY = y[0];
	while (j < ptr->width)
	{
		x[0] = ptr->tmpX;
		x[1] = x[0] - 10;
		y[0] = ptr->tmpY;
		y[1] = y[0] + 20;
		i = 0;
		while (i + 1 < ptr->index)
		{
			x[0] -= 10;
			x[1] -= 10;
			y[0] = y[0] + 20 - (ptr->entry[i][j] * 3);
			y[1] = y[1] + 20 - (ptr->entry[i + 1][j] * 3);
			ft_connect(x, y, mlx, win);
			y[0] += (ptr->entry[i][j] * 3);
			y[1] += (ptr->entry[i + 1][j] * 3);
			i++;
		}
		ptr->tmpX += 20;
		j++;
	}
//	ft_draw(ptr, mlx, win);
}
