/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:00:03 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/20 14:44:16 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"
#include <fcntl.h>

void error(void)
{
    //error message from a write call;
    write(1, "Error\n", 6);
}

int main(int argc, char **argv)
{
    //throw error if the map read is invalid or the file can't be opened
    // if no arguments are passed read from pipe or < stdin via redirection
    // if a single parameter is given - this will be the path to the map file, read from it
    int                 i;
    int                 fd;
    t_map               *map;

    if (argc == 1)
    {
        map = read_map(0, "stdin");
        if (!map || !check_valid_map(map))
            error();
        else
        {
            write_solution(map);
            print_result(map);
        }
        if (map)
        {
            free_char_map(map->n_rows, map->str_map);
            free(map);
        }
    }
    else
    {
        i = 1;
        while (i < argc)
        {
            fd = open(argv[i], O_RDONLY);
            if (fd < 0)
            {
                ERROR_MAP
                ft_putchar('\n');
            }
            else
            {
                map = read_map(fd, argv[i]);
                close(fd);
                if (!map || !check_valid_map(map))
                {
                    ERROR_MAP
                    ft_putchar('\n');
                }
                else
                {
                    write_solution(map);
                    print_result(map);
                }
                if (map)
                {
                    free_char_map(map->n_rows, map->str_map);
                    free(map);
                }
            }
            i++;
        }
    }
    return (0);
}
