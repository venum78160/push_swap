/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 10:54:46 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/15 16:16:53 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *i ,t_list **list)
{
	t_list *tete;

	tete = *list;
	while (ft_if_sort(*list) == 1)
	{
		if (ft_lstsize(*list) == 2 && tete->content > tete->next->content)
		{
			// printf("sa\n");
			ft_sa(i , list, 'a');
		}
		else if (tete->content < tete->next->content && tete->content < tete->next->next->content)
		{
			// printf("rra\n");
			ft_rra(i, list, 'a');
		}
		else if (tete->content < tete->next->content && tete->content > tete->next->next->content)
		{
			// printf("rra\n");
			ft_rra(i, list, 'a');
		}
		else if (tete->content > tete->next->content && tete->content < tete->next->next->content)
		{
			// printf("sa\n");
			ft_sa(i, list, 'a');
		}
		else if (tete->content > tete->next->content && tete->content > tete->next->next->content)
		{
			if (tete->next->content > tete->next->next->content)
			{
				// printf("sa\n");
				ft_sa(i, list, 'a');
			}
			else
			{
				// printf("ra\n");
				ft_ra(i, list, 'a');
			}
		}
		tete = *list;
	}
}

void	sort_three_up(t_info *i, t_list **list)
{
	t_list *tete;

	tete = *list;
	while (ft_if_sort(*list) == 1)
	{
		if (ft_if_sort(tete->next->next) == 0 && tete->content > tete->next->content)
		{
			ft_sa(i, list, 'a');
			// printf("sa\n");
		}
		else if (ft_lstmove(tete, ft_lstsize(*list) - 1)->content > ft_lstlast(tete)->content)
		{
			if (tete->content > tete->next->content)
			{
				// printf("sa\n");
				ft_sa(i, list, 'a');
			}
			else
			{
				// printf("rra\n");
				ft_rra(i, list, 'a');
			}
		}
		else if (tete->content < tete->next->content && tete->next->content > tete->next->next->content)
		{
			// printf("ra\n");
			ft_ra(i, list, 'a');
		}
		else if (tete->content > tete->next->content && tete->next->content < tete->next->next->content)
		{
			// printf("sa\n");
			ft_sa(i, list, 'a');
		}
		else if (tete->content > tete->next->content && tete->next->content > tete->next->next->content)
		{
			// printf("sa\n");
			ft_sa(i, list, 'a');
		}
		tete = *list;
	}
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