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

int		parse_format(char *ft, t_spec *sp, int i, va_list orig)
{
	clear_param(sp);
	while (ft[i] && ft_strchr(",;:_vaACSnjz0123456789hlL*.'#-+ ", ft[i]))
	{
		if (ft[i] >= '1' && ft[i] <= '9')
			 i = num_param(sp, ft, i);
		else if (ft[i] == '*')
			i = star_param(sp, ft, i + 1, orig);
		else if (ft[i] == '.')
			i = dot_param(sp, ft, i + 1, orig);
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
	return (i);
}

void		process_output(char *format, t_buf *buf, t_args *arg_info, va_list ap_orig)
{
	int		i;
	t_spec	*sp;
	char	*res;

	if(!(sp = (t_spec*)ft_memalloc(sizeof(t_spec*))))
		ft_err_exit("Failed to allocate specifications");
	i = 0;
	while (format[i])
	{
		if (format[i] == '{')
			i = change_color(format, i, buf);
		else if (format[i] != '%')
			buf_store_chr(buf, format[i++]);
		else
		{
			i = parse_format(format, sp, i + 1, ap_orig);
			res = d_p_f(sp, ap_orig);
			buf_store_str(buf, res);
			free(res);
		}
	}
	arg_info++; // remove later
}

int		ft_printf(const char *format, ...)
{
	t_buf   *buf;
	va_list	ap_orig;
	t_args	*arg_info;

	if (!(buf = buf_init()))
		return (-42);
	va_start(ap_orig, format);
	arg_info = set_args_lst(format);
	process_output(format, buf, arg_info, ap_orig);
	va_end(ap_orig);
	buf_output_clear(buf);
	return (buf_del(buf));
}
	
	
//	int		i;
//	int 	j;
//	char	*s;
//	char	*tmp;
//	t_spec	*spec;
//  t_buf   *buf;
//	va_list	ap_orig;
//
//	i = 0;
//	if (!(spec = (t_spec*)ft_memalloc(sizeof(t_spec))))
//		return (-1);
//	spec->buf = buf_init();
//	va_start(ap_orig, format);
//    // arg info
//	va_end(ap_orig);
//	while (format[i])
//	{
//		if (format[i] == '{')
//			i = change_color((char*)format, i, spec);
//		if (format[i] != '%')
//			buf_store_chr(spec->buf, format[i++]);
//		else
//		{
//			i = parse_format((char*)format, spec, i + 1, ap_orig);
//			if (spec->valid > 0)
//			{
//				s = d_p_f(spec, ap_orig);
//				buf_store_str(spec->buf, s);
//				free(s);
//			}
//			else
//			{
//				j = i;
//				while (format[i] && format[i] != '%')
//					i++;
//				s = ft_strsub(format, j, i - j);
//				tmp = finalize(spec, s);
//				buf_store_str(spec->buf, tmp);
//				free(tmp);
//			}
//		}
//	}
//	buf_output_clear(spec->buf);
//	free(spec);
//	return (buf_del(buf));