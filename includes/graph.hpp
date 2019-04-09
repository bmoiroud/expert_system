/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:43 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/02 18:16:27 by eferrand         ###   ########.fr       */
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
		static int				get_fact_id(char name);
		static string			get_list(string type);
		static void				print_list();
		void					resolve();

		//	TODO
		void					delete_duplicate(vector<string> &data);
		void					simplify_rules(vector<string> &data);

		static int				n_facts;
		static vector<Fact>		facts;
		bool					test;
		std::string				to_find;
};

#endif
