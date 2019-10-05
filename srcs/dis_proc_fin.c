/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_proc_fin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:58:33 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/28 11:58:36 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

char	*finalize(t_spec *sp, char *str) // process width, etc.
{
	char	*tmp;
	
	if (sp->width > (int)ft_strlen(str))
	{
		if ((!ft_strchr("diouxXb", sp->specifier) || sp->precision == -1) && sp->flags[4] && !sp->flags[0])
			tmp = ft_stradd(str, '0', -1, sp->width - (int)ft_strlen(str));
		else if (sp->flags[0])
			tmp = ft_stradd(str, ' ', 1, sp->width - (int)ft_strlen(str));
		else
			tmp = ft_stradd(str, ' ', -1, sp->width - (int)ft_strlen(str));
		free(str);
		str = tmp;
	}
	return str;
}

char	*d_p_f(t_spec *sp, va_list orig) // distribute, process, finalize
{
	char	*to_ret;
//	char	*tmp;
	
	if (ft_strchr("cs", sp->specifier))
		to_ret = initial_cs(sp, orig);
	else if (ft_strchr("diouxXb", sp->specifier))
		to_ret = initial_diouxb(sp, orig);
	else if (ft_strchr("feg", sp->specifier))
		to_ret = initial_feg(sp, orig);
//	else if (sp->specifier == 'k')
//		to_ret = ;
	else if (sp->specifier == 'p')
		to_ret = initial_p(sp, orig);
//	else if (sp->specifier == 'r')
//		to_ret = ;
	else if (sp->specifier == '%')
		to_ret = ft_strdup("%");
	else
		return (NULL);
//	to_ret = finalize(sp, to_ret);
	return (finalize(sp, to_ret));
}