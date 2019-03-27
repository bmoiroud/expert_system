#ifndef STATE_HPP
# define STATE_HPP

#include <vector>
#include "Fact.hpp"
#include "Graph.hpp"

using namespace std;

class	State: public Graph
{
	vector<Fact>	isTrue;
	vector<Fact>	isFalse;
	vector<Fact>	iDunno;

	bool			change_state();
	static string	get_list(string type);
	static void		print_list();
	static Fact		get_fact(string name);
};

#endif
