/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:35:35 by alcristo          #+#    #+#             */
/*   Updated: 2026/02/08 12:18:18 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_print_board(int *array, int row_length);

int	*ft_visuals_sum_is_five(int iterator, int row, int *array, int *visuals)
{
	if (iterator % 4 == 0)
		array[iterator + 4 * (visuals[iterator] - 1)] = 4;
	if (iterator % 4 == 2)
		array[4 * row + (visuals[iterator] - 1)] = 4;
	return (array);
}

int	*ft_visual_is_one(int iterator, int row, int *array, int *visuals)
{
	array[iterator + 4 * row] = 4;
	if (iterator % 4 == 0 && visuals[iterator + 4] == 2)
		array[iterator + 12] = 3;
	if (iterator % 4 == 1 && visuals[iterator - 4] == 2)
		array[iterator - 12] = 3;
	if (iterator % 4 == 2 && visuals[iterator + 4] == 2)
		array[iterator + 4] = 3;
	if (iterator % 4 == 3 && visuals[iterator - 4] == 2)
		array[iterator - 4] = 3;
	return (array);
}

int	*ft_visual_is_four_row(int iterator, int row, int *array)
{
	int	iterator_4;

	if (iterator % 4 == 2)
	{
		{
			while (iterator_4 < 4)
			{
				array[4 * row + iterator_4] = iterator_4 + 1;
				iterator_4++;
			}
		}
	}
	if (iterator % 4 == 3)
	{
		{
			while (iterator_4 < 4)
			{
				array[4 * row + 3 - iterator_4] = iterator_4 + 1;
				array[4 * row + 3 - iterator_4] = iterator_4 + 1;
				iterator_4++;
			}
		}
	}
	return (array);
}

int	*ft_visual_is_four_column(int iterator, int *array)
{
	int	iterator_4;

	iterator_4 = 0;
	if (iterator % 4 == 0)
	{
		{
			while (iterator_4 < 4)
			{
				array[iterator + 4 * iterator_4] = iterator_4 + 1;
				iterator_4++;
			}
		}
	}
	if (iterator % 4 == 1)
	{
		{
			while (iterator_4 < 4)
			{
				array[8 + iterator - 4 * iterator_4] = iterator_4 + 1;
				iterator_4++;
			}
		}
	}
	return (array);
}

void	ft_rush01_place(int visuals[16])
{
	int	*array;
	int	iterator;
	int	row;

	iterator = 0;
	array = (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	while (iterator < 16)
	{
		if (visuals[iterator] == 1)
			array = ft_visual_is_one(iterator, row, array, visuals);
		if (visuals[iterator] == 4)
		{
			if (iterator / 8 == 0)
				array = ft_visual_is_four_column(iterator, array);
			else
				array = ft_visual_is_four_row(iterator, row, array);
		}
		if (visuals[iterator] + visuals[4 + iterator] == 5 && iterator < 12)
			array = ft_visuals_sum_is_five(iterator, row, array, visuals);
		iterator++;
		if (iterator % 4 == 0)
			row++;
	}
	ft_rush01_fill(array, visuals);
}
