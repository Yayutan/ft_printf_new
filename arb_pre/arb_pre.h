#ifndef ARB_PRE_H
# define ARB_PRE_H
# include "../libft/libft.h"
# define LEN 16449
# define DEC 65
# define WH 16384

void	add(char *n1, const char *n2);
void	sub(char *n1, const char *n2);
void	basic_mult(char *n1, char *n2);
void	mult(char *n1, char *n2);
void	divi(char *n1, const char *n2);
void	clear_str(char *n, int length);
int		basic_divi(char *n1, char *n2, int leng);
void	increment(char *n1, int index);
# endif
