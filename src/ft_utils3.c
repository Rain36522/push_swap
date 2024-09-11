/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:32:36 by pudry             #+#    #+#             */
/*   Updated: 2023/10/30 14:05:46 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_sort(t_stack *stck)
{
	if (!stck)
		return (0);
	else if (!stck->next)
		return (1);
	while (stck->next)
	{
		if (stck->nbr > stck->next->nbr)
			return (0);
		stck = stck->next;
	}
	return (1);
}
