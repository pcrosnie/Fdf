/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:20:13 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/10 11:50:22 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	char	*str;
	t_data	*ptr;
	int		fd;
	int		ret;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &str)))
		{
			if (ret == -1)
				return (0);
			ptr = ft_read(str);
			if (ptr == NULL)
				return (0);
		}
		if (ptr->index == 1 && ptr->width == 1)
			return (0);
		ft_loop(ptr);
	}
	return (0);
}
