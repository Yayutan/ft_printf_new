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
				add(m, g_neg_pow_two[p]);
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
	while (p <= 63)
	{
		sh = 7;
		while (sh >= 0)
		{
			if ((u_ld.data[i] >> sh) & 1)
				add(m, g_neg_pow_two[p]);
			p++;
			sh--;
		}
		i--;
	}
}

int		shift_mantissa(char *res, int e) // think about how to trim only front
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
        else if (e >= 1024)
            p = 1024;
		else if (e >= 256)
			p = 256;
        else if (e >= 64)
			p = 64;
		else if (e >= -64)
			p = e;
        else if (e <= -4096)
			p = -4096;
        else if (e <= -1024)
			p = -1024;
        else if (e <= -256)
			p = -256;
        else if (e <= -64)
			p = -64;
		
		if (e > 0)
		{
			if (p == 4096)
				mult(res, g_pos_pow_two[67]);
			else if (p == 1024)
				mult(res, g_pos_pow_two[66]);
			else if (p == 256)
				mult(res, g_pos_pow_two[65]);
			else
				mult(res, g_pos_pow_two[p]);
		}
		else if (e < 0)
		{
			if (p == -4096)
				neg = ft_strtrim(g_neg_pow_two[67]);
			else if (p == -1024)
				neg = ft_strtrim(g_neg_pow_two[66]);
			else if (p == -256)
				neg = ft_strtrim(g_neg_pow_two[65]);
			else
				neg = ft_strtrim(g_neg_pow_two[p]);
			mult(res, neg);
			free(neg);
			 sh += -1 * p;
		}
		e -= p;
	}
//        if (e >= 4096)
//		{
//			mult(res, g_pos_pow_two[67]);
//			e -= 4096;
//		}
//        else if (e >= 1024)
//		{
//			mult(res, g_pos_pow_two[66]);
//			e -= 1024;
//		}
//		else if (e >= 256)
//		{
//			mult(res, g_pos_pow_two[65]);
//			e -= 256;
//		}
//        else if (e >= 64)
//		{
//			mult(res, g_pos_pow_two[64]);
//			e -= 64;
//		}
//		else if (e >= -64)
//		{
//			if (e > 0)
//				mult(res, g_pos_pow_two[e]);
//			else
//				mult(res, g_neg_pow_two[e * -1]);
//            sh += (e > 0) ? 0 : -1 * e;
//			e = 0;
//		}
//        else if (e <= -4096)
//		{
//			mult(res, g_neg_pow_two[67]);
//			e += 4096;
//            sh += 4096;
//		}
//        else if (e <= -1024)
//		{
//			mult(res, g_neg_pow_two[66]);
//			e += 1024;
//            sh += 1024;
//		}
//        else if (e <= -256)
//		{
//			mult(res, g_neg_pow_two[65]);
//			e += 256;
//			sh += 256;
//		}
//        else if (e <= -64)
//		{
//			mult(res, g_neg_pow_two[64]);
//			e += 64;
//            sh += 64;
//		}
	return (sh);
}
