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
	t_buf	*to_ret;
	int		i;
	
	if (!(to_ret = (t_buf*)ft_memalloc(sizeof(t_buf))))
		return (NULL);
	i = 0;
	while (i <= BUFF_SIZE)
		(to_ret->buf)[i++] = 0;
	to_ret->len = 0;
	to_ret->total = 0;
	return (to_ret);
}

int		till_full(t_buf *buf)
{
	return (BUFF_SIZE - buf->len);
}

void		buf_store_str(t_buf *buf, char *to_add)
{
	int		i;
	int		s_len;
	
	s_len = (int)ft_strlen(to_add);
	if (till_full(buf) <= s_len)
	{
		buf_output_clear(buf);
		if (s_len < BUFF_SIZE)
			buf_store_str(buf, to_add);
		else	
		{
			i = 0;
			while (i <= BUFF_SIZE)
				(buf->buf)[i++] = *(to_add++);
			buf->len = BUFF_SIZE;
			buf->total += BUFF_SIZE;
			buf_store_str(buf, to_add);
		}
	}
	else
	{
		i = buf->len;
		while (*to_add)
			(buf->buf)[i++] = *(to_add++);
		buf->len += s_len;
		buf->total += s_len;
	}
}

void	buf_store_chr(t_buf *buf, char to_add)
{
	if (buf->len == BUFF_SIZE)
		buf_output_clear(buf);
	(buf->buf)[buf->len] = to_add;
	buf->len++;
	buf->total++;
}

void	buf_output_clear(t_buf *buf)
{
	int i;

	write(1, buf->buf, buf->len);
	i = 0;
	while (i <= BUFF_SIZE)
		(buf->buf)[i++] = 0;
	buf->len = 0;
}

int		buf_del(t_buf *buf)
{
	int		to_ret;
	
	to_ret = buf->total;
	free(buf);
	return (to_ret);
}
