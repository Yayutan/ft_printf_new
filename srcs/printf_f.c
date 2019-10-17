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
# include "arb_pre.h"

static char	*shorten_mantissa(char *man, int pre, int hash)
{
	int		i;
	char	*s1;
	char	*s2;
	char	*s3;

	if (pre < 112 && man[4932 + pre + 1] >= '5') // if pre over 112(seg fault?)
		increment(man, 4932 + pre);
	i = 0;
	while (man[i] && man[i] == '0' && i < 4932)
		i++;
	s1 = ft_strsub(man, i, 4933 - i);
	if (pre > 0 || hash)
		s2 = ft_strjoin(s1, ".");
	else
		s2 = ft_strdup(s1);
	free(s1);
	if (pre <= 112)
		s1 = ft_strsub(man, 4933, pre);
	else
	{
		s1 = ft_strsub(man, 4933, 112);
		s3 = ft_stradd(s1, '0', 1, pre - 112);
		free(s1);
		s1 = s3;
	}
	s3 = ft_strjoin(s2, s1);
	free(s1);
	free(s2);
	return (s3);
}

char	*uldtoa(long double ld, int pre, int hash)
{
	union u_ldouble	u_ld;
	int				exp;
	char			man[LEN + 1];
	

	u_ld.ldbl = ld;
	exp =  get_ld_exp(u_ld);
	clear_str(man, LEN);
	if (exp == -16383)
		return (shorten_mantissa(man, pre, hash)); // subnormal?
	get_ld_mantissa(u_ld, man);
	shift_mantissa(man, exp);
	return (shorten_mantissa(man, pre, hash));
}

char	*udtoa(double d, int pre, int hash)
{
	union u_double	u_d;
	int				exp;
	char			man[LEN + 1];
	

	u_d.dbl = d;
	exp =  get_d_exp(u_d);
	clear_str(man, LEN);
	if (exp == -1023)
		return (shorten_mantissa(man, pre, hash)); // subnormal?
	get_d_mantissa(u_d, man);
	shift_mantissa(man, exp);
	return (shorten_mantissa(man, pre, hash));
}
