/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:45:49 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/11/14 20:57:58 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
// int main()
// {
// 	printf("%c\n", ft_toupper(66));
// 	printf("%c\n", ft_toupper(87));
// 	printf("%c\n", ft_toupper(23));
// 	printf("%c\n", ft_toupper(97));
// }