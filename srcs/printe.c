/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:32:25 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/15 15:32:34 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*increment_e(char *dec, int pre)
{
	char	*tmp;
	char	*n_dec;
	char	*dot;

	n_dec = ft_strnew(ft_strlen(dec) + 1);
	n_dec[0] = '0';
	ft_strcpy(n_dec + 1, dec);
	free(dec);
	dec = ft_strdup(n_dec);
	tmp = dec;
	while (*tmp && ft_strchr("0.", *tmp))
		tmp++;
	dot = ft_strchr(tmp, '.');
	if (dot && dot - tmp <= pre)
	{
		if (*tmp && pre <= (int)ft_strlen(tmp) - 2 && *(tmp + pre + 2) >= '5')
			increment(dec, (tmp - dec) + pre + 1);
	}
	else // no dec in pre
	{
		if (*tmp && pre <= (int)ft_strlen(tmp) - 1 && *(tmp + pre + 1) >= '5')
			increment(dec, (tmp - dec) + pre);
	}
	return (dec);
}


int		calc_exp(char *dec)
{
	char	*d_pos;
	int		i;

	while (*dec && *dec == '0')
		dec++;
	d_pos = ft_strchr(dec, '.');
	if (!d_pos)
		return (ft_strlen(dec) - 1);
	else if (!ft_strchr("0.", dec[0]))
		return (d_pos - dec - 1);
	i = 1;
	while (d_pos[i] && d_pos[i] == '0')
		i++;
	if (!(d_pos[i]))
		return (0);
	return (i * -1);
}

//char	*form_dec(char *dec, int exp, int hash, int pre)
//{
//	char	*exp_s;  // 1 digit + . + prec + e/E + exp
//	int		i;
//	
//	exp_s = ft_itoa(exp); // pad 0 if |exp| < 10
//	i = 0;
//	while (dec[i] && dec[i])
//	
//	
//	
//	return (dec); // fix 
//}
