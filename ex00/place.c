/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:35:35 by alcristo          #+#    #+#             */
/*   Updated: 2026/02/07 20:54:13 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_rush01_place(int visuals[16])
{
	int	array[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void	ft_rush01_place(int visuals[16], int array[16])
{
	int	iterator;
	int	iterator_4;
	int	row;

	iterator = 0;
	while (iterator < 16)
	{
		if (visuals[iterator] == 1)
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
		}
		if (visuals[iterator] == 4)
		{
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
		}
		if (visuals[iterator] + visuals[4 + iterator] == 5 && iterator % 4 == 0)
			array[iterator + 4 * (visuals[iterator] - 1)] = 4;
		if (visuals[iterator] + visuals[4 + iterator] == 5 && iterator % 4 == 2)
			array[4 * row + (visuals[iterator] - 1)] = 4;
		iterator++;
		if (iterator % 4 == 0)
		{
			row++;
		}
	}
}

