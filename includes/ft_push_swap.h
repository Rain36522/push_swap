/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:43:02 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 10:43:02 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lstpos
{
	t_stack	*strt_a;
	t_stack	*strt_b;
}	t_lst_pos;

t_stack		*ft_new_lst_back(int nbr, t_stack *start);
t_stack		*ft_lst_last(t_lst_pos *start, int i);
t_lst_pos	*ft_lst_clear(t_lst_pos *start);
t_lst_pos	*check_input(int nArg, char **Args);
int			ft_check_double_value(int nArg, char **Args);
t_stack		*ft_simplify_stack(t_stack *ptr1);
t_lst_pos	*ft_rr(t_lst_pos *start, int cmd);
t_lst_pos	*ft_p(t_lst_pos *start, int cmd);
t_lst_pos	*ft_r(t_lst_pos *start, int cmd);
t_lst_pos	*ft_s(t_lst_pos *start, int cmd);
int			ft_cnt_stack(t_stack *ptr);
int			ft_check_sort(t_stack *stck);
int			ft_give_smaller_pos(t_stack *stck);
int			ft_give_biger_pos(t_stack *stck);
t_lst_pos	*ft_change_min(t_lst_pos *start);
t_lst_pos	*ft_change_max(t_lst_pos *start, int cmd);
t_stack		*ft_get_stack(t_lst_pos *start, int cmd);
t_lst_pos	*ft_solve_3(t_lst_pos *start, int cmd);
t_lst_pos	*ft_solve_5(t_lst_pos *start);
t_lst_pos	*ft_radix(t_lst_pos *start);
int			ft_check_bit(t_stack *ptr, unsigned long ibit);
t_lst_pos	*ft_return_b(t_lst_pos *start);
void		ft_put_stacks(t_lst_pos *start);

#endif