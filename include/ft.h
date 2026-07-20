/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:01:37 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/20 10:07:20 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
#define FT_BSQ_H

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE_BYTES 32768
#define ERROR_MAP {ft_putstr(argv[i]);ft_putstr(": map error");}

int     ft_atoi(char *str);
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putnbr(int nb);
char    *read_map(int file, char *argv);
int     check_valid_map(char *str_map);

#endif