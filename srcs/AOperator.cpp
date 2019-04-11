/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:17:12 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/11 19:10:32 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AOperator.hpp"
#include "Graph.hpp"
#include "Fact.hpp"

using namespace std;

AOperator::AOperator(void)
{
}

AOperator::~AOperator(void) 
{
	_facts.clear();
	_op.clear();
}

And::And(string liaison, Graph *Master)
{
	cout << "creation And::And\t\t" << "liaison : " << liaison << endl;
	vector<int>	all;

	master = Master;
	get_influence(liaison, all);
	char	c = liaison[all.size() - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&(master->facts[master->get_fact_id(c)]));
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all.size() - 1], all[all.size() - 1] - 1), master));
	else if (c == '+')                                                                   
		_op.push_back(new And(liaison.substr(all[all.size() - 1], all[all.size() - 1] - 1), master));
	else if (c == '|')                                                                   
		_op.push_back(new Or(liaison.substr(all[all.size() - 1] , all[all.size() - 1] - 1), master));
	else if (c == '^')                                                                   
		_op.push_back(new Xor(liaison.substr(all[all.size() - 1], all[all.size() - 1] - 1), master));
	
	c = liaison[all[all.size() - 1] - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&master->facts[master->get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1), master));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1), master));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(all[all[all.size() - 1] - 1] , all[all.size() - 1] - 1), master));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1), master));
	cout << "sortie And::And" << endl;
}

And::~And(void) {}

bool 	And::compare(string already_passed)
{
	cout << "je rentre dans And::And" << endl;
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
	cout << "sortie And::And" << endl;
	return (a & b);
}

Or::Or(string liaison, Graph *Master)
{
	cout << "creation Or::Or\t\t" << "liaison : " << liaison << endl;
	vector<int>	all;

	master = Master;
	get_influence(liaison, all);
	char	c = liaison[all.size() - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&master->facts[master->get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all.size() - 1], all[all.size() - 1] - 1), master));
	else if (c == '+')                                                                   
		_op.push_back(new And(liaison.substr(all[all.size() - 1], all[all.size() - 1] - 1), master));
	else if (c == '|')                                                                   
		_op.push_back(new Or(liaison.substr(all[all.size() - 1] , all[all.size() - 1] - 1), master));
	else if (c == '^')                                                                   
		_op.push_back(new Xor(liaison.substr(all[all.size() - 1], all[all.size() - 1] - 1), master));
	
	c = liaison[all[all.size() - 1] - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&master->facts[master->get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1), master));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1), master));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(all[all[all.size() - 1] - 1] , all[all.size() - 1] - 1), master));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1), master));
	cout << "sortie Or::Or" << endl;
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

Xor::Xor(string liaison, Graph *Master)
{
	cout << "creation Xor::Xor\t\t" << "liaison : " << liaison << endl;
	vector<int>	all;

	master = Master;
	get_influence(liaison, all);
	char	c = liaison[all.size() - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&master->facts[master->get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all.size() - 1], all[all.size() - 1] - 1), master));
	else if (c == '+')                                                                   
		_op.push_back(new And(liaison.substr(all[all.size() - 1], all[all.size() - 1] - 1), master));
	else if (c == '|')                                                                   
		_op.push_back(new Or(liaison.substr(all[all.size() - 1] , all[all.size() - 1] - 1), master));
	else if (c == '^')                                                                   
		_op.push_back(new Xor(liaison.substr(all[all.size() - 1], all[all.size() - 1] - 1), master));
	
	c = liaison[all[all.size() - 1] - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&master->facts[master->get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1), master));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1), master));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(all[all[all.size() - 1] - 1] , all[all.size() - 1] - 1), master));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(all[all[all.size() - 1] - 1], all[all.size() - 1] - 1), master));
	cout << "sortie Xor::Xor" << endl;
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

Egal::Egal(string liaison, Graph *Master)
{
	cout << "creation Egal::Egal\t\t" << "liaison : " << liaison << endl;
	master = Master;
	_facts.push_back(&master->facts[master->get_fact_id(liaison[0])]);
	cout << "sortie Egal::Egal" << endl;
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
	return (false);
}

Not::Not(string liaison, Graph *Master)
{
	cout << "creation Not::Not\t\t" << "liaison : " << liaison << endl;
	master = Master;
	char	c = liaison[liaison.size() - 1];
	if ('A' <= c && c <= 'Z')
		_facts.push_back(&master->facts[master->get_fact_id(c)]);
	else if (c == '!')
		_op.push_back(new Not(liaison.substr(0, liaison.size() - 1), master));
	else if (c == '+')
		_op.push_back(new And(liaison.substr(0, liaison.size() - 1), master));
	else if (c == '|')
		_op.push_back(new Or(liaison.substr(0, liaison.size() - 1), master));
	else if (c == '^')
		_op.push_back(new Xor(liaison.substr(0, liaison.size() - 1), master));
	cout << "sortie Not::Not" << endl;
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
	return (false);
}
