/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:59:29 by pfedosse          #+#    #+#             */
/*   Updated: 2019/10/30 13:55:30 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_itoa(long long n)
{
	long long	len;
	char		*str;

	len = ft_count(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n < -9223372036854775807 || n > +9223372036854775807)
	{
		ft_putstr("error");
		exit(1);
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n != 0 && len >= 0)
	{
		str[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
