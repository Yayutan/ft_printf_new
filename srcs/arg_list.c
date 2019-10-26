/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:38:02 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/25 16:38:03 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "arg_list.h"

t_args	*new_arg(int i, char t)
{
	t_args	*to_ret;

	to_ret = (t_args*)ftmemalloc(sizeof(t_args));
	to_ret->index = i;
	to_ret->type = t;
	to_ret->next = NULL;
	return (to_ret);
}

t_args	*insert_arg(t_args *lst, t_args *t)
{
	t_args	*cur;
	t_args	*pre;

	if (t->index < lst->index)
	{
		t->next = lst;
		lst = t;
		return (lst);
	}
	pre = NULL;
	cur = lst;
	while (cur && cur->index <= t->index)
	{
		if (t->index == cur->index)
		{
			cur->type = t->type;
			return (lst);
		}			
		else if (t->index < cur->index && t->index > pre->index)
		{
			pre->next = t;
			t->next = cur;
			return (lst);
		}
		pre = cur;
		cur = cur->next;
	}
	pre->next = t;
	return (lst);
}

int		arg_lst_len(t_args *lst)
{
	int		len;
	t_args	*cur;

	if (!lst)
		return (0);
	len = 0;
	cur = lst;
	while (cur)
	{
		cur = cur->next;
		len++;
	}
	return (len);
}

t_args	*arg_lst_at(t_args *lst, int i)
{
	t_args	*cur;

	if (!lst)
		return (NULL);
	else if (pos == 0)
		return (lst);
	else
	{
		cur = lst;
		while (cur)
		{
			if (pos == 0)
				return (cur);
			pos--;
			cur = cur->next;
		}
		return (NULL);
	}
}

void	arg_lst_del(t_args *lst)
{
	t_args	*cur;
	t_args	*nxt;

	cur = lst;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
}