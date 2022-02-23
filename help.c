/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 10:55:06 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/22 18:14:51 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_med(t_list *list, t_info *i)
{
	int	*tab;
	int	res;

	tab = crea_tabi(&list);
	sort_tab(tab, ft_lstsize(list));
	if (ft_lstsize(list) % 2 == 0)
		res = tab[ft_lstsize(list) / 2];
	else
		res = tab[ft_lstsize(list) / 2 + 1];
	if (ft_lstsize(list) == 5 || ft_lstsize(list) == 4)
		res = tab[2];
	if (ft_lstsize(list) == 4 && i->first == 0 && i->second == 1)
		res = tab[1];
	if (ft_lstsize(list) == 4 && i->first == 0 && i->second == 0)
		res = tab[1];
	if (ft_lstsize(list) == 4 && i->first == 1)
		res = tab[1];
	free(tab);
	return (res);
}

void	find_dbl_med(t_info *i, t_list *list)
{
	int	*tab;

	tab = crea_tabi(&list);
	sort_tab(tab, ft_lstsize(list));
	i->tier1 = tab[ft_lstsize(list) / 3 - 1];
	i->tier2 = tab[ft_lstsize(list) / 3 * 2 - 1];
	free(tab);
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

void	print_lst_move(t_ret *list, char *a, char *b)
{
	if (list->tag == 'a')
		ft_putstr_fd(a, 1);
	else
		ft_putstr_fd(b, 1);
}

int	ft_lstsize_ret(t_ret *lst)
{
	int	s;

	s = 0;
	while (lst)
	{
		lst = lst->next;
		s++;
	}
	return (s);
}
