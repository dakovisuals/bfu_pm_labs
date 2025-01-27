#include <iostream>
#include <fstream>
#include <string>

const int N_Max = 2000;

char toLower(char s)
{
    if('A' <= s && s <= 'Z')
        s += 32;
    
    return s;
}

bool Read(int& cnt, std::string words[N_Max])
{
	std::ifstream in("text.txt");
	if(!in.is_open())
	{
		std::cerr << "Error" << std::endl;
		return false; 
	}
    
	cnt = 0;
	while(!in.eof())
	{
		in >> words[cnt];
		cnt++;
	}
	return true;
}

void Write(int cnt, std::string words[N_Max], int countLetters[N_Max])
{
	std::string previous = "";
	for(int i=0;i<cnt;i++)
	{
		if(words[i] != previous)
		{
			previous = words[i];
			std::cout << "<" << words[i] << "> " << countLetters[i] << std::endl;
		}
        if(words[i] == "")
            break;
	}
	
}

void ClearWords(int cnt, std::string words[N_Max])
{
	for(int i=0;i<cnt;i++)
		for(int j=0;j<words[i].length();j++)
		{
			if(!isalpha(words[i][j]))
			{
				words[i].erase(j, 1);
				j--;
				continue;
			}
			words[i][j] = toLower(words[i][j]);

		}
}

void CountEqualLetters(int cnt, std::string words[N_Max], int countLetters[N_Max])
{
	for(int i=0;i<cnt;i++)
	{
		char letters[256] = {0};
		// lower case
		for(int j=0;j<words[i].length();j++)
		{
			char c = toLower(words[i][j]);
			letters[c]++;
		}

		int max = INT_MIN;
		for(int k=0;k<256;k++)
			if(letters[k] > max)
				max = letters[k];
		countLetters[i] = max;
	}
}

void Sort(int cnt, std::string words[N_Max], int countLetters[N_Max])
{
	for(int i=0;i<cnt-1;i++)
		for(int j=i+1;j<cnt;j++)
			if((countLetters[i] < countLetters[j]) ||
			   (countLetters[i] == countLetters[j] &&
			    words[i] < words[j]))
			{
				std::swap(countLetters[i], countLetters[j]);
				std::swap(words[i], words[j]);
			}
}

int main()
{
	int cnt;
	std::string words[N_Max];
	if(!Read(cnt, words))
		return -1;

	ClearWords(cnt, words);

	int countLetters[N_Max] = {0};
	CountEqualLetters(cnt, words, countLetters);

	Sort(cnt, words, countLetters);

	Write(cnt, words, countLetters);

    
	return 0;
}
