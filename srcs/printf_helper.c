/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:50:40 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/17 01:50:42 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "arb_pre.h"
# include "pow_of_two.h"

int		get_d_exp(union u_double u_d)
{
	int		exp;
	int		i;

	exp = 0;
	i = 0;
	while (i <= 3)
	{
		exp += (((u_d.data[6] >> (i + 4)) & 1) << i);
		i++;
	}
	while (i <= 10)
	{
		exp += (((u_d.data[7] >> (i - 4)) & 1) << i);
		i++;
	}	
	return (exp - 1023);
}

void	get_d_mantissa(union u_double u_d, char *m)
{
	int	i;
	int	sh;
	int	p;

	add(m, g_neg_pow_two[0]);
	p = 1;
	i = 6;
	sh = 3;
	while (p <= 52)
	{
		while (sh >= 0)
		{
			if ((u_d.data[i] >> sh) & 1)
				add(m, (char*)g_neg_pow_two[p]);
			p++;
			sh--;
		}
		i--;
		sh = 7;
	}
}

int		get_ld_exp(union u_ldouble u_ld)
{
	int		exp;
	int		i;

	exp = 0;
	i = 0;
	while (i <= 7)
	{
		exp += (((u_ld.data[8] >> i) & 1) << i);
		i++;
	}
	while (i <= 14)
	{
		exp += (((u_ld.data[9] >> (i - 8)) & 1) << i);
		i++;
	}	
	return (exp - 16383);
}

void	get_ld_mantissa(union u_ldouble u_ld, char *m)
{
	int	i;
	int	sh;
	int	p;

	p = 0;
	i = 7;
	while (p < 64)
	{
		sh = 7;
		while (sh >= 0)
		{
			if ((u_ld.data[i] >> sh) & 1)
				add(m, (char*)g_neg_pow_two[p]);
			p++;
			sh--;
		}
		i--;
	}
}

void	shift_mantissa(char *man, int e)
{
	while (e != 0)
	{
		if (e >= 20)
		{
			mult(man, g_pos_pow_two[20]);
			e -= 20;
		}
		else if (e > 0)
		{
			mult(man, g_pos_pow_two[e]);
			e = 0;
		}				
		else if (e > -20)
		{
			divi(man, g_pos_pow_two[e * -1]);
			e = 0;
		}
		else
		{
			divi(man, g_pos_pow_two[20]);
			e += 20;
		}
	}
}
