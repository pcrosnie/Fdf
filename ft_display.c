/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:48:25 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/20 17:33:49 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_test_fill(MLXCore *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, i, j++, 0x0000FF);
		i++;
	}
}

void	ft_open_window(int width, int height)
{
	MLXImage *adr;
	MLXWindow *adr2;
	MLXCore *ptr;
	ptr->mlx_ptr = mlx_init();
	ptr->mlx_win = mlx_new_window(adr2, width, height, "fdf");
	adr = mlx_new_image(adr, 200, 200);
	ft_test_fill(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, adr2, adr, 0, 0);
	mlx_loop(adr2);
}

//void	ft_set_image(int width, int height, t_data *ptr)
//{

