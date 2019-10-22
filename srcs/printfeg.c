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
		if ((long double)n_ld < 0)
			sp->sign[0] = '-';
		else if (sp->flags[1] || sp->flags[2])
			sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
		return (uldtoa(n_ld, sp->precision, sp->flags[3]));
	}
	else
	{
		n_d = get_d_param(sp, orig);
		if ((double)n_d < 0)
			sp->sign[0] = '-';
		else if (sp->flags[1] || sp->flags[2])
			sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
		return (udtoa(n_d, sp->precision, sp->flags[3]));
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
//	return (ft_itoa(exp));
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
