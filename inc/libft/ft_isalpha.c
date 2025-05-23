/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:45:00 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/11/14 03:46:26 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
// int main()
// {
// 	printf("%d\n", ft_isalpha(97));
// 	printf("%d\n", ft_isalpha(87));
// 	printf("%d\n", ft_isalpha(23));
// 	printf("%d\n", ft_isalpha(32));
// }