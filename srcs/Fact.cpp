/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:36 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/10 17:58:42 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fact.hpp"
#include "AOperator.hpp"

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
	if (already_passed.find(name) != string::npos)
		return false;
	if (value == true) // faire à la fin pour checker incohérence ?
		return (true);
	for (int a = 0; a < _cond.size(); ++a)
	{
		if (_cond[a]->compare(already_passed) == true)
			return (true);
	}
	return (false);
}

void	Fact::create_operator(string condition, string conclusion)
{
	vector<int>	all;
	int			pos = -1; // last_find of fact.name
	int			a;
	int			count = 0;

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
