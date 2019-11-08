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

int		setup_basic(t_spec *sp, union u_argument u_arg, char *basic)
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

char	*form_f(char *basic, int dec, int p, int hash)
{
	int		pre;

	pre = (p == -1) ? 6 : p;
	return (form_final(basic, dec, pre, hash));
}

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
		pt1 = ft_stradd("0.", '0', 1, pre); // 0.000
	to_ret = append_exp(pt1, exp);
	free(pt1);
	return (to_ret);
}

char	*form_g(char *basic, int dec, int exp, int p, int hash)
{
	int		pre;
    char    *to_ret;
    char    *dec_pos;
	char	*tmp;
	int		end;

	if (p == -1)
		pre  = 6;
	else if (p == 0)
		pre = 1;
	else
		pre = p;
	if (exp >= -4 && exp < pre)
        tmp = form_f(basic, dec, pre - exp - 1, hash);
    else
        tmp = form_e(basic, exp, pre - 1, hash);
	if (hash)
		return (tmp);
    dec_pos = ft_strchr(tmp, 'e');
	if (!dec_pos) // f
	{
		end = ft_strlen(tmp) - 1;
		while (tmp[end] && tmp[end] == '0')
			end--;
		if (tmp[end] == '.')
			end--;
		to_ret = ft_strsub(tmp, 0, end + 1);
		free(tmp);
		return (to_ret);
	}
	else // refactor duplicate parts
	{
		end = dec_pos - tmp;
    	dec_pos = ft_strdup(dec_pos);
		while (tmp[end] && tmp[end] == '0')
			end--;
		to_ret = ft_strsub(tmp, 0, end);
		free(tmp);
		tmp = ft_strjoin(to_ret, dec_pos);
		free(to_ret);
		free(dec_pos);
		return (tmp);
	}
}

char	*initial_feg(t_spec *sp, union u_argument u_arg)
{
	char	*basic;
	char	*to_ret;
	int		dec;
	int		exp;

	basic = ft_strnew(LEN);
	dec = setup_basic(sp, u_arg, basic);
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
