/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_cmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 09:56:48 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/10 13:30:52 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdelone_cmp(t_list **lst, t_list **del)
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
