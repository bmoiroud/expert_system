/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:39:08 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/28 18:50:12 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOPERATOR_HPP
# define AOPERATOR_HPP

# define	EGAL 0
# define	NOT 1
# define	AND 2 
# define	OR 3
# define	XOR 4

# include	"Graph.hpp"
# include	"Fact.hpp"

class	AOperator: public Graph
{
	public:
		virtual AOperator::AOperator() = 0;
		~AOperator(void);

		virtual bool	compare() = 0;
		void			connect_fact(vector <string> str, int i);
		void			connect_op(vector <string> str, int i);
	
	private:
		Fact				*_parent;
		int					_type;
		vector <Fact*>		_facts;
		vector <AOperator>	_op;
};

class	And: public AOperator
{
	public:
		And(char *liaison, Fact *parent);
		~And(void);

		virtual bool	compare();
};

class	Or: public AOperator
{
	public:
		Or(char *liaison, Fact *parent);
		~Or(void);
		
		virtual bool	compare();
};

class	Xor: public AOperator
{
	public:
		Xor(char *liaison, Fact *parent);
		~Xor(void);
		
		virtual bool	compare();
};

class	Egal: public AOperator
{
	public:
		Egal(char *liaison, Fact *parent);
		~Egal(void);

		virtual bool	compare();
};

class	Not: public AOperator
{
	public:
		Not(char *liaison, Fact *parent);
		~Not(void);

		virtual bool	compare();
};

#endif
