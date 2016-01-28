/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_points.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:47:42 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/28 14:40:43 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_draw_line1(t_link *adr, MLXCore *ptr)
{
	float x;
	float y;
	float tmp;

	x = 1;
	y = 1;
	while (adr->Xa + x <= adr->Xb || adr->Ya + y <= adr->Yb)
	{
		tmp = x / y;
		if (tmp >= adr->coeff_dir)
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xa + x, adr->Ya + y++, 0xFF00FF);
		else
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xa + x++, adr->Ya + y, 0xFF00FF);
	}
}

void    ft_draw_line4(t_link *adr, MLXCore *ptr)
{
	float x;
	float y;
	float tmp;

	x = 1;
	y = 1;
	while (adr->Xb + x <= adr->Xa || adr->Yb + y <= adr->Ya)
	{
		tmp = x / y;
		if (tmp >= adr->coeff_dir)
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xb + x, adr->Yb + y++, 0xFF00FF);
		else
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xb + x++, adr->Yb + y, 0xFF00FF);
	}
}

void    ft_draw_line3(t_link *adr, MLXCore *ptr)
{
	float x;
	float y;
	float tmp;

	x = -1;
	y = 1;
	while (adr->Xa + x >= adr->Xb || adr->Ya + y <= adr->Yb)
	{
		tmp = x / y;
		if (tmp >= adr->coeff_dir)
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xa + x--, adr->Ya + y, 0xFF00FF);
		else
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xa + x, adr->Ya + y++, 0xFF00FF);
	}
}

void    ft_draw_line2(t_link *adr, MLXCore *ptr)
{
	float x;
	float y;
	float tmp;

	x = -1;
	y = 1;
	while (adr->Xb + x >= adr->Xa || adr->Yb + y <= adr->Ya)
	{
		tmp = x / y;
		if (tmp >= adr->coeff_dir)
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xb + x--, adr->Yb + y, 0xFF00FF);
		else
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xb + x, adr->Yb + y++, 0xFF00FF);
	}
}

void    ft_connect_points(MLXCore *ptr, t_link *adr)
{
	float x;
	float y;
	int i;

	i = 0;
	x = (adr->Xb) - (adr->Xa);
	y = (adr->Yb) - (adr->Ya);
	if (y != 0)
		adr->coeff_dir = x / y;
	if (adr->Xb == adr->Xa)
	{
		if (adr->Yb - adr->Ya < 0)
			while (i < adr->Ya - adr->Yb)
				mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xa, adr->Ya - i++, 0xFF00FF);
		else
			while (i < adr->Yb - adr->Ya)
				mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xa, adr->Ya + i++, 0xFF00FF);
	}
	else if (adr->Ya == adr->Yb)
	{
		if (adr->Xb - adr->Xa < 0)
			while (i < adr->Xa - adr->Xb)
				mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xa - i++, adr->Ya, 0xFF00FF);
		else
			while (i < adr->Xb - adr->Xa)
				mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, adr->Xa + i++, adr->Ya, 0xFF00FF);
	}
	else if (adr->coeff_dir < 0)
	{
		if (x < 0)
			ft_draw_line3(adr, ptr);
		else
			ft_draw_line2(adr, ptr);
	}
	else
	{
		if (x < 0 && y < 0)
			ft_draw_line4(adr, ptr);
		else
			ft_draw_line1(adr, ptr);
	}
}
