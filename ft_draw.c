/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:44:54 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/09 09:41:22 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_draw(t_data *ptr)
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
			ptr->color = ptr->tmp_color - (ptr->entry[i][j] + ptr->entry[i][j + 1] * 10000);
			x[0] = 500 + (ptr->scale * ((cos(ptr->angles[0]) * i) + (sin(ptr->angles[0]) * j)));
			x[1] = 500 + (ptr->scale * ((cos(ptr->angles[0]) * i) + (sin(ptr->angles[0]) * (j + 1))));
			y[0] = 500 + (ptr->scale * (sin(ptr->angles[1]) * ((sin(ptr->angles[0]) * i) + (cos(ptr->angles[0]) * j))) + (cos(ptr->angles[1]) * ptr->entry[i][j]));
			y[1] = 500 + (ptr->scale * (sin(ptr->angles[1]) * ((sin(ptr->angles[0]) * i) + (cos(ptr->angles[0]) * (j + 1)))) + (cos(ptr->angles[1]) * ptr->entry[i][j + 1]));
			ft_connect(x, y, ptr);
			j++;
		}
		i++;
	}
}

void    ft_draw_vert(t_data *ptr)
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
			ptr->color = ptr->tmp_color - (ptr->entry[i][j] + ptr->entry[i + 1][j] * 10000);
			x[0] = 500 + (ptr->scale * (cos(ptr->angles[0]) * i + (sin(ptr->angles[0]) * j)));
			x[1] = 500 + (ptr->scale * ((cos(ptr->angles[0]) * (i + 1)) + (sin(ptr->angles[0]) * j)));
			y[0] = 500 + (ptr->scale * (sin(ptr->angles[1]) * ((sin(ptr->angles[0]) * i) + (cos(ptr->angles[0]) * j))) + (cos(ptr->angles[1]) * ptr->entry[i][j]));
			y[1] = 500 + (ptr->scale * (sin(ptr->angles[1]) * ((sin(ptr->angles[0]) * (i + 1)) + (cos(ptr->angles[0]) * j))) + (cos(ptr->angles[1]) * ptr->entry[i + 1][j]));
			ft_connect(x, y, ptr);
			j++;
		}
		i++;
		ft_putnbr(ptr->entry[1][18]);
	}
}

