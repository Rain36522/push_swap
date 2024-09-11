/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:32:52 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 10:43:34 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_lst_pos	*ft_solve_3(t_lst_pos *start, int cmd)
{
	t_stack	*ptr;

	ptr = ft_get_stack(start, cmd);
	if (ft_give_smaller_pos(ptr) == 3)
	{
		if (ptr->nbr > ptr->next->nbr)
			start = ft_s(start, cmd);
		ptr = ft_get_stack(start, cmd);
		start = ft_rr(start, cmd);
		return (start);
	}
	else if (ft_give_smaller_pos(ptr) == 2 && ptr->nbr > ptr->next->next->nbr)
		ft_r(start, cmd);
	else if (ft_give_smaller_pos(ptr) == 2)
		ft_s(start, cmd);
	else
	{
		start = ft_s(start, cmd);
		start = ft_r(start, cmd);
	}
	return (start);
}

t_lst_pos	*ft_solve_5(t_lst_pos *start)
{
	int	isize;

	isize = ft_cnt_stack(start->strt_a);
	start = ft_change_min(start);
	if (isize == 5)
		start = ft_change_max(start, 0);
	if (ft_check_sort(start->strt_a) != 1)
		start = ft_solve_3(start, 0);
	if (isize == 5)
	{
		ft_p(start, 0);
		ft_r(start, 0);
	}
	ft_p(start, 0);
	return (start);
}

t_lst_pos	*ft_radix(t_lst_pos *start)
{
	unsigned long	ibit;
	int				isize;

	ibit = 1;
	while ((!ft_check_sort(start->strt_a) || start->strt_b))
	{
		isize = ft_cnt_stack(start->strt_a);
		while (isize > 0 && start->strt_a)
		{
			if (start->strt_a->nbr / ibit % 2 == 1)
				start = ft_r(start, 0);
			else
				start = ft_p(start, 1);
			isize --;
		}
		ibit *= 2;
		start = ft_return_b(start);
		if (ft_check_bit(start->strt_a, ibit) != 2 && \
		ft_check_bit(start->strt_a, ibit) == ft_check_bit(start->strt_b, ibit))
			ibit *= 2;
	}
	return (start);
}
