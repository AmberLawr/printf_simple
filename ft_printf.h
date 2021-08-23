/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:35:05 by jzhou             #+#    #+#             */
/*   Updated: 2021/08/22 09:28:46 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *printarg, ...);

int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_putptr(void *ptr);
int	ft_putnbr(int nbr);
int	ft_putunsigned(unsigned int nbr);
int	ft_putpcnt(void);
int	ft_puthex(unsigned long decimalnbr);
int	ft_puthex_cap(unsigned long decimalnbr);

#endif
