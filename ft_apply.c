/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:49:40 by pfedosse          #+#    #+#             */
/*   Updated: 2019/10/30 14:18:17 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*applylength(t_params *prms, va_list *ap)
{
	intmax_t	n;
	char		*str;

	if (!ll || !l)
		n = (!ll) ? (long long)va_arg(*ap, long long) :\
		(long)va_arg(*ap, long);
	else if (!hh || !h)
		n = (!hh) ? (signed char)va_arg(*ap, int) :\
		(short int)va_arg(*ap, int);
	else
		n = (!L) ? (long double)va_arg(*ap, long double) :\
		(int)va_arg(*ap, int);
	str = ft_itoa(n);
	return (str);
}

char		*applyprecision(t_params *prms, char *str, int *len)
{
	char	*tmp1;
	char	*tmp;

	tmp1 = ft_strnew(prms->prec - *len);
	ft_memset(tmp1, '0', prms->prec - *len);
	if (str[0] == '-')
	{
		str[0] = '0';
		tmp = ft_strjoin(tmp1, str);
		free(tmp1);
		tmp[0] = '-';
	}
	else
	{
		tmp = ft_strjoin(tmp1, str);
		free(tmp1);
	}
	free(str);
	str = tmp;
	if ((PLUS == 1 || SPACE == 1) && str[0] != '-')
	{
		tmp = (PLUS == 1) ? ft_strjoin("+", str) :\
		ft_strjoin(" ", str);
		free(str);
		str = tmp;
	}
	return (str);
}

char		*applywidth2(t_params *prms, char *tmp, int *len)
{
	char	*str;
	char	*tmp1;

	if (PLUS == 1 && tmp[0] != '-')
	{
		str = ft_strjoin("+", tmp);
		free(tmp);
		tmp = str;
		prms->width -= 1;
	}
	tmp1 = ft_strnew(prms->width - *len);
	if (ZERO == 1 && prms->prec > *len)
	{
		ft_memset(tmp1, '0', prms->width - *len);
		if (tmp[0] == '-')
		{
			tmp[0] = '0';
			str = ft_strjoin(tmp1, tmp);
			str[0] = '-';
			free(tmp1);
			free(tmp);
			return (str);
		}
	}
	ft_memset(tmp1, ' ', prms->width - *len);
	str = (MINUS == 1) ? ft_strjoin(tmp, tmp1) :\
	ft_strjoin(tmp1, tmp);
	free(tmp1);
	free(tmp);
	return (str);
}

char		*applywidth(t_params *prms, char *tmp, int *len)
{
	char	*str;
	char	*tmp1;

	if (prms->prec > *len)
	{
		prms->width = (PLUS == 1 || SPACE == 1 || tmp[0] == '-') ?\
		prms->width - 1 : prms->width;
		str = applyprecision(prms, tmp, len);
		tmp1 = ft_strnew(prms->width - prms->prec);
		if (ZERO && !prms->dot)
		{
			ft_memset(tmp1, '0', prms->width - prms->prec);
			if (str[0] == '-')
			{
				str[0] = '0';
				tmp = ft_strjoin(tmp1, str);
				free(str);
				free(tmp1);
				str = tmp;
				str[0] = '-';
				return (str);
			}
		}
		ft_memset(tmp1, ' ', prms->width - prms->prec);
		tmp = (MINUS == 1) ? ft_strjoin(str, tmp1) :\
		ft_strjoin(tmp1, str);
		free(str);
		str = tmp;
		free(tmp1);
	}
	else
		str = applywidth2(prms, tmp, len);
	return (str);
}
