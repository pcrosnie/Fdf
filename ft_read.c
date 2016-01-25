/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:52:38 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/25 14:43:54 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*ft_read(char *entry)
{
	int i;
	char **tmp;
	static t_data *ptr;

	i = 0;
	if (!ptr)
	{
		ptr = (t_data *)malloc(sizeof(t_data));
		ptr->entry = (int **)malloc(sizeof(int *) * 100000);
	}
	if (!(ptr->entry[ptr->index]))
		ptr->entry[ptr->index] = (int *)malloc(sizeof(int) * 100000);
	tmp = ft_strsplit(entry, ' ');
	while (tmp[i])
	{
		ptr->entry[ptr->index][i] = ft_atoi(tmp[i]);
		i++;
	}
	ptr->index++;
	ptr->width = i;
	return (ptr);
}
