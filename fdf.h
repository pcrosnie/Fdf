/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:50:19 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/28 14:41:25 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"

typedef struct	s_data
{
	int index;
	int	width;
	int **entry;
}				t_data;

typedef struct	s_link
{
	float Xa;
	float Ya;
	float Xb;
	float Yb;
	float tmpY;
	float tmpX;
	float coeff_dir;
	struct s_link *next;
}				t_link;

typedef struct
{
	void *mlx_ptr;
	void *mlx_win;
}				MLXCore;

typedef struct
{
	int         win_width;
	int         win_height;
	void		*win_texts;
	void		*win_next;
}				MLXWindow;

typedef struct
{
	int                im_width;
	int                im_height;
	unsigned int       im_bpp;
	unsigned int       im_bpl;
	unsigned char      *im_buffer;
	void				*im_ximg;
}				MLXImage;

void	ft_connect_points(MLXCore *ptr, t_link *adr);
void	ft_open_window(int width, int height, t_data *ptr);
void	ft_draw_base(MLXCore *pt, t_data *ptr);
t_data	*ft_read(char *entry);
void	ft_print_tab(int **tab);
void	ft_draw_vert(MLXCore *pt, t_data *ptr);
void	ft_draw_hor(MLXCore *pt, t_data *ptr);

#endif
