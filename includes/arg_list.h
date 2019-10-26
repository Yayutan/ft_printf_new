/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchuang <mchuang@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:37:54 by mchuang           #+#    #+#             */
/*   Updated: 2019/10/25 16:37:55 by mchuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_LIST_H
# define ARG_LIST_H
# include <stdlib.h>

typedef struct  s_args  // works like hashtable
{
	int			index;
    char		type; // or int size?
    s_args		*next;
}				t_args;


#endif