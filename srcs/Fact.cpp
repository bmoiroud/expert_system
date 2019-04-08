/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:36 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/08 16:46:53 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fact.hpp"

Fact::Fact(const string name, const bool state)
{
	this.name = name;
	this._state = state;
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
	// construire conlusion comme une condition puis la retourner ? (pb multi-instance ?)
	// a chaque "!" voir [pos-1] == id_fact_in_used
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
	vector<string>	all;
	n = -1;
	while (++n < conclusion.size())
	{
		all.push_back( string(1, conclusion[n]) )
		if (conclusion[n] == '+')
		{
			i = n;
			while (0 < --i && all[n].size() < 3)
			{

			}
		}
		else if (conclusion[n] == '!')
		{
		}
		else if ('A' <= conclusion[n] && conclusion[n] <= 'Z')
		{
		}

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
