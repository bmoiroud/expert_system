/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:30:14 by eferrand          #+#    #+#             */
/*   Updated: 2019/04/10 15:38:34 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_sys.hpp"

using namespace std;

void	list_error_input()
{
}

void	combinaison_fact(string input, vector<std::string> &data, string base)
{
	int		i = 0;

	while (i < input.size() && base.size())
	{
		data.push_back(base + input[i]);
		//std::cout << base + input[i] << std::endl;
		++i;
	}
	base += input[0]; 
	if (1 < input.size())
	{
		std::string tmp = &(input.c_str()[1]);
		combinaison_fact(tmp, data, base);
	}
}

//	envoie en parametre =ABD et doit avoir accès à la liste des règles
//	return la valeur de la condition

bool	check_case(string a_case)
{
	(void)a_case;
	/*
	for (all_rules)
	{
	}
	*/
	return (false);
}

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
