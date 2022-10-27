/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:10:11 by donghyle          #+#    #+#             */
/*   Updated: 2022/07/08 12:10:13 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_def.h"
#include <stdlib.h>

static void	ft_memmove_rtol(t_uchar *dst, t_uchar *src, size_t len)
{
	src += (len - 1);
	dst += (len - 1);
	while (len > 0)
	{
		(*dst) = (*src);
		dst--;
		src--;
		len--;
	}
}

static void	ft_memmove_ltor(t_uchar *dst, t_uchar *src, size_t len)
{
	while (len > 0)
	{
		(*dst) = (*src);
		dst++;
		src++;
		len--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_uchar	*cursor_src;
	t_uchar	*cursor_dst;

	if (len == 0)
		return (dst);
	cursor_src = (t_uchar *) src;
	cursor_dst = (t_uchar *) dst;
	if (cursor_src == cursor_dst)
		return (dst);
	if (cursor_src < cursor_dst && cursor_dst < cursor_src + len)
		ft_memmove_rtol(cursor_dst, cursor_src, len);
	else
		ft_memmove_ltor(cursor_dst, cursor_src, len);
	return (dst);
}
