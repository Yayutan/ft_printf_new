/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:51:56 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/28 11:52:05 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

char		*n_th_s(t_spec *sp, va_list orig, int i)
{
	va_list		cp;
	int			j;
	char		*to_ret;
	
	va_copy(cp, orig);
	j = 1;
	while (j < i)
	{
		va_arg(cp, int);
		j++;
	}
	to_ret = va_arg(cp, char*);
	va_end(sp->param_lst);
	va_copy(sp->param_lst, cp);
	va_end(cp);
	return (to_ret);
}

char		n_th_c(t_spec *sp, va_list orig, int i)
{
	va_list		cp;
	int			j;
	char		to_ret;
	
	va_copy(cp, orig);
	j = 1;
	while (j < i)
	{
		va_arg(cp, int);
		j++;
	}
	to_ret = (char)va_arg(cp, int);
	va_end(sp->param_lst);
	va_copy(sp->param_lst, cp);
	va_end(cp);
	return (to_ret);
}

char	*initial_s(t_spec *sp, va_list orig)
{
	char	*str;
	char	n_c;
	char	*n_s;
	
	if (sp->specifier == 'c')
	{
		n_c = (sp->param != 0) ? n_th_c(sp, orig, sp->param): (char)va_arg(sp->param_lst, int);
		str = (char*)ft_memalloc(2 * sizeof(char));
		str[0] = n_c;
		return (str);
	}
	else if (sp->specifier == 's')
	{
		n_s = (sp->param != 0) ? n_th_s(sp, orig, sp->param): va_arg(sp->param_lst, char*);
		str = ft_strdup(n_s);
		return (str);		
	}
	else
		return (NULL);
}