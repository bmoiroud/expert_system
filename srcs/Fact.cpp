/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:36 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/11 16:54:28 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fact.hpp"
#include "AOperator.hpp"
#include "Graph.hpp"

using namespace std;

Fact::Fact(Graph *Master, const string Name, const bool state)
{
	master = Master;
	name = Name;
	value = state;
}

Fact::~Fact()
{
	_cond.clear();
}

bool	Fact::calc(string already_passed)
{
	if (already_passed.find(name) != string::npos) // si on est deja passé dedans
	{
		cout << "return value" << endl;
		return (value);
	}
	if (value == true) // faire à la fin pour checker incohérence ?
	{
		cout << "return true" << endl;
		return (true);
	}
	for (int a = 0; a < _cond.size(); ++a)
	{
		if (_cond[a]->compare(already_passed + name) == true)
		{
			cout << "return apres calcul true" << endl;
			return (true);
		}
	}
	return (false);
}

void	Fact::create_operator(string condition, string conclusion)
{
	vector<int>	all;
	int			pos = -1; // last_find of fact.name
	int			a;
	int			count = 0;

	cout << "Conclusions en remplissage" << conclusion << endl;
	get_influence(condition, all);

	// debugage
	if (all.size() != condition.size())
		cout << "bug get_influence size" << endl;

	//condition
	a = all.size() - 1;
	cout << "condition : " << condition << endl << "coupé en : " << condition.substr(0, a) << endl;
	if (condition[a] == '!')
		_cond.push_back(new Not(condition.substr(0, a), master));
	else if (condition[a] == '+')
		_cond.push_back(new And(condition.substr(0, a), master));
	else if (condition[a] == '|')
		_cond.push_back(new Or(condition.substr(0, a), master));
	else if(condition[a] == '^')
		_cond.push_back(new Xor(condition.substr(0, a), master));
	else
		_cond.push_back(new Egal(condition, master));

	cout << "tkl la famille" << endl;

	//conclusion
	all.clear();
	get_influence(conclusion, all);
	while ((pos = conclusion.find(name, pos + 1)) != string::npos)
	{
		a = pos;
		while (++a < all.size())
			if (conclusion[a] == '!' && all[a] <= pos)
				++count;
	}
	_concl.push_back((count % 2) == 0) ;
}

bool		Fact::change_state()
{
	/*
	int	a;

	a = -1;
	while (++a < _cond.size())
	{
		if (_cond[a]->calc() == true)
		{
		}
	}
	*/
	return (false);
}
