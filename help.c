/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 10:55:06 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/01/23 17:29:18 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_med(t_list *list)
{
	int	*tab;
	int res;

	tab = crea_tabi(&list);
	sort_tab(tab, ft_lstsize(list));
	if (ft_lstsize(list) % 2 == 0)
		res = tab[ft_lstsize(list) / 2];
	else
		res = tab[ft_lstsize(list) / 2 + 1];
	free(tab);
	return (res);
}

void	sort_tab(int *tab, int size)
{
	int		swap;
	int		count;

	count = 0;
	while (count < (size - 1))
	{
		if (tab[count] > tab[count + 1])
		{
			swap = tab[count];
			tab[count] = tab[count + 1];
			tab[count + 1] = swap;
			count = 0;
		}
		else
			count++;
	}
}

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
			if(lst->content > lst->next->content)
				return (1);
			lst = lst->next;
			s--;
		}
	}
	return (0);
}

int	ft_amoreb(t_info *i)
{
	int	s;
	t_list lst;

	if (i->list_b)
	{
		lst = *i->list_b;
		// if (ft_if_sort(i->list_a) == 1)
		// 	return (1);
		s = ft_lstsize(i->list_b);
		while (s > 1)
		{
			if(i->list_a->content < lst.content)
				return (1);
			lst = *lst.next;
			s--;
		}
	}
	return (0);
}