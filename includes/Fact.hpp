/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:17:06 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/10 15:29:18 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACT_HPP
# define FACT_HPP

# include <iostream>
# include <string>
# include <vector>
# include <Graph.hpp>

using namespace std;

class	AOperator;

class	Fact: public Graph
{
	public:
		Fact(const string name, const bool state);
		~Fact(void);

		// TODO
		bool		calc(string already_passed);
		bool		get_state(void);
		void		create_operator(string condition, string conclusion);
		bool		change_state();

		string		name;
		bool		value;
		
	protected:
		vector <AOperator*>	_cond;	//condition
		vector <bool>		_concl;	//conclusion
};

#endif
