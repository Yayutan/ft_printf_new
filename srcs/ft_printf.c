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

# include "../includes/ft_printf.h"


int		parse_format(char *ft, t_spec *sp, int i, va_list orig)
{
	clear_param(sp);
	while (ft[i] && ft_strchr(",;:_vaACSnjz0123456789hlL*.'#-+ ", ft[i]))
	{
		if (ft[i] >= '1' && ft[i] <= '9')
			i = num_param(sp, ft, i);
		else if (ft[i] == '*')
			i = star_param(sp, ft, i, orig);
		else if (ft[i] == '.')
			i = dot_param(sp, ft, i, orig);
		else
			i = not_num_param(sp, ft, i);
	}
	if (ft[i] && ft_strchr("dDioOuUxXbBfegcsprk%", ft[i]))
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

int		change_color(char *ft, int i, t_spec *sp)
{
	if (!ft_strncmp(ft + i, "{RED}", ft_strlen("{RED}")))
		buf_store_str(sp->buf, RED);
	else if (!ft_strncmp(ft + i, "{GREEN}", ft_strlen("{GREEN}")))
		buf_store_str(sp->buf, GREEN);
	else if (!ft_strncmp(ft + i, "{YELLOW}", ft_strlen("{YELLOW}")))
		buf_store_str(sp->buf, YELLOW);
	else if (!ft_strncmp(ft + i, "{BLUE}", ft_strlen("{BLUE}")))
		buf_store_str(sp->buf, BLUE);
	else if (!ft_strncmp(ft + i, "{MAG}", ft_strlen("{MAG}")))
		buf_store_str(sp->buf, MAG);
	else if (!ft_strncmp(ft + i, "{CYAN}", ft_strlen("{CYAN}")))
		buf_store_str(sp->buf, CYAN);
	else if (!ft_strncmp(ft + i, "{CLEAR}", ft_strlen("{CLEAR}")))
		buf_store_str(sp->buf, CLEAR);
	else
		return (i);
	while (ft[i] && ft[i - 1] != '}')
		i++;
	return (i);
}

//////////
//# include <stdio.h>
/////////

int		ft_printf(const char *format, ...)
{
	int		i;
	int 	j;
	char	*s;
	char	*tmp;
	t_spec	*spec;
	va_list	ap_orig;

	i = 0;
	if (!(spec = (t_spec*)ft_memalloc(sizeof(t_spec))))
		return (-1);
	spec->buf = buf_init();
	va_start(spec->param_lst, format);
	va_copy(ap_orig, spec->param_lst);
	while (format[i])
	{
		if (format[i] == '{')
			i = change_color((char*)format, i, spec);
		if (format[i] != '%')
			buf_store_chr(spec->buf, format[i++]);
		else
		{
//			printf("Spec being set up for %s:..\n", format + i);
			i = parse_format((char*)format, spec, i + 1, ap_orig);
//			printf("Param: %d\nFlags: %d%d%d%d%d%d\nWidth: %d\nPrecision: %d\nLength: %d\nSpecifier: %c\nValid: %d\n", spec->param, spec->flags[0], spec->flags[1], spec->flags[2], spec->flags[3], spec->flags[4], spec->flags[5], spec->width, spec->precision, spec->len, spec->specifier, spec->valid);
			if (spec->valid > 0)
			{
				s = d_p_f(spec, ap_orig);
				buf_store_str(spec->buf, s);
				free(s); // cannot free???	
			}
			else
			{
				j = i;
				while (format[i] && format[i] != '%')
					i++;
				s = ft_strsub(format, j, i - j);
				tmp = finalize(spec, s);
				buf_store_str(spec->buf, tmp);
				free(tmp); // cannot free???	
			}
		}
	
	}
	buf_output_clear(spec->buf);
	i = buf_del(spec->buf);
	va_end(spec->param_lst);
	free(spec);
	va_end(ap_orig);
	return (i);
}