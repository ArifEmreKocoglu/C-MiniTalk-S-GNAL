/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:35:39 by akocoglu          #+#    #+#             */
/*   Updated: 2022/01/31 17:58:54 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && 'Z' >= c)
	{
		return (c = c + 32);
	}
	return (c);
}

// int main(void)
// {
//     int a = ft_tolower('+');
//     printf("%c",a);
//     return(0);
// }