/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:10:13 by donghyle          #+#    #+#             */
/*   Updated: 2022/07/08 12:10:14 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_def.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	t_uchar	*cursor;
	t_uchar	content;

	content = (t_uchar) c;
	cursor = (t_uchar *) b;
	while (len > 0)
	{
		*cursor = content;
		cursor++;
		len--;
	}
	return (b);
}
