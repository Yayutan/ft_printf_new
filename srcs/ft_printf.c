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
	while (ft[i] && ft_strchr("0123456789hlL*.'#-+ ", ft[i]))
	{
//		//////////////////
//		ft_putstr("Looking at : ");
//		ft_putchar(ft[i]);
//		ft_putchar('\n');
//		//////////////////
		if (ft[i] >= '1' && ft[i] <= '9')
			i = num_param(sp, ft, i);
		else if (ft[i] == '*')
			i = star_param(sp, ft, i, orig);
		else if (ft[i] == '.')
			i = dot_param(sp, ft, i, orig);
		else
			i = not_num_param(sp, ft, i);
	}
	if (ft_strchr("dDioOuUxXbBfegcsprk%", ft[i]))
	{
		sp->valid = 1;
		sp->specifier = ft[i]; // set type
		i++;
	}
	else
		sp->valid = -1;
	return (i);
}

//////////
# include <stdio.h>
/////////

int		ft_printf(const char *format, ...)
{
	int		i;
//	char	*s;	// the processed string to output and tmp for finding spec
	t_buf	*b; // the buffer
	t_spec	*spec; // the parameters set up
	va_list	ap_orig; // will always remain the same

	i = 0;
	b = buf_init();
	if (!(spec = (t_spec*)ft_memalloc(sizeof(t_spec))))
		return (-1);
	va_start(spec->param_lst, format);
	va_copy(ap_orig, spec->param_lst);
	while (format[i])
	{
		
		if (format[i] != '%')
		{
			buf_store_chr(b, format[i]);
			i++;
		}
		else
		{
			printf("Spec being set up for %s:..\n", format + i);
			i++;
			i = parse_format((char*)format, spec, i, ap_orig);
			printf("Param: %d\nFlags: %d%d%d%d%d%d\nWidth: %d\nPrecision: %d\nLength: %c%c\nSpecifier: %c\nValid: %d\n", spec->param, spec->flags[0], spec->flags[1], spec->flags[2], spec->flags[3], spec->flags[4], spec->flags[5], spec->width, spec->precision, spec->length[0], spec->length[1], spec->specifier, spec->valid);
			if (spec->valid > 0)
			{
				// process argument(as a list), depending on spec param			
//				buf_store_str(b, s); // store in buf (output and clear when full)			
//				free(s);	
			}
			else
			{
				// invalid, keep reading till next % or EOF, then format
			}
		}
	
	}
//	printf("Spec being set up for %s:..\n", format);
//	printf("Param: %d\nFlags: %d%d%d%d%d%d\nWidth: %d\nPrecision: %d\nLength: %c%c\nSpecifier: %c\nValid: %d\n", spec->param, spec->flags[0], spec->flags[1], spec->flags[2], spec->flags[3], spec->flags[4], spec->flags[5], spec->width, spec->precision, spec->length[0], spec->length[1], spec->specifier, spec->valid);
//	free(spec);
	buf_output_clear(b);
//	va_end(ap_actual);
//	va_end(ap_orig);
//	return(b_del(b));
	return (0);
}