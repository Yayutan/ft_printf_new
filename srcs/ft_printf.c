/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:37:19 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/24 16:37:37 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

/*
** From the given index of the format string, set up the format spec of the
** next part of the output.
** Returns the index of the beginning of the part after this one.
*/

int		parse_format(char *ft, t_spec *sp, t_args *arg_l, va_list orig)
{
	int 	i;
	
	i = 0;
	while (ft[i] && ft_strchr(",;:_vaACSnjz0123456789hlL*.'#-+ ", ft[i]))
	{
		if (ft[i] >= '1' && ft[i] <= '9')
			 i = num_param(sp, ft, i);
		else if (ft[i] == '*')
			i += star_param(&(sp->width), ft + i + 1, sp, arg_l, orig);
		else if (ft[i] == '.')
			i += dot_param(&(sp->precision), ft + i + 1, sp, arg_l, orig);
		else
			i = not_num_param(sp, ft, i);
	}
	if (ft[i] && ft_strchr("dDioOuUxXbBfFeEgGcsprk%", ft[i]))
	{
		sp->valid = 1;
		sp->specifier = (ft_strchr("DOUB", ft[i])) ? ft[i] + 32 : ft[i];
		sp->len = (ft_strchr("DOUB", ft[i])) ? 8 : sp->len;
		i++;
	}
	else
		sp->valid = -1;
	return (i + 1);
}


/*
** Iterates through the format string, sets up format and form output
** accordingly to put in the buffer.
*/

void		process_output(char *format, t_buf *buf, t_args *arg_l, va_list ap_orig)
{
	int		i;
	t_spec	*sp;
	char	*res;

	if(!(sp = (t_spec*)ft_memalloc(sizeof(t_spec))))
		ft_err_exit("Failed to allocate specifications");
	i = 0;
	sp->arg = arg_l;
	va_copy(sp->param_lst, ap_orig);
	while (format[i])
	{
		if (format[i] == '{')
			i = change_color(format, i, buf);
		if (format[i] != '%')
			buf_store_chr(buf, format[i++]);
		else
		{
			clear_param(sp);
			i += parse_format(format + i + 1, sp, arg_l, ap_orig);
			if (sp->valid > 0)
				res = d_p_f(buf, sp, arg_l, ap_orig);
			else
				res = invalid_format(sp, format, &i);
			buf_store_str(buf, res);
			free(res);
		}
	}
	va_end(sp->param_lst);
	free(sp);
}

/*
** Iterates the format string to set up all arguments used.
** Whenever we find the '%', we start looking into that "set" of format and 
** add nodes to the argument list if needed.
** Returns the list of arguments with their types.
*/

t_args	*set_args_lst(char *format) // closed for now, not tested
{
	t_args	*arg;
	int		i;
	int		arg_c;

	arg = NULL;
	i = 0;
	arg_c = 1;
	while (format[i])
	{
		if (format[i] == '%')
			i = add_arg_info(format, i + 1, &arg, &arg_c);
		else
			i++;
	}
	return (arg);
}

/*
** Function that prints out formatted output from the format str and the given
** arguments.
** First forms a linked list of arguement types, then processes and outputs
** each part of the format string.
** Returns the number of characters output.
*/

int		ft_printf(const char *format, ...)
{
	t_buf   *buf;
	va_list	ap_orig;
	t_args	*arg_info;

	if (!(buf = buf_init()))
		return (-42);
	va_start(ap_orig, format);
	arg_info = set_args_lst((char*)format);
	process_output((char*)format, buf, arg_info, ap_orig);
	va_end(ap_orig);
	arg_lst_del(arg_info);
	buf_output_clear(buf);
	return (buf_del(buf));
}
