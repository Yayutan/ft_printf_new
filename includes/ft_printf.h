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
# include "arb_pre.h"
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

union		u_double
{
	double	dbl;
	char	data[sizeof(double)];
};

union		u_ldouble
{
	long double	ldbl;
	char		data[sizeof(long double)];
};

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
char			*initial_f(t_spec *sp, va_list orig);
char			*initial_e(t_spec *sp, va_list orig);
char			*initial_g(t_spec *sp, va_list orig);
int				get_d_exp(union u_double u_d);
void			get_d_mantissa(union u_double u_d, char *m);
int				get_ld_exp(union u_ldouble u_ld);
void			get_ld_mantissa(union u_ldouble u_d, char *m);
int				shift_mantissa(char *man, int e);
char			*udtoa(double d, int pre, int hash);
char			*uldtoa(long double d, int pre, int hash);
int				calc_exp(char *dec);
char			*form_dec(char *dec, int exp, int hash, int pre);
char			*increment_e(char *dec, int pre);
char			*finalize(t_spec *sp, char *str);
#endif
