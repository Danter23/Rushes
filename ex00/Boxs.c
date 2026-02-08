/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boxs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:55:08 by jbaltza-          #+#    #+#             */
/*   Updated: 2026/02/08 11:55:39 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_board(int *array, int row_length)
{
	int		i;
	char	rows;

	i = 0;
	while (i < row_length * row_length)
	{
		if (i % row_length == 0)
		{
			write(1, "\n", 1);
			rows = array[i] + '0';
			write(1, &rows, 1);
			i++;
		}
	}
}

// int main (void)
// {
// 	// char str[] = "Alfonso";
// 	int	count[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	ft_print_board(count, 10);
// 	return (0);
// }
// //Meter datos de count en consola
//hay que eliminar el salto de linea del inicio y ver tambien lengh multiplicarlo por 4  
