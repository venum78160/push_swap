/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:00:02 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/23 18:18:00 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_second_step(t_info *i, int tete)
{
	static int	count = 0;

	if (i->second == 1)
	{
		if (i->head == 0)
			declar_step_2_up(i);
		else
			declar_step_2_down(i);
	}
	if (i->second > 1)
	{
		if (i->head == 0)
			sort_step_2_up(i, &count, tete);
		else
			sort_step_2_down(i, &count, tete);
	}
}

void	sort_step_2_up(t_info *i, int *count, int tete)
{
	if (i->count->content == 0)
		step2_up_hlp(i, count);
	else if (tete >= i->med)
	{		
		ft_pa(i, &i->list_b, &i->list_a, 'a');
		i->count->content--;
		i->count_a++;
	}
	else if (tete < i->med)
	{
		ft_ra(i, &i->list_b, 'b');
		i->count->content--;
		(*count)++;
	}
}

void	sort_step_2_down(t_info *i, int *count, int tete)
{
	if (ft_lstmove_i(i->count, ft_lstsize(i->count)) == 0)
	{
		if ((*count) > 0)
			ft_lstadd_front(&i->count, ft_lstnew((*count)));
		(*count) = 0;
		free_count(i);
		etat_chg_hlp(i, 0, 1, 0);
	}
	else if (tete >= i->med)
	{
		ft_rra(i, &i->list_b, 'b');
		ft_pa(i, &i->list_b, &i->list_a, 'a');
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
		i->count_a++;
	}
	else if (tete < i->med)
	{
		ft_rra(i, &i->list_b, 'b');
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
		(*count)++;
	}
}

void	declar_step_2_up(t_info *i)
{
	crea_lst_inter(i, i->list_b, i->count->content);
	i->med = find_med(i->temp, i);
	ft_lstclear(&i->temp);
	i->second = 2;
	i->lock = 1;
	i->last = ft_lstmove_i(i->list_b, i->count->content);
	if (i->count->content <= 3)
	{
		while (i->count->content > 0)
		{
			ft_pa(i, &i->list_b, &i->list_a, 'a');
			i->count->content--;
			i->count_a++;
		}
		free_count(i);
		etat_chg_hlp(i, 0, 1, 0);
	}
}

void	declar_step_2_down(t_info *i)
{
	int	last;

	last = ft_lstmove_i(i->count, ft_lstsize(i->count));
	help_crea_lst_2(i);
	i->med = find_med(i->temp, i);
	ft_lstclear(&i->temp);
	etat_chg_hlp(i, 2, 0, 2);
	i->last = ft_lstmove_i(i->list_b, last);
	if (ft_lstmove_i(i->count, ft_lstsize(i->count)) <= 3)
	{
		while (ft_lstmove_i(i->count, ft_lstsize(i->count)) > 0)
		{
			ft_rra(i, &i->list_b, 'b');
			ft_pa(i, &i->list_b, &i->list_a, 'a');
			ft_lstmove(i->count, ft_lstsize(i->count))->content--;
			i->count_a++;
		}
		free_count(i);
		etat_chg_hlp(i, 0, 1, 0);
	}
}
