/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:55:39 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/02 21:55:58 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float f, int pre)
{
	char	*whole;
	char	*dec;
	char	*to_ret;
	float	de;
	int		i;
	
	whole = ft_itoa((int)f);
	de = (f - (int)f) * 10;
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