/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:49:35 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/25 13:49:40 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_buf.h"

t_buf	*buf_init(void)
{
	t_buf *to_ret;
	
	if (!(to_ret = (t_buf*)ft_memalloc(sizeof(t_buf))))
		return NULL;
	if (!(to_ret->buf = (char*)ft_strnew(BUFF_SIZE)))
		return NULL;
	to_ret->len = 0;
	return (to_ret);
}

int		till_full(t_buf *buf)
{
	return (BUFF_SIZE - buf->len);
}

void		buf_store(t_buf *buf, char *to_add)
{
	char	*tmp;
	
	if (till_full(buf) <= ft_strlen(to_add))
	{
		buf_output_clear(buf);
		if (ft_strlen(to_add) <= BUFF_SIZE)
			buf_store(buf, to_add);
		else
		{
			buf->buf = ft_strncpy(buf->buf, to_add, BUFF_SIZE);
			buf->len = BUFF_SIZE;
			tmp = ft_strdup(to_add + BUFF_SIZE);
			free(to_add);
			buf_store(buf, tmp);
		}
	}
	else
	{
		buf->buf = ft_strcpy(buf->buf, to_add);
		buf->len += ft_strlen(to_add);
		buf->buf[buf->len] = '\0';
		free(to_add);
	}
}

void	buf_output_clear(t_buf *buf)
{
	ft_putstr(buf->buf);
	ft_bzero(buf->buf, (size_t)BUFF_SIZE);
	buf->len = 0;
}

void	buf_del(t_buf *buf)
{
	free(buf->buf);
	buf->buf = NULL;
	free(buf);
}
