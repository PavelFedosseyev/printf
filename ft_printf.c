/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:58:11 by pfedosse          #+#    #+#             */
/*   Updated: 2019/10/30 14:14:11 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parsestring(t_params *prms, char *str, va_list *ap)
{
	int size;

	size = 0;
	while (*str != '\0')
	{
		ft_memset(prms, 0, sizeof(t_params));
		if (*str == '%' && *str != '\0')
		{
			str++;
			identifyflags(prms, &str);
			identifywidth(prms, &str, ap);
			identifyprec(prms, &str, ap);
			identifylength(prms, &str);
			size += identifyspec(prms, &str, ap);
		}
		else
		{	
			ft_putchar(*str);
			size++;
		}
		str++;
	}
	return (size);
}

int		ft_printf(const char *format, ...)
{
	t_params	*params;
	va_list		ap;
	int			size;

	size = 0;
	if (!(params = (t_params *)malloc(sizeof(t_params))))
		return (0);
	va_start(ap, format);
	size = parsestring(params, (char*)format, &ap);
	va_end(ap);
	return (size);
}
