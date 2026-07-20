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
    int i;

    i = 0;
    while (i < row)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void    free_char_map(int row, char **map)
{
    int i;

    (void)row;
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
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
    int row;
    int col;
    int **dist_map;
    int count_max;
    t_found_position fp;

    row = 0;
    count_max = 0;
    fp.square_size = 0;
    fp.i_begin = 0;
    fp.j_begin = 0;
    fp.i_end = 0;
    fp.j_end = 0;
    dist_map = generate_map(map->n_rows, map->n_cols);
    while (row < map->n_rows)
    {
        col = 0;
        while (col < map->n_cols)
        {
            if (map->str_map[row][col] == map->obstacle)
                dist_map[row][col] = 0;
            else if (row == 0 || col == 0)
                dist_map[row][col] = 1;
            else
                dist_map[row][col] = ft_min(dist_map[row - 1][col], dist_map[row][col - 1], dist_map[row - 1][col - 1]) + 1;
            if (dist_map[row][col] > count_max)
            {
                count_max = dist_map[row][col];
                fp.square_size = count_max;
                fp.i_end = row;
                fp.j_end = col;
                fp.i_begin = fp.i_end - fp.square_size + 1;
                fp.j_begin = fp.j_end - fp.square_size + 1;
            }
            col++;
        }
        row++;
    }
    free_map(map->n_rows, dist_map);
    return fp;
}

