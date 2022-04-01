/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:57:25 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/11/15 21:26:32 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	x;
	size_t			i;
	unsigned char	*str;

	i = 0;
	x = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == x)
			return (&str[i]);
		i++;
	}
	return (0);
}
// int main()
// {
// 	char	str[] = "Hello";

// 	printf("%s", ft_memchr(str, 72, sizeof(str)));
// 	printf("%s", memchr(str, 72, sizeof(str)));
// }