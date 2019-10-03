/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:56:01 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/02 21:56:05 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		next_int(double d)
{
	int		to_ret;

	to_ret = 0;
	while (d > to_ret)
		to_ret++;
	return (to_ret - 1);
}


char	*ft_dtoa(double d, int pre)
{
	char	*whole;
	char	*dec;
	char	*to_ret;
	double	de;
	int		i;
	
	whole = ft_itoa(next_int(d));
	de = (d - next_int(d)) * 10;
	dec = ft_strnew(pre + 1);
	dec[0] = '.';
	i = 1;
	while (i <= pre)
	{
		dec[i] = next_int(de) + '0';
		de = (de - next_int(de)) * 10;
		i++;
	}
	to_ret = ft_strjoin(whole, dec);
	free(whole);
	free(dec);
	return (to_ret);
}


//http://www.ryanjuckett.com/programming/printing-floating-point-numbers/
// http://kurtstephens.com/files/p372-steele.pdf
// https://blog.benoitblanchon.fr/lightweight-float-to-string/