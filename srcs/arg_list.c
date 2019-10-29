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

int		spec_arg(t_args *arg, char sp, int *n_w, int *nxt_arg)
{
	if (ft_strchr("dDioOuUxXbBfFeEgGcsprk%", sp))
	{
		if (ft_strchr("csprk", ft[i]))
            insert_arg(arg, new_arg(*nxt_arg, ft[i]));
		else if (ft_strchr("fFeEgG", ft[i]))
		{
			insert_arg(arg, new_arg(*nxt_arg, 'f'));
			if (n_w[2] == 1)
				insert_arg(arg, new_arg(*nxt_arg, 'F'));				
		}
		else if (ft_strchr("diouxXbB", ft[i]))
		{
			insert_arg(arg, new_arg(*nxt_arg, 'i'));
			if (n_w[0] == 1)
				insert_arg(arg, new_arg(*nxt_arg, 'l'));
			else if (n_w[0] == 2)
				insert_arg(arg, new_arg(*nxt_arg, 'L'));
			else if (n_w[0] == 1)
				insert_arg(arg, new_arg(*nxt_arg, 'h'));
			else if (n_w[0] == 2)
				insert_arg(arg, new_arg(*nxt_arg, 'H'));
		}
		else if (ft_strchr("DOU", ft[i]))
			insert_arg(arg, new_arg(*nxt_arg, 'l'));
		return (1);
	}
	return (0);
}

int		star_arg(t_args *arg, char *ft, int i, int *nxt_arg)
{
	int		num;

	if (ft[i] >= '0' && ft[i] <= '9')
	{
		num = ft_atoi(ft + i);
		while (ft[i] >= '0' && ft[i] <= '9')
			i++;
		if (ft[i] == '$') // *n$
		{
			insert_arg(arg, new_arg(num, 'i'));
			*nxt_arg = num + 1;
		}
	}
	else if (ft[i] != '$') // *
        insert_arg(arg, new_arg((*next_arg)++, 'i');
	i += (ft[i] != '$') ? 0 : 1;
	return (i);
}

int		num_arg(t_args *arg, char *ft, int j, int *n_w, int *nxt_arg) // make ft->ft+j to eliminate 1 arg
{
	int		num;
	
	num = ft_atoi(ft + j);
	while (ft[j] && ft[j] >= '0' && ft[j] <= '9')
		j++;
	if (ft[j] == '$')
	{
		j++;
		if (ft[j] && spec_arg(arg, ft[j], n_w, &num))
		{
			j++;
			*nxt_arg = num;
		}
	}
	return (j);
}

int		add_arg_info(char *ft, int i, t_args *arg, int *nxt_arg)
{
    int n_w[3]; // l, h, L

    ft_bzero(n_w, sizeof(int) * 3);
	while (ft[i] && ft_strchr(",;:_vaACSnjz0123456789hlL*.'#-+ ", ft[i]))
	{
		if (ft[i] >= '1' && ft[i] <= '9')
			i = num_arg(arg, ft, i); // make new node if $
		if (ft_strchr("dDioOuUxXbBfFeEgGcsprk%", ft[i - 1]))
			return (i);
		else if (ft[i] == '*') // *(next) or *n$(n) (diff in precision and width)
			i = star_arg(arg, ft, i + 1, nxt_arg);
        else if (ft[i] == 'l' || ft[i] == 'h')
        {
            (ft[i] == 'l') ? n_w[1] = 0 : n_w[0] = 0;
			if (ft[i] == 'l')
				n_w[0] = (n_w[0] == 1) ? 2 : 1;
			else
				n_w[1] = (n_w[1] == 1) ? 2 : 1;
        }
        else if (ft[i] == 'L')
            n_w[2] = 1;
        else
			i++;
	}
	if (spec_arg(arg, ft[i], n_w, nxt_arg))
	{
		i++;
		(*nxt_arg)++;
	}
	return (i);
}

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
