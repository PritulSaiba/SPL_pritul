#include <iostream>
#include<fstream>
#include <sstream>
#include<string.h>

using namespace std;

	int  length,row,column,j,k,i,coun,c;

	string strArr[10000];

	string stArr[10000];

	string newString[10000];

	string newString1[10000]

	int m,n;

	string array[10000],unique[10000];
	double tf[10000];

	int myStrLen(string &str)
	{
	length = 0;

		for(int i=0;str[i]!='\0';i++)
		{
		    length++;
		}

	return length;
	}



	void caseConversion(string &str){
	    length = myStrLen(str);

		for (int i = 0; i <= length; i++)
		{

		    if (str[i] >=  'a' && str[i] <='z')
		    {

		        str[i] = str[i];


		    }
		    else if(str[i] >=  'A' && str[i] <='Z')
		    {

		        str[i] = str[i]+32;



		    }

		}
	}

	void removeStopword(int i, int k)
	{

		bool test;

		int m = 0;

		for (int x = 0; x <k; x++)
		{

			test=true;

			for (int y = 0; y<i; y++)
				if(array[x] == strArr[y])
						test=false;
			if(test){

				newString[m]=array[x];

				m++;
			}

		}
	}


	void cleanup(string &str){

		char removePunctuationAndNumbers[] = "0123456789$#*'\"=+-&,.!\;\{}[]/():?";

	  	for (int i = 0; i < length; i++)
		{
		  	for (int j = 0; j < 35; j++)
			{
		  		if (str[i] ==  removePunctuationAndNumbers[j])

				str[i] = ' ';
			}
		}
	}


	void removeMultiSpaces(string &str){

		for(int i=0;i<length;i++){

		    if((str[i]==' ')&&(str[i+1]==' '))
		    {
		        for(;;)
		        {
		            if(str[i+1]!=' ')

		                break;
		            else

		                for(int j = i; j< length;j++)

		    str[j]=str[j+1];

		    length--;

		        }
		    }
		}
	}


	void stringToArray(string &str){
		string str1;
		m=0;

		istringstream iss(str);
		while(iss >> str1)
		{
			array[m] = str1;
			m++;
		}

	}


	void printArray(){

	 printf ("words in an array: \n\n");

		for (int i = 0; i < m; i++)
		{
			cout << newString[i] << endl;

		    }


		}


void printFreq()
{
	n=0;
	for(int i=0; i<m; i++)
	{
		int wordCount=0;
		bool flag = false;
		//cout << newString[i] << endl;
		for(int k=0; k<n; k++)
			if(newString[i] == unique[k])
				flag = true;
		if(flag == false)
		{
			for(int j=0; j<m; j++)
				if(newString[i] == newString[j])
					wordCount++;
			unique[n] = newString[i];
			n++;
			tf[n-1] = (wordCount*1.0)/(m*1.0);
			cout << newString[i] << " freq is " << tf[n-1] << endl;
		}
	}
}

void readFile(char *str1,int i)
{
	string st;
	ifstream iFile;
	iFile.open(str1);
	int j=0;
	int k = 0;

	while(iFile>>st){

    caseConversion(st);

    stArr[k] = st;

	k++;


	}


	iFile.close();



	string str="\0";

	for(int a=0;a<k;a++){

		str=str+stArr[a];

		str=str+" ";
	}
	length = myStrLen(str);
	cleanup(str);
	stringToArray(str);

/*	for(i=0; i<m; i++)
	    cout << array[i] << endl;*/
//	cout << str << endl;

	removeStopword(i,m);

	    printFreq();
}


int main ()
{
	string sw;


	int i=0;
	ifstream wFile;

	wFile.open("stopWords.txt");



	while(getline(wFile,sw))
	{
		strArr[i]=sw;

		i++;
	}

	wFile.close();

	readFile("myfile.txt",i);
	/*int newL =myStrLen(newString);
	for(int i=0;i<newL;i++){
        newString1[i] = newString[i];
	}
	for(int i=0;i<newL;i++){
       cout <<   newString1[i];
	}*/



    cout << "Frequency of the words" << endl;




  return 0;
}
