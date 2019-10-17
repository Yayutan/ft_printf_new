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

#include "../includes/ft_printf.h"

static void	increment(char *n1, int index)
{
	n1[index] = ((n1[index] - '0' + 1) % 10) + '0';
	if (n1[index] == '0')
		increment(n1, index - 1);
}

//void	form_str_large(char *res, double d, int exp, int precision)
//{
//	int		i;
//	int		j;
//	char	*next;
//	unsigned long long int n;
//
//	ft_bzero(res, 309 + 1 + precision);
//	i = 1;
//	while (i <= exp + precision)
//	{
//		if (d >= 10e17)
//		{
//			n = d / ;
//			d = ;
//		}			
//		else
//		{
//			n = (unsigned long long int)d;
//			d = (d - n >= 1) ?  d - n : (d - n) * pow_10(16);
//		}
//		next = ft_ulltoa_base(d, 10);
//		j = 0;
//		while (next[j] && i <= exp + precision)
//			res[i++] = next[j++];
//		free(next);
//	}
//	if (d >= 5)
//		increment(res, i);
//}

void	form_str_small(char *res, double d, int exp, int precision)
{
	int		i;
	int		j;
	char	*next;

	ft_bzero(res, 309 + 1 + precision);
	i = (exp >= 0) ? 1 : exp * -1 + 1;
	exp = (exp >= 0) ? exp : 0;
	while (i <= exp + precision)
	{
		if (exp + precision - i >= 18)
			d *= pow_10(17);
		else
			d *= pow_10(exp + precision - i + 1);
		next = ft_ulltoa_base((unsigned long long int)d, 10);
		d -= (unsigned long long int)d;
		j = 0;
		while (next[j])
			res[i++] = next[j++] - '0';
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
			dest[i_d++] = src[i_s++] + '0';
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
//	if (exp <= 5)
//		form_str_small(num_str, cur, exp, precision);
//	else
//		form_str_large(num_str, d, exp, precision);
		form_str_small(num_str, cur, exp, precision);
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
