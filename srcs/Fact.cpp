/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:36 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/28 17:06:31 by eferrand         ###   ########.fr       */
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
}

bool	Fact::calc(void)
{
	_prev.clear();
}

void	Fact::create_operator(vector <string> str, int i)
{
	int		n;

	while (str[i])
	{
		n = this._prev.size();
		if (str[i] == "|")
			this._prev.push_back(Or());
		else if (str[i] == "+")
			this._prev.push_back(And());
		else if (str[i] == "^")
			this._prev.push_back(Xor());
		else if (str[i] == "!")
			this._prev.push_back(Not());
		else
			this._prev.push_back(Egal());
		if (is_fact(str[i - 1]))
			this._prev[n].connect_fact(str, i - 1);
		else
			this._prev[n].connect_op(str, i - 1);
		i--;
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
