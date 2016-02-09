/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:44:54 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/09 14:54:16 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_set_x_coord(t_data *ptr, int i, int j)
{
	float nb;

	nb = 500 + (ptr->scale * ((cos(ptr->angles[0]) * i)
				+ (sin(ptr->angles[0]) * j)));
	return (nb);
}

float	ft_set_y_coord(t_data *ptr, int i, int j)
{
	float nb;

	nb = 500 + (ptr->scale * (sin(ptr->angles[1])
				* ((sin(ptr->angles[0]) * i) + (cos(ptr->angles[0]) * (j))))
			+ (cos(ptr->angles[1]) * ptr->entry[i][j]));
	return (nb);
}

void	ft_draw(t_data *ptr)
{
	float	*x;
	float	*y;
	int		i;
	int		j;

	i = 0;
	x = (float *)malloc(sizeof(float) * 2);
	y = (float *)malloc(sizeof(float) * 2);
	while (i < ptr->index)
	{
		j = 0;
		while (j + 1 < ptr->width)
		{
			ptr->color = ptr->tmp_color
			- ((ptr->entry[i][j] + ptr->entry[i][j + 1]) * 10000);
			x[0] = ft_set_x_coord(ptr, i, j);
			x[1] = ft_set_x_coord(ptr, i, j + 1);
			y[0] = ft_set_y_coord(ptr, i, j);
			y[1] = ft_set_y_coord(ptr, i, j++ + 1);
			ft_connect(x, y, ptr);
		}
		i++;
	}
	free(x);
	free(y);
}

void	ft_draw_vert(t_data *ptr)
{
	float	*x;
	float	*y;
	int		i;
	int		j;

	i = 0;
	x = (float *)malloc(sizeof(float) * 2);
	y = (float *)malloc(sizeof(float) * 2);
	while (i + 1 < ptr->index)
	{
		j = 0;
		while (j < ptr->width)
		{
			ptr->color = ptr->tmp_color
				- ((ptr->entry[i][j] + ptr->entry[i + 1][j]) * 10000);
			x[0] = ft_set_x_coord(ptr, i, j);
			x[1] = ft_set_x_coord(ptr, i + 1, j);
			y[0] = ft_set_y_coord(ptr, i, j);
			y[1] = ft_set_y_coord(ptr, i + 1, j++);
			ft_connect(x, y, ptr);
		}
		i++;
	}
	free(x);
	free(y);
}
