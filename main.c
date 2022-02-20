/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:14:55 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/20 12:35:52 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "my_lib.h"

int main(int argc, char *argv[])
{
	int i;
	char **result;

	if (argc == 1)			// 문자열 인자가 없는 경우- 미완
	{
		
	}
	else					// 문자열 인자가 있는 경우
	{
		i = 1;
		while (i < argc)
		{
			result = get_solution(argv[i])
			print_result(result);
			if (i != (argc -1))
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
