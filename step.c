/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:42:25 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/23 18:25:02 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_firtsort(t_info *i, int tete)
{
	static int	count = 0;

	if (i->first == 1)
		declar_step_1(i);
	else if (i->first == 3)
		sort_dbl_med(i, tete, &count, &i->first);
	else if (tete < i->med)
	{
		count++;
		ft_pa(i, &i->list_a, &i->list_b, 'b');
	}
	else if (tete >= i->med)
	{
		ft_ra(i, &i->list_a, 'a');
	}
	if (tete == i->last)
	{
		if (count > 0)
			ft_lstadd_front(&i->count, ft_lstnew(count));
		count = 0;
		i->first = 1;
	}
}

void	declar_step_1(t_info *i)
{
	i->med = find_med(i->list_a, i);
	find_dbl_med(i, i->list_a);
	i->last = ft_lstmove_i(i->list_a, ft_lstsize(i->list_a));
	i->first = 2;
	if (ft_lstsize(i->list_a) > 6)
		i->first = 3;
	if ((ft_lstsize(i->list_a) <= 3) && ft_amoreb(i) == 0)
	{
		sort_three(i, &i->list_a);
		i->first = 0;
	}
}

void	last_1(t_info *i, int *count1, int *count_pa, int *step)
{
	if ((*step) == 3)
	{
		ft_lstadd_back(&i->count, ft_lstnew(*count1));
		ft_lstadd_front(&i->count, ft_lstnew(*count_pa));
		(*count1) = 0;
		(*count_pa) = 0;
		i->count_a = 0;
		while (i->count2 > 0)
		{
			ft_rra(i, &i->list_a, 'a');
			i->count2--;
			if (i->third == 3)
			{
				i->count_a++;
			}
		}
		(*step) = 1;
	}
}

void	sort_dbl_med(t_info *i, int tete, int *count, int *step)
{
	static int	count_pa = 0;

	if (tete <= i->tier1)
	{
		ft_pa(i, &i->list_a, &i->list_b, 'b');
		if (ft_lstsize(i->list_b) > 1)
			ft_ra(i, &i->list_b, 'b');
		(*count)++;
	}
	else if (tete <= i->tier2)
	{
		ft_pa(i, &i->list_a, &i->list_b, 'b');
		count_pa++;
	}
	else if (tete > i->tier2)
	{
		ft_ra(i, &i->list_a, 'a');
		i->count2++;
	}
	if (tete == i->last)
		last_1(i, count, &count_pa, step);
}
