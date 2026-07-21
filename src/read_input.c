/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:45:00 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/21 12:45:00 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

static char	*append_chunk(char *content, int total_len, char *buf, int n)
{
	char	*new_content;
	int		i;

	new_content = malloc(total_len + n + 1);
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
	i = 0;
	while (i < total_len)
	{
		new_content[i] = content[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		new_content[total_len + i] = buf[i];
		i++;
	}
	new_content[total_len + n] = '\0';
	free(content);
	return (new_content);
}

char	*parse_map(int file)
{
	char	buffer[BUFFER_SIZE_BYTES + 1];
	char	*content;
	int		bytes_read;
	int		total_len;

	content = NULL;
	total_len = 0;
	bytes_read = read(file, buffer, BUFFER_SIZE_BYTES);
	while (bytes_read > 0)
	{
		content = append_chunk(content, total_len, buffer, bytes_read);
		if (!content)
			return (NULL);
		total_len += bytes_read;
		bytes_read = read(file, buffer, BUFFER_SIZE_BYTES);
	}
	if (bytes_read < 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}
