
# include "ft_pritnf.h"

/*
** Function that sets the argument union from the information
** provided in argument node arg.
*/

union argument next_arg(union argument next, t_args *arg, va_list param)
{
	if (ft_strchr("crH", arg->size))
		next.c = (char)va_args(param, int);
	else if (arg->size == 's')
		next.str = va_args(param, char*);
	else if (arg->size == 'f')
		next.d = va_args(param, double);
	else if (arg->size == 'F')
		next.ld = va_args(param, long double);
	else if (arg->size == 'i')
		next.sh = (short)va_args(param, int);
	else if (arg->size == 'l')
		next.li = va_args(param, long int);
	else if (arg->size == 'L' || arg->size == 'p')
		next.lli = va_args(param, long long int);
	return (next);
}

/*
** Function that sets the argument union of the nth node argument list
** Copies from the original va_list
*/

union argument nth_arg_orig(union argument next, t_args *arg, int n, va_list orig)
{
	int i;
	t_args *cur;
	va_list	cp;

	i = 1;
	cur = arg;
	va_copy(cp, orig);
	while (i <= n)
	{
		next = next_arg(next, cur, cp);
		i++;
		cur = cur->next;
	}
	va_end(cp);
	return (next);
}

/*
** Function that sets the argument union of the nth node argument list
** Changes the provided va_list
*/

union argument nth_arg_sp(union argument next, t_args *arg, int n, va_list sp)
{
	int i;
	t_args *cur;

	i = 1;
	cur = arg;
	while (i <= n)
	{
		next = next_arg(next, cur, sp);
		i++;
		cur = cur->next;
	}
	return (next);
}