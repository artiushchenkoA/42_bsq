/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:45:00 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/21 12:45:00 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}
