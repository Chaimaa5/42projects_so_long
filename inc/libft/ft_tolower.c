/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:10:09 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/11/14 20:57:43 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
// int main()
// {
// 	printf("%c\n", ft_tolower(66));
// 	printf("%c\n", ft_tolower(87));
// 	printf("%c\n", ft_tolower(23));
// 	printf("%c\n", ft_tolower(97));
// }