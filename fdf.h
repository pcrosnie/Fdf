/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:50:19 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/08 16:29:49 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include <math.h>

typedef struct	s_data
{
	int tmp_color;
	int color;
	int	scale;
	float *angles;
	void *mlx;
	void *win;
	int index;
	int	width;
	int **entry;
}				t_data;

void	ft_draw(t_data *ptr);
void	ft_draw_vert(t_data *ptr);
void	ft_connect(float *x, float *y, t_data *ptr);
void	ft_loop(t_data *ptr);
t_data	*ft_read(char *entry);

#endif
