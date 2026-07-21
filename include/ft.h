/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartyush <aartyush@student.42.prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:01:37 by aartyush          #+#    #+#             */
/*   Updated: 2026/07/21 13:03:51 by aartyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE_BYTES 32768

typedef struct s_map
{
	int		n_rows;
	int		n_cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**str_map;
}	t_map;

typedef struct s_found_position
{
	int	i_begin;
	int	j_begin;
	int	i_end;
	int	j_end;
	int	square_size;
}	t_found_position;

int					ft_min(int a, int b, int c);
int					ft_atoi(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_stdin(int file);
void				error(void);

char				*parse_map(int file);
t_map				*read_map(char **cursor);
int					validate_chars(t_map *map);
int					check_valid_map(t_map *map);
int					count_lines(t_map *map);

void				free_map(int row, int **map);
void				free_char_map(char **map);
int					**generate_map(int row, int col);
t_found_position	find_biggest_square(t_map *map);
void				print_result(t_map *map);
void				write_solution(t_map *map);

#endif
