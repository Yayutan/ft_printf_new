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

typedef struct	s_spec
{ 
	int			param;// param $   0 1 2 3 4 5
	int			flags[6]; // flags - +   # 0 '    0 for off, 1 for on
	int			width; // width * (number)
	int			precision; // .precision .number .*
	char		length[2]; // length h hh l ll L
	char		specifier; 
	va_list		param_lst;
	int			valid;
}				t_spec;

int	ft_printf(const char *format, ...);
void	clear_param(t_spec *sp);
int		num_param(t_spec *sp, char *ft, int i);
int		not_num_param(t_spec *sp, char *ft, int i);
int		dot_param(t_spec *sp, char *ft, int i, va_list orig);
int		star_param(t_spec *sp, char *ft, int i, va_list orig);
int		parse_format(char *ft, t_spec *sp, int i, va_list orig);
int		n_th_int(va_list orig, int i);
char	*d_p_f(t_spec *sp, va_list orig);
char	*initial_s(t_spec *sp, va_list orig);
char	*initial_diouxb(t_spec *sp, va_list orig);
# endif

// Useful description of params
// https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

// More examples
// https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
