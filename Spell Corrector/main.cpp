#include <bits/stdc++.h>

#include "spell_corrector.h"

#define ll long long

using namespace std;

spell_corrector spell;

int main()
{
	while(1)
	{
		string s;
		cout<<"\nEnter the string to be CHECKED\n";
		cin>>s;
		if(s=="exit")
			break;
		spell.correct(s);
	}
	return 0;	
}


