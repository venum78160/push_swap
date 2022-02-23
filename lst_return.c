/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:22:36 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/22 18:17:16 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_rt(t_ret *list)
{
	if (list)
	{
		while (list)
		{
			if (list->content == 4)
				print_lst_move(list, "ra\n", "rb\n");
			if (list->content == 1)
				print_lst_move(list, "sa\n", "sb\n");
			if (list->content == 3)
				print_lst_move(list, "pa\n", "pb\n");
			if (list->content == 6)
				print_lst_move(list, "rra\n", "rrb\n");
			if (list->content == 2)
				ft_putstr_fd("ss\n", 1);
			if (list->content == 5)
				ft_putstr_fd("rr\n", 1);
			if (list->content == 7)
				ft_putstr_fd("rrr\n", 1);
			list = list->next;
		}
	}
}

void	lst_change_rt_under(t_ret **list)
{
	t_ret	*tete;

	tete = *list;
	while ((*list)->next->next != NULL)
	{
		if ((*list)->next->content == 4)
			ft_ra_rra_same_tag(list, 6);
		if ((*list)->next->content == 3)
			ft_ra_rra_diff_tag(list, 3);
		if ((*list)->next->content == 1)
			ft_ss_diff_tag(list, 1, 2);
		if ((*list)->next->content == 4)
			ft_ss_diff_tag(list, 4, 5);
		if ((*list)->next->content == 6)
			ft_ss_diff_tag(list, 6, 7);
		if ((*list)->next->content == 6)
			ft_ra_rra_same_tag(list, 4);
		(*list) = (*list)->next;
	}
	*list = tete;
}

void	ft_ra_rra_same_tag(t_ret **list, int t)
{
	char	tag;
	t_ret	*temp;

	tag = (*list)->next->tag;
	if ((*list)->next->next->content == t)
	{
		if (tag == (*list)->next->next->tag)
		{
			temp = (*list)->next->next->next;
			free((*list)->next->next);
			free((*list)->next);
			(*list)->next = temp;
		}
	}
}

void	ft_ra_rra_diff_tag(t_ret **list, int t)
{
	char	tag;
	t_ret	*temp;

	tag = (*list)->next->tag;
	if ((*list)->next->next->content == t)
	{
		if (tag != (*list)->next->next->tag)
		{
			temp = (*list)->next->next->next;
			free((*list)->next->next);
			free((*list)->next);
			(*list)->next = temp;
		}
	}
}

void	ft_ss_diff_tag(t_ret **list, int t, int content)
{
	char	tag;
	t_ret	*temp;

	tag = (*list)->next->tag;
	if ((*list)->next->next->content == t)
	{
		if (tag != (*list)->next->next->tag)
		{
			temp = (*list)->next->next->next;
			free((*list)->next->next);
			free((*list)->next);
			(*list)->next = ft_lstnew_ret(content, 'b');
			(*list)->next->next = temp;
		}
	}
}
