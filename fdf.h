/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:50:19 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/04 15:46:08 by pcrosnie         ###   ########.fr       */
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
	float tmpX;
	float tmpY;
	int index;
	int	width;
	int **entry;
}				t_data;

void	ft_draw(t_data *ptr, void *mlx, void *win);
void	ft_draw_vert(t_data *ptr, void *mlx, void *win);
void	ft_connect(float *x, float *y, void *mlx, void *win);
void	ft_loop(t_data *ptr);
t_data	*ft_read(char *entry);

#endif
