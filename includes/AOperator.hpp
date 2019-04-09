/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:39:08 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/08 15:20:04 by eferrand         ###   ########.fr       */
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

		virtual bool	compare(string already_passed) = 0;
		/* inutile ?
		void			connect_fact(vector <string> str, int i);
		void			connect_op(vector <string> str, int i);
		*/

	private:
		int					_type;
		vector <Fact*>		_facts;
		vector <AOperator*>	_op;
};

class	And: public AOperator
{
	public:
		And(string liaison);
		~And(void);

		virtual bool	compare(string already_passed);
};

class	Or: public AOperator
{
	public:
		Or(string liaison);
		~Or(void);
		
		virtual bool	compare(string already_passed);
};

class	Xor: public AOperator
{
	public:
		Xor(string liaison);
		~Xor(void);
		
		virtual bool	compare(string already_passed);
};

class	Egal: public AOperator
{
	public:
		Egal(string liaison);
		~Egal(void);

		virtual bool	compare(string already_passed);
};

class	Not: public AOperator
{
	public:
		Not(string liaison);
		~Not(void);

		virtual bool	compare(string already_passed);
};

#endif
