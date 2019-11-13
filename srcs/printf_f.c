/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:50:32 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/17 01:50:36 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Sets all characters after a certain index to 0 in a double string
*/

void	clear_digits(char *n, int pos)
{
	int		i;
	int		len;

	len = ft_strlen(n);
	i = pos;
	while (i < len && n[i])
	{
		if (n[i] != '.')
			n[i] = '0';
		i++;
	}
}

/*
** Function that forms the final version of the (long) double string according
** to infomation given.
** 1. Handles whether rounding is needed, then clears off all redundant digits
** 2. Removes redundant '0's before the actual digits to print
** 3. Add in decimal points and cut off digits out of precision
*/

char	*form_final(char *man, int dec, int pre, int hash)
{
	int		i;
	char	*s[3];

	if (dec + pre + 1 < LEN && man[dec + pre + 1] >= '5')
		increment(man, dec + pre);
	clear_digits(man, dec + pre + 1);
	i = 0;
	while (man[i] && man[i] == '0' && i < dec)
		i++;
	s[0] = ft_strsub(man, i, dec - i + 1);
	s[1] = (pre > 0 || hash) ? ft_strjoin(s[0], ".") : ft_strdup(s[0]);
	free(s[0]);
	if (dec + pre < LEN)
		s[0] = ft_strsub(man, dec + 1, pre);
	else
	{
		s[2] = ft_strdup(man + (dec + 1));
		s[0] = ft_stradd(s[2], '0', 1, pre - (LEN - dec));
		free(s[2]);
	}
	s[2] = ft_strjoin(s[1], s[0]);
	free(s[0]);
	free(s[1]);
	return (s[2]);
}

/*
** Function that forms a basic long double string and stores it in str.
** 1. Uses bit operations to extract the exp and mantissa
** 2. Uses arbitrary precision operations to have the accurate string
** representation of the long double
** <NOTE> Precision, rounding, and decimal pt not handled here
** Returns index of the decimal point within the basic string
** <For norm> m_sh: 0->mantissa != 0, 1->shift
*/

int		uldtoa_basic(union u_ldouble u_ld, char **str)
{
	int				exp;
	char			man[DEC + 1];
	char			res[LEN + 1];
	int				m_sh[2];

	exp = get_ld_exp(u_ld);
	clear_str(man, DEC);
	m_sh[0] = get_ld_mantissa(u_ld, man);
	clear_str(res, LEN);
	if (exp == -16383 && !m_sh[0])
	{
		*str = ft_strdup(res);
		return (WH + 1);
	}
	else if (exp == -16383 && m_sh[0])
		divi(man, "2");
	else if (exp == 16384)
	{
		*str = (m_sh[0]) ? ft_strdup("nan") : ft_strdup("inf");
		return (-4242);
	}
	ft_strcpy(res + WH + 1, man);
	m_sh[1] = shift_mantissa(res, exp);
	*str = ft_strdup(res);
	return (WH + 1 - m_sh[1]);
}

/*
** Function that forms a basic double string and stores it in str
** 1. Uses bit operations to extract the exp and mantissa
** 2. Uses arbitrary precision operations to have the accurate string
** representation of the double
** <NOTE> Precision, rounding, and decimal pt not handled here
** Returns index of the decimal point within the basic string
** <For norm> m_sh: 0->mantissa != 0, 1->shift
*/

int		udtoa_basic(union u_double u_d, char **str)
{
	int				exp;
	char			man[DEC + 1];
	char			res[LEN + 1];
	int				m_sh[2];

	exp = get_d_exp(u_d);
	clear_str(man, DEC);
	m_sh[0] = get_d_mantissa(u_d, man);
	clear_str(res, LEN);
	if (exp == -1023 && !m_sh[0])
	{
		*str = ft_strdup(res);
		return (WH + 1);
	}
	else if (exp == -1023 && m_sh[0])
		divi(man, "2");
	else if (exp == 1024)
	{
		*str = (m_sh[0]) ? ft_strdup("nan") : ft_strdup("inf");
		return (-4242);
	}
	ft_strcpy(res + WH + 1, man);
	m_sh[1] = shift_mantissa(res, exp);
	*str = ft_strdup(res);
	return (WH + 1 - m_sh[1]);
}
