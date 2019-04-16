/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:47 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/16 18:52:15 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"
#include "Fact.hpp"

using namespace std;

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
				create_fact(data[a][b], ((data[data.size() - 2].find(data[a][b]) != string::npos) ? true : false));

	//	recuperer les facts a trouver
	to_find = data.back().substr(1);
	data.pop_back(); // suppression ?ABC
	data.pop_back(); //	suppression =ABC

	//	enregistrer les regles dans rules
	a = -1;
	while (++a < data.size())
	{
		if (data[a].find("<=>") != string::npos)
		{
			rules.push_back(data[a].substr(3));
			rules.push_back(data[a].substr(3));
			rules.push_back(data[a - 1]);
		}
		else if (data[a].find("=>") != string::npos)
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
			if ('A' <= rules[a][b] && rules[a][b] <= 'Z')
				facts[get_fact_id(rules[a][b])].create_operator(rules[a-1], rules[a]);
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
		facts.push_back(Fact(this, string(1, name), value));
}

bool			Graph::fact_exist(string name)
{
	int		i;

	i = -1;
	while (++i < facts.size())
		if (facts[i].name == name)
			return (true);
	return (false);
}

int				Graph::get_fact_id(char name)
{
	int		i;

	i = -1;
	while (++i < facts.size())
		if (facts[i].name == string(1, name))
			return (i);
	return (-1);
}

void			Graph::resolve()
{
	int 	a = -1;
	while (++a < facts.size())
		facts[a].value = facts[a].calc("");
	a = -1;
	while (++a < to_find.size())
		cout << to_find[a] << " = " << facts[get_fact_id(to_find[a])].value << endl;
}