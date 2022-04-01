/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:44:23 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/11/14 21:34:31 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
// int main()
// {
// 	printf("%d\n", ft_isascii(2));
// 	printf("%d\n", ft_isascii(87));
// 	printf("%d\n", ft_isascii(23));
// 	printf("%d\n", ft_isascii(129));
// }