/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:00:56 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/20 14:49:21 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int count_lines(t_map *map)
{
    //count the number of lines in the map, and return it
    int i;
    int lines;

    if (!map->str_map || !map->str_map[0])
        return (0);
    i = 0;
    lines = 0;
    while (map->str_map[i])
    {
        if (*(map->str_map[i]) == '\n')
            lines++;
        i++;
    }
    if (*(map->str_map[i - 1]) != '\n')
        lines++;
    return (lines);
}

int validate_chars(t_map *map)
{
    //check that the map only contains the empty and obstacle characters, and that the first line contains the empty, obstacle, and full characters
    // check that passed chars are all printable and number of lines is a positive integer convertible with ft_atoi;
    int i;

    if (map->n_rows <= 0)
        return (0);
    if (map->empty < 32 || map->empty > 126
        || map->obstacle < 32 || map->obstacle > 126
        || map->full < 32 || map->full > 126)
        return (0);
    if (map->empty == map->obstacle || map->empty == map->full
        || map->obstacle == map->full)
        return (0);
    i = 0;
    while (map->str_map[i])
    {
        if (*(map->str_map[i]) != map->empty && *(map->str_map[i]) != map->obstacle
            && *(map->str_map[i]) != '\n')
            return (0);
        i++;
    }
    return (1);
}

int check_valid_map(t_map *map)
{
    //check that the first line says number of lines, followed by
    //the empty, obstacle, and full characters, together 4 chars only
    //then check that every line has the same number of characters, and that they only contain
    //the empty and obstacle characters, and that the number of lines matches the number in the
    //first line
    int i;
    int len;
    int first_len;

    if (!validate_chars(map))
        return (0);
    if (count_lines(map) != map->n_rows)
        return (0);
    first_len = 0;
    while (map->str_map[first_len] && *(map->str_map[first_len]) != '\n')
        first_len++;
    i = 0;
    while (map->str_map[i])
    {
        len = 0;
        while (map->str_map[i] && *(map->str_map[i]) != '\n')
        {
            len++;
            i++;
        }
        if (len != first_len)
            return (0);
        if (*(map->str_map[i]) == '\n')
            i++;
    }
    return (1);
}

t_map   *read_map(int file, char *argv)
{
   //get the parsed map, and return a t_map struct with the number of rows, empty, obstacle, and full characters, and the string representation of the map
    t_map *map;
    char *content;
    char *rest;
    int i;
    int len;

    content = parse_map(file, argv);
    if (!content || !content[0])
    {
        free(content);
        return (NULL);
    }
    i = 0;
    while (content[i] >= '0' && content[i] <= '9')
        i++;
    if (i == 0 || content[i] == '\0' || content[i + 1] == '\0'
        || content[i + 2] == '\0' || content[i + 3] != '\n')
    {
        free(content);
        return (NULL);
    }
    map = malloc(sizeof(t_map));
    if (!map)
    {
        free(content);
        return (NULL);
    }
    map->n_rows = ft_atoi(content);
    map->empty = content[i];
    map->obstacle = content[i + 1];
    map->full = content[i + 2];
    rest = content + i + 4;
    len = 0;
    while (rest[len])
        len++;
    map->str_map = malloc(len + 1 * sizeof(char));
    if (!map->str_map)
    {
        free(content);
        free(map);
        return (NULL);
    }
    i = 0;
    while (i < len)
    {
        map->str_map[i] = &rest[i];
        i++;
    }
    *(map->str_map[len]) = '\0';
    free(content);
    return (map);
}

char  *parse_map(int file, char *argv)
{
    //read map from file descriptor;
    char buffer[BUFFER_SIZE_BYTES + 1];
    char *content;
    char *new_content;
    int bytes_read;
    int total_len;
    int i;

    (void)argv;
    content = malloc(1);
    if (!content)
        return (NULL);
    content[0] = '\0';
    total_len = 0;
    bytes_read = read(file, buffer, BUFFER_SIZE_BYTES);
    while (bytes_read > 0)
    {
        new_content = malloc(total_len + bytes_read + 1);
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
        while (i < bytes_read)
        {
            new_content[total_len + i] = buffer[i];
            i++;
        }
        new_content[total_len + bytes_read] = '\0';
        free(content);
        content = new_content;
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

