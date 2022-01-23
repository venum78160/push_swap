/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 10:54:46 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/01/23 10:57:37 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **list)
{
	t_list *tete;

	tete = *list;
	while (ft_if_sort(*list) == 1)
	{
		if (ft_lstsize(*list) == 2 && tete->content > tete->next->content) 
			ft_sa(list);
		else if (tete->content < tete->next->content && tete->content < tete->next->next->content)
			ft_rra(list);
		else if (tete->content < tete->next->content && tete->content > tete->next->next->content)
			ft_rra(list);
		else if (tete->content > tete->next->content && tete->content < tete->next->next->content)
			ft_sa(list);
		else if (tete->content > tete->next->content && tete->content > tete->next->next->content)
		{
			if (tete->next->content > tete->next->next->content)
				ft_sa(list);
			else
				ft_ra(list);
		}
		tete = *list;
	}
}

void	sort_three_up(t_list **list)
{
	t_list *tete;

	tete = *list;
	while (ft_if_sort(*list) == 1)
	{
		if (ft_if_sort(tete->next->next) == 0 && tete->content > tete->next->content)
			ft_sa(list);
		else if (ft_lstmove(tete, ft_lstsize(*list) - 1)->content > ft_lstlast(tete)->content)
		{
			if (tete->content > tete->next->content)
				ft_sa(list);
			else
				ft_rra(list);
		}
		else if (tete->content < tete->next->content && tete->next->content > tete->next->next->content)
			ft_ra(list);
		else if (tete->content > tete->next->content && tete->next->content < tete->next->next->content)
			ft_sa(list);
		else if (tete->content > tete->next->content && tete->next->content > tete->next->next->content)
			ft_sa(list);
		tete = *list;
	}
}