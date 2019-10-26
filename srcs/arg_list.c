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

// create
t_args	*new_arg(int i, char t)
{
	t_args	*to_ret;

	to_ret = (t_args*)ftmemalloc(sizeof(t_args));
	to_ret->index = i;
	to_ret->type = t;
	to_ret->next = NULL;
	return (to_ret);
}

// insert 
t_args	*insert_arg(t_args *lst, t_args *t)
{
	int		target;
	t_args	*cur;
	t_args	*pre;

	target = t->index;
	pre = NULL;
	cur = lst;
	if (target < cur->index)
	{
		t->next = cur;
		lst = t;
		return (lst);
	}
	while (cur && cur->index <= target)
	{
		if (target == cur->index)
		{
			cur->type = t->type;
			return (lst);
		}			
		else if (target < cur->index && target > pre->index)
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


// len


// del

