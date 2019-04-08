/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:36 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/08 18:11:12 by eferrand         ###   ########.fr       */
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
	_prev.clear();
}

bool	Fact::calc(void)
{
	if (_state == true)
		return (true);
	for (int a = 0; a < _prev.size(); ++a)
	{
		if (_prev[a].compare() == true)
			return (true);
	}
}

void	Fact::create_operator(string condition, string conclusion)
{
	int		i = 0;
	int		n;
	vector

	// TODO maj
	while (condition[i])
	{
		n = this._prev.size();
		if (condition[i] == "|")
			this._prev.push_back(Or());
		else if (condition[i] == "+")
			this._prev.push_back(And());
		else if (condition[i] == "^")
			this._prev.push_back(Xor());
		else if (condition[i] == "!")
			this._prev.push_back(Not());
		else
			this._prev.push_back(Egal());
		if (is_fact(condition[i - 1]))
			this._prev[n].connect_fact(condition, i - 1);
		else
			this._prev[n].connect_op(condition, i - 1);
		i--;
	}
	// end TODO MAJ

	// enregistrer debut zone influence de chaque caractere
	// AB+CD+!+
	// A=0		B=1		+=0		C=3		D=4		+=3		!=+=3	+=(!=3)(+=0)=0
	// si notre fact est compris entre pos et zone influence alors on est concerné
	vector<int>	all;
	int			pos = -1;
	int			a;
	int			b;

	a  = -1;
	while (++a < conclusion.size())
	{
		all.push_back(a);
		if (conclusion[a] == '+')
		{
		}
	}

	while ((pos = conclusion.find(name, pos + 1)) != string::npos)
	{
	}
}

bool		Fact::change_state()
{
	int	a;

	a = -1;
	while (++a < _prev.size())
	{
		if (_prev[a].calc() == true)
		{
		}
	}
}
