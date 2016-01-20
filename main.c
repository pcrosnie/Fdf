/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:57:55 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/20 17:33:51 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_tab(int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 19)
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
	int fd;
	int ret;
	char *str;
	t_data *ptr;

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &str)))
		ptr = ft_read(str);
//	ft_print_tab(ptr->entry);
	ft_open_window(1000, 1000);
	return (0);
}
