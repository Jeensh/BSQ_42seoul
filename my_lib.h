/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:29:51 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/20 20:27:58 by donghshi         ###   ########.fr       */
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
	int		row_size;
	int		col_size;
} opt;

void	print_result(char **result);									// my_print

int 	get_min(int a, int b, int c);									// math

char	*open_file(char *filename, int *fd);							// fileio		
int		skip_first_fline(char *buf)

void 	set_col(char *buf, struct opt *c);								// matrix
void	set_opt(char *buf, struct opt *c);
char 	**make_int_matrix(struct opt *c);
char	**make_char_matrix(struct opt *c);
int		change_c2i(struct opt *c, char target);
char	**make_original_matrix(int fd, char *filename, int *fd);
char	**make_basic_matrix(struct opt *c, char **original_matrix)
void	make_two_matrix(char *filename, int *fd, char **ori_m, char **sol_m);
void	free_char_matrix(char **char_m, struct opt *c);
void	free_int_matrix(int **int_m, struct opt *c);

int 	get_square_size(int **sol_m, int row, int col);					// solving
char    **make_solution_matrix(int **basic_matrix, struct opt *c);
int 	find_biggest_sqare(int **sol_m, struct opt *c, int *row, int *col);
char    **turn_original2answer(int **sol_m, char **ori_m, struct opt *c);
void    get_solution(char *filename);

int	check_sign(char *str);												// atoi
int	get_num(char *str);
int	ft_atoi(char *str);

#endif
