/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaltza- <jbaltza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:15:30 by alcristo          #+#    #+#             */
/*   Updated: 2026/02/07 16:15:27 by albrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	str_to_int_arr(char *raw_conditions, int clean_conditions, int length)
{
	int	length;
	int	i;

	lengh = lengh * 2 + 1;
	i = 0;
	while (i < lengh)
	{
		int_conditions[i / 2] = str_conditions[i];
		i = i + 2;
	}
	write (1, &conditions, 16);
}