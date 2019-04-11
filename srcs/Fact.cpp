/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:36 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/11 18:38:52 by eferrand         ###   ########.fr       */
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
	int		a = 0;
	bool	ret;
	bool	init_ret = false;

	if (already_passed.find(name) != string::npos) // si on est deja passé dedans
	{
		cout << "return value" << endl;
		return (value);
	}
	while (a < _cond.size())
	{
		if (_cond[a]->compare(already_passed + name) == true)
		{
			if (init_ret == true && _concl[a] != ret)
				cout << "tout deconne" << endl;	// TODO erreur
			ret = _concl[a];
			init_ret = true;
			cout << "return apres calcul true" << endl;

		}
		++a;
	}
	if (value == true)
	{
		cout << "return true" << endl;
		return (true);
	}
	if (init_ret)
		return (_concl[a]);
	return (false);
}

void	Fact::create_operator(string condition, string conclusion)
{
	vector<int>	all;
	int			pos = -1; // last_find of fact.name
	int			a;
	int			count = 0;

	get_influence(condition, all);

	//condition
	a = all.size() - 1;
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
