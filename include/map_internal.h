/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:45:00 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/21 12:45:00 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INTERNAL_H
#define MAP_INTERNAL_H

#include "ft.h"

int	alloc_rows_array(t_map *map);
int	build_rows(t_map *map, char *rest, int *end);

#endif
