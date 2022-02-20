/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:29:51 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/20 17:31:00 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_H
# define MY_LIB_H

# define BUF_SIZE 20000000
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map_opt{
	char	hurdle_c;
	char	empty_c;
	char	fill_c;
} opt;

char	**get_solution(char *filename);									// sol

void	print_result(char **result);									// my_print

char	*open_file(char *filename, int *fd);							// fileio		

void	set_len_chars(int *col_size, int *row_size, struct chars *c);	// matrix
char	**make_char_matrix(char *filename);
char	**make_original_matrix(int fd, char *filename);

int	check_sign(char *str);												// atoi
int	get_num(char *str);
int	ft_atoi(char *str);

#endif
