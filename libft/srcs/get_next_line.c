/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:10:10 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/30 17:26:07 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char		*ft_strjoin_freestr(char *str, char *buf)
{
	char *tmp;

	tmp = str;
	str = ft_strjoin(str, buf);
	free(tmp);
	return (str);
}

char		*ft_strndup(const char *s1, size_t n)
{
	char	*ret;

	ret = ft_strnew(n);
	if (!ret)
		return (NULL);
	ret = ft_strncpy(ret, s1, n);
	return (ret);
}

int			ft_strclen(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int			ft_order(char **tmp, char **line)
{
	char *str;

	str = *tmp;
	if (!*tmp && !ft_strchr(*tmp, '\n'))
	{
		free(*tmp);
		return (0);
	}
	if (ft_strchr(*tmp, '\n'))
	{
		*line = ft_strndup(*tmp, ft_strclen(*tmp, '\n'));
		*tmp = ft_strdup(*tmp + (ft_strclen(*tmp, '\n') + 1));
		free(str);
		return (1);
	}
	else if (*tmp[0] != '\0')
	{
		*line = ft_strdup(*tmp);
		*tmp = NULL;
		free(*tmp);
		free(str);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*buf;
	static char	*tmp = NULL;

	if (fd < 0 || read(fd, NULL, 0) < 0 ||
			((buf = (char *)ft_memalloc(sizeof(*buf) * BUFF_SIZE + 1)) == 0))
		return (-1);
	if (!tmp)
		tmp = ft_strdup("");
	while (!(ft_strchr(tmp, '\n')) && ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin_freestr(tmp, buf);
	}
	free(buf);
	if (tmp && ft_order(&tmp, line) == 1)
		return (1);
	free(tmp);
	*line = NULL;
	free(*line);
	return (0);
}
