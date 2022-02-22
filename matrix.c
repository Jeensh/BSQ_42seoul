/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:00:20 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/22 13:17:32 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	set_col(char *buf, opt *c)
{
	int i;
	int size;

	i = 0;
	size = 0;
	i = skip_first_fline(buf);
	while (buf[i] && (buf[i] != '\n'))				// 한 줄의 길이 세기(열 크기 세기)
	{
		i++;
		size++;
	}
	c->col_size = size;
}

void	set_opt(char *buf, opt *c)		// 첫 행 검사하는 함수 필요
{
	char	opt_row[100];
	char	opt_c[4];
	int		i;
	int		j;

	i = 0;
	j = 0;
	opt_c[3] = '\0';
	while (buf[i]  && (buf[i] != '\n'))
		i++;
	opt_c[2] = buf[--i];
	opt_c[1] = buf[--i];
	opt_c[0] = buf[--i];
	j = -1;
	while (++j < i)
		opt_row[j] = buf[j];
	opt_row[++j] = '\0';
	c->row_size = ft_atoi(opt_row);						// 행 개수 세팅
	c->empty_c = opt_c[0];
	c->hurdle_c = opt_c[1];
	c->fill_c = opt_c[2];
	set_col(buf, c);
}

char	**make_char_matrix(opt *c)
{
	char		**char_matrix;
	int			i;

	char_matrix = (char **)malloc(sizeof(char *) * (c->row_size + 1));		// 마지막 행은 NULL포인터
	if (!char_matrix)
		return (0);
	char_matrix[c->row_size] = 0;
	i = -1;
	while (++i < c->row_size)
	{
		char_matrix[i] = (char *)malloc(sizeof(char) * (c->col_size + 1));	// 마지막 열(문자)은 '\0'
		if (!char_matrix[i])
		{
			free_char_matrix(char_matrix, c);
			return (0);
		}
	}
	i = -1;
	while (++i < c->row_size)
		char_matrix[i][c->col_size] = '\0';
	return (char_matrix);	
}

int	**make_int_matrix(opt *c)
{
	int	**int_matrix;
	int	i;

	int_matrix = (int **)malloc(sizeof(int *) * (c->row_size + 1));		// 마지막 행은 NULL포인터
	if (!int_matrix)
		return (0);
	int_matrix[c->row_size] = 0;
	i = -1;
	while (++i < c->row_size)
	{
		int_matrix[i] = (int *)malloc(sizeof(int) * (c->col_size + 1));	// 마지막 열(정수)는 -1
		if (!int_matrix[i])
		{
			free_int_matrix(int_matrix, c);
			return (0);
		}
	}
	i = -1;
	while (++i < c->row_size)
		int_matrix[i][c->col_size] = -1;
	return (int_matrix);		
}

int	change_c2i(opt *c, char target)								// 문자를 옵션에 따라 해당하는 숫자로 바꿔주기
{
	if (target == c->hurdle_c)
		return (0);
	else if (target == c->empty_c)
		return (1);
	else
		return (-1);
}

char	**make_origianl_matrix(opt *c, char *buf)
{
	char		**original_matrix;
	int			row;
	int			col;
	int			buf_i;

	original_matrix = make_char_matrix(c);
	row = -1;
	col = -1;
	buf_i = skip_first_fline(buf);
	while (++row < c->row_size)
	{
		col = -1;
		while (++col < c->col_size)
			original_matrix[row][col] = buf[buf_i++];
		buf_i++;															// 줄바꿈 문자 건너가기
	}
	return (original_matrix);
}

int	**make_basic_matrix(opt *c, char **original_matrix)
{
	int		**basic_matrix;
	int		row;
	int		col;

	basic_matrix = make_int_matrix(c);
	row = -1;
	col = -1;
	while (++row < c->row_size)
	{
		col = -1;
		while (++col < c->col_size)
			basic_matrix[row][col] = change_c2i(c, original_matrix[row][col]);
	}
	return (basic_matrix);
}

opt	*make_two_matrix(char *filename, int *fd, char ***ori_m, int ***basic_m)
{
	char		*buf;
	opt	*c;
	
	c = (opt *)malloc(sizeof(opt));
	if (!c)
		return (0);
	buf = open_file(filename, fd);											// 파일에서 내용 전부 가져오기
	set_opt(buf, c);														// 파일 첫줄 이용해서 옵션 세팅
	*ori_m = make_origianl_matrix(c, buf);
	*basic_m = make_basic_matrix(c, *ori_m);
	free(buf);
	return (c);
}

opt	*make_two_matrix_std(char *buf, char ***ori_m, int ***basic_m)
{
	opt	*c;
	
	c = (opt *)malloc(sizeof(opt));
	if (!c)
		return (0);
	set_opt(buf, c);														// 파일 첫줄 이용해서 옵션 세팅
	*ori_m = make_origianl_matrix(c, buf);
	*basic_m = make_basic_matrix(c, *ori_m);
	free(buf);
	return (c);
}

void	free_char_matrix(char **char_m, opt *c)
{
	int row;

	row = -1;
	while (++row < c->row_size + 1)
		free(char_m[row]);
	free(char_m);
}

void	free_int_matrix(int **int_m, opt *c)
{
	int row;
	row = -1;
	while (++row < c->row_size + 1)
		free(int_m[row]);
	free(int_m);
}
