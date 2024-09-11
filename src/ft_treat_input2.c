/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_input2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:44:09 by pudry             #+#    #+#             */
/*   Updated: 2023/10/29 10:44:09 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_stack	*ft_duplicate_stack(int isize)
{
	t_stack	*ptr;
	t_stack	*mem_ptr;

	ptr = (t_stack *) malloc(sizeof(t_stack) * 1);
	if (!ptr)
		return (NULL);
	mem_ptr = ptr;
	ptr->nbr = 0;
	ptr->next = NULL;
	while (isize > 1)
	{
		ptr = ft_new_lst_back(0, ptr);
		if (!ptr)
			return (NULL);
		isize --;
	}
	return (mem_ptr);
}

static void	ft_put_value_pos(int pos, int nbr, t_stack *ptr)
{
	while (pos > 1)
	{
		pos --;
		ptr = ptr->next;
	}
	ptr->nbr = nbr;
}

static void	ft_stack_clear(t_stack *start)
{
	t_stack	*ptr;

	ptr = start;
	while (start)
	{
		ptr = start;
		start = start->next;
		free(ptr);
	}
	free (start);
}

t_stack	*ft_simplify_stack(t_stack *ptr1)
{
	t_stack	*ptr2;
	int		i;
	int		j;
	int		isize;

	if (!ptr1)
		return (NULL);
	isize = ft_cnt_stack(ptr1);
	ptr2 = ft_duplicate_stack(isize);
	i = ft_give_biger_pos(ptr1);
	isize --;
	ft_put_value_pos(i, 2147483647, ptr1);
	ft_put_value_pos(i, isize, ptr2);
	j = 0;
	while (isize > j)
	{
		i = ft_give_smaller_pos(ptr1);
		ft_put_value_pos(i, 2147483647, ptr1);
		ft_put_value_pos(i, j ++, ptr2);
	}
	ft_stack_clear(ptr1);
	return (ptr2);
}

int	ft_check_double_value(int nArg, char **Args)
{
	int	i;
	int	j;

	i = 0;
	while (i < nArg)
	{
		j = i + 1;
		while (j < nArg)
		{
			if (ft_strncmp(Args[i], Args[j], 10) == 0)
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}
