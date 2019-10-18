#ifndef ARB_PRE_H
# define ARB_PRE_H
# include "../libft/libft.h"
# define LEN 4997
# define DEC 65
# define WH 4932

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

void	add(char *n1, const char *n2);
void	sub(char *n1, const char *n2);
void	basic_mult(char *n1, char *n2);
void	mult(char *n1, char *n2);
void	divi(char *n1, const char *n2);
void	clear_str(char *n, int length);
int		basic_divi(char *n1, char *n2, int leng);
void	increment(char *n1, int index);
int		get_d_exp(union u_double u_d);
void	get_d_mantissa(union u_double u_d, char *m);
int		get_ld_exp(union u_ldouble u_ld);
void	get_ld_mantissa(union u_ldouble u_d, char *m);
void	shift_mantissa(char *man, int e);
# endif
