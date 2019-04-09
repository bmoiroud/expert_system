/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:36 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/08 18:47:22 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fact.hpp"

Fact::Fact(const string name, const bool state)
{
	this.name = name;
	this._value = state;
}

Fact::~Fact()
{
	_cond.clear();
}

bool	Fact::calc(void)
{
	if (_state == true)
		return (true);
	for (int a = 0; a < _cond.size(); ++a)
	{
		if (_cond[a].compare() == true)
			return (true);
	}
}

void	Fact::create_operator(string condition, string conclusion)
{
	vector<int>	all;
	int			pos = -1; // last_find of fact.name
	int			a;
	int			count = 0;

	//condition
	a = all.condition() - 1;
	if (condition[a] == '!')
		_op.push_back(Not(condition.substr(0, a)));
	else if (condition[a] == '+')
		_op.push_back(And(condition.substr(0, a)));
	else if (condition[a] == '|')
		_op.push_back(Or(condition.substr(0, a)));
	else if(condition[a] == '^')
		_op.push_back(Xor(condition.substr(0, a)));
	else
		_op.push_back(Egal(condition));

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
	int	a;

	a = -1;
	while (++a < _cond.size())
	{
		if (_cond[a].calc() == true)
		{
		}
	}
}
