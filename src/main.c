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
    char                *content;
    char                *cursor;

    if (argc == 1)
    {
        content = parse_map(0, "stdin");
        if (!content || !content[0])
            error();
        else
        {
            cursor = content;
            while (*cursor)
            {
                map = read_map(&cursor, "stdin");
                if (!map)
                {
                    error();
                    break ;
                }
                else if (!check_valid_map(map))
                {
                    error();
                    free_char_map(map->n_rows, map->str_map);
                    free(map);
                }
                else
                {
                    write_solution(map);
                    print_result(map);
                    free_char_map(map->n_rows, map->str_map);
                    free(map);
                    ft_putchar('\n');
                }
            }
        }
        free(content);
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
                content = parse_map(fd, argv[i]);
                close(fd);
                if (!content || !content[0])
                {
                    ERROR_MAP
                    ft_putchar('\n');
                }
                else
                {
                    cursor = content;
                    while (*cursor)
                    {
                        map = read_map(&cursor, argv[i]);
                        if (!map)
                        {
                            ERROR_MAP
                            ft_putchar('\n');
                            break ;
                        }
                        else if (!check_valid_map(map))
                        {
                            ERROR_MAP
                            ft_putchar('\n');
                            free_char_map(map->n_rows, map->str_map);
                            free(map);
                        }
                        else
                        {
                            write_solution(map);
                            print_result(map);
                            free_char_map(map->n_rows, map->str_map);
                            free(map);
                            ft_putchar('\n');
                        }
                    }
                }
                free(content);
            }
            i++;
        }
    }
    return (0);
}
