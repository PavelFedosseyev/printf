/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:28:12 by pfedosse          #+#    #+#             */
/*   Updated: 2019/10/28 13:18:24 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_count(long long n)
{
	long long	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
