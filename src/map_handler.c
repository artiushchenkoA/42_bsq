/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:00:56 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/21 12:45:00 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map_internal.h"

int	count_lines(t_map *map)
{
	int	i;

	if (!map->str_map)
		return (0);
	i = 0;
	while (map->str_map[i])
		i++;
	return (i);
}

int	validate_chars(t_map *map)
{
	int	i;
	int	j;

	if (map->n_rows <= 0)
		return (0);
	if (map->empty < 32 || map->empty > 126 || map->obstacle < 32
		|| map->obstacle > 126 || map->full < 32 || map->full > 126
		|| map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	i = 0;
	while (map->str_map[i])
	{
		j = 0;
		while (map->str_map[i][j])
		{
			if (map->str_map[i][j] != map->empty
				&& map->str_map[i][j] != map->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid_map(t_map *map)
{
	int	i;
	int	len;

	if (!validate_chars(map))
		return (0);
	if (count_lines(map) != map->n_rows)
		return (0);
	i = 0;
	while (map->str_map[i])
	{
		len = 0;
		while (map->str_map[i][len])
			len++;
		if (len != map->n_cols)
			return (0);
		i++;
	}
	return (1);
}

static char	*parse_header(char *header, t_map *map)
{
	int	i;

	i = 0;
	while (header[i] >= '0' && header[i] <= '9')
		i++;
	if (i == 0 || header[i] == '\0' || header[i + 1] == '\0'
		|| header[i + 2] == '\0' || header[i + 3] != '\n')
		return (NULL);
	map->n_rows = ft_atoi(header);
	map->empty = header[i];
	map->obstacle = header[i + 1];
	map->full = header[i + 2];
	return (header + i + 4);
}

t_map	*read_map(char **cursor)
{
	t_map	*map;
	char	*rest;
	int		end;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	rest = parse_header(*cursor, map);
	if (!rest || !alloc_rows_array(map))
	{
		free(map);
		return (NULL);
	}
	if (!build_rows(map, rest, &end))
	{
		free(map);
		return (NULL);
	}
	*cursor = rest + end;
	return (map);
}
