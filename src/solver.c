/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:25:26 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/21 12:45:00 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	**generate_map(int row, int col)
{
	int	**map;
	int	i;

	map = malloc(sizeof(int *) * row);
	if (!map)
		return (NULL);
	i = 0;
	while (i < row)
	{
		map[i] = malloc(sizeof(int) * col);
		if (!map[i])
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

static t_found_position	init_position(void)
{
	t_found_position	fp;

	fp.square_size = 0;
	fp.i_begin = 0;
	fp.j_begin = 0;
	fp.i_end = 0;
	fp.j_end = 0;
	return (fp);
}

static int	cell_value(t_map *map, int **dist_map, int row, int col)
{
	if (map->str_map[row][col] == map->obstacle)
		return (0);
	if (row == 0 || col == 0)
		return (1);
	return (ft_min(dist_map[row - 1][col], dist_map[row][col - 1],
			dist_map[row - 1][col - 1]) + 1);
}

static void	update_best(t_found_position *fp, int value, int row, int col)
{
	if (value <= fp->square_size)
		return ;
	fp->square_size = value;
	fp->i_end = row;
	fp->j_end = col;
	fp->i_begin = row - value + 1;
	fp->j_begin = col - value + 1;
}

t_found_position	find_biggest_square(t_map *map)
{
	int					row;
	int					col;
	int					**dist_map;
	t_found_position	fp;

	fp = init_position();
	dist_map = generate_map(map->n_rows, map->n_cols);
	row = 0;
	while (row < map->n_rows)
	{
		col = 0;
		while (col < map->n_cols)
		{
			dist_map[row][col] = cell_value(map, dist_map, row, col);
			update_best(&fp, dist_map[row][col], row, col);
			col++;
		}
		row++;
	}
	free_map(map->n_rows, dist_map);
	return (fp);
}
