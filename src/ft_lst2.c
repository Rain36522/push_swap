/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:38:36 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 10:38:36 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*ft_lst_last(t_lst_pos *start, int i)
{
	t_stack	*stck;

	if (i == 0)
		stck = start->strt_a;
	else
		stck = start->strt_b;
	if (!stck)
		return (NULL);
	while (stck->next)
		stck = stck->next;
	return (stck);
}

static t_lst_pos	*ft_first_to_last(t_lst_pos *start, int cmd)
{
	t_stack	*last;
	t_stack	*ptr;

	if ((!start->strt_a && cmd == 0) || (!start->strt_b && cmd == 1))
		return (start);
	else if (cmd == 0)
	{
		ptr = start->strt_a;
		start->strt_a = ptr->next;
		ptr->next = NULL;
	}
	else
	{
		ptr = start->strt_b;
		start->strt_b = ptr->next;
		ptr->next = NULL;
	}
	last = ft_lst_last(start, cmd);
	if (last)
		last->next = ptr;
	return (start);
}

//cmd 1 -> pit top a to top b
t_lst_pos	*ft_p(t_lst_pos *start, int cmd)
{
	t_stack	*mem_top;

	if (cmd == 1 && start->strt_a)
	{
		mem_top = start->strt_a->next;
		start->strt_a->next = start->strt_b;
		start->strt_b = start->strt_a;
		start->strt_a = mem_top;
		write(1, "pb\n", 3);
	}
	else if (cmd == 0 && start->strt_b)
	{
		mem_top = start->strt_b->next;
		start->strt_b->next = start->strt_a;
		start->strt_a = start->strt_b;
		start->strt_b = mem_top;
		write(1, "pa\n", 3);
	}
	return (start);
}

t_lst_pos	*ft_r(t_lst_pos *start, int cmd)
{
	if (cmd == 0 && start->strt_a)
	{
		start = ft_first_to_last(start, 0);
		write(1, "ra\n", 3);
	}
	else if (cmd == 1 && start->strt_b)
	{
		start = ft_first_to_last(start, 1);
		write(1, "rb\n", 3);
	}
	else if (start->strt_a && start->strt_b)
	{
		if (!start->strt_a->next || !start->strt_b->next)
			return (start);
		start = ft_first_to_last(start, 0);
		start = ft_first_to_last(start, 1);
		write(1, "rr\n", 3);
	}
	return (start);
}
