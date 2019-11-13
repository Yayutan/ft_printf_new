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

/*
** Function that sets up the basic string and the sign of the argument.
*/

int		setup_basic(t_spec *sp, union u_argument u_arg, char **basic)
{
	union u_double	u_d;
	union u_ldouble	u_ld;
	int				dec;
	
	if (sp->len == 16)
	{
		u_ld.ldbl = u_arg.ld;
		if ((u_ld.data[9] >> 7) & 1)
			sp->sign[0] = '-';
		else if (sp->flags[1] || sp->flags[2])
			sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
		dec = uldtoa_basic(u_ld, basic);
	}
	else
	{
		u_d.dbl = u_arg.d;
		if ((u_d.data[7] >> 7) & 1)
			sp->sign[0] = '-';
		else if (sp->flags[1] || sp->flags[2])
			sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
		dec = udtoa_basic(u_d, basic);
	}
	return (dec);
}

/*
** Function that forms the final string in the %f form
*/

char	*form_f(char *basic, int dec, int p, int hash)
{
	int		pre;

	pre = (p == -1) ? 6 : p;
	return (form_final(basic, dec, pre, hash));
}

/*
** Function that forms the final string in the %e form
*/

char	*form_e(char *basic, int exp, int p, int hash)
{
	int		pre;
	int		i;
	char	*to_ret;
	char	*pt1;

	pre = (p == -1) ? 6 : p;
	i = 0;
	while (basic[i] && basic[i] == '0')
		i++;
	if (basic[i])
		pt1 = form_final(basic + i, 0, pre, hash);
	else
		pt1 = ft_stradd("0.", '0', 1, pre);
	to_ret = append_exp(pt1, exp);
	free(pt1);
	return (to_ret);
}

char	*finalize_g(char *basic)
{
    char    *dec_pos;
	char	*to_ret;
	char	*tmp;
	int		end;

	dec_pos = ft_strchr(basic, 'e');
	end = (!dec_pos) ? ft_strlen(basic) - 1 : dec_pos - basic - 1;
	dec_pos = (!dec_pos) ? dec_pos : ft_strdup(dec_pos);
	while (basic[end] && basic[end] == '0' && basic[end] != '.')
		end--;
	end -= (basic[end] == '.');
	to_ret = ft_strsub(basic, 0, end + 1);
	if (dec_pos)
	{
		tmp = ft_strjoin(to_ret, dec_pos);
		free(to_ret);
		free(dec_pos);
		return (tmp);
	}
	return (to_ret);
}

/*
** Function that forms the final string in the %g form
** Result will be in %f or %e form according to precision and exp
*/

char	*form_g(char *basic, int dec, int exp, int p, int hash)
{
	int		pre;
    char    *to_ret;
	char	*tmp;

	if (p == -1)
		pre  = 6;
	else if (p == 0)
		pre = 1;
	else
		pre = p;
	if (exp >= -4 && exp < pre)
	{
		pre = pre - exp - 1;
		tmp = form_f(basic, dec, pre, hash);
	}
    else
	{
		pre = pre - 1;
		tmp = form_e(basic, exp, pre, hash);
	}
	if (hash || !pre)
		return (tmp);
	to_ret = finalize_g(tmp);
	free(tmp);
	return (to_ret);
}

char	*initial_feg(t_spec *sp, union u_argument u_arg)
{
	char	*basic;
	char	*to_ret;
	int		dec;
	int		exp;

	basic = NULL;
	dec = setup_basic(sp, u_arg, &basic);
	if (dec == -4242)
	{
		sp->flags[4] = 0;
		if (!ft_strcmp(basic, "nan"))
			sp->sign[0] = '\0';
		return (basic);
	}
	exp = calc_exp(basic, dec);
	if (sp->specifier == 'f' || sp->specifier == 'F')
		to_ret = form_f(basic, dec, sp->precision, sp->flags[3]);
	else if (sp->specifier == 'g' || sp->specifier == 'G')
		to_ret = form_g(basic, dec, exp, sp->precision, sp->flags[3]);
	else
		to_ret = form_e(basic, exp, sp->precision, sp->flags[3]);
	free(basic);
	return (to_ret);
}
