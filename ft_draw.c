/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 10:37:01 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/28 15:12:05 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_base(MLXCore *pt, t_data *ptr)
{
	t_link *adr;
	int i;
	int j;

	i = 0;
	j = 0;
	adr = (t_link *)malloc(sizeof(t_link));
	adr->Xa = 100 + ptr->width * 20;
	adr->Ya = 700;
	adr->Xb = 100;
	adr->Yb = 700;
	ft_connect_points(pt, adr);
	adr->Xa = (adr->Xb + ptr->index * 10);
	adr->Ya = adr->Yb - (ptr->index * 10);
	ft_connect_points(pt, adr);
	adr->Xb = adr->Xa + ptr->width * 20;
	adr->Yb = adr->Ya;
	ft_connect_points(pt, adr);
	adr->Xa = adr->Xb - ptr->index * 10;
	adr->Ya = adr->Yb + ptr->index * 10;
	ft_connect_points(pt, adr);
}

void	ft_draw_vert(MLXCore *pt, t_data *ptr)
{
	t_link *adr;
	int x;
	int y;
	int height;

	x = 0;
	y = 0;
	adr = (t_link *)malloc(sizeof(t_link));
	adr->Xa = 300;
	adr->Ya = 200; // - ptr->entry[0][0];
	adr->Xb = 290;
	adr->Yb = 220; // - ptr->entry[0][1];
	adr->tmpX = 300;
	adr->tmpY = 200;
	while (x < ptr->width)
	{
		adr->Xa = adr->tmpX;
		adr->Ya = adr->tmpY;
		adr->Xb = adr->Xa - 10;
		adr->Yb = adr->Ya + 20;
		y = 0;
		while (y + 1 < ptr->index)
		{
			adr->Xa -= 10;
			adr->Ya = adr->Ya + 20 - (ptr->entry[y][x] * 3);
			adr->Xb -= 10;
			adr->Yb = adr->Yb + 20 - (ptr->entry[y + 1][x] * 3);
			ft_connect_points(pt, adr);
			adr->Ya = adr->Ya + (ptr->entry[y][x] * 3);
			adr->Yb = adr->Yb + (ptr->entry[y + 1][x] * 3);
			y++;
		}
		adr->tmpX += 20;
		x++;
	}
}

void    ft_draw_hor(MLXCore *pt, t_data *ptr)
{
	t_link *adr;
	int x;
	int y;
	int height;

	x = 0;
	y = 0;
	adr->Xa = 270;
	adr->Ya = 220;
	adr->Xb = 290;
	adr->Yb = 220;
	adr->tmpX = 270;
	adr->tmpY = 220;
	while (y < ptr->index)
	{
		adr->Xa = adr->tmpX;
		adr->Ya = adr->tmpY;
		adr->Xb = adr->Xa + 20;
		adr->Yb = adr->Ya;
		x = 0;
		while (x + 1 < ptr->width)
		{
			adr->Xa += 20;
			adr->Xb += 20;
			adr->Ya -= ptr->entry[y][x] * 3;
			adr->Yb -= ptr->entry[y][x + 1] * 3;
			ft_connect_points(pt, adr);
			adr->Ya += ptr->entry[y][x] * 3;
			adr->Yb += ptr->entry[y][x + 1] * 3;
			x++;
		}
		y++;
		adr->tmpX -= 10;
		adr->tmpY += 20;
	}
}
