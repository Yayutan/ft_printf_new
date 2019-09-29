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

char	*do_dDi(t_spec *sp, long long int arg)
{
	char			*str;

	if (sp->specifier == 'D')
		str = ft_lltoa_base((long int)arg, 10);
	else if (sp->length[0] == '\0') // only di
		str = ft_lltoa_base((int)arg, 10);
	else if (sp->length[0] == 'h' && sp->length[0] == 'h')
		str = ft_lltoa_base((char)arg, 10);
	else if (sp->length[0] == 'h')
		str = ft_lltoa_base((short)arg, 10);
	else if (sp->length[0] == 'l' && sp->length[0] == 'l')
		str = ft_lltoa_base(arg, 10);
	else if (sp->length[0] == 'l')
		str = ft_lltoa_base((long)arg, 10);
	else
		str = NULL;
	return (str);
}

char	*do_OUB(t_spec *sp, long long int arg)
{
	char	*str;

	if (sp->specifier == 'O')
		str = ft_ulltoa_base((unsigned long int)arg, 8);
	else if (sp->specifier == 'U')
		str = ft_ulltoa_base((unsigned long int)arg, 10);
	else if (sp->specifier == 'B')
		str = ft_ulltoa_base((unsigned long int)arg, 2);
	else
		str = NULL;
	return (str);
}


char	*do_ouxb(t_spec *sp, long long int arg)
{
	char	*str;
	int		base;

	if (sp->specifier == 'o')
		base = 8;
	else if (ft_strchr("xX", sp->specifier))
		base = 16;
	else if (sp->specifier == 'u')
		base = 10;
	else if (sp->specifier == 'b')
		base = 2;
	if (sp->length[0] == '\0')
		str = ft_ulltoa_base((unsigned int) arg, base);
	else if (sp->length[0] == 'h' && sp->length[0] == 'h')
		str = ft_ulltoa_base((unsigned char)arg, base);
	else if (sp->length[0] == 'h')
		str = ft_ulltoa_base((unsigned short)arg, base);
	else if (sp->length[0] == 'l' && sp->length[0] == 'l')
		str = ft_ulltoa_base((unsigned long long)arg, base);
	else if (sp->length[0] == 'l')
		str = ft_ulltoa_base((unsigned long)arg, base);
	else
		str = NULL;
	return (str);
}

char	*initial_diouxb(t_spec *sp, va_list orig)
{
	char			*str;
	va_list			cp;
	int				i;
	long long int	arg;
	
	if (sp->param == 0)
		arg = va_arg(sp->param_lst, long long int);
	else
	{
		va_copy(cp, orig);
		i = 1;
		while (i < sp->param)
		{
			va_arg(cp, long long int);
			i++;
		}
		arg = va_arg(cp, long long int);
		va_end(cp);
	}
	if (ft_strchr("dDi", sp->specifier))
		str = do_dDi(sp, arg);
	else if (ft_strchr("OUB", sp->specifier))
		str = do_OUB(sp, arg);
	else
		str = do_ouxb(sp, arg);
	return (str);
}