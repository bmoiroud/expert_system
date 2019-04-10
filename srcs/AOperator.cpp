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

#include "Graph.hpp"
#include "Fact.hpp"
#include "AOperator.hpp"

AOperator::~AOperator(void)
{
	_facts.clear();
	_op.clear();
}

/* inutile ?
void	AOperator::connect_fact(vector <string> str, int i)
{
	if (!this->graph.fact_exist(str[i]))
		this->graph.create_fact(str[i]);
}

void	AOperator::connect_op(vector <string> str, int i)
{
	
}
*/

And::And(string liaison)
{
	vector<int>	all;
	get_influence(liaison, all);
	char	c = liaison[all.size() - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&facts[get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all.size() - 1], all.size() -2)));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(all[all.size() - 1], all.size() -2)));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(all[all.size() - 1], all.size() -2)));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(all[all.size() - 1], all.size() -2)));
	
	c = liaison[all[all.size() - 1] - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&facts[get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
	else if (c == '+')                                                 
		_op.push_back(new And(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
	else if (c == '|')                                                 
		_op.push_back(new Or(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
	else if (c == '^')                                                 
		_op.push_back(new Xor(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
}

And::~And(void) {}

bool 	And::compare(string already_passed)
{
	bool	a = false;
	bool	b = false;

	switch (_op.size())
	{
		case 0:
			a = _facts[0]->calc(already_passed);
			b = _facts[1]->calc(already_passed);
			break ;
		case 1:
			a = _facts[0]->calc(already_passed);
			b = _op[0]->compare(already_passed);
			break ;
		default:
			a = _op[0]->compare(already_passed);
			b = _op[1]->compare(already_passed);
			break ;
	}
	return (a & b);
}

Or::Or(string liaison)
{
	vector<int>	all;
	get_influence(liaison, all);
	char	c = liaison[all.size() - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&facts[get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all.size() - 1], all.size() -2)));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(all[all.size() - 1], all.size() -2)));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(all[all.size() - 1], all.size() -2)));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(all[all.size() - 1], all.size() -2)));
	
	c = liaison[all[all.size() - 1] - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&facts[get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
}

Or::~Or(void) {}

bool	Or::compare(string already_passed)
{
	bool	a = false;
	bool	b = false;

	switch (_op.size())
	{
		case 0:
			a = _facts[0]->calc(already_passed);
			b = _facts[1]->calc(already_passed);
			break ;
		case 1:
			a = _facts[0]->calc(already_passed);
			b = _op[0]->compare(already_passed);
			break ;
		default:
			a = _op[0]->compare(already_passed);
			b = _op[1]->compare(already_passed);
			break ;
	}
	return (a | b);
}

Xor::Xor(string liaison)
{
	vector<int>	all;
	get_influence(liaison, all);
	char	c = liaison[all.size() - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&facts[get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all.size() - 1], all.size() -2)));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(all[all.size() - 1], all.size() -2)));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(all[all.size() - 1], all.size() -2)));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(all[all.size() - 1], all.size() -2)));
	
	c = liaison[all[all.size() - 1] - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&facts[get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1)));
}

Xor::~Xor(void) {}

bool 	Xor::compare(string already_passed)
{
	bool	a = false;
	bool	b = false;

	switch (_op.size())
	{
		case 0:
			a = _facts[0]->calc(already_passed);
			b = _facts[1]->calc(already_passed);
			break ;
		case 1:
			a = _facts[0]->calc(already_passed);
			b = _op[0]->compare(already_passed);
			break ;
		default:
			a = _op[0]->compare(already_passed);
			b = _op[1]->compare(already_passed);
			break ;
	}
	return (a ^ b);
}

Egal::Egal(string liaison)
{
	_facts.push_back(&facts[get_fact_id(liaison)]);
}

Egal::~Egal(void) {}

bool 	Egal::compare(string already_passed)
{
	switch (_op.size())
	{
		case 0:
			return (_facts[0]->calc(already_passed));
		case 1:
			return (_op[0]->compare(already_passed));
	}
}

Not::Not(string liaison)
{
	char	c = liaison[liaison.size() - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&facts[get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(0, liaison.size() - 2)));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(0, liaison.size() - 2)));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(0, liaison.size() - 2)));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(0, liaison.size() - 2)));
}

Not::~Not(void) {}

bool 	Not::compare(string already_passed)
{
	switch (_op.size())
	{
		case 0:
			return (!_facts[0]->calc(already_passed));
		case 1:
			return (!_op[0]->compare(already_passed));
	}
}
