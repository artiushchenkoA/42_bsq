/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:25:26 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/20 14:46:46 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void free_map(int row, int **map)
{
    while(map[row])
    {
        free(map[row]);
        row--;
    }
    free(map);
}

void    free_char_map(int row, char **map)
{
     while(map[row])
    {
        free(map[row]);
        row--;
    }
    free(map);
}

int **generate_map(int row, int col)
{
    int **map;
    int i;

    i = 0;
    if ((map = (int**)malloc(sizeof(int*) * row)) == NULL)
        return (NULL);
    while (i < row)
    {
        if ((map[i] = (int*)malloc(sizeof(int) * col)) == NULL)
        {
            while (i >= 0)
            {
                free(map[i]);
                i--;
            }
            free(map);
            return (NULL);
        }
        i++;
    }
    return (map);
}

t_found_position find_biggest_square(t_map *map)
{
    int i;
    int j;
    int **dist_map;
    int count_max;
    t_found_position fp;

    i = 0;
    count_max = 0;
    dist_map = generate_map(map->n_rows, map->n_cols);
    while (i < map->n_cols)
    {
        j = 0;
        while (j < map->n_rows - 1)
        {
            if (map->str_map[i][j] == map->obstacle)
                dist_map[i][j] = 0;
            else if (i == 0 || j == 0)
                dist_map[i][j] = 1;
            else
                dist_map[i][j] = ft_min(dist_map[i - 1][j], dist_map[i][j - 1], dist_map[i - 1][j - 1]) + 1;
            if (dist_map[i][j] > count_max)
            {
                count_max = dist_map[i][j];
                fp.square_size = count_max;
                fp.i_end = i;
                fp.j_end = j;
                fp.i_begin = fp.i_end - fp.square_size;
                fp.j_begin = fp.j_end - fp.square_size;
            }
            j++;
        }
        i++;
    }
    free_map(map->n_rows, dist_map);
    return fp;
}

