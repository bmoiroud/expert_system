/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:30:14 by eferrand          #+#    #+#             */
/*   Updated: 2019/04/16 19:00:49 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_sys.hpp"

using namespace std;

//	Enregistrer debut zone influence de chaque caractere
//	AB+CD+!+
//	A=0		B=1		+=0		C=3		D=4		+=3		!=+=3	+=(!=3)(+=0)=0
//	Si notre fact est compris entre pos et zone influence alors on est concerné
void	get_influence(string str, vector<int> &all)
{
	int			a;

	a  = -1;
	while (++a < str.size())
	{
		all.push_back(a);
		if (str[a] == '+' || str[a] == '^' || str[a] == '|')
		{
			if (all[a - 1] < all[ all[a-1] - 1])
				all[a] = all[a - 1];
			else
				all[a] = all[ all[a-1] - 1];
		}
		else if (str[a] == '!')
			all[a] = all[a - 1];
	}
}
