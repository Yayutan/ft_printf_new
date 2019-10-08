/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 23:08:40 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/26 23:09:11 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

int		n_th_int(va_list orig, int i)
{
	va_list		cp;
	int			j;
	int			to_ret;
	
	va_copy(cp, orig);
	j = 1;
	while (j < i)
	{
		va_arg(cp, int);
		j++;
	}
	to_ret = va_arg(cp, int);
	va_end(cp);
	return (to_ret);
}

int		star_param(t_spec *sp, char *ft, int i, va_list orig)
{
	int		num;
	int		width;

	i++; // *'' || *n || *n$
	
	if (ft[i] >= '0' && ft[i] <= '9')
	{
		num = ft_atoi(ft + i);
		while (ft[i] >= '0' && ft[i] <= '9')
			i++;
		width = (ft[i] != '$') ? num : n_th_int(orig, num);
	}	
	else if (ft[i] != '$')
		width = va_arg(sp->param_lst, int);
	if (sp->precision == -420)
		sp->precision = width;
	else
		sp->width = width;
	i += (ft[i] != '$') ? 0: 1;
	return (i);
}


int		dot_param(t_spec *sp, char *ft, int i, va_list orig)
{
	int		num;

	i++; // .''  || .* || .n
	if (ft[i] >= '0' && ft[i] <= '9')
	{
		num = ft_atoi(ft + i);
		while (ft[i] >= '0' && ft[i] <= '9')
			i++;
		sp->precision = num;
	}
	else if (ft[i] == '*')
	{
		sp->precision = -420;
		return (star_param(sp, ft, i, orig));
	}
	else
		sp->precision = 0;
	return (i);
}


int		not_num_param(t_spec *sp, char *ft, int i)
{
	// hlL '#-+ 
	if (ft[i] == '-')
		sp->flags[0] = 1;
	else if (ft[i] == '+')
		sp->flags[1] = 1;
	else if (ft[i] == ' ')
		sp->flags[2] = 1;
	else if (ft[i] == '#')
		sp->flags[3] = 1;
	else if (ft[i] == '0')
		sp->flags[4] = 1;
	else if (ft[i] == '\'')
		sp->flags[5] = 1;
	else if (ft[i] == 'h')  // length h:2 hh:1 l:8 ll:8 L:16 \0:4
	{
		sp->len = (ft[i + 1] == 'h') ? 1 : 2;
		i += (ft[i + 1] == 'h') ? 1 : 0;
	}
	else if (ft[i] == 'l')
	{
		sp->len = 8;
		i += (ft[i + 1] == 'l') ? 1 : 0;
	}
	else if (ft[i] == 'L')
		sp->len = 16;
	else if (ft[i] == 'j')
		sp->len = 8;
	else if (ft[i] == 'z')
		sp->len = 8;
	return (++i);
}

int		num_param(t_spec *sp, char *ft, int i)
{
	int		num;
	int		j;
	
	j = i;
	num = ft_atoi(ft + j);
	while (ft[j] && ft[j] >= '0' && ft[j] <= '9')
		j++;
	if (ft[j] == '$')
	{
		sp->param = num;
		j++;
	}
	else
		sp->width = num;
	return (j);
}

void	clear_param(t_spec *sp)
{
	int	i;

	sp->param = 0;
	i = 0;
	while(i < 6)
		sp->flags[i++] = 0;
	sp->width = 0;
	sp->precision = -1;
	sp->len = 4;
	sp->specifier = '\0';
	sp->valid = 0;
	sp->sign[0] = '\0';
	sp->sign[1] = '\0';
	sp->pref[0] = '\0';
	sp->pref[1] = '\0';
	sp->pref[2] = '\0';
}

