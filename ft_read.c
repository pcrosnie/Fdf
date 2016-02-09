/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:52:38 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/09 12:16:48 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if ((str[i] > 57 || str[i] < 48) && str[i] != '\t' && str[i] != ' ' 
				&& str[i] != '\n' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

t_data	*ft_read(char *entry)
{
	int i;
	char **tmp;
	static t_data *ptr;

	i = 0;
	ft_putstr(entry);
	if (ft_check(entry) == 0)
		return (NULL);
	if (!ptr)
	{
		ptr = (t_data *)malloc(sizeof(t_data));
		ptr->entry = (int **)malloc(sizeof(int *) * 100000);
		ptr->index = 0;
		ptr->width = 0;
	}
	if (!(ptr->entry[ptr->index]))
		ptr->entry[ptr->index] = (int *)malloc(sizeof(int) * 100000);
	tmp = ft_strsplit(entry, ' ');
	while (tmp[i])
	{
		ptr->entry[ptr->index][i] = ft_atoi(tmp[i]);
		i++;
	}
	if (ptr->index != 0 && i > ptr->width)
		return (NULL);
	ptr->index++;
	ptr->width = i;
	return (ptr);
}
