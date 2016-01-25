/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:48:25 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/25 14:50:08 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_key_esc(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_open_window(int width, int height)
{
	MLXImage *adr;
	MLXWindow *adr2;
	MLXCore *ptr;
	t_link *ptr2;
	ptr2 = (t_link *)malloc(sizeof(t_link));
	ptr->mlx_ptr = mlx_init();
	ptr->mlx_win = mlx_new_window(adr2, width, height, "fdf");
	adr = mlx_new_image(adr, 1000, 1000);
	ft_connect_points(ptr, ptr2);
	mlx_put_image_to_window(ptr->mlx_ptr, adr2, adr, 0, 0);
	mlx_key_hook(ptr->mlx_win, ft_key_esc, 0);
	mlx_loop(adr2);
}
