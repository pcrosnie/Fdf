/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:52:38 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/20 11:25:12 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_get_tab	*ft_read(char *entry)
{
	int i;
	char **tmp;
	static t_get_tab *ptr;

	i = 0;
	if (!ptr)
	{
		ptr = (t_get_tab *)malloc(sizeof(t_get_tab));
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
	return (ptr);
}
