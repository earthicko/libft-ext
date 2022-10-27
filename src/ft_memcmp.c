/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:43:43 by donghyle          #+#    #+#             */
/*   Updated: 2022/07/08 13:43:44 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_def.h"
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_uchar	*cursor_1;
	t_uchar	*cursor_2;

	cursor_1 = (t_uchar *) s1;
	cursor_2 = (t_uchar *) s2;
	while (n > 0)
	{
		if (*cursor_1 != *cursor_2)
			return ((int)(*cursor_1) - (int)(*cursor_2));
		cursor_1++;
		cursor_2++;
		n--;
	}
	return (0);
}
