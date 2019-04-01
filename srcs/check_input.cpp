/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:30:14 by eferrand          #+#    #+#             */
/*   Updated: 2019/04/01 21:36:47 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;

void	list_error_input()
{
}

void	combinaison_fact(std::string input, std::vector<std::string> &data,
		std::string base = "")
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

bool	check_case(string case)
{
	for (all_rules)
	{
	}
}
