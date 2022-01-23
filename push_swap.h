/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:48:50 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/01/23 12:32:22 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

//include

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h> // a enlever !!!!!!

// structure
typedef struct s_info {
    int *tab;
    int size_tab;
    int med;
    int argc;
	t_list	*list_a;
    t_list	*list_b;
	int		last;
    int     etat;
    int     first;
    int		second;
	int		third;
    t_list  *count;
    t_list *temp;
}	t_info;

//fonction

void	crea_lst(t_list **list,char *argv);
void	print_list(t_list *list);
void    ft_sa(t_list **list);
void    ft_ra(t_list **list);
void    ft_rra(t_list **list);
void    ft_pa(t_list **list_a, t_list **list_b);
char	**crea_tabs(t_list **list);
int     *crea_tabi(t_list **list);
void	sort_tab(int *tab, int size);
int	    find_med(t_list *list);
int		find_dup(int *tab, int size);
int     ft_deter_int( const char *theString);
void	verif(t_list **list,char **argv);
void	ft_erreur();
void	ft_exit(int	*tab);
void	ft_brain(t_info *i);
void	print_tab(int *tab, int size);
void	sort_three(t_list **list);
void	sort_three_up(t_list **list);
int	    ft_lstmove_i(t_list *lst, int indice);
t_list	*ft_lstmove(t_list *lst, int indice);
int     ft_if_sort(t_list *lst);
int     ft_firtsort(t_info *i, int tete);
void	ft_second_step(t_info *i, int tete);
void	crea_lst_inter(t_info *i,t_list *lst, int count);

#endif