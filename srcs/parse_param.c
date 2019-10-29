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

int		star_param(t_spec *sp, char *ft, int i, va_list orig) // pass in int* to avoid prec to be -420 by chance
{
	int		num;
	int		width;

	if (ft[i] >= '0' && ft[i] <= '9')
	{
		num = ft_atoi(ft + i);
		while (ft[i] >= '0' && ft[i] <= '9')
			i++;
		width = (ft[i] != '$') ? num : n_th_int(orig, num);
		if (ft[i] != '$')
			; //va_arg(sp->param_lst, int);
	}	
	else if (ft[i] != '$')
		; // width = va_arg(sp->param_lst, int);
	if (sp->precision == -420)
		sp->precision = width;
	else
		sp->width = width;
	i += (ft[i] != '$') ? 0: 1;
	if (sp->width < 0)
	{
		sp->flags[0] = 1;
		sp->width *= -1;
	}
	return (i);
}


int		dot_param(t_spec *sp, char *ft, int i, va_list orig)
{
	int		num;

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
		return (star_param(sp, ft, i + 1, orig));
	}
	else
		sp->precision = 0;
	return (i);
}


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
	else if (ft[i] == 'l')
		len = 8;
	else if (ft[i] == 'L')
		len = 16;
	else if (ft[i] == 'j')
		len = 8;
	else if (ft[i] == 'z')
		len = 8;
	i += (ft[i + 1] == 'h' || ft[i + 1] == 'l') ? 1 : 0;
	sp->len = (sp->len > len) ? sp->len : len;
	return (++i);
}

int		num_param(t_spec *sp, char *ft, int j)
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

void	clear_param(t_spec *sp)
{
	int	i;

	sp->param = 0;
	i = 0;
	while(i < 6)
		sp->flags[i++] = 0;
	sp->width = 0;
	sp->precision = -1;
	sp->len = -1;
	sp->specifier = '\0';
	sp->valid = 0;
	sp->sign[0] = '\0';
	sp->sign[1] = '\0';
	sp->pref[0] = '\0';
	sp->pref[1] = '\0';
	sp->pref[2] = '\0';
}

