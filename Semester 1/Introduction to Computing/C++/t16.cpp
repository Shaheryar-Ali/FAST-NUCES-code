#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>

using namespace std;

string replace(string sentence, string word1, string word2);

int main()
{

	string text, w1, w2, res;

	cout << "Enter the string: ";
	getline(std::cin, text);

	cout << "Enter the text you want to replace: ";
	getline(std::cin, w1);

	cout << "Enter the text to replace with: ";
	getline(std::cin, w2);

	res = replace(text, w1, w2);


	for (int i = 0; res[i] != NULL; i++)
		cout << res[i];

	cout << endl;
	return 0;
}

string replace(string sentence, string word1, string word2)
{
	int flag = 0,len_sent,len1, len2;
	int diff2 = 0;

	for (len_sent = 0; sentence[len_sent] != NULL; len_sent++)
	{

	}
	for (len1 = 0; word1[len1] != NULL; len1++)
	{

	}
	for (len2 = 0; word2[len2] != NULL; len2++)
	{

	}




	for (int i = 0; sentence[i] != NULL; i++)
	{
		if (sentence[i] == word1[0])
		{
			flag = 1;
			for (int j = 0; j < len1 && flag == 1; j++)
			{
				if (sentence[i + j] != word1[j])
					flag = 0;
			}

			if (flag == 1)
			{
				if (len1 == len2)
				{
					for (int j = 0; j < len2 && flag == 1; j++)
					{
						sentence[i + j] = word2[j];

					}
				}
				else if (len1 > len2)
				{
					int diff = len1 - len2;
					len_sent = len_sent - diff;
					for (int j = 0; j < len2 && flag == 1; j++)
					{
						sentence[i + j] = word2[j];

					}
					int k = len2;
					for (k; sentence[i + k] != NULL; k++)
					{
						sentence[i + k] = sentence[i + k + diff];
						if (sentence[i + k] == NULL)
							break;
					}



				}
				else if (len1 < len2)
				{
					int diff = len2 - len1;
					string temp;
					len_sent = len_sent + diff;
					sentence.resize(len_sent);

	

					temp = sentence;
					for (int j = 0; j < len2 && flag == 1; j++)
					{
						sentence[i + j] = word2[j];

					}
					int k = 0;
					for (k; temp[i + len1 + k] != NULL; k++)
					{
						sentence[i + len2 + k] = temp[i + len1 + k];
						if (temp[i + k + len1] == NULL)
							break;
					}
					sentence[i + len2 + k] = NULL;

				}

			}

		}


	}
	return sentence;



}
