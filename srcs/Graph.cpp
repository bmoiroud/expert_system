/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:47 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/08 15:06:10 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"
#include "Fact.hpp"

using namespace std;

Graph::Graph()
{
}

// a quel moment le parametre est clear ?
Graph::Graph(vector<string> data)
{
	vector<string>	rules; // condition suivi de conclusion en boucle

	int		a = -1;
	int		b = -1;

	//	creer tous les facts avec la bonne valeur (use =ABC)
	while (++a < data.size() && (b = -1))
		while (++b < data[a].size())
			if ('A' <= data[a][b] && data[a][b] <= 'Z' && get_fact_id(data[a][b]) == -1)
				create_fact(data[a][b], (data[data.size() - 3].find(data[a][b]) != string::npos ? true : false));

	//	recuperer les facts a trouver
	to_find = data.back().substr(1);
	data.pop_back(); // suppression ?ABC
	data.pop_back(); //	suppression =ABC

	//	enregistrer les regles
	a = -1;
	while (++a < data.size())
	{
		if (data[a].find("<=>") != string::npos)
		{
			rules.push_back(data[a].substr(3));
			rules.push_back(data[a].substr(3));
			rules.push_back(data[a - 1]);
		}
		else if (data[a].find("=>"))
			rules.push_back(data[a].substr(2));
		else
			rules.push_back(data[a].substr());
	}

	//	remplissage des facts avec les regles
	a = 1;
	while (a < rules.size())
	{
		b = -1;
		while (++b < rules[a].size())
		{
			if ('A' <= rules[a][b] && rules[a][b] <= 'Z')
				facts[get_fact_id(rules[a][b])].create_operator(rules[a-1], rules[a]);
			if (rules[a][b] == '|' || rules[a][b] == '^')
			{
				string tmp = rules[a];
				rules.clear();
				data.clear();
				error(rules[a]);
			}
		}
		a += 2;
	}
}

Graph::~Graph(void)
{
	facts.clear();
}

void			Graph::create_fact(char name, bool value)
{
	if (!fact_exist(string(1, name)))
		facts.push_back(Fact(string(1, name), value));
}

/*
void			Graph::create_rule(vector <string> str)
{
	int		i;

	i = str.size() - 1;
	if (!fact_exist(str[i]))
		create_fact(str[i]);
	facts[get_fact_id(str[i])]->create_operator(str, i - 1);
}
*/

bool			Graph::fact_exist(string name)
{
	int		i;

	i = -1;
	while (++i < facts.size())
		if (facts[i].name == name)
			return (true);
	return (false);
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

int				Graph::get_fact_id(char name)
{
	int		i;

	i = -1;
	while (++i < n_facts)
		if (facts[i].name == string(1, name))
			return (i);
	return (-1);
}

string	Graph::get_list(string type)
{

}

void		Graph::print_list()
{

}

void			Graph::resolve()
{
	int 	a = -1;
	while (++a < facts.size())
		facts[a].calc("");
	a = -1;
	while (++a < to_find.size())
		cout << facts[a].name << " = " << facts[a].value << endl;
}

void			Graph::check_input(string allFacts)
{
	// faire un par un tous les statements en registrant dans un vector le resultat attendu. Si un statemen envoie un résultat oposé après calcul INCONHERENCE
	vector<string>	data;

	while (allFacts.size())
	{
		data.push_back(allFacts.substr(0 ,1));
		//cout << input[0] << endl;
		combinaison_fact(allFacts, data);
		allFacts.erase(0,1);
	}

	for (int a = 0; a < data.size(); ++a)
	{
		//cout << data[a] << endl;
		check_case(data[a]);
	}
}
