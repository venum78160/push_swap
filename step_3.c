/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:24:17 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/23 18:39:05 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_third_step(t_info *i, int tete)
{
	static int	count = 0;
	static int	count_b = 0;

	if (i->third == 1)
		declar_step_3(i);
	else if (i->third == 3)
		sort_dbl_med(i, tete, &count_b, &i->third);
	else if (tete >= i->med)
	{
		ft_ra(i, &i->list_a, 'a');
		i->count_a--;
		count++;
	}
	else if (tete < i->med)
	{
		ft_pa(i, &i->list_a, &i->list_b, 'b');
		count_b++;
		i->count_a--;
	}
	if (tete == i->last && i->third != 3)
		last_step_3(i, &count, &count_b);
}

void	last_step_3(t_info *i, int *count, int *count_b)
{
	if ((*count_b) > 0)
		ft_lstadd_front(&i->count, ft_lstnew(*count_b));
	(*count_b) = 0;
	while (*count > 0)
	{
		ft_rra(i, &i->list_a, 'a');
		(*count)--;
		i->count_a++;
	}
	i->third = 1;
}

void	declar_step_3(t_info *i)
{
	i->count_a = make_count_a(i);
	crea_lst_inter(i, i->list_a, i->count_a);
	i->med = find_med(i->temp, i);
	ft_lstclear(&i->temp);
	crea_lst_inter(i, i->list_a, i->count_a);
	find_dbl_med(i, i->temp);
	ft_lstclear(&i->temp);
	i->third = 2;
	if (i->count_a > 6)
		i->third = 3;
	i->last = ft_lstmove_i(i->list_a, i->count_a);
	if (i->count_a <= 3)
	{
		sort_three_up(i, &i->list_a);
		i->count_a = 0;
		i->second = 1;
	}
}
