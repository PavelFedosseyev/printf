/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkfunction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 23:17:09 by pfedosse          #+#    #+#             */
/*   Updated: 2019/10/21 14:44:17 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	linkfunction(t_function *function)
{
	function['i'] = &convertinteger;
	function['d'] = &convertinteger;
	function['s'] = &convertstring;
	function['%'] = &convertchar;
	function['c'] = &convertchar;
	// function['u'] = &convertuint;
	// function['x'] = &converthex;
	// function['X'] = &converthex;
	// function['o'] = &convertoctal;
	// function['e'] = &convertscient;
	// function['E'] = &convertscient;
	// function['f'] = &convertfloat;
	return ;
}
