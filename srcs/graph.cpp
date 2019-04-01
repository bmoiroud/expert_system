/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:47 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/01 21:46:02 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.hpp"

using namespace std;

Graph::Graph(void) {}

Graph::~Graph(void)
{
	facts.clear();
}

void			Graph::create_fact(string name)
{
	facts.push_back(Fact(name, false));
}

void			Graph::create_rule(vector <string> str)
{
	int		i;

	i = str.size() - 1;
	if (!fact_exist(str[i]))
		create_fact(str[i]);
	facts[get_fact_id(str[i])]->create_operator(str, i - 1);
}

bool			Graph::fact_exist(string name)
{
	int		i;

	i = -1;
	while (++i < facts.size())
		if (facts[i].name == str)
			return (true);
	return (false);
}

bool			Graph::calc_fact()
{

}

int				Graph::get_fact_id(string name)
{
	int		i;

	i = -1;
	while (++i < n_facts)
		if (facts[i].name == name)
			return (i);
	return (-1);
}

static string	Graph::get_list(string type)
{

}

static void		Graph::print_list()
{

}

void			Graph::resolve()
{

}

void			Graph::check_input(string allFacts)
{
	// faire un par un tous les statements en registrant dans un vector le resultat attendu. Si un statemen envoie un résultat oposé après calcul INCONHERENCE
	std::string allFacts = "ABCD";
	std::vector<std::string>	data;
	while (allFacts.size())
	{
		data.push_back(input.substr(0 ,1));
		//std::cout << input[0] << std::endl;
		combinaison_fact(input, data);
		input.erase(0,1);
	}

	for (int a = 0; a < data.size(); ++a)
	{
		//std::cout << data[a] << std::endl;
		check_case(data[a]);
	}
	return 0;
}
