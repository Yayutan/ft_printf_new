/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdiouxb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:52:08 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/28 11:52:11 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*do_di(t_spec *sp, union u_argument u_arg)
{
	char			*str;
	char			*tmp;

	str = NULL;
	if (sp->precision == 0 && check_zero(sp->len, u_arg))
		str = ft_strnew(0);
	else if (sp->len == 4)
		str = ft_lltoa_base((int)bit_abs(u_arg.lli, 4), 10);
	else if (sp->len == 1)
		str = ft_lltoa_base((char)bit_abs(u_arg.lli, 1), 10);
	else if (sp->len == 2)
		str = ft_lltoa_base((short)bit_abs(u_arg.lli, 2), 10);
	else if (sp->len == 8)
		str = ft_lltoa_base(bit_abs(u_arg.lli, 8), 10);
	if ((u_arg.lli >> (8 * sp->len - 1)) & 1)
		sp->sign[0] = '-';
	else if (sp->flags[1] || sp->flags[2])
		sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
	if (str[0] == '-')
	{
		tmp = ft_strsub(str, 1, ft_strlen(str) - 1);
		free(str);
		str = tmp;
	}
	return ((sp->flags[5]) ? add_apos(str) : str);
}

char	*do_ouxb(t_spec *sp, union u_argument u_arg)
{
	char	*str;
	int		base;

	str = NULL;
	if (sp->precision == 0 && u_arg.lli == 0)
		return (ft_strnew(0));
	else if (sp->specifier == 'o')
		base = 8;
	else if (ft_strchr("xX", sp->specifier))
		base = 16;
	else if (sp->specifier == 'u')
		base = 10;
	else if (sp->specifier == 'b')
		base = 2;
	if (sp->len == 4)
		str = ft_ulltoa_base((unsigned int)u_arg.i, base);
	else if (sp->len == 1)
		str = ft_ulltoa_base((unsigned char)u_arg.uc, base);
	else if (sp->len == 2)
		str = ft_ulltoa_base((unsigned short)u_arg.sh, base);
	else if (sp->len == 8)
		str = ft_ulltoa_base((unsigned long long int)u_arg.lli, base);
	return (str);
}

char	*initial_diouxb(t_spec *sp, union u_argument u_arg)
{
	char	*str;
	char	*tmp;

	if (sp->len == -1 || sp->len == 16)
		sp->len = 4;
	if (check_zero(sp->len, u_arg))
		u_arg.lli = 0;
	if (ft_strchr("di", sp->specifier))
		str = do_di(sp, u_arg);
	else
		str = do_ouxb(sp, u_arg);
	tmp = ft_stradd(str, '0', -1, sp->precision - (int)ft_strlen(str));
	free(str);
	str = tmp;
	if (ft_strchr("bxX", sp->specifier) && u_arg.lli != 0 && sp->flags[3])
	{
		sp->pref[0] = (sp->specifier == 'b') ? 'b' : '0';
		sp->pref[1] = (ft_strchr("xX", sp->specifier)) ? 'x' : '\0';
	}
	else if (sp->specifier == 'o' && sp->flags[3] && str[0] != '0')
		sp->pref[0] = '0';
	return (str);
}
