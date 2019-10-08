/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:51:56 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/28 11:52:05 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

char		*n_th_s(t_spec *sp, va_list orig, int i)
{
	va_list		cp;
	int			j;
	char		*to_ret;
	
	va_copy(cp, orig);
	j = 1;
	while (j < i)
	{
		va_arg(cp, int);
		j++;
	}
	to_ret = va_arg(cp, char*);
	va_end(sp->param_lst);
	va_copy(sp->param_lst, cp);
	va_end(cp);
	return (to_ret);
}

unsigned char		n_th_c(t_spec *sp, va_list orig, int i)
{
	va_list				cp;
	int					j;
	unsigned char		to_ret;
	
	va_copy(cp, orig);
	j = 1;
	while (j < i)
	{
		va_arg(cp, int);
		j++;
	}
	to_ret = (unsigned char)va_arg(cp, int);
	va_end(sp->param_lst);
	va_copy(sp->param_lst, cp);
	va_end(cp);
	return (to_ret);
}

char	*initial_cs(t_spec *sp, va_list orig)
{
	char	*str;
	unsigned char	n_c;
	char	*n_s;
	
	if (sp->specifier == 'c')
	{
		n_c = (sp->param != 0) ? n_th_c(sp, orig, sp->param): (unsigned char)va_arg(sp->param_lst, int);
		if (sp->flags[4] && !sp->flags[0])
			str = ft_stradd("", '0', -1, sp->width - 1);
		else
			str = ft_stradd("", ' ', -1, sp->width - 1);
		if (sp->flags[0])
		{
			buf_store_chr(sp->buf, n_c);
			buf_store_str(sp->buf, str);
		}
		else
		{
			buf_store_str(sp->buf, str);
			buf_store_chr(sp->buf, n_c);
		}
		free(str);
		return (ft_strnew(0));
	}
	else if (sp->specifier == 's')
	{
		n_s = (sp->param != 0) ? n_th_s(sp, orig, sp->param): va_arg(sp->param_lst, char*);
		if (!n_s)
			str = ft_strdup("(null)");
		else if (sp->precision < 0)
			str = ft_strdup(n_s);
		else	
			str = ft_strsub(n_s, 0, sp->precision);
		return (str);
	}
	else
		return (NULL);
}