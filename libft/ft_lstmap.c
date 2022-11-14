/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:37:04 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/11 20:17:33 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_del(void *content, void (*del)(void *))
{
	if (content)
		del(content);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_start;
	t_list	*res_last;
	void	*content;

	if (!lst)
		return (NULL);
	content = f(lst->content);
	res_start = ft_lstnew(content);
	if (!res_start)
		return (ft_del(content, del));
	res_last = res_start;
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		res_last->next = ft_lstnew(content);
		res_last = res_last->next;
		if (!res_last)
		{
			ft_lstclear(&res_start, del);
			return (ft_del(content, del));
		}
		lst = lst->next;
	}
	return (res_start);
}
