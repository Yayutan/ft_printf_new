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

# include "../includes/ft_printf.h"

char	*add_apos(char *s)
{
	char	*to_ret;
	int		i;
	int		j;

	i = (ft_strchr(" -+", s[0])) ? 1 : 0 ;
	to_ret = ft_strnew(ft_strlen(s) + (ft_strlen(s) - 1 - i) / 3);
    i = ft_strlen(s) + (ft_strlen(s) - 1 - i) / 3 - 1;
	j = 0;
	to_ret[0] = s[0];
	while (i > 0)
	{
		if (j % 3 == 0 && j != 0)
		{
			to_ret[i--] = ','; // ? localconv?
			to_ret[i] = s[ft_strlen(s) - 1 - j];
		}
		else
			to_ret[i] = s[ft_strlen(s) - 1 - j];
		j++;
		i--;		
	}
	return (to_ret);
}

char	*do_di(t_spec *sp, long long int arg)
{
	char	*str;
	char	*tmp;

	str = NULL;
	if (sp->precision == 0 && arg == 0)
		return (ft_strnew(0));
	else if (sp->len == 4)
		str = ft_lltoa_base(((int)arg > 0) ? (int)arg : (int)(~arg + 1), 10);
	else if (sp->len == 1)
		str = ft_lltoa_base(((char)arg > 0) ? (char)arg : (char)(~arg + 1), 10);
	else if (sp->len == 2)
		str = ft_lltoa_base(((short)arg > 0) ? (short)arg : (short)(~arg + 1), 10);
	else if (sp->len == 8)
		str = ft_lltoa_base((arg > 0) ? arg : (~arg + 1), 10);
	if ((arg >> (8 * sp->len - 1)) & 1)
		sp->sign[0] = '-';
	else if (sp->flags[1] || sp->flags[2])
		sp->sign[0] = (sp->flags[1]) ? '+' : ' ';
	if (str[0] == '-')
	{
		tmp = ft_strsub(str, 1, ft_strlen(str) - 1);
		free(str);
		str = tmp;
	}
	if (sp->flags[5])
	{
		tmp = add_apos(str);
		free(str);
		str = tmp;	
	}
	return (str);
}

char	*do_ouxXb(t_spec *sp, long long int arg)
{
	char	*str;
	int		base;

	str = NULL;
	if (sp->precision == 0 && arg == 0)
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
		str = ft_ulltoa_base((unsigned int) arg, base);
	else if (sp->len == 1)
		str = ft_ulltoa_base((unsigned char)arg, base);
	else if (sp->len == 2)
		str = ft_ulltoa_base((unsigned short)arg, base);
	else if (sp->len == 8)
		str = ft_ulltoa_base((unsigned long long)arg, base);
	return (str);
}

char	*split_n_fix(t_spec *sp, long long int arg)
{
	char	*str;
	char	*tmp;

	if (ft_strchr("di", sp->specifier))
		str = do_di(sp, arg);
	else
		str = do_ouxXb(sp, arg);
	tmp = ft_stradd(str, '0', -1, sp->precision - (int)ft_strlen(str));
	free(str);
	str = tmp;
	if (ft_strchr("bxX", sp->specifier) && arg != 0 && sp->flags[3])
	{
		if (sp->specifier == 'b')
			sp->pref[0] = 'b';
		else
		{
			sp->pref[0] = '0';
			sp->pref[1] = 'x';
		}
	}
    else if (sp->specifier == 'o' && sp->flags[3] && str[0] != '0')
		sp->pref[0] = '0';
	return (str);
}

char	*initial_diouxb(t_spec *sp, va_list orig)
{
	va_list			cp;
	int				i;
	long long int	arg;
	
	if (sp->len == -1)
		sp->len = 4;
	if (sp->param == 0)
		arg = va_arg(sp->param_lst, long long int);
	else
	{
		va_copy(cp, orig);
		i = 1;
		while (i++ < sp->param)
			va_arg(cp, long long int);
		arg = va_arg(cp, long long int);
		va_end(sp->param_lst);
		va_copy(sp->param_lst, cp);
		va_end(cp);
	}
	return (split_n_fix(sp, arg));
}