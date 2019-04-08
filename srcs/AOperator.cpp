/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:17:12 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/08 15:15:18 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AOperator.hpp"

AOperator::~AOperator(void)
{
	_facts.clear();
	_op.clear();
}

void	AOperator::connect_fact(vector <string> str, int i)
{
	if (!this->graph.fact_exist(str[i]))
		this->graph.create_fact(str[i]);
}

void	AOperator::connect_op(vector <string> str, int i)
{
	
}

And::And(string liaison)
{

}

And::~And(void) {}

bool 	And::compare()
{
	int		i = -1;
	bool	a = false;
	bool	b = false;

	if (_facts.size() + _op.size() == 1)
	{
		b = true;
		if (_facts.size() == 1)
			a = _facts[0]->calc();
		else
			a = _op[0].calc();
	}
	else
		switch (_op.size())
		{
			case 0:
				a = _facts[0]->calc();
				b = _facts[1]->calc();
				break ;
			case 1:
				a = _facts[0]->calc();
				b = _op[0].compare();
				break ;
			default:
				a = _op[0].compare();
				b = _op[1].compare();
				break ;
		}
	return (a & b);
}

Or::Or(string liaison)
{

}

Or::~Or(void) {}

bool	Or::compare()
{
	int		i = -1;
	bool	a = false;
	bool	b = false;

	switch (_op.size())
	{
		case 0:
			a = _facts[0]->calc();
			b = _facts[1]->calc();
			break ;
		case 1:
			a = _facts[0]->calc();
			b = _op[0]->compare();
			break ;
		default:
			a = _op[0]->compare();
			b = _op[1]->compare();
			break ;
	}
	return (a | b);
}

Xor::Xor(string liaison)
{

}

Xor::~Xor(void) {}

bool 	Xor::compare()
{
	int		i = -1;
	bool	a = false;
	bool	b = false;

	switch (_op.size())
	{
		case 0:
			a = _facts[0]->calc();
			b = _facts[1]->calc();
			break ;
		case 1:
			a = _facts[0]->calc();
			b = _op[0]->compare();
			break ;
		default:
			a = _op[0]->compare();
			b = _op[1]->compare();
			break ;
	}
	return (a ^ b);
}



Egal::Egal(string liaison)
{

}

Egal::~Egal(void) {}

bool 	Egal::compare()
{
	bool	res;

	switch (_op.size())
	{
		case 0:
			return (!this->_facts[0].calc());
		case 1:
			return (!this->_op[0].calc());
	}
}

Not::Not(string liaison)
{

}

Not::~Not(void) {}

bool 	Not::compare()
{
	switch (_op.size())
	{
		case 0:
			return (!this->_facts[0].calc());
		case 1:
			return (!this->_op[0].calc());
	}
}
