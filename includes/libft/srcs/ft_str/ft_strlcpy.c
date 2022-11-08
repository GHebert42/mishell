/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:35:32 by loadjou           #+#    #+#             */
/*   Updated: 2022/11/07 10:28:40 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = ft_strlen(src);
	if (dstsize == 0)
		return (i);
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}
/*
int	main(void)
{
	char	dest[];
	char	src[];

	dest[] = "Hello";
	src[] = " World";
	printf("function return:    %lu\n", strlcpy(dest, src, 0));
	printf("my function return: %zu\n", ft_strlcpy(dest, src, 0));
	ft_strlcpy(dest, src, 0);
	printf("%s\n", dest);
}
*/