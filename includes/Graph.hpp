/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:43 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/16 18:33:40 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

# include "expert_sys.hpp"

using namespace std;

class		Fact;

class		Graph
{
	public:
		Graph(vector<string> data);
		~Graph(void);

		void					create_fact(char name, bool value = false);
		bool					fact_exist(string name);
		bool					calc_fact(string name);
		int						get_fact_id(char name);
		string					get_list(bool type);
		void					print_list();
		void					resolve();
		void					check_input(string allFacts);

		//	TODO
		void					delete_duplicate(vector<string> &data);
		void					simplify_rules(vector<string> &data);

		vector<Fact>			facts;
		bool					test;
		bool					nonsense;
		string					to_find;
};

#endif
