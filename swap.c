/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:25:54 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/01/22 16:23:01 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sa(t_list **list)
{
    t_list	*tmp;
    t_list	*tete;

    tete = *list;
    tmp = tete->next;
    tete->next = tete->next->next;
    tmp->next = *list;
    *list = tmp;
}

void    ft_ra(t_list **list)
{
    t_list *tmp;
    t_list	*tete;
    int count;

    count = 0;
    tmp = *list;
    tete = *list;
    *list = tete->next;
    while (count < ft_lstsize(*list))
    {
        tete = tete->next;
        count++;
    }
    tete->next = tmp;
    tete->next->next = NULL;
}

void    ft_rra(t_list **list)
{
    t_list	*tete;
    int count;

    count = 0;
    tete = *list;
    while (count < ft_lstsize(*list) - 2)
    {
        tete = tete->next;
        count++;
    }
    tete->next->next = *list;
    *list = tete->next;
    tete->next = NULL;
}

void    ft_pa(t_list **list_a, t_list **list_b)
{
    t_list	*tmp;

    tmp = *list_a;
    *list_a = tmp->next;
    tmp->next = NULL;
    ft_lstadd_front(list_b, tmp);
}
