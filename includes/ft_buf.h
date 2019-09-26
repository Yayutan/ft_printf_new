/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:48:20 by mchuang           #+#    #+#             */
/*   Updated: 2019/09/25 13:48:31 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 4

typedef struct	s_buf
{
	char	*buf;
	int		len;
}				t_buf;

t_buf	*buf_init(void);
int		till_full(t_buf *buf);
void	buf_store(t_buf *buf, char *to_add);
void	buf_output_clear(t_buf *buf);
void	buf_del(t_buf *buf);
