#include "State.hpp"

using namespace std;

vector<Fact>	State::get_list(string type)
{
	if (type == "true")
		return (isTrue);
	else if (type == "false")
		return (isFalse);
	else if (type == "dunno")
		return (iDunno);
}

void			State::print_list(string type)
{
	int	a;

	a = -1;
	cout << "Ce qui est vrai: " << endl;
	while (++a < isTrue.size())
		cout << isTrue[a].get_name << endl;
	a = -1;
	cout << "Ce qui est faux: " << endl;
	while (++a < isFalse.size())
		cout << isTrue[a].get_name << endl;
	a = -1;
	cout << "Ce qui est indetermine: " << endl;
	while (++a < iDunno.size())
		cout << isTrue[a].get_name << endl;
}

Fact			State::get_fact(string name)
{
	int	a;

	a = -1;
	while (++a < isTrue.size())
		if (name == isTrue[a].get_name())
			return isTrue[a];
	
	a = -1;
	while (++a < isFalse.size() && name != isFalse[a].get_name())
		if (name == isTrue[a].get_name())
			return isTrue[a];
	
	a = -1;
	while (++a < iDunno.size() && name != iDunno[a].get_name())
		if (name == isTrue[a].get_name())
			return isTrue[a];

	return (nullptr)
}
