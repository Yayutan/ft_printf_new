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

# include "ft_printf.h"

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

char	*form_final(char *man, int dec, int pre, int hash)
{
	int		i;
	char	*s1;
	char	*s2;
	char	*s3;

	if (dec + pre + 1 < LEN && man[dec + pre + 1] >= '5')
		increment(man, dec + pre);
	clear_digits(man, dec + pre + 1);
	i = 0;
	while (man[i] && man[i] == '0' && i < dec)
		i++;
	s1 = ft_strsub(man, i, dec - i + 1);
	if (pre > 0 || hash)
		s2 = ft_strjoin(s1, ".");
	else
		s2 = ft_strdup(s1);
	free(s1);
	if (dec + pre < LEN)
		s1 = ft_strsub(man, dec + 1, pre);
	else
	{
		s3 = ft_strdup(man + (dec + 1));
		s1 = ft_stradd(s3, '0', 1, pre - (LEN - dec));
		free(s3);
	}
	s3 = ft_strjoin(s2, s1);
	free(s1);
	free(s2);
	return (s3);
}

int		uldtoa_basic(union u_ldouble u_ld, char *str)
{
	int				exp;
	char			man[DEC + 1];	
	char			res[LEN + 1];
	int				sh;
	int				m_zero;

	exp =  get_ld_exp(u_ld);
	clear_str(man, DEC);
	m_zero = get_ld_mantissa(u_ld, man);
	clear_str(res, LEN);
	if (exp == -16383)
	{
		if (!m_zero) // special case: 0
		{
			ft_strcpy(str, res);
			return (WH + 1);
		}
		divi(man, "2"); // special case: subnormal
	}
	else if (exp == 16384)
	{
		if (m_zero)
			ft_strcpy(str, "nan");
		else
			ft_strcpy(str, "inf");
		return (-4242);
	}
	ft_strcpy(res + WH + 1, man);
	sh = shift_mantissa(res, exp);
	ft_strcpy(str, res);
	return (WH + 1 - sh);
}

int		udtoa_basic(union u_double u_d, char *str)
{
	int				exp;
	char			man[DEC + 1];
	char			res[LEN + 1];
	int				sh;
	int				m_zero;

	exp =  get_d_exp(u_d);
	clear_str(man, DEC);
	m_zero = get_d_mantissa(u_d, man);
	clear_str(res, LEN);
	if (exp == -1023)
	{
		if (!m_zero) // special case: 0
		{
			ft_strcpy(str, res);
			return (WH + 1);
		}
		divi(man, "2"); // special case: subnormal
	}
	else if (exp == 1024)
	{
		if (m_zero)
			ft_strcpy(str, "nan");
		else
			ft_strcpy(str, "inf");
		return (-4242);
	}
	ft_strcpy(res + WH + 1, man);
	sh = shift_mantissa(res, exp);
	ft_strcpy(str, res);
	return (WH + 1 - sh);
}
