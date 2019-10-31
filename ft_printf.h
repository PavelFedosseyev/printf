/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:19:10 by pfedosse          #+#    #+#             */
/*   Updated: 2019/10/30 13:44:33 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>
#include "libft/libft.h"


typedef struct		s_params
{
	int				width;
	int				size;
	int				dot;
	int				prec;
	char			spec;
	char			*length;
	short			plus;
	short			minus;
	short			space;
	short			zero;
	short			hash;
}					t_params;

typedef int			(*t_function)(t_params *prms, va_list *ap);

#define PLUS	(prms->plus)
#define MINUS	(prms->minus)
#define SPACE	(prms->space)
#define ZERO	(prms->zero)
#define HASH	(prms->hash)
#define ISNUM(x) (x >= '0' && x <= '9')
#define ll		ft_strcmp(prms->length, "ll")
#define hh		ft_strcmp(prms->length, "hh")
#define h		ft_strcmp(prms->length, "h")
#define l		ft_strcmp(prms->length, "l")
#define L		ft_strcmp(prms->length, "L")

int 				main();
int					ft_printf(const char *format, ...);
void				identifyflags(t_params *prms, char **str);
void				identifywidth(t_params *prms, char **str, va_list *ap);
void				identifyprec(t_params *prms, char **str, va_list *ap);
void				identifylength(t_params *prms, char **str);
int					identifyspec(t_params *prms, char **str, va_list *ap);
void				linkfunction(t_function *function);
int					convertchar(t_params *prms, va_list *ap);
int					convertstring(t_params *prms, va_list *ap);
int					convertinteger(t_params *prms, va_list *ap);
char				*applywidth(t_params *prms, char *tmp, int *len);
char				*applyprecision(t_params *prms, char *str, int *len);
char				*applylength(t_params *prms, va_list *ap);

#endif
