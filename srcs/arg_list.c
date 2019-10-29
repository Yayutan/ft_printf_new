/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:35:23 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/26 18:35:26 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

/*
** Setting up a new argument node depending on whether we encounter a  
** specifier character. 
** Returns 0 if no valid spec char is found
** Adds new node to arg list and returns 1 if valid spec is found
*/

int		spec_arg(t_args *arg, char sp, int *n_l, int *nxt_arg)
{
	if (ft_strchr("dDioOuUxXbBfFeEgGcsprk%", sp))
	{
		if (ft_strchr("csprk", ft[i]))
            insert_arg(arg, new_arg(*nxt_arg, ft[i]));
		else if (ft_strchr("fFeEgG", ft[i]))
		{
			insert_arg(arg, new_arg(*nxt_arg, 'f'));
			if (n_l[2] == 1)
				insert_arg(arg, new_arg(*nxt_arg, 'F'));				
		}
		else if (ft_strchr("diouxXbB", ft[i]))
		{
			insert_arg(arg, new_arg(*nxt_arg, 'i'));
			if (n_l[0] == 1)
				insert_arg(arg, new_arg(*nxt_arg, 'l'));
			else if (n_l[0] == 2)
				insert_arg(arg, new_arg(*nxt_arg, 'L'));
			else if (n_l[0] == 1)
				insert_arg(arg, new_arg(*nxt_arg, 'h'));
			else if (n_l[0] == 2)
				insert_arg(arg, new_arg(*nxt_arg, 'H'));
		}
		else if (ft_strchr("DOU", ft[i]))
			insert_arg(arg, new_arg(*nxt_arg, 'l'));
		return (1);
	}
	return (0);
}

/*
** Setting up a new argument node when we see '*' in ft.
** Possible cases include:
** * -> get next argument (nxt_arg++)
** *n -> still gets next argument, and don't worry about n (nxt_arg++)
** *n$ -> nth parameter is an int (doesn't affect nxt_arg)
** Returns the index of the next char to look at in ft
*/

int		star_arg(t_args *arg, char *ft, int i, int *nxt_arg)
{
	int		num;

	if (ft[i] >= '0' && ft[i] <= '9')
	{
		num = ft_atoi(ft + i);
		while (ft[i] >= '0' && ft[i] <= '9')
			i++;
		if (ft[i] == '$')
			insert_arg(arg, new_arg(num, 'i'));
	}
	else if (ft[i] != '$')
        insert_arg(arg, new_arg((*next_arg)++, 'i'));
	i += (ft[i] != '$') ? 0 : 1;
	return (i);
}

/*
** Setting up a new argument node when we see numbers in ft.
** Possible cases include:
** n -> probably fixed width, nothing needs to be done
** n$c -> if c is a valid specifier, add node to list and set nxt_arg to num+1
** (Due to norm) Returns the increment in index to the next char to look at
*/

int		num_arg(t_args *arg, char *ft, int *n_l, int *nxt_arg)
{
	int		num;
	int		j;
	
	num = ft_atoi(ft);
	j = 0;
	while (ft[j] && ft[j] >= '0' && ft[j] <= '9')
		j++;
	if (ft[j] == '$')
	{
		j++;
		if (ft[j] && spec_arg(arg, ft[j], n_l, &num))
		{
			j++;
			*nxt_arg = num + 1;
		}
	}
	return (j);
}

/*
** Looks through a "set" of format and set up new arguments
** If we find numbers, '*', specifiers, we need to check and set up nodes.
** We also need to keep track of length charactes(l,h,L), since they affect 
** the final type of the argument as well.
** n_l[i]-> 0:l, 1:h, 2:L
** Returns the next index to look at past this set of format.
*/

int		add_arg_info(char *ft, int i, t_args *arg, int *nxt_arg)
{
    int n_l[3];

    ft_bzero(n_l, sizeof(int) * 3);
	while (ft[i] && ft_strchr(",;:_vaACSnjz0123456789hlL*.'#-+ ", ft[i]))
	{
		if (ft[i] >= '1' && ft[i] <= '9')
			i += num_arg(arg, ft + i, n_l, nxt_arg);
		if (ft_strchr("dDioOuUxXbBfFeEgGcsprk%", ft[i - 1]))
			return (i);
		else if (ft[i] == '*')
			i = star_arg(arg, ft, i + 1, nxt_arg);
        else if (ft[i] == 'l' || ft[i] == 'h')
        {
            (ft[i] == 'l') ? n_l[1] = 0 : n_l[0] = 0;
			if (ft[i] == 'l')
				n_l[0] = (n_l[0] == 1) ? 2 : 1;
			else
				n_l[1] = (n_l[1] == 1) ? 2 : 1;
        }
        else if (ft[i] == 'L')
            n_l[2] = 1;
        else
			i++;
	}
	if (spec_arg(arg, ft[i], n_l, nxt_arg))
	{
		i++;
		(*nxt_arg)++;
	}
	return (i);
}

/*
** Iterates the format string to set up all arguments used.
** Whenever we find the '%', we start looking into that "set" of format and 
** add nodes to the argument list if needed.
** Returns the list of arguments with their types.
*/

t_args	*set_args_lst(const char *format)
{
	t_args	*arg;
	int		i;
	int		arg_c;

	arg = NULL;
	i = 0;
	arg_c = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = add_arg_info(format, i, arg, &arg_c);
		else
			i++;
	}
	return (arg);
}
