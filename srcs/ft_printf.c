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

int	ft_printf(const char *format, ...)
{
	int		i;
	char	*s;	// the processed string to output
	t_buf	*b;
	

	i = 0;
	b = buf_init();
	while (format[i]) // for each argument(part of format)
	{
		if (format[i] != '%') // not yet found %
		{
			s = ft_strsub(format, i, 1);
			
			
			
			
		}
		else // start complex part
		{
			// identify & splice specs(substr) for next arg

			// set up spec str as param

			// retrieve next arg

			// process argument, depending on spec param			
			
		}
		buf_store(b, s); // store in buf (output and clear when full)			
		i++;
		free(s);
	}
	buf_output_clear(b);
//	buf_del(b);
	return (0); //?
}