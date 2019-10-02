/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:52:24 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/28 11:52:26 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

char	*initial_p(t_spec *sp, va_list orig)
{
	char			*str;
	char			*address;
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
	address = ft_ulltoa_base(arg, 16);
	str = ft_strjoin("0x", address);
	free(address);
	return (str);
}