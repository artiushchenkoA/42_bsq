/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:01:37 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/20 14:43:57 by aartyush         ###   ########.fr       */
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
    int     n_rows;
    int     n_cols;
    char    empty;
    char    obstacle;
    char    full;
    char    **str_map;
} t_map;

typedef struct t_found_position
{
    int i_begin;
    int j_begin;
    int i_end;
    int j_end;
    int square_size;
}t_found_position;

int                 ft_min(int a, int b, int c);
int                 ft_atoi(char *str);
void                ft_putchar(char c);
void                ft_putstr(char *str);
void                ft_putnbr(int nb);
char                *parse_map(int file, char *argv);
t_map               *read_map(int file, char *argv);
int                 validate_chars(t_map *map);
int                 check_valid_map(t_map *map);
int                 count_lines(t_map *map);
void	            ft_stdin(int file);
void                error(void);
void                free_map(int row, int **map);
void                free_char_map(int row, char **map);
int                 **generate_map(int row, int col);
t_found_position    find_biggest_square(t_map *map);
void                print_result(t_map *map);
void                write_solution(t_map *map);


#endif
