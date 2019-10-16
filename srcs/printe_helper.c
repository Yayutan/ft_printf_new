/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printe_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:32:46 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/15 15:32:51 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	find_small_ex(int prev, double *f)
{
	while (*f >= 10)
	{
		if (*f >= 100000000)
		{
			prev += 8;
			*f /= 100000000;
		}
		else if (*f >= 10000)
		{
			prev += 4;
			*f /= 10000;
		}
		else if (*f >= 100)
		{
			prev += 2;
			*f /= 100;
		}
		else if (*f >= 10)
		{
			prev += 1;
			*f /= 10;
		}
	}
    return prev;
}

int	find_large_ex(int prev, double *f)
{
	while (*f >= 1e16)
	{
		if (*f >= 1e128)
		{
			prev += 128;
			*f /= 1e128;
		}
		else if (*f >= 1e64)
		{
			prev += 64;
			*f /= 1e64;
		}
		else if (*f >= 1e32)
		{
			prev += 32;
			*f /= 1e32;
		}
		else if (*f >= 1e16)
		{
			prev += 16;
			*f /= 1e16;
		}
	}
    return find_small_ex(prev, f);
}

int	find_small_neg_ex(int prev, double *f)
{
	while (*f < 1)
	{
		if (*f < 1e-7)
		{
			prev -= 8;
			*f *= 100000000;
		}
		else if (*f < 1e-3)
		{
			prev -= 4;
			*f *= 10000;
		}
		else if (*f < 1e-1)
		{
			prev -= 2;
			*f *= 100;
		}
		else if (*f < 1)
		{
			prev -= 1;
			*f *= 10;
		}
	}
    return prev;
}

int	find_large_neg_ex(int prev, double *f)
{
	while (*f < 1e-15)
	{
		if (*f < 1e-127)
		{
			prev -= 128;
			*f *= 1e128;
		}
		else if (*f < 1e-63)
		{
			prev -= 64;
			*f *= 1e64;
		}
		else if (*f < 1e-31)
		{
			prev -= 32;
			*f *= 1e32;
		}
		else if (*f < 1e-15)
		{
			prev -= 16;
			*f *= 1e16;
		}
	}
    return find_small_neg_ex(prev, f);
}

unsigned long long int pow_10(int n)
{
	int i;
	unsigned long long int	res;

	i = n;
	res = 1;
	while (i)
	{
		res *= 10;
		i--;
	}
	return (res);
}
