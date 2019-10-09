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

void	increment(char *res, int index)
{
	res[index] = (res[index] + 1) % 10;
	if (res[index] == 0)
		increment(res, index - 1);
}

char	*form_str(double d, int exp, int precision)
{
	char	res[309 + 1 + precision]; // 留一位給進位（9.9999->10
	int		i;

	ft_bzero(res, 309 + 1 + precision);
	if (exp >= 0)
	{
		i = 1; 
		while i <= exp + precision)
		{
			res[i] = (int)d;
			d = (d - (int)d) * 10;
			i++;
		}
	}
	else
	{
		i = exp; 
		while i <= exp + precision)
		{
			res[i] = (int)d;
			d = (d - (int)d) * 10;
			i++;
		}
	}
	if (d >= 5)
		increment(res, i);
	return (res);
}



char	*ft_dtoa(double d, int precision)
{
	char	*to_ret;
	int		exp;
	double	cur;
	
	cur = (d < 0) ? -1 * d : d;
	exp = (cur > 1) ? find_large_ex(0, &cur) : find_large_neg_ex(0, &cur);
	
	
	form_str(cur, exp, precision);
	
	
}