/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:20:13 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/04 15:33:03 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_print_tab(int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 18)
		{
			ft_putnbr(tab[i][j++]);
			ft_putchar(' ');
		}
		i++;
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	char	*str;
	t_data	*ptr;
	int		fd;
	int a;

	a = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &str))
	{
		ptr = ft_read(str);
	}
//	ft_print_tab(ptr->entry);
	ft_loop(ptr);
	return (0);
}
