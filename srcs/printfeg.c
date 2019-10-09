/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfeg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:52:14 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/28 11:52:16 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


double		n_th_d(t_spec *sp, va_list orig, int i)
{
	va_list	cp;
	int		j;
	double	to_ret;
	
	va_copy(cp, orig);
	j = 1;
	while (j < i)
	{
		va_arg(cp, double);
		j++;
	}
	to_ret = va_arg(cp, double);
	va_end(sp->param_lst);
	va_copy(sp->param_lst, cp);
	va_end(cp);
	return (to_ret);
}

long double		n_th_ld(t_spec *sp, va_list orig, int i)
{
	va_list		cp;
	int			j;
	long double	to_ret;
	
	va_copy(cp, orig);
	j = 1;
	while (j < i)
	{
		va_arg(cp, long double);
		j++;
	}
	to_ret = va_arg(cp, long double);
	va_end(sp->param_lst);
	va_copy(sp->param_lst, cp);
	va_end(cp);
	return (to_ret);
}

char	*initial_feg(t_spec *sp, va_list orig)
{
	char	*to_ret;
	double	next;
	
	sp->precision = (sp->precision == -1) ? 6 : sp->precision;
	if (sp->len == 16)
	{
		if (sp->param != 0)
			to_ret = ft_ldtoa(n_th_ld(sp, orig, sp->param), sp->precision);
		else
			to_ret = ft_ldtoa(va_arg(sp->param_lst, long double), sp->precision);
	}
	else if (sp->specifier == 'f')
	{
		if (sp->param != 0)
			next = n_th_d(sp, orig, sp->param);
		else
			next = va_arg(sp->param_lst, double);
		if (next < 0)
		{
			sp->sign[0] = '-';
			next *= -1;
		} //  + and space?
		to_ret = pos_dtoa(next, sp->precision);
//		if (sp->param != 0)
//			to_ret = ft_dtoa(n_th_d(sp, orig, sp->param), sp->precision);
//		else
//			to_ret = ft_dtoa(va_arg(sp->param_lst, double), sp->precision);
	}
	else
		to_ret = NULL;
	return (to_ret);
}

// https://en.wikipedia.org/wiki/Single-precision_floating-point_format
// https://en.wikipedia.org/wiki/Double-precision_floating-point_format
// https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format

// http://cstl-csm.semo.edu/xzhang/Class%20Folder/CS280/Workbook_HTML/FLOATING_tut.htm