/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:01:37 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/20 11:12:54 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
#define FT_BSQ_H

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE_BYTES 32768
#define ERROR_MAP {ft_putstr(argv[i]);ft_putstr(": map error");}

typedef struct t_map
{
    int n_rows;
    char empty;
    char obstacle;
    char full;
    char *str_map;
} t_map;

int     ft_atoi(char *str);
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putnbr(int nb);
char    *parse_map(int file, char *argv);
t_map   *read_map(int file, char *argv);
int     validate_chars(t_map *map);
int     check_valid_map(t_map *map);
int     count_lines(t_map *map);
void	ft_stdin(int file);
void    error(void);

#endif
