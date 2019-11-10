/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:47:28 by mchuang           #+#    #+#             */
/*   Updated: 2019/11/08 22:47:42 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Clears all elements of the spec to default.
** Since there will only be 1 specification struct, we need to clear it each
** time we are processing a new format.
*/

void	clear_param(t_spec *sp)
{
	sp->param = 0;
	ft_bzero(sp->flags, sizeof(int) * 6);
	sp->width = 0;
	sp->precision = -1;
	sp->len = -1;
	sp->specifier = '\0';
	sp->valid = 0;
	ft_bzero(sp->sign, sizeof(char) * 2);
	ft_bzero(sp->pref, sizeof(char) * 3);
}

void	del_spec(t_spec *sp)
{
	va_end(sp->param_lst);
	va_end(sp->orig);
	free(sp);
}