/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:43:38 by donghyle          #+#    #+#             */
/*   Updated: 2022/07/08 13:43:41 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_def.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uchar	*cursor;
	t_uchar	target;

	cursor = (t_uchar *) s;
	target = c;
	while (n > 0)
	{
		if (*cursor == target)
			return ((void *) cursor);
		cursor++;
		n--;
	}
	return (NULL);
}
