/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_exit_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:53:22 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/23 12:20:07 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	if (list)
	{
		while (list)
		{
			printf("valeur de la chaine : %i\n", list->content);
			list = list->next;
		}
	}
}

void	free_count(t_info *i)
{
	if (ft_lstsize(i->count) > 0)
	{
		if (ft_lstmove_i(i->count, ft_lstsize(i->count)) == 0)
		{
			if (ft_lstsize(i->list_b) == 0)
				i->count = NULL;
			else
			{
				free(ft_lstmove(i->count, ft_lstsize(i->count)));
				ft_lstmove(i->count, ft_lstsize(i->count) - 1)->next = NULL;
			}
		}
		else if (i->count->content == 0)
		{
			if (ft_lstsize(i->list_b) == 0)
				i->count = NULL;
			else
			{
				i->temp2 = i->count->next;
				free(i->count);
				i->count = i->temp2;
			}
		}
	}
}

void	init(t_info *i)
{
	i->first = 1;
	i->second = 1;
	i->third = 1;
	i->list_a = NULL;
	i->list_b = NULL;
	i->count = NULL;
	i->count_a = 0;
	i->count2 = 0;
	i->ret = NULL;
	i->temp2 = NULL;
	i->head = 0;
	i->end_count = 0;
	i->lock = 0;
}

void	sw_te_hlp(t_info *i, t_list **tete, t_list *goal, int etat)
{
	i->head = etat;
	(*tete) = goal;
}

void	lock_tete(t_info *i, t_list **tete)
{
	if (i->lock == 1)
	{
		i->head = 0;
		(*tete) = i->list_b;
	}
	else if (i->lock == 2)
	{
		i->head = 1;
		(*tete) = ft_lstmove(i->list_b, ft_lstsize(i->list_b));
	}
}
