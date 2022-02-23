/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:07:23 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/22 18:12:57 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstmove_i(t_list *lst, int indice)
{
	int	s;

	if (lst)
	{
		s = 1;
		while (s < indice)
		{
			lst = lst->next;
			s++;
		}
	}
	return (lst->content);
}

t_list	*ft_lstmove(t_list *lst, int indice)
{
	int	s;

	if (lst)
	{
		s = 1;
		while (s < indice)
		{
			lst = lst->next;
			s++;
		}
	}
	return (lst);
}

int	ft_if_sort(t_list *lst)
{
	int	s;

	if (lst)
	{
		s = ft_lstsize(lst);
		while (s > 1)
		{
			if (lst->content > lst->next->content)
				return (1);
			lst = lst->next;
			s--;
		}
	}
	return (0);
}

int	ft_amoreb(t_info *i)
{
	t_list	lst;

	if (i->list_b)
	{
		lst = *i->list_b;
		while (lst.next != NULL)
		{
			if (i->list_a->content < lst.content)
				return (1);
			lst = *lst.next;
		}
		if (i->list_a->content < lst.content)
			return (1);
	}
	return (0);
}

int	make_count_a(t_info *i)
{
	t_list	tete;
	int		count;
	int		max;

	count = 0;
	max = -2147483648;
	tete = *i->list_a;
	while (tete.next != NULL)
	{
		if (ft_if_sort(&tete) == 0 && tete.content > max)
			return (count);
		if (tete.content > max)
			max = tete.content;
		count++;
		tete = *tete.next;
	}
	return (count);
}
