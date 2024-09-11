/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:56:20 by pudry             #+#    #+#             */
/*   Updated: 2023/10/29 10:56:20 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_cnt_stack(t_stack *ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		i ++;
		ptr = ptr->next;
	}
	return (i);
}

int	ft_give_smaller_pos(t_stack *stck)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 2147483647;
	k = 0;
	while (stck)
	{
		if (j >= stck->nbr)
		{
			j = stck->nbr;
			k = i;
		}
		stck = stck->next;
		i ++;
	}
	return (k);
}

int	ft_give_biger_pos(t_stack *stck)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = -2147483648;
	k = 0;
	while (stck)
	{
		if (j <= stck->nbr)
		{
			j = stck->nbr;
			k = i;
		}
		stck = stck->next;
		i ++;
	}
	return (k);
}

t_stack	*ft_get_stack(t_lst_pos *start, int cmd)
{
	if (cmd == 0)
		return (start->strt_a);
	return (start->strt_b);
}
