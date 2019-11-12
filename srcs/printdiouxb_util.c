/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdiouxb_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:42:11 by mchuang           #+#    #+#             */
/*   Updated: 2019/11/11 16:42:24 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	bit_abs(long long int num, int len)
{
	long long int	cleared;

	if (len == 8 && num < 0)
		return (num * -1);
	if ((num >> (8 * len - 1)) & 1)
	{
		cleared = num & ~(((long long int)1 << 63) >> ((8 - len) * 8 - 1));
		return (~cleared + 1);
	}
	else
		return (num);
}

char			*add_apos(char *s)
{
	char	*to_ret;
	int		i;
	int		j;

	i = 0;
	to_ret = ft_strnew(ft_strlen(s) + (ft_strlen(s) - 1 - i) / 3);
	i = ft_strlen(s) + (ft_strlen(s) - 1 - i) / 3 - 1;
	j = 0;
	to_ret[0] = s[0];
	while (i > 0)
	{
		if (j % 3 == 0 && j != 0)
		{
			to_ret[i--] = ',';
			to_ret[i] = s[ft_strlen(s) - 1 - j];
		}
		else
			to_ret[i] = s[ft_strlen(s) - 1 - j];
		j++;
		i--;
	}
	free(s);
	return (to_ret);
}

int				check_zero(int len, union u_argument u_arg)
{
	if (len == 4 && u_arg.i == 0)
		return (1);
	else if (len == 1 && u_arg.uc == 0)
		return (1);
	else if (len == 2 && u_arg.sh == 0)
		return (1);
	else if (len == 8 && u_arg.lli == 0)
		return (1);
	return (0);
}
