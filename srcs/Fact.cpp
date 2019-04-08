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
	int		i = 0;
	int		n;

	// TODO maj (date du debut du projet a refaire)
	// partir de la fin ? la fin comprend toujours tout ?
	while (condition[i])
	{
		n = this._cond.size();
		if (condition[i] == "|")
			this._cond.push_back(Or());
		else if (condition[i] == "+")
			this._cond.push_back(And());
		else if (condition[i] == "^")
			this._cond.push_back(Xor());
		else if (condition[i] == "!")
			this._cond.push_back(Not());
		else
			this._cond.push_back(Egal());
		if (is_fact(condition[i - 1]))
			this._cond[n].connect_fact(condition, i - 1);
		else
			this._cond[n].connect_op(condition, i - 1);
		i--;
	}
	// end TODO MAJ

	// enregistrer debut zone influence de chaque caractere
	// AB+CD+!+
	// A=0		B=1		+=0		C=3		D=4		+=3		!=+=3	+=(!=3)(+=0)=0
	// si notre fact est compris entre pos et zone influence alors on est concerné
	vector<int>	all;
	int			pos = -1; // last_find of fact.name
	int			a;
	int			count = 0;

	a  = -1;
	while (++a < conclusion.size())
	{
		all.push_back(a);
		if (conclusion[a] == '+')
		{
			if (all[a - 1] < all[ all[a-1] - 1])
				all[a] = all[a - 1];
			else
				all[a] = all[ all[a-1] - 1];
		}
		else if (conclusion[a] == '!')
			all[a] = all[a - 1];
	}

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
