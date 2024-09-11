/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:26:47 by pudry             #+#    #+#             */
/*   Updated: 2023/10/30 15:58:15 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//add lst at end of stack and return a pointer to the last struck of the file
t_stack	*ft_new_lst_back(int nbr, t_stack *start)
{
	t_stack	*a;

	a = start;
	while (a->next)
		a = a->next;
	a->next = (t_stack *) malloc(sizeof(t_stack) * 1);
	if (!a)
		return (NULL);
	a = a->next;
	a->next = NULL;
	a->nbr = nbr;
	return (a);
}

t_lst_pos	*ft_lst_clear(t_lst_pos *start)
{
	t_stack	*ptr;

	while (start->strt_a)
	{
		ptr = start->strt_a->next;
		free(start->strt_a);
		start->strt_a = ptr;
	}
	while (start->strt_b)
	{
		ptr = start->strt_b->next;
		free(start->strt_b);
		start->strt_b = ptr;
	}
	free(start);
	return (NULL);
}

static t_stack	*ft_swap(t_stack *a)
{
	t_stack	*b;

	if (!a)
		return (NULL);
	else if (!a->next)
		return (a);
	b = a->next;
	a->next = b->next;
	b->next = a;
	return (b);
}

//For every commande, there is a int with 3 values.
// cmd a (0)  or cmd b (1) or cmd both (2)
t_lst_pos	*ft_s(t_lst_pos *start, int cmd)
{
	if (cmd == 0 && start->strt_a && start->strt_a->next)
	{
		start->strt_a = ft_swap(start->strt_a);
		write(1, "sa\n", 3);
	}
	else if (cmd == 1 && start->strt_b && start->strt_b->next)
	{
		start->strt_b = ft_swap(start->strt_b);
		write(1, "sb\n", 3);
	}
	else if (start->strt_a && start->strt_a->next && \
	start->strt_b && start->strt_b->next)
	{
		start->strt_a = ft_swap(start->strt_a);
		start->strt_b = ft_swap(start->strt_b);
		write(1, "ss\n", 3);
	}
	return (start);
}
