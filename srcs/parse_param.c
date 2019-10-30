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

# include "ft_printf.h"

/*
** When we encounter '.', we need to set the precision
** There are 3 cases:
** *: next parameter
** *n: uses up next argument, but sets to n 
** *n$: sets to the nth argument(does not affect the cur_arg)
** Returns the beginning index of the next part of format.
*/

int		star_param(int *set, char *ft, t_spec *sp, t_args *arg_l, va_list orig)
{
	int		num;
	int		width;
	int		i;
	union arguemnt arg;

	i = 0;
	if (ft[i] >= '0' && ft[i] <= '9')
	{
		num = ft_atoi(ft + i);
		while (ft[i] >= '0' && ft[i] <= '9')
			i++;
		if (ft[i] != '$')
		{
			*set = num;
			va_arg(sp->param_lst, int);
			sp->arg = (sp->arg)->next;
		}
		else
		{
			arg = nth_arg_orig(arg_l, num, orig);
			*set = arg.i;
		}
	}	
	else if (ft[i] != '$')
	{
		*set = va_arg(sp->param_lst, int);
		sp->arg = (sp->arg)->next;
	}
	i += (ft[i] != '$') ? 0: 1;
	if (sp->width < 0)
	{
		sp->flags[0] = 1;
		sp->width *= -1;
	}
	return (i);
}

/*
** When we encounter '.', we need to set the precision
** There are 3 cases:
** .n: set 
** .*: handled in star_param
** .*n: handled in star_param
** .*n$: handled in star_param
** Returns the beginning index of the next part of format.
*/

int		dot_param(int *prec, char *ft, t_spec *sp, t_args *arg_info, va_list orig)
{
	int		num;
	int		i;

	i = 0;
	if (ft[i] >= '0' && ft[i] <= '9')
	{
		num = ft_atoi(ft + i);
		while (ft[i] >= '0' && ft[i] <= '9')
			i++;
		*prec = num;
	}
	else if (ft[i] == '*')
		return (star_param(prec, ft, i + 1, orig));
	else
		*prec = 0;
	return (i);
}

/*
** When we encounter char not related to numbers, it can be the flags, or the
** length of the specifier.
** If a bigger length is already assigned to the spec, it preceeds all upcoming
** smaller ones.
** Returns the beginning index of the next part of format.
*/

int		not_num_param(t_spec *sp, char *ft, int i)
{
	int	len;
	
	len = sp->len;
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
	else if (ft[i] == 'h')
		len = (ft[i + 1] == 'h') ? 1 : 2;
	else if (ft[i] == 'L')
		len = 16;
	else if (ft_strchr("ljz", ft[i]))
		len = 8;
	sp->len = (sp->len > len) ? sp->len : len;
	i += (ft[i + 1] && (ft[i + 1] == 'h' || ft[i + 1] == 'l')) ? 2 : 1;
	return (i);
}

/*
** When we encounter numbers in the format string, it can be the width, or the
** indicator of which argument this input is.
** Returns the beginning index of the next part of format.
*/

int		num_param(t_spec *sp, char *ft, int j) // assumes that always spec char follows?s
{
	int		num;
	
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

/*
** Checks the next few characters in the stirnf to check if a color is used.
** If so, puts the color code to the buffer.
** Returns the beginning index of the next part of format.
*/

int		change_color(char *ft, int i, t_buf *buf)
{
	if (!ft_strncmp(ft + i, "{RED}", ft_strlen("{RED}")))
		buf_store_str(buf, RED);
	else if (!ft_strncmp(ft + i, "{GREEN}", ft_strlen("{GREEN}")))
		buf_store_str(buf, GREEN);
	else if (!ft_strncmp(ft + i, "{YELLOW}", ft_strlen("{YELLOW}")))
		buf_store_str(buf, YELLOW);
	else if (!ft_strncmp(ft + i, "{BLUE}", ft_strlen("{BLUE}")))
		buf_store_str(buf, BLUE);
	else if (!ft_strncmp(ft + i, "{MAG}", ft_strlen("{MAG}")))
		buf_store_str(buf, MAG);
	else if (!ft_strncmp(ft + i, "{CYAN}", ft_strlen("{CYAN}")))
		buf_store_str(buf, CYAN);
	else if (!ft_strncmp(ft + i, "{CLEAR}", ft_strlen("{CLEAR}")))
		buf_store_str(buf, CLEAR);
	else
		return (i);
	while (ft[i] && ft[i - 1] != '}')
		i++;
	return (i);
}

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
	ap->arg = NULL;
}

