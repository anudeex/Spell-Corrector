#include <bits/stdc++.h>

#include "spell_corrector.h"

#define ll long long

#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

string to_simple_string(string s)
{
	string str="";
	ll n=s.size();
	ll i,j;
	for(i=0;i<n;i++)
	{
		if(s[i]>='A' and s[i]<='Z')
		{
			str+=s[i]+32;
		}
		else if(s[i]>='a' and s[i]<='z')
		{
			str+=s[i];
		} 
	}
	return str;
}

void spell_corrector :: add_word(trie *vertex,string word)
{
	if(word=="")
	{
		vertex->words++;
	}
	else
	{
		ll k=word[0]-'a';
		if(vertex->edges[k]==NULL)
		{
			vertex->edges[k]=new trie();
		}
		word.erase(0,1);
		return add_word(vertex->edges[k],word);
	}
}

ll spell_corrector :: search(trie *vertex,string word)
{
	if(word=="")
	{
		return vertex->words;
	}
	else
	{
		ll k=word[0]-'a';
		if(vertex->edges[k]==NULL)
		{
			return 0;
		}
		word.erase(0,1);
		return search(vertex->edges[k],word);
	}
}

void spell_corrector :: edit_distance(string s,ll curr)
{
	ll count=0;
	ll n=s.size();
	ll i,j,k;
	for(i=-1;i<n;i++)
	{
		for(j=0;j<26;j++)
		{
			char c='a'+j;
			string str=s.substr(0,i+1)+c+s.substr(i+1,n-i-1);
			ll no_of_str=search(root,str);
			no_of_str*=-1;
			if(no_of_str!=0)
			{
				possible_words.insert(mp(no_of_str,str));
			}
			if(curr==0)
				edit_distance(str,1);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<26;j++)
		{
			char c='a'+j;
			string str=s.substr(0,i)+c+s.substr(i+1,n-i-1);
			ll no_of_str=search(root,str);
			no_of_str*=-1;
			if(no_of_str!=0)
			{
				possible_words.insert(mp(no_of_str,str));
			}
			if(curr==0)
				edit_distance(str,1);
		}
	}
	for(i=0;i<n;i++)
	{
		string str=s.substr(0,i)+s.substr(i+1,n-i-1);
		ll no_of_str=search(root,str);
		no_of_str*=-1;
		if(no_of_str!=0)
		{
			possible_words.insert(mp(no_of_str,str));
		}
		if(curr==0)
			edit_distance(str,1);
	}
	for(i=0;i<n-1;i++)
	{
		char a=s[i],b=s[i+1];
		string str=s.substr(0,i)+b+a+s.substr(i+2,n-i-2);
		ll no_of_str=search(root,str);
		no_of_str*=-1;
		if(no_of_str!=0)
		{
			possible_words.insert(mp(no_of_str,str));
		}
		if(curr==0)
			edit_distance(str,1);
	}
}

spell_corrector :: spell_corrector()
{
	total_words=0;
	root=new trie();
	ifstream fin;
	fin.open("big.txt");
	string s;
	ll t;
	while(fin.eof()==0)
	{
		fin>>s;
		s=to_simple_string(s);
		if(s!="")
		{
			add_word(root,s);
			total_words++;
		}
	}
	fin.close();
	cout<<"This program is 'SPELL CORRECTOR'\nIn this you enter a string you want to check.\nIf string is valid no problem, but if it is invalid then it recommends you valid possible strings!\n";
	cout<<"\nENTER 'exit' to EXIT...\n";
}

void spell_corrector :: correct(string s)
{
	possible_words.clear();
	s=to_simple_string(s);
	ll no_of_str=search(root,s);
	if(no_of_str==0)
	{
		set<pair<ll,string> > :: iterator it;
		edit_distance(s,1);
		if(possible_words.size()==0)
		{
			edit_distance(s,0);
		}
		if(possible_words.size()==0)
		{
			cout<<"\nNo Recommendations...Sorry...\n";
		}
		else
		{
			cout<<"\nPossible Correct Words may be "<<endl;
			for(it=possible_words.begin();it!=possible_words.end();it++)
			{
				cout<<(*it).s<<" "<<endl;
			}
		}
	}
	else
	{
		cout<<"\nCorrect Word Entered!!!\n";
	}
}

