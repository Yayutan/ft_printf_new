/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:17:22 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/24 16:19:14 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include "ft_buf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <locale.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAG "\033[0;35m"
# define CYAN "\033[0;36m"
# define CLEAR "\033[0m"


typedef struct	s_spec
{
	int			param;
	int			flags[6];
	int			width;
	int			precision;
	int			len;
	char		specifier;
	va_list		param_lst;
	int			valid;
	char		sign[2];
	char		pref[3];
	t_buf		*buf;
}				t_spec;

int				ft_printf(const char *format, ...);
void			clear_param(t_spec *sp);
int				num_param(t_spec *sp, char *ft, int i);
int				not_num_param(t_spec *sp, char *ft, int i);
int				dot_param(t_spec *sp, char *ft, int i, va_list orig);
int				star_param(t_spec *sp, char *ft, int i, va_list orig);
int				parse_format(char *ft, t_spec *sp, int i, va_list orig);
int				n_th_int(va_list orig, int i);
char			*d_p_f(t_spec *sp, va_list orig);
char			*initial_s(t_spec *sp, va_list orig);
char			*initial_c(t_spec *sp, va_list org);
char			*initial_diouxb(t_spec *sp, va_list orig);
char			*initial_p(t_spec *sp, va_list orig);
char			*initial_feg(t_spec *sp, va_list orig);
char			*pos_dtoa(double d, int precision);
int				find_large_ex(int prev, double *f);
int				find_large_neg_ex(int prev, double *f);
unsigned long long int pow_10(int n);
char			*udtoa(double d);
char			*finalize(t_spec *sp, char *str);
#endif
