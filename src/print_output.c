/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:25:22 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/20 14:41:30 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void    write_solution(t_map *map)
{
    t_found_position    fp;
    int                 i;
    int                 j;

    fp = find_biggest_square(map);
    i = fp.i_begin;
    while (i < fp.i_end)
    {
        j = fp.j_begin;
        while (j < fp.j_end){
            map->str_map[i][j] = map->full;
            j++;
        }
        i++;
    }
}

void print_result(t_map *map)
{
    int i;
    
    i = 0;
    while (i < map->n_rows)
    {
        ft_putstr(map->str_map[i]);
        ft_putchar('\n');
        i++;
    }
}
