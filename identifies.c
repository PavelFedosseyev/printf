/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:59:08 by pfedosse          #+#    #+#             */
/*   Updated: 2019/10/30 13:34:53 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		identifyspec(t_params *prms, char **str, va_list *ap)
{
	int 		size;
	t_function	*function;

	function = (t_function *)malloc(sizeof(t_function) * 256);
	size = 0;
	prms->spec = **str;
	if (ft_strchr("csp%diouxXf", prms->spec))
	{
		linkfunction(function);
		size = (function[(int)prms->spec])(prms, ap);
	}
	return (size);
}

void	identifylength(t_params *prms, char **str)
{
	prms->length = ft_strnew(2);
	if (**str == 'h' || **str == 'l' || **str == 'L')
	{
		if (**str == 'h' && *((*str) + 1) == 'h')
		{
			prms->length = "hh";
			*str += 2;
			return ;
		}
		if (**str == 'l' && *((*str) + 1) == 'l')
		{
			prms->length = "ll";
			*str += 2;
			return ;
		}
		prms->length[0] = **str;
		prms->length[1] = '\0';
		*str += 1;
	}
	return ;
}

void	identifyprec(t_params *prms, char **str, va_list *ap)
{
	if (**str == '.')
	{
		prms->dot = 1;
		*str += 1;
		if (**str == '*')
		{
			if ((prms->prec = va_arg(*ap, int)) < 0)
				prms->prec *= -1;
			*str += 1;
			return ;
		}
		else
			prms->prec = ft_atoi(*str);
		while (ISNUM(**str))
			*str += 1;
	}
	return ;
}

void	identifywidth(t_params *prms, char **str, va_list *ap)
{
	if (**str == '*')
	{
		if ((prms->width = va_arg(*ap, int)) < 0)
			prms->width *= -1;
		*str += 1;
		return ;
	}
	else
		prms->width = ft_atoi(*str);
	while (ISNUM(**str))
		*str += 1;
	return ;
}

void	identifyflags(t_params *prms, char **str)
{
	while (**str == '+' || **str == '-' || **str == ' '\
	|| **str == '0' || **str == '#')
	{
		if (**str == '+')
			PLUS = 1;
		if (**str == '-')
			MINUS = 1;
		if (**str == ' ')
			SPACE = 1;
		if (**str == '0')
			ZERO = 1;
		if (**str == '#')
			HASH = 1;
		*str += 1;
	}
	return ;
}
