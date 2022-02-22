/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghshi <donghshi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:14:55 by donghshi          #+#    #+#             */
/*   Updated: 2022/02/22 12:22:31 by donghshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "my_lib.h"

int main(int argc, char *argv[])
{
	int i;
	
	if (argc == 1)			// 문자열 인자가 없는 경우- 미완
	{
		
	}
	else					// 문자열 인자가 있는 경우
	{
		i = 0;
		while (++i < argc)
		{
			get_solution(argv[i]);
			if (i != (argc -1))
				write(1, "\n", 1);
		}
	}
	system("leaks bsq");
	return (0);
}
