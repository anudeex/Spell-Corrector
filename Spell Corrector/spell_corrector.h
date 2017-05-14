#ifndef _SPELL_CORRECTOR_H
#define _SPELL_CORRECTOR_H

#include <bits/stdc++.h>

#define ll long long

using namespace std;

class spell_corrector
{
	ll total_words;

	struct trie{
		ll words;
		trie *edges[26];
			
		trie()
		{
			words=0;
			for(int i=0;i<26;i++)
			{
				edges[i]=NULL;
			}
		}
	};

	trie *root;

	set<pair<ll,string> > possible_words;

	public:
		
		void edit_distance(string,ll);
		
		void add_word(trie *,string);
		
		ll search(trie *,string);

		spell_corrector();

		void correct(string);

};

#endif

