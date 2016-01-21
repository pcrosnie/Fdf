/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:48:25 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/21 17:45:52 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_test_fill(MLXCore *ptr)
{
	int j;
	int i;
	int k;

	i = 700;
	j = 250;
	k = 350;
	while (j < 600)
		mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, j++, 700, 0x0000FF);
	while (i > 600)
		mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, j++, i--, 0X0000FF);
	while (j > 350)
		mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, j--, 600, 0x0000FF);
	while (i < 700)
		mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, j--, i++, 0x0000FF);
/*
	while (k < 700)
	{
		i = 600;
		j = k;
		while (i < 700)
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, j--, i++, 0x0000FF);
		k++;
	}
	*/
}

void	ft_draw_line1(t_link *adr, MLXCore *ptr)
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

void	ft_draw_line4(t_link *adr, MLXCore *ptr)
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

void	ft_draw_line3(t_link *adr, MLXCore *ptr)
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

void	ft_draw_line2(t_link *adr, MLXCore *ptr)
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

void	ft_connect_points(MLXCore *ptr)
{
	float x;
	float y;
	t_link *adr;

	adr = (t_link *)malloc(sizeof(t_link));
	adr->Xa = 853;
	adr->Ya = 17;
	adr->Xb = 120;
	adr->Yb = 670;
	x = (adr->Xb) - (adr->Xa);
	y = (adr->Yb) - (adr->Ya);
	adr->coeff_dir = x / y;
	printf("%f\n", adr->coeff_dir);
	if (adr->coeff_dir < 0)
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


void	ft_open_window(int width, int height)
{
	MLXImage *adr;
	MLXWindow *adr2;
	MLXCore *ptr;
	ptr->mlx_ptr = mlx_init();
	ptr->mlx_win = mlx_new_window(adr2, width, height, "fdf");
	adr = mlx_new_image(adr, 1000, 1000);
	ft_test_fill(ptr);
	ft_connect_points(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, adr2, adr, 0, 0);
	mlx_loop(adr2);
}

//void	ft_set_image(int width, int height, t_data *ptr)
//{

