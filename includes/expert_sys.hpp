/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_sys.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:15:16 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/25 16:53:10 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_HPP
# define EXPERT_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <fstream>
# include <vector>

# include "graph.hpp"

using namespace std;

string				trim(string str);
string				remove_comment(string str);
vector <string>		strsplit(string str);
bool				check_term(string str);
bool				check_order(vector <string> terms);
void				parse(const char *filename, Graph graph);

#endif