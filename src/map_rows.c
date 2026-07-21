/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:45:00 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/21 12:45:00 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map_internal.h"

int	alloc_rows_array(t_map *map)
{
	map->str_map = malloc(sizeof(char *) * (map->n_rows + 1));
	return (map->str_map != NULL);
}

static int	line_end(char *rest, int start)
{
	int	i;

	i = start;
	while (rest[i] && rest[i] != '\n')
		i++;
	return (i);
}

static int	row_len(char *row)
{
	int	len;

	if (!row)
		return (0);
	len = 0;
	while (row[len])
		len++;
	return (len);
}

static char	*dup_row(char *rest, int start, int len)
{
	char	*row;
	int		j;

	row = malloc(len + 1);
	if (!row)
		return (NULL);
	j = 0;
	while (j < len)
	{
		row[j] = rest[start + j];
		j++;
	}
	row[len] = '\0';
	return (row);
}

int	build_rows(t_map *map, char *rest, int *end)
{
	int	rows;
	int	start;
	int	i;

	rows = 0;
	start = 0;
	while (rows < map->n_rows && rest[start])
	{
		i = line_end(rest, start);
		map->str_map[rows] = dup_row(rest, start, i - start);
		if (!map->str_map[rows])
		{
			free_char_map(map->str_map);
			return (0);
		}
		rows++;
		if (rest[i] == '\n')
			start = i + 1;
		else
			start = i;
	}
	map->str_map[rows] = NULL;
	map->n_cols = row_len(map->str_map[0]);
	*end = start;
	return (1);
}
