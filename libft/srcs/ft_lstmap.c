/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sflinois <sflinois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:11:52 by sflinois          #+#    #+#             */
/*   Updated: 2017/01/10 13:30:52 by sflinois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lsttmp;
	t_list	*lstret;

	if (lst == NULL || f == NULL)
		return (NULL);
	lsttmp = f(lst);
	if (!(lstret = ft_lstnew(lsttmp->content, lsttmp->content_size)))
		return (NULL);
	if (lst->next)
		lstret->next = ft_lstmap(lst->next, f);
	return (lstret);
}
