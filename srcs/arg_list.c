/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:35:23 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/26 18:35:26 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"





int		add_param_info(char *ft, int i, t_args *arg, int *nxt_arg)
{
	while (ft[i] && ft_strchr(",;:_vaACSnjz0123456789hlL*.'#-+ ", ft[i]))
	{
		if (ft[i] >= '1' && ft[i] <= '9')
			i = num_arg(arg, ft, i); // make new node if $
		else if (ft[i] == '*') // *(next) or *n$(n) (diff in precision and width)
			i = star_arg(arg, ft, i, nxt_arg);
		else
			i++;
	}
	if (ft[i] && ft_strchr("dDioOuUxXbBfFeEgGcsprk%", ft[i]))
	{
		if (ft[i] != '%')
		{
			sp->specifier = (ft_strchr("DOUB", ft[i])) ? ft[i] + 32 : ft[i];
			
			// make new node (after *nxt_arg)	
		}
		i++;
	}
	return (i);
}

t_args	*set_args_lst(const char *format)
{
	t_args	*arg;
	int		i;
	int		arg_c;

	arg = NULL;
	i = 0;
	arg_c = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = add_param_info(format, i, arg, &arg_c);
		else
			i++;
	}
	
}
