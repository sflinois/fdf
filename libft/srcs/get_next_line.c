/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:10:10 by sflinois          #+#    #+#             */
/*   Updated: 2017/05/20 21:35:32 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static void	ft_lstdelone_gnl(t_list **lst, t_list **del)
{
	t_list	*prev;
	t_list	*tmp;

	tmp = *lst;
	if (tmp == *del)
	{
		*lst = tmp->next;
		free(tmp->content);
		free(tmp);
		return ;
	}
	prev = *lst;
	tmp = (*lst)->next;
	while (tmp != *del)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	free(tmp->content);
	free(tmp);
}

static void	add_line(char **line, char *str, int size)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*line);
	tmp = ft_strdup(*line);
	ft_strdel(line);
	*line = NULL;
	if ((*line = (char*)malloc(sizeof(char) * (len + size + 1))))
	{
		ft_strcpy(*line, tmp);
		ft_strncat(*line, str, size);
	}
	free(tmp);
}

static int	fill_line(char **line, t_list **lst, t_list **l_buff)
{
	int		i;
	char	*tmp;

	if (*lst && line)
	{
		i = 0;
		while (((char*)(*lst)->content)[i] != '\0'
				&& ((char*)(*lst)->content)[i] != '\n')
			i++;
		*line = ft_strndup((*lst)->content, i);
		if (((char*)(*lst)->content)[i] == '\n')
		{
			tmp = ft_strdup((char*)((*lst)->content + i + 1));
			free((*lst)->content);
			(*lst)->content = ft_strdup(tmp);
			free(tmp);
			return (1);
		}
		else
			ft_lstdelone_gnl(l_buff, lst);
	}
	else if (line)
		*line = ft_strnew(BUFF_SIZE);
	return (0);
}

static int	get_index_buff(char *buff, char **line, int ret)
{
	int		i;

	buff[ret] = '\0';
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	add_line(line, buff, i);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*l_buff = NULL;
	t_list			*lst;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	int				i;

	lst = l_buff;
	while (lst && (int)lst->content_size != fd)
		lst = lst->next;
	if (fill_line(line, &lst, &l_buff))
		return (1);
	while (BUFF_SIZE > 0 && line && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		i = get_index_buff(buff, line, ret);
		if (buff[i] == '\n' && buff[i + 1])
		{
			lst = ft_lstnew(buff + i + 1, BUFF_SIZE - i);
			lst->content_size = fd;
			ft_lstadd(&l_buff, lst);
		}
		if (buff[i] == '\n' || ft_strlen(buff) != BUFF_SIZE)
			return (1);
	}
	ret = ((!line || BUFF_SIZE <= 0) ? -1 : ret);
	return ((ret != -1 && **line) ? 1 : ret);
}
