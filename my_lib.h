/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:29:51 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/22 19:17:33 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_H
# define MY_LIB_H

# define BUF_SIZE 20000000
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct t_map_t_opt{
	char	hurdle_c;
	char	empty_c;
	char	fill_c;
	int		row_size;
	int		col_size;
}	t_opt;

void	print_result(char **result, t_opt *c);
int		get_min(int a, int b, int c);
char	*get_standard_input(void);

char	*open_file(char *filename, int *fd);
int		skip_first_fline(char *buf);

void	set_col(char *buf, t_opt *c);
void	set_opt(char *buf, t_opt *c);
int		**make_int_matrix(t_opt *c);
char	**make_char_matrix(t_opt *c);
int		change_c2i(t_opt *c, char target);
char	**make_original_matrix(t_opt *c, char *buf);
int		**make_basic_matrix(t_opt *c, char **original_matrix);
t_opt	*make_two_matrix(char *filename, int *fd, char ***ori_m, int ***sol_m);
t_opt	*make_two_matrix_std(char *buf, char ***ori_m, int ***basic_m);
void	free_char_matrix(char **char_m, t_opt *c);
void	free_int_matrix(int **int_m, t_opt *c);

int		get_square_size(int **sol_m, int row, int col);
int		**make_solution_matrix(int **basic_matrix, t_opt *c);
int		find_biggest_sqare(int **sol_m, t_opt *c, int *row, int *col);
char	**turn_original2answer(int **sol_m, char **ori_m, t_opt *c);
void	get_solution(char *filename);
void	get_std_solution(char *buf);

int		check_sign(char *str);
int		get_num(char *str);
int		ft_atoi(char *str);

#endif
