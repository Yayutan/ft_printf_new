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
	if (!*tmp)
		return (dec);
	dot = ft_strchr(tmp, '.');
	if (dot && dot - tmp <= pre)
	{
		if (*tmp && pre <= (int)ft_strlen(tmp) - 2 && *(tmp + pre + 2) >= '5')
			increment(dec, (tmp - dec) + pre + 1);
		if (pre <= (int)ft_strlen(tmp) - 2)
			clear_digits(tmp + pre + 2);
	}
	else
	{
		if (*tmp && pre <= (int)ft_strlen(tmp) - 1 && *(tmp + pre + 1) >= '5')
			increment(dec, (tmp - dec) + pre);
		if (pre <= (int)ft_strlen(tmp) - 1)
			clear_digits(tmp + pre + 1);
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

char	*form_dec(char *dec, int exp, int hash, int pre)
{
	char	*exp_s;  // 1 digit + (.) + prec + e/E + exp_sign + (0) + exp
    char    *to_ret; // 3 + (0) + (.) + prec + exp (handle hash)
	int		i;
	int		j;

	while (*dec && ft_strchr(".0", *dec))
		dec++;
	exp_s = (exp < 0) ? ft_itoa(-1 * exp) : ft_itoa(exp);
	i = pre + ft_strlen(exp_s) + 3;
	if (ft_strlen(exp_s) < 2)
        i++;
	if (pre > 0 || hash)
		i++;
	to_ret = ft_strnew(i);
	to_ret[0] = (*dec) ? dec[0] : '0';
	to_ret[1] = '.';
	i = 2;
	j = 1;
	while (i < pre + 2)
	{
		if (!(*dec))
			to_ret[i++] = '0';
		else if (dec[j] != '.')
			to_ret[i++] = dec[j];
		j++;
	}
	to_ret[i++] = 'e';
	to_ret[i++] = (exp >= 0) ? '+' : '-';
	if (ft_strlen(exp_s) < 2)
		to_ret[i++] = '0';
	ft_strcpy(to_ret + i, exp_s);
	return (to_ret); // fix 
}

char	*append_exp(char *dec, int exp)
{
	char	*to_ret;
	char	*tmp;

	tmp = ft_strjoin(dec, "e");
	if (exp < 0)
		to_ret = ft_itoa(exp * -1);
	else
		to_ret = ft_itoa(exp);
	
	// if to_ret len < 2, add 0
	
}