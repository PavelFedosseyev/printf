/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:47:37 by pfedosse          #+#    #+#             */
/*   Updated: 2019/10/30 14:17:07 by pfedosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    long long a = 42;
	char *s	= "Renata";
	char d = 'W';
	int b = 0;
	int c = 0;
    b = printf("%-25lld%ssuper%c\n", a, s, d);
    c = ft_printf("%-25lld%ssuper%c\n", a, s, d);
	printf("%d\n", b);
	printf("%d\n", c);
    return (0);
}
