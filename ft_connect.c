#include "fdf.h"

void	ft_draw_line3(float *x, float *y, t_data *ptr)
{
	float i;
	float j;
	float coeff_dir;
	float tmp;

	coeff_dir = (x[1] - x[0]) / (y[1] - y[0]);
	j = - 1;
	i = 1;
	while (x[0] + j > x[1] || y[0] + i < y[1])
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(ptr->mlx, ptr->win, x[0] + j--, y[0] + i, ptr->color);
		else
			mlx_pixel_put(ptr->mlx, ptr->win, x[0] + j, y[0] + i++, ptr->color);
	}
}

void	ft_draw_line2(float *x, float *y, t_data *ptr)
{
	float i;
	float j;
	float coeff_dir;
	float tmp;

	j = -1;
	i = 1;
	coeff_dir = (x[1] - x[0]) / (y[1] - y[0]);
	while (x[1] + j > x[0] || y[1] + i < y[0])
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(ptr->mlx, ptr->win, x[1] + j--, y[1] + i, ptr->color);
		else
			mlx_pixel_put(ptr->mlx, ptr->win, x[1] + j, y[1] + i++, ptr->color);
	}
}

void	ft_draw_line1(float *x, float *y, t_data *ptr)
{
	float i;
	float j;
	float coeff_dir;
	float tmp;

	i = 1;
	j = 1;
	coeff_dir = (x[1] - x[0]) / (y[1] - y[0]);
	while (x[0] + j < x[1] || y[0] + i < y[1])
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(ptr->mlx, ptr->win, x[0] + j, y[0] + i++, ptr->color);
		else
			mlx_pixel_put(ptr->mlx, ptr->win, x[0] + j++, y[0] + i, ptr->color);
	}
}

void    ft_draw_line4(float *x, float *y, t_data *ptr)
{
	float i;
	float j;
	float coeff_dir;
	float tmp;

	i = 1;
	j = 1;
	coeff_dir = (x[1] - x[0]) / (y[1] - y[0]);
	while (x[1] + j < x[0] || y[1] + i < y[0])
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(ptr->mlx, ptr->win, x[1] + j, y[1] + i++, ptr->color);
		else
			mlx_pixel_put(ptr->mlx, ptr->win, x[1] + j++, y[1] + i, ptr->color);
	}
}

void	ft_connect(float *x, float *y, t_data *ptr)
{
	float coeff_dir;
	int i;

	i = 0;
	if (y[1] - y[0] != 0)
		coeff_dir = (x[1] - x[0]) / (y[1] - y[0]);
	if (coeff_dir == 0 && x[1] > x[0])
		while (i < x[1] - x[0])
			mlx_pixel_put(ptr->mlx, ptr->win, x[0] + i++, y[0], ptr->color);
	else if (coeff_dir == 0 && x[1] < x[0])
		while (i < x[0] - x[1])
			mlx_pixel_put(ptr->mlx, ptr->win, x[1] + i++, y[1], ptr->color);
	else if (coeff_dir < 0)
	{
		if (x[1] - x[0] < 0)
			ft_draw_line3(x, y, ptr);
		else
			ft_draw_line2(x, y, ptr);
	}
	else
	{
		if (x[1] - x[0] < 0 && y[1] - y[0] < 0)
			ft_draw_line4(x, y, ptr);
		else
			ft_draw_line1(x, y, ptr);
	}
}
