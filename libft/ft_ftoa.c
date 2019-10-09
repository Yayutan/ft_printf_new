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

static unsigned long long int pow_10(int n)
{
	int i;
	unsigned long long int	res;

	i = n;
	res = 1;
	while (i)
	{
		res *= 10;
		i--;
	}
	return (res);
}

char	*ft_ftoa(float d, int pre)
{
	char	*whole;
	char	*dec;
	char	*to_ret;
	float	de;
	float	d2;;
	
	d2 = (d < 0) ? -1 * d : d;
	whole = ft_ulltoa_base((unsigned long long int)d2, 10);
	de = (d2 - (unsigned long long int)d2) * pow_10(pre);
	if ((de -(unsigned long long int)de >= 0.5))
		dec = ft_ulltoa_base((unsigned long long int)(de + 1), 10);
	else
		dec = ft_ulltoa_base((unsigned long long int)de, 10);		
	to_ret = ft_strjoin(whole, ".");
	free(whole);
	whole = ft_strjoin(to_ret, dec);
	free(to_ret);
	if (d < 0)
		to_ret = ft_strjoin("-", whole);
	else
		to_ret = ft_strdup(whole);
	free(dec);		
	free(whole);
	return (to_ret);
}