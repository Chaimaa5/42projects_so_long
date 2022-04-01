/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:13:33 by cel-mhan          #+#    #+#             */
/*   Updated: 2021/11/19 02:31:21 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
// void    MY_toupper(unsigned int i, char *s)
// {
// 	*s = *s - 32;

// }
//  int main ()
//  {
//      unsigned int i = 0;
//      char s[] = "working";
//     ft_striteri(s, MY_toupper);
//     printf("%s\n", s);
//  }