/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 10:55:06 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/01/23 10:57:28 by vl-hotel         ###   ########.fr       */
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