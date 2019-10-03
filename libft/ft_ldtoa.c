/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:56:09 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/02 21:56:14 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ldtoa(long double d, int pre)
{
	char		*whole;
	char		*dec;
	char		*to_ret;
	long double		de;
	int			i;
	
	whole = ft_itoa((int)d);
	de = (d - (int)d) * 10;
	dec = ft_strnew(pre + 1);
	dec[0] = '.';
	i = 1;
	while (i <= pre)
	{
		dec[i] = (int)de + '0';
		de = (de - (int)de) * 10;
		i++;
	}
	to_ret = ft_strjoin(whole, dec);
	free(whole);
	free(dec);
	return (to_ret);
}