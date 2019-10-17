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


double		get_d_param(t_spec *sp, va_list orig)
{
	va_list	cp;
	int		j;
	double	to_ret;

	if(sp->param != 0)
	{
		va_copy(cp, orig);
		j = 1;
		while (j < sp->param)
		{
			va_arg(cp, double);
			j++;
		}
		to_ret = va_arg(cp, double);
		va_end(sp->param_lst);
		va_copy(sp->param_lst, cp);
		va_end(cp);
	}
	else
		to_ret = va_arg(sp->param_lst, double);
	return (to_ret);
}

long double		get_ld_param(t_spec *sp, va_list orig)
{
	va_list		cp;
	int			j;
	long double	to_ret;

	if(sp->param != 0)
	{
		va_copy(cp, orig);
		j = 1;
		while (j < sp->param)
		{
			va_arg(cp, long double);
			j++;
		}
		to_ret = va_arg(cp, long double);
		va_end(sp->param_lst);
		va_copy(sp->param_lst, cp);
		va_end(cp);
	}
	else
		to_ret = va_arg(sp->param_lst, long double);
	return (to_ret);
}

char	*initial_f(t_spec *sp, va_list orig)
{
	double		n_d;
	long double	n_ld;

	sp->precision = (sp->precision == -1) ? 6 : sp->precision;
	if (sp->len == 16)
	{
		n_ld = get_ld_param(sp, orig);
		if (n_ld < 0)
			sp->sign[0] = '-';
		else if (sp->flags[1] || sp->flags[2])
			sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
		return (uldtoa(n_ld, sp->precision, sp->flags[3]));
	}
	else
	{
		n_d = get_d_param(sp, orig);
		if (n_d < 0)
			sp->sign[0] = '-';
		else if (sp->flags[1] || sp->flags[2])
			sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
		return (udtoa(n_d, sp->precision, sp->flags[3]));
	}
}
