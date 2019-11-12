/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:32:25 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/15 15:32:34 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_exp(char *dec, int p)
{
	int		i;

	i = 0;
	while (dec[i] && dec[i] == '0' && i < p)
		i++;
	return (p - i);
}

char	*append_exp(char *dec, int exp)
{
	char	*to_ret;
	char	*tmp;

	if (exp < 0)
		tmp = ft_itoa(exp * -1);
	else
		tmp = ft_itoa(exp * 1);
	if (ft_strlen(tmp) < 2)
		to_ret = ft_strjoin("0", tmp);
	else
		to_ret = ft_strdup(tmp);
	free(tmp);
	if (exp < 0)
		tmp = ft_strjoin("e-", to_ret);
	else
		tmp = ft_strjoin("e+", to_ret);
	free(to_ret);
	to_ret = ft_strjoin(dec, tmp);
	free(tmp);
	return (to_ret);
}
