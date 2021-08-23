/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:27:09 by jzhou             #+#    #+#             */
/*   Updated: 2021/08/22 09:22:09 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *c)
{
	int	index;

	index = 0;
	if (c == NULL)
	{
		write(1, &"(null)", 6);
		index = index + 6;
	}
	while (c[index] != '\0')
	{
		write(1, &c[index], 1);
		index++;
	}
	return (index);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	unsigned long	res;
	int				index;

	addr = (unsigned long) ptr;
	index = 0;
	write(1, "0x", 2);
	index = index + 2;
	res = ft_puthex(addr);
	index = index + res;
	return (index);
}

int	ft_putnbr(int nbr)
{
	int	index;

	index = 0;
	ft_putnbr_fd(nbr, 1);
	if (nbr < 0)
		index++;
	index = index + ft_intlen(nbr);
	return (index);
}
