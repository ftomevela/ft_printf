/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:50:07 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/02/29 15:15:10 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

//prototipos
int	print_str(char *s);
int	print_digit(unsigned long n, unsigned int base, char specifier);
int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);
int	converse_neg(long n, unsigned int base, char specifier);

#endif
