#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <map>
#include <cctype>

using namespace std;

ifstream fin("fisier.in");

int verif(string& s, int poz)
{
	if (s.find_first_of(" .?!", poz) != string::npos)
		return s.find_first_of(" .?!", poz);
	
	return -1;
}

auto comparare = [](pair<string, int> p1, pair<string, int> p2)
	{
		if (p1.second > p2.second) return 0;
		else if (p1.second > p2.second) return 1;
		else
		{
			if (p1.first > p2.first) return 1;
			else return 0;
		}
	};

int main()
{
	map<string, int> harta;
	string prop, aux;
	getline(fin, prop);

	int poz1 = 0;
	int poz2 = verif(prop, 0);
	aux = prop.substr(0, poz2 - poz1);
	for (int i = 0; i < aux.length(); i++) aux[i] = tolower(aux[i]);

	while (poz2 < prop.length())
	{
		if (aux.length())
		{
			for (int i = 0; i < aux.length(); i++) aux[i] = tolower(aux[i]);
			if (harta[aux]) harta[aux]++;
			else harta[aux] = 1;
		}
		poz1 = poz2 + 1;
		poz2 = verif(prop, poz1);
		aux = prop.substr(poz1, poz2 - poz1);
	}
	aux = prop.substr(poz1, aux.length() - poz2 + 1); if (aux.length())
	{
		for (int i = 0; i < aux.length(); i++) aux[i] = tolower(aux[i]);
		if (harta[aux]) harta[aux]++;
		else harta[aux] = 1;
	}

	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comparare)> pq(comparare);
	for (auto i : harta)
	{
		pq.push(i);
	}

	while (!pq.empty())
	{
		cout << pq.top().first << "=>" << pq.top().second << '\n';
		pq.pop();
	}
	return 0;
}