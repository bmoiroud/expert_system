/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:43 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/01 21:46:03 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

# include "node.hpp"
# include <vector>

using namespace std;

class		Graph
{
	public:
		Graph(void) = 0;
		~Graph(void);

		void					create_fact(string name);
		void					create_rule(vector <string> str);
		bool					fact_exist(string name);
		bool					calc_fact(string name);
		static int				get_fact_id(string name);
		static string			get_list(string type);
		static void				print_list();
		void					resolve();

		static int				n_facts;
		static vector<Fact*>	facts;
		bool					test;
};

#endif
