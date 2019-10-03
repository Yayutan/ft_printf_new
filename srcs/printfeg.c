/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfeg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:52:14 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/28 11:52:16 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"





//char	*initial_feg(sp, orig)
//{
//	va_list			cp;
//	int				i;
//	long long int	arg;
//	
//	if (sp->param == 0)
//		arg = va_arg(sp->param_lst, long long int);
//	else
//	{
//		va_copy(cp, orig);
//		i = 1;
//		while (i++ < sp->param)
//			va_arg(cp, long long int);
//		arg = va_arg(cp, long long int);
//		va_end(sp->param_lst);
//		va_copy(sp->param_lst, cp);
//		va_end(cp);
//	}
//   return (split_n_fix(sp, arg));
//}

// https://en.wikipedia.org/wiki/Single-precision_floating-point_format
// https://en.wikipedia.org/wiki/Double-precision_floating-point_format
// https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format

// http://cstl-csm.semo.edu/xzhang/Class%20Folder/CS280/Workbook_HTML/FLOATING_tut.htm