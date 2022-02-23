/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 10:54:46 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/23 17:50:24 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *i, t_list **list)
{
	t_list	*tete;

	tete = *list;
	while (ft_if_sort(*list) == 1)
	{
		sort_three_hlp(i, list, tete);
		tete = *list;
	}
}

void	sort_three_hlp(t_info *i, t_list **list, t_list	*tete)
{
	int	d;
	int	t;

	d = tete->next->content;
	t = tete->next->next->content;
	if (ft_lstsize(*list) == 2 && tete->content > d)
		ft_sa(i, list, 'a');
	else if (tete->content < d && tete->content < t)
		ft_rra(i, list, 'a');
	else if (tete->content < d && tete->content > t)
		ft_rra(i, list, 'a');
	else if (tete->content > d && tete->content < t)
		ft_sa(i, list, 'a');
	else if (tete->content > d && tete->content > t)
	{
		if (d > t)
			ft_sa(i, list, 'a');
		else
			ft_ra(i, list, 'a');
	}
}

void	sort_three_up(t_info *i, t_list **list)
{
	t_list	*tete;

	tete = *list;
	while (ft_if_sort(*list) == 1)
	{
		sort_three_up_hlp(i, list, tete);
		tete = *list;
	}
}

void	sort_three_up_hlp(t_info *i, t_list **list, t_list	*tete)
{
	int	d;
	int	t;

	d = tete->next->content;
	t = tete->next->next->content;
	if (ft_if_sort(tete->next->next) == 0 && tete->content > d)
		ft_sa(i, list, 'a');
	else if (ft_lstmove_i(tete, ft_lstsize(*list) - 1)
		> ft_lstlast(tete)->content)
	{
		if (tete->content > d)
			ft_sa(i, list, 'a');
		else
			ft_rra(i, list, 'a');
	}
	else if (tete->content < d && d > t)
		ft_ra(i, list, 'a');
	else if (tete->content > d && d < t)
		ft_sa(i, list, 'a');
	else if (tete->content > d && d > t)
		ft_sa(i, list, 'a');
}

t_ret	*ft_lstnew_ret(int content, char tag)
{
	t_ret	*newlist;

	newlist = malloc(sizeof(t_ret));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->tag = tag;
	newlist->next = NULL;
	return (newlist);
}
