/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:48:25 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/28 14:40:35 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_esc(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

/*
void	ft_draw(t_data *ptr, t_link **adr2)
{
	t_link *adr;
	int i;
	int j;

	i = 0;
	j = 0;
	adr = *adr2;
	
*/


void	ft_open_window(int width, int height, t_data *ptr3)
{
	MLXImage *adr;
	MLXWindow *adr2;
	MLXCore *ptr;
	ptr = (MLXCore *)malloc(sizeof(MLXCore));
	adr2 = (MLXWindow *)malloc(sizeof(MLXWindow));
	ptr->mlx_ptr = mlx_init();
	ptr->mlx_win = mlx_new_window(adr2, width, height, "fdf");
	adr = mlx_new_image(adr, 1000, 1000);
	ft_draw_vert(ptr, ptr3);
	ft_draw_hor(ptr, ptr3);
	mlx_put_image_to_window(ptr->mlx_ptr, adr2, adr, 0, 0);
	mlx_key_hook(ptr->mlx_win, ft_key_esc, 0);
	mlx_loop(adr2);
}
