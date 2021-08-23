/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:54:48 by jzhou             #+#    #+#             */
/*   Updated: 2021/08/22 09:51:18 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_evalu(char c, va_list args)
{
	int	count;

	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		count = ft_putptr(va_arg(args, void *));
	if (c == 'd')
		count = ft_putnbr(va_arg(args, int));
	if (c == 'i')
		count = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count = ft_putunsigned(va_arg(args, unsigned int));
	if (c == 'x')
		count = ft_puthex(va_arg(args, unsigned int));
	if (c == 'X')
		count = ft_puthex_cap(va_arg(args, unsigned int));
	if (c == '%')
		count = ft_putpcnt();
	return (count);
}

int	ft_printf(const char *printarg, ...)
{
	int		index;
	int		returnvalue;
	int		count;
	va_list	args;

	va_start(args, printarg);
	index = 0;
	returnvalue = 0;
	while (printarg[index] != '\0')
	{
		if (printarg[index] != '%')
		{
			write(1, &printarg[index++], 1);
			returnvalue++;
		}
		else
		{
			index++;
			count = ft_evalu(printarg[index++], args);
			returnvalue = returnvalue + count;
		}
	}
	va_end(args);
	return (returnvalue);
}
