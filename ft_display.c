/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:48:25 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/21 12:29:52 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	while (k < 700)
	{
		i = 600;
		j = k;
		while (i < 700)
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, j--, i++, 0x0000FF);
		k++;
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
	mlx_put_image_to_window(ptr->mlx_ptr, adr2, adr, 0, 0);
	mlx_loop(adr2);
}

//void	ft_set_image(int width, int height, t_data *ptr)
//{

