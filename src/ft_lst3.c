/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:39:56 by pudry             #+#    #+#             */
/*   Updated: 2023/10/27 16:40:21 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_stack	*ft_befor_lst_last(t_lst_pos *start, int i)
{
	t_stack	*stck;

	if (i == 0)
		stck = start->strt_a;
	else
		stck = start->strt_b;
	if (!stck || !stck->next)
		return (NULL);
	else if (!stck->next->next)
		return (stck);
	while (stck->next->next)
		stck = stck->next;
	return (stck);
}

static t_lst_pos	*ft_swap_last_first(t_lst_pos *start, int cmd)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = ft_lst_last(start, cmd);
	tmp = ft_befor_lst_last(start, cmd);
	if (!tmp)
		return (start);
	tmp->next = NULL;
	if (cmd == 0)
	{
		ptr->next = start->strt_a;
		start->strt_a = ptr;
	}
	else
	{
		ptr->next = start->strt_b;
		start->strt_b = ptr;
	}
	return (start);
}

t_lst_pos	*ft_rr(t_lst_pos *start, int cmd)
{
	if (cmd == 0)
	{
		start = ft_swap_last_first(start, 0);
		write(1, "rra\n", 4);
	}
	else if (cmd == 1)
	{
		start = ft_swap_last_first(start, 1);
		write(1, "rrb\n", 4);
	}
	else if (start->strt_a && start->strt_a->next && \
	start->strt_b && start->strt_b->next)
	{
		start = ft_swap_last_first(start, 0);
		start = ft_swap_last_first(start, 1);
		write(1, "rrr\n", 4);
	}
	return (start);
}
