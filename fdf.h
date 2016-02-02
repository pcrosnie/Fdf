/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:50:19 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/02 13:53:26 by pcrosnie         ###   ########.fr       */
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
	int index;
	int	width;
	int **entry;
}				t_data;

void	ft_connect(float *x, float *y, void *mlx, void *win);
void	ft_loop(void);
t_data	*ft_read(char *entry);

#endif
