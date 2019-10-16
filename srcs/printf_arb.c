/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_arb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:32:01 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/15 15:32:02 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "arb_pre.h"
# include "pow_of_two.h"

int		get_exp(union u_double u_d)
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

void	get_mantissa(union u_double u_d, char *m)
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

void	shift_mantissa(char *man, int exp)
{
	int		e;

	e = exp;
	while (e != 0)
	{
		if (e > 0)
		{
			if (e >= 20)
			{
				mult(man, g_pos_pow_two[20]);
				e -= 20;
			}
			else
			{
				mult(man, g_pos_pow_two[e]);
				e = 0;
			}				
		}
		else if (e < 0)
		{
			if (e <= -20)
			{
				divi(man, g_pos_pow_two[20]);
				e += 20;
			}
			else
			{
				divi(man, g_pos_pow_two[e * -1]);
				e = 0;
			}
		}
	}
}

void	shorten_mantissa(char *man)
{
	// use ft_strchr and ft_strrchr to look for 0s
	while (*man && *man == '0')
		man++;
}

char	*udtoa(double d)
{
	union u_double	u_d;
	int				exp;
	char			man[len + 1];
	

	u_d.dbl = d;
	exp =  get_exp(u_d); // special case for 00000 and fffff ?
	clear_str(man, len);
	get_mantissa(u_d, man);
	shift_mantissa(man, exp);
//	shorten_mantissa(man); // might affect decimal??
	return ft_strdup(man); // need to change
}
