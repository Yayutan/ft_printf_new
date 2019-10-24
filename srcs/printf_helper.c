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

int		get_d_mantissa(union u_double u_d, char *m)
{
	int	i;
	int	sh;
	int	p;
	int zero;

	zero = 0;
	add(m, g_neg_pow_two[0]);
	p = 1;
	i = 6;
	sh = 3;
	while (p <= 52)
	{
		while (sh >= 0)
		{
			if ((u_d.data[i] >> sh) & 1)
			{
				add(m, g_neg_pow_two[p]);
				zero = 1;
			}				
			p++;
			sh--;
		}
		i--;
		sh = 7;
	}
	return (zero);
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

int		get_ld_mantissa(union u_ldouble u_ld, char *m)
{
	int	i;
	int	sh;
	int	p;
	int	zero;

	p = 0;
	i = 7;
	zero = 0;
	while (p <= 63)
	{
		sh = 7;
		while (sh >= 0)
		{
			if ((u_ld.data[i] >> sh) & 1)
			{
				add(m, g_neg_pow_two[p]);
				if (p)
					zero = 1;
			}
			p++;
			sh--;
		}
		i--;
	}
	return (zero);
}

int		shift_mantissa(char *res, int e)
{
	int		sh;
    int     p;
	char	*neg;

	sh = 0;
	p = 0;
	while (e != 0)
	{
        if (e >= 4096)
            p = 4096;
		else if (e >= 2048)
			p = 2048;
        else if (e >= 1024)
            p = 1024;
		else if (e >= 512)
			p = 512;
		else if (e >= 256)
			p = 256;
        else if (e >= 64)
			p = 64;
		else if (e >= -64)
			p = e;
        else if (e <= -4096)
			p = -4096;
		else if (e <= -2048)
			p = -2048;
        else if (e <= -1024)
			p = -1024;
		else if (e <= -512)
			p = -512;
        else if (e <= -256)
			p = -256;
        else if (e <= -64)
			p = -64;
		if (e > 0)
		{
			if (p == 4096)
				mult(res, g_pos_pow_two[69]);
			else if (p == 2048)
				mult(res, g_pos_pow_two[68]);
			else if (p == 1024)
				mult(res, g_pos_pow_two[67]);
			else if (p == 512)
				mult(res, g_pos_pow_two[66]);
			else if (p == 256)
				mult(res, g_pos_pow_two[65]);
			else
				mult(res, g_pos_pow_two[p]);
		}
		else if (e < 0)
		{
			if (p == -4096)
				neg = ft_strtrimc(g_neg_pow_two[69], '0');
			else if (p == -2048)
				neg = ft_strtrimc(g_neg_pow_two[68], '0');
			else if (p == -1024)
				neg = ft_strtrimc(g_neg_pow_two[67], '0');
			else if (p == -512)
				neg = ft_strtrimc(g_neg_pow_two[66], '0');
			else if (p == -256)
				neg = ft_strtrimc(g_neg_pow_two[65], '0');
			else
				neg = ft_strtrimc(g_neg_pow_two[-1 * p], '0');
			mult(res, neg);
			free(neg);
			 sh += -1 * p;
		}
		e -= p;
	}
	return (sh);
}
