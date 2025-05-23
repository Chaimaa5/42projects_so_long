/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:41:25 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/11/14 20:56:23 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// int main()
// {
// 	printf("%d\n", ft_isprint(56));
// 	printf("%d\n", ft_isprint(87));
// 	printf("%d\n", ft_isprint(233));
// 	printf("%d\n", ft_isprint(31));
// }