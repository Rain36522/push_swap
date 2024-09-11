/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:00:17 by pudry             #+#    #+#             */
/*   Updated: 2023/10/29 12:05:01 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_small_int_max(char *str)
{
	int	i;
	int	j;
	int	iminus;

	iminus = 0;
	if (str[0] == '-')
		iminus = 1;
	str += iminus;
	if (!*str)
		return (0);
	j = 0;
	i = ft_strlen(str);
	while (j < i)
	{
		if (!ft_isdigit(str[j]))
			return (0);
		j ++;
	}
	if (i > 10)
		return (0);
	if (i == 10 && iminus == 1 && ft_strncmp(str, "2147483648", 10) > 0)
		return (0);
	if (i == 10 && iminus == 0 && ft_strncmp(str, "2147483647", 10) > 0)
		return (0);
	return (1);
}

static t_lst_pos	*ft_init_start_ptr(void)
{
	t_lst_pos	*start;

	start = (t_lst_pos *) malloc(sizeof(t_lst_pos) * 1);
	if (!start)
		return (NULL);
	start->strt_b = NULL;
	start->strt_a = NULL;
	return (start);
}

static t_lst_pos	*ft_full_stack_a(int nArg, char **Args)
{
	t_lst_pos	*start;
	int			i;
	t_stack		*ptr;

	i = 2;
	start = ft_init_start_ptr();
	if (!start)
		return (NULL);
	start->strt_a = (t_stack *) malloc(sizeof(t_stack) * 1);
	if (!start->strt_a)
		return (NULL);
	ptr = start->strt_a;
	ptr->nbr = ft_atoi(Args[1]);
	ptr->next = NULL;
	while (i < nArg)
	{
		ptr = ft_new_lst_back(ft_atoi(Args[i]), ptr);
		if (!ptr)
			return (ft_lst_clear(start));
		i ++;
	}
	if (ft_cnt_stack(start->strt_a) > 5)
		start->strt_a = ft_simplify_stack(start->strt_a);
	return (start);
}

t_lst_pos	*check_input(int nArg, char **Args)
{
	int			i;

	if (nArg <= 1)
		return (NULL);
	i = 1;
	if (ft_check_double_value(nArg, Args) == 1)
		return (NULL);
	while (i < nArg)
	{
		if (ft_small_int_max(Args[i++]) == 0)
			return (NULL);
	}
	return (ft_full_stack_a(nArg, Args));
}


void	ft_put_stacks(t_lst_pos *start)
{
	t_stack	*pos_a;
	t_stack	*pos_b;

	pos_a = start->strt_a;
	pos_b = start->strt_b;
	printf("--------A--------  -------B---------\n");
	while (pos_a || pos_b)
	{
		if (pos_a)
		{
			printf("(|\t%i\t|)", pos_a->nbr);
			pos_a = pos_a->next;
		}
		else
			printf("(|\t\t|)");
		if (pos_b)
		{
			printf(" (|\t  %i\t|)", pos_b->nbr);
			pos_b = pos_b->next;
		}
		printf("\n");
	}
}
