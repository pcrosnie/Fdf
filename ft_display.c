/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:48:25 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/27 15:28:31 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_esc(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

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
	ft_putchar('A');
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
	ft_putchar('A');
	ptr->mlx_ptr = mlx_init();
	ptr->mlx_win = mlx_new_window(adr2, width, height, "fdf");
	adr = mlx_new_image(adr, 1000, 1000);
	ft_draw_base(ptr, ptr3);
	mlx_put_image_to_window(ptr->mlx_ptr, adr2, adr, 0, 0);
	mlx_key_hook(ptr->mlx_win, ft_key_esc, 0);
	mlx_loop(adr2);
}
