/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chg_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:47:47 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/23 18:20:35 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_ret(t_ret **alst, t_ret *new)
{
	t_ret	*tmp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	swap_tete(t_info *i, t_list **tete)
{
	(*tete) = i->list_a;
	if (i->first == 0 && i->second > 0)
	{
		if (ft_lstmove_i(i->count, ft_lstsize(i->count)) == 0)
			sw_te_hlp(i, tete, ft_lstmove(i->list_b, ft_lstsize(i->list_b)), 1);
		else if (i->count->content == 0)
			sw_te_hlp(i, tete, i->list_b, 0);
		else if (i->list_b->content < ft_lstmove_i(i->list_b, adclst(i->count))
			&& ft_lstsize(i->count) > 1)
			sw_te_hlp(i, tete, ft_lstmove(i->list_b, ft_lstsize(i->list_b)), 1);
		else
			sw_te_hlp(i, tete, i->list_b, 0);
		lock_tete(i, tete);
	}
}

void	etat_chg_hlp(t_info *i, int second, int third, int lock)
{
	i->second = second;
	i->third = third;
	i->lock = lock;
}

void	step2_up_hlp(t_info *i, int *count)
{
	if (ft_lstsize(i->count) == 1)
	{
		i->count->content = (*count);
		(*count) = 0;
	}
	while ((*count) > 0)
	{
		ft_rra(i, &i->list_b, 'b');
		(*count)--;
		i->count->content++;
	}
	etat_chg_hlp(i, 0, 1, 0);
}

void	help_crea_lst_2(t_info *i)
{
	t_list	*tete;
	int		size_b;
	int		end_count_b;

	size_b = ft_lstsize(i->list_b);
	end_count_b = ft_lstmove_i(i->count, ft_lstsize(i->count));
	tete = ft_lstmove(i->list_b, (size_b - end_count_b));
	crea_lst_inter(i, tete->next, end_count_b);
}
