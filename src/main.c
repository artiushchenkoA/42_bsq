/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:00:03 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/21 12:45:00 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"
#include <fcntl.h>

void	error(void)
{
	write(1, "Error\n", 6);
}

static void	report_error(char *label)
{
	if (!label)
		error();
	else
	{
		ft_putstr(label);
		ft_putstr(": map error");
		ft_putchar('\n');
	}
}

static int	handle_map(t_map *map)
{
	int	valid;

	valid = check_valid_map(map);
	if (valid)
	{
		write_solution(map);
		print_result(map);
		ft_putchar('\n');
	}
	free_char_map(map->str_map);
	free(map);
	return (valid);
}

static void	process_stream(char *content, char *label)
{
	char	*cursor;
	t_map	*map;

	if (!content || !content[0])
	{
		report_error(label);
		free(content);
		return ;
	}
	cursor = content;
	while (*cursor)
	{
		map = read_map(&cursor);
		if (!map)
		{
			report_error(label);
			break ;
		}
		if (!handle_map(map))
			report_error(label);
	}
	free(content);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*content;

	if (argc == 1)
		process_stream(parse_map(0), NULL);
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
				report_error(argv[i]);
			else
			{
				content = parse_map(fd);
				close(fd);
				process_stream(content, argv[i]);
			}
			i++;
		}
	}
	return (0);
}
