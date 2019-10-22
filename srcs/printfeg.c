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

#include "ft_printf.h"


union u_double		get_d_param(t_spec *sp, va_list orig)
{
	union u_double	u_d;
	va_list	cp;
	int		j;

	if(sp->param != 0)
	{
		va_copy(cp, orig);
		j = 1;
		while (j < sp->param)
		{
			va_arg(cp, double);
			j++;
		}
		u_d.dbl = va_arg(cp, double);
		va_end(sp->param_lst);
		va_copy(sp->param_lst, cp);
		va_end(cp);
	}
	else
		u_d.dbl = va_arg(sp->param_lst, double);
	return (u_d);
}

union u_ldouble		get_ld_param(t_spec *sp, va_list orig)
{
	union u_ldouble	u_ld;
	va_list		cp;
	int			j;

	if(sp->param != 0)
	{
		va_copy(cp, orig);
		j = 1;
		while (j < sp->param)
		{
			va_arg(cp, long double);
			j++;
		}
		u_ld.ldbl = va_arg(cp, long double);
		va_end(sp->param_lst);
		va_copy(sp->param_lst, cp);
		va_end(cp);
	}
	else
		u_ld.ldbl = va_arg(sp->param_lst, long double);
	return (u_ld);
}

char	*initial_f(t_spec *sp, va_list orig)
{
	union u_double	u_d;
	union u_ldouble	u_ld;

	sp->precision = (sp->precision == -1) ? 6 : sp->precision;
	if (sp->len == 16)
	{
		u_ld = get_ld_param(sp, orig);
		if ((u_ld.data[9] >> 7) & 1)
			sp->sign[0] = '-';
		else if (sp->flags[1] || sp->flags[2])
			sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
		return (uldtoa(u_ld, sp->precision, sp->flags[3]));
	}
	else
	{
		u_d = get_d_param(sp, orig);
		if ((u_d.data[7] >> 7) & 1)
			sp->sign[0] = '-';
		else if (sp->flags[1] || sp->flags[2])
			sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
		return (udtoa(u_d, sp->precision, sp->flags[3]));
	}
}

char	*initial_e(t_spec *sp, va_list orig)
{
	char	*f_res;
	char	*to_ret;
	int		pre;
	int		exp;

	pre = (sp->precision == -1) ? 6 : sp->precision;
	sp->precision = LEN;
	f_res = initial_f(sp, orig);
	sp->precision = pre;
	f_res = increment_e(f_res, pre); // rounding is done here
	exp = calc_exp(f_res);
	to_ret = form_dec(f_res, exp, sp->flags[3], pre);
	free(f_res);
	return (to_ret);
}

char	*initial_g(t_spec *sp, va_list orig)
{
	char	*f_res;
	char	*e_res;

	f_res = initial_f(sp, orig);
	e_res = initial_e(sp, orig);
	if (ft_strlen(f_res) < ft_strlen(e_res))
	{
		free(e_res);
		return (f_res);
	}
	else
	{
		free(f_res);
		return (e_res);
	}
}
