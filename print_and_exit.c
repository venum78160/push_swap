/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:48:07 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/23 11:36:38 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int	*tab)
{
	free(tab);
	ft_erreur();
}

void	ft_erreur(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	print_tab(int *tab, int size)
{
	int	n;

	n = 0;
	printf("tableau: ");
	while (n < size)
	{
		printf("%d ", tab[n]);
		n++;
	}
	printf("\n");
}

void	ft_bullshit(t_list *a, t_list *b, t_info *i)
{
	t_list	*tmp;

	printf("PILE A: ");
	tmp = a;
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\nPILE B: ");
	tmp = b;
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\nCOUNT: ");
	tmp = i->count;
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n\n");
}

void	ft_lstclear_ret(t_ret **lst)
{
	t_ret	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
}
