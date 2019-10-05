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


int	find_small_ex(int prev, float *f)
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

int	find_large_ex(int prev, float *f)
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

int	find_small_neg_ex(int prev, float *f)
{
	while (*f <= 10)
	{
		if (*f <= 1e-8)
		{
			prev -= 8;
			*f *= 100000000;
		}
		else if (*f <= 1e-4)
		{
			prev -= 4;
			*f *= 10000;
		}
		else if (*f <= 1e-2)
		{
			prev -= 2;
			*f *= 100;
		}
		else if (*f <= 1e-1)
		{
			prev -= 1;
			*f *= 10;
		}
	}
    return prev;
}

int	find_large_neg_ex(int prev, float *f)
{
	while (*f <= 1e-16)
	{
		if (*f<= 1e-128)
		{
			prev -= 128;
			*f *= 1e128;
		}
		else if (*f <= 1e-64)
		{
			prev -= 64;
			*f *= 1e64;
		}
		else if (*f <= 1e-32)
		{
			prev -= 32;
			*f *= 1e32;
		}
		else if (*f <= 1e-16)
		{
			prev -= 16;
			*f *= 1e16;
		}
	}
    return find_small_neg_ex(prev, f);
}

static unsigned long long int pow_10(int n)
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

char	*ft_ftoa(float f, int pre)
{
	float				cur;
	int					ex;
	unsigned long long	dec;
	char				*to_ret;
	char				*de;
	char				*tmp;

	cur = (f < 0) ? -1 * f : f;
	ex = (cur < 1) ? find_large_neg_ex(0, &cur): find_large_ex(0, &cur);
	to_ret = ft_itoa((int)cur);
	tmp = ft_strjoin(to_ret, ".");
	free(to_ret);
	to_ret = tmp;
	cur = (cur - (int)cur) * pow_10(pre); // assume not over ull limit...(pres < 19)
	dec = (unsigned long long int)cur;
	cur = cur - dec;
	de = (cur >= 0.5) ? ft_ulltoa_base(dec + 1, 10) : ft_ulltoa_base(dec, 10);
	tmp = ft_strjoin(to_ret, de);
	free(to_ret);
	free(de);
	to_ret = ft_strjoin(tmp, "e");
	free(tmp);
	de = ft_itoa(ex);
	tmp = ft_strjoin(to_ret, de);
	free(to_ret);
	free(de);
	to_ret = tmp;
	if (f < 0)
	{
		tmp = ft_strjoin("-", to_ret);
		free(to_ret);
		to_ret = tmp;
	}
	return (to_ret);
}