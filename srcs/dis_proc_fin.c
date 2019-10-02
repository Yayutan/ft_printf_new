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

char	*finalize(t_spec *sp, char *str) // process width, precision, etc.
{
	char	*res;
//	char	*tmp;
	
	res = ft_strdup(str);
	sp->valid = -1; // remove later
	return res;
}

char	*d_p_f(t_spec *sp, va_list orig) // distribute, process, finalize
{
	char	*to_ret;
	char	*tmp;
	
	if (sp->specifier == 'c')  // need to fix!!!!
		to_ret = initial_s(sp, orig);
		//return (c_special_unsigned(sp, orig));
	else if (sp->specifier == 's')
		to_ret = initial_s(sp, orig);
	else if (ft_strchr("diouxXb", sp->specifier))
		to_ret = initial_diouxb(sp, orig);
//	else if (ft_strchr("feg", sp->specifier))
//		to_ret = ;
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
	tmp = finalize(sp, to_ret);
	free(to_ret);
	to_ret = tmp;
	return (to_ret);
}