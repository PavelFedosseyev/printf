/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertspecifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:01:12 by pfedosse          #+#    #+#             */
/*   Updated: 2019/10/30 14:19:03 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convertinteger(t_params *prms, va_list *ap)
{
	int			len;
	char		*tmp;
	char		*str;
	
	
	tmp = applylength(prms, ap);
	len = ft_strlen(tmp);
	len = (tmp[0] == '-' && (prms->prec >= len)) ? len - 1 : len;
	if (len >= prms->width && len >= prms->prec)
	{
		str = tmp;
		if ((PLUS == 1 || SPACE == 1) && tmp[0] != '-')
		{
			free (str);
			tmp = (PLUS == 1) ? ft_strjoin("+", str) :\
			ft_strjoin(" ", str);
			free (str);
			str = tmp;
		}
	}
	else if (prms->prec >= prms->width)
		str = applyprecision(prms, tmp, &len);
	else
		str = applywidth(prms, tmp, &len);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

int		convertstring(t_params *prms, va_list *ap)
{
	char	*str;
	char	*tmp;
	char	*tmp1;
	int		len;

	tmp1 = (char *)va_arg(*ap, char *);
	len = ft_strlen(tmp1);
	if ((prms->width - len) > 0)
	{
		tmp = ft_strnew(prms->width - len);
		ft_memset(tmp, ' ', prms->width - len);
		str = (MINUS == 1) ? ft_strjoin(tmp1, tmp)\
		: ft_strjoin(tmp, tmp1);
		free (tmp);
		free (tmp1);
		len = prms->width;
	}
	else
		str = tmp1;
	ft_putstr(str);
	return (len);
}

int		convertchar(t_params *prms, va_list *ap)
{
	char	*str;
	char	*tmp;
	char	*tmp1;
	int		len;

	tmp1 = ft_strnew(1);
	len = 1;
	*tmp1 = (char)va_arg(*ap, int);
	if (prms->width > 1)
	{
		tmp = ft_strnew(prms->width - 1);
		ft_memset(tmp, ' ', prms->width - 1);
		str = (MINUS == 1) ? ft_strjoin(tmp1, tmp)\
		: ft_strjoin(tmp, tmp1);
		free (tmp);
		free (tmp1);
		len = prms->width;
	}
	else
		str = tmp1;
	ft_putstr(str);
	return (len);
}
