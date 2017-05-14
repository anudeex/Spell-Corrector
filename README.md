# Spell Corrector

## Background

It is a program in which for a given string it checks if the spelling provided is correct or not, if not then it recommends words. We use the concepts of levenshtein distance(Edit Distance) to consider possible recommended words for the given string. Trie data structure is used for storing words with count of how many times word was found in the text file(big.txt) used. Idea was taken from Peter Norvig's article([How to Write a Spelling Corrector](http://norvig.com/spell-correct.html)) and understanding of some C++ aspects of implementation from [here](https://github.com/felipefarinon/spellingcorrector). 	  

## Getting Started and Deployment

Just download the whole repository in zip format ,unzip it. Then double click the 'Spell Corrector.exe'. It will open a console where on screen instructions are provided.

![screenshot 31](https://cloud.githubusercontent.com/assets/26831996/26033392/fd36e6fa-38c8-11e7-9dec-5a06afc47408.png)


### Prerequisites

#### Concepts
* Trie Data Structure.

* Levenshtein distance for strings.

* C++.

#### Software and Tools
* Any C++ IDE (I used DevC++)

* Any Code Editor (I used Sublime Text3)

### Installing

Download all the files of repository. Create a project in IDE and add the files('main.cpp','spell_corrector.h' and 'spell_corrector.cpp') to the project. Then build and run the project.

Screenshot of my IDE:-

![screenshot 33](https://cloud.githubusercontent.com/assets/26831996/26033450/3e964aa4-38ca-11e7-88c9-dda059b405cc.png)

## Contributing

Please read [CONTRIBUTING.md](https://github.com/anudeexCR7/Spell-Corrector/blob/master/CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to me.

## Authors

* **Anudeex D Shetty** - [anudeexCR7](https://github.com/anudeexCR7)

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/anudeexCR7/Spell-Corrector/blob/master/LICENSE) file for details

## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* Peter Norvig [link](http://norvig.com/spell-correct.html)
* grandpriest [link](https://github.com/grandpriest/SpellChecker)
* felipefarinon [link](https://github.com/felipefarinon/spellingcorrector)
