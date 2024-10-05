/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:13:47 by rakim             #+#    #+#             */
/*   Updated: 2024/10/03 19:53:03 by rakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	src_idx;
	int	dst_idx;

	src_idx = 0;
	dst_idx = 0;
	while (src[src_idx] != '\0' && src_idx < (int)size)
		dst[dst_idx++] = src[src_idx++];
	dst[dst_idx] = '\0';
	while (src[src_idx] != '\0')
		src_idx++;
	return (src_idx);
}