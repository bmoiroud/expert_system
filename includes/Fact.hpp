/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:17:06 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/28 16:22:02 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACT_HPP
# define FACT_HPP

# include <iostream>
# include <string>
# include <vector>

# include "Graph.hpp"
# include "AOperator.hpp"
# include "State.hpp"

using namespace std;

class	Fact: public Graph
{
	public:
		Fact(const string name, const bool state);
		~Fact(void);

		bool		calc(void);
		bool		get_state(void);
		void		create_operator(vector <string> str, int i);
		bool		change_state();

		string		name;
		
	private:
		bool				_state;
		vector <AOperator>	_prev;
};

#endif
