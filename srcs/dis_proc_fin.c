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

# include "ft_printf.h"

char	*finalize(t_spec *sp, char *str) // process width, etc.
{
	char	*tmp; // sign pref precision str // sign pref width(0) str // width( ) sign pref precision str
	int	to_pad;
	
	to_pad = sp->width - (int)ft_strlen(str) - (int)ft_strlen(sp->pref) - (int)ft_strlen(sp->sign);
	if ((!ft_strchr("diouxXb", sp->specifier) || sp->precision < 0) && sp->flags[4] && !sp->flags[0])
	{
		tmp = ft_stradd(str, '0', -1, to_pad);
		free(str);
		str = tmp;		
	}
	tmp = ft_strjoin(sp->pref, str);
	free(str);
	str = ft_strjoin(sp->sign, tmp);
	free(tmp);
	if (sp->flags[0])
		tmp = ft_stradd(str, ' ', 1, sp->width - (int)ft_strlen(str));
	else
		tmp = ft_stradd(str, ' ', -1, sp->width - (int)ft_strlen(str));
	free(str);
	str = (ft_strchr("XEG", sp->specifier)) ? ft_strup(tmp) : tmp;
	return (str);
}


/*
** Function that forms the 
** First finds the next parameter, then distributes initial string processing
** functions according to the sp, then adds padding, signs, etc. to form the
** final string.
** Returns the final result of the output for the sp given.
*/

char	*d_p_f(t_spec *sp, t_arg *arg_lst, va_list orig) // distribute, process, finalize
{
	char	*to_ret;
	union argument arg;

	if (sp->specifier != '%' && sp->param == 0)
	{
		arg = next_arg(sp->arg, sp->param_lst);
		sp->arg = (sp->arg)->next;
	}
	else if (sp->specifier != '%')
	{
		va_copy(sp->param_lst, orig);
		arg = nth_arg_sp(arg_lst, sp->param, sp->param_lst);
		sp->arg = arg_lst_at(arg_lst, sp->param);
	}
	if (sp->specifier == 'c')
		return (initial_c(sp, arg, orig));
	else if (sp->specifier == 's')
		to_ret = initial_s(sp, arg, orig);
	else if (ft_strchr("diouxXb", sp->specifier))
		to_ret = initial_diouxb(sp, arg, orig);
	else if (ft_strchr("fFeEgG", sp->specifier))
		to_ret = initial_feg(sp, arg, orig);
//	else if (sp->specifier == 'k')
//		to_ret = ;
	else if (sp->specifier == 'p')
		to_ret = initial_p(sp, arg, orig);
//	else if (sp->specifier == 'r')
//		to_ret = ;
	else if (sp->specifier == '%')
		to_ret = ft_strdup("%");
	else
		return (NULL);
	return (finalize(sp, to_ret));
	
	
//	handle case for invalid		
//	s = ft_strsub(format, i, ft_strchr(format + i, '%') - (format + i));
//	tmp = finalize(spec, s);
//	buf_store_str(buf, tmp);
//	free(tmp);

}