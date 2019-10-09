/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_scientific.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 05:25:28 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/05 05:25:30 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	increment(char *res, int index)
{
	res[index] = (res[index] + 1) % 10;
	if (res[index] == 0)
		increment(res, index - 1);
}

//void	form_whole_str(char *res, double d, int exp, int precision)
//{
//	int		i;
//	int		j;
//	char	*next;
//
//	ft_bzero(res, 309 + 1 + precision);
//	i = (exp >= 0) ? 1 : exp * -1;
//	while (i <= exp + precision)
//	{
//			///////////////// // can use in e
////		if (exp + precision - i >= 18)
////			d *= pow_10(17);
////		else
////			d *= pow_10(exp + precision - i + 1);
////		next = ft_ulltoa_base((unsigned long long int)d, 10);
////		d -= (unsigned long long int)d;
////		j = 0;
////		while (next[j])
////			res[i++] = next[j++];
////		free(next);
//			/////////////
//	}
//	if (d >= 5)
//		increment(res, i);
//}

void	form_dec_str(char *res, double d, int exp, int precision)
{
	int		i;
	int		j;
	char	*next;

	ft_bzero(res, 309 + 1 + precision);
	i = (exp >= 0) ? 1 : exp * -1;
	exp = (exp >= 0) ? exp : 0;
	while (i <= exp + precision)
	{
			/////////////// // can use in e
		if (exp + precision - i >= 18)
			d *= pow_10(17);
		else
			d *= pow_10(exp + precision - i + 1);
		next = ft_ulltoa_base((unsigned long long int)d, 10);
		d -= (unsigned long long int)d;
		j = 0;
		while (next[j])
			res[i++] = next[j++];
		free(next);
	}
	if (d >= 5)
		increment(res, i);
}

void	fill_in(char *dest, char *src, int len)
{
	int i_d;
	int i_s;

	i_d = 0;
	i_s = (src[0]) ? 0 : 1;
	while (i_d < len)
	{
		if (dest[i_d] == '.')
			i_d++;
		else
//			dest[i_d++] = src[i_s++] + '0';
			dest[i_d++] = src[i_s++];
	}
}

char	*pos_dtoa(double d, int precision) // d is already pos; 0 precision????
{
	char	*to_ret;
	char	num_str[309 + 1 + precision];
	int		exp;
	double	cur;
	int		len;
	
	cur = d;
	exp = (cur > 1) ? find_large_ex(0, &cur) : find_large_neg_ex(0, &cur);
	form_dec_str(num_str, cur, exp, precision);
	if (num_str[0])
		exp++;
	len = (exp >= 0) ? (exp + 2 + precision) : (2 + precision);
	to_ret = ft_strnew(len);
	if (exp >= 0)
		to_ret[exp + 1] = '.';
	else
		to_ret[1] = '.';
	fill_in(to_ret, num_str, len);
	return (to_ret);
}