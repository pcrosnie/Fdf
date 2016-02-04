/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:10:15 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/04 13:16:08 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_restline(char **reste, char *buf)
{
	char	*tmp;

	tmp = NULL;
	if (*reste)
	{
		tmp = ft_strjoin(*reste, buf);
		ft_memdel((void **)reste);
		*reste = ft_strdup(tmp);
		ft_memdel((void **)&tmp);
	}
	else
		*reste = ft_strdup(buf);
}

static int			ft_strsearch(char **reste, int len, char **line)
{
	char			*tmp;
	int				i;

	i = 0;
	while (i < len)
	{
		if ((*reste)[i] == '\n')
		{
			*line = ft_strsub(*reste, 0, i);
			tmp = ft_strsub(*reste, i + 1, ft_strlen(*reste) - i);
			ft_memdel((void **)reste);
			*reste = ft_strdup(tmp);
			ft_memdel((void **)&tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

static int			ft_getline(char **reste, char **line, int ret)
{
	size_t			i;
	size_t			len;
	char			*tmp;

	tmp = NULL;
	len = ft_strlen(*reste);
	i = 0;
	if (ft_strsearch(reste, len, line))
		return (1);
	if (ret == 0)
	{
		*line = *reste;
		*reste = NULL;
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static char		*reste = NULL;

	if (!line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) || reste)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret > 0)
			ft_restline(&reste, buf);
		if (ft_getline(&reste, line, ret))
			return (1);
	}
	return (0);
}
