#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <math.h>
#include "splmerge.h"

using namespace std;

	int  length,row,column,j,k,i,coun,c;

	string strArr[1000000];

	string stArr[1000000];

	string strArrNeg[1000000];

	string strArrPos[1000000];

	string newString[1000000];

	string newString1[1000000];

	string newString2[1000000];

	string addString[1000000];

	string keywords[100];



	int newL;


	int m,n;

	string array[1000000],unique[1000000];

	double tf[1000000];

	double tf1[1000000];

	double tf2[1000000];

    double idf[1000000];

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

		m = 0;

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


	void stringToArray(string &str)
	{

		string str1;
		m=0;

		istringstream iss(str);
		while(iss >> str1)
		{
			array[m] = str1;
			m++;
		}

	}


	void printArray()
	{

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

			cout << newString[i] << " tf is " << tf[n-1] << endl;
		}
	}
//	cout << n << endl;
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


	removeStopword(i,m);

	    printFreq();
}



int main ()
{
	string sw,nw,pw;


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

    int firstArrCount = 0;

	int arcnt=0;

	for(int i=0;i<n;i++)
    {
        newString1[i] = unique[i];

        tf1[i] = tf [i];

		//cout <<   newString1[i] <<" tf is " << tf1[i] << endl;
        arcnt++;

	}
	//cout << m << " " << n << endl;
	//cout << arcnt<< endl;
	cout << endl << endl;


    readFile("myfile2.txt",i);

    int arc=0;

    for(int i=0;i<n;i++)
    {
        newString2[i] = unique[i];


        tf2[i] = tf [i];

		//cout <<   newString2[i] <<" tf is " << tf2[i] << endl;

       arc++;
	}
	//cout << arc << endl;

	for(int i=0;i<arcnt;i++)
    {
        addString[i] = newString1[i];

		//cout <<   newString1[i] << endl;

	}

	int addcount = 0;

	for(int i=arcnt,j=0;i<arcnt,j<arc;j++)
    {
    	int is_present = 0;

    	for(int k=0; k<arcnt; k++)

    		if(newString2[j] == newString1[k])

    			is_present = 1;

        if(is_present == 0)
        {
        	addString[i] = newString2[j];

			i++;
        }
        addcount = i;
		//cout <<   newString1[i] << endl;

	}

	double idf[addcount];

	for(int i=0;i<(addcount);i++)
    {
        //addString[i] = newString1[i];

		double txtcount=0.0;

		for(int j=0; j<arcnt; j++)

			if(addString[i] == newString1[j])

				txtcount += 1.0;

		for(int j=0; j<arc; j++)

			if(addString[i] == newString2[j])

				txtcount += 1.0;

		idf[i] = log(2.0/txtcount)/log(10.0);

		cout << "Idf of " << addString[i] << " is " << idf[i] << endl;

	}

	cout << endl << endl;

	double tfidf[addcount];

	for(int i=0; i<addcount; i++)
	{
		double tftot = 0.0;

		for(int j=0; j<arcnt; j++)

			if(addString[i] == newString1[j])

				tftot += tf1[j];

		for(int j=0; j<arc; j++)

			if(addString[i] == newString2[j])

				tftot += tf2[j];

		tfidf[i] = tftot*idf[i];

		cout << "Tf-Idf of " << addString[i] << " is " << tfidf[i] << endl;
	}

	splmerge(tfidf,addcount,addString);

	for(int j=addcount,i=0;j >(addcount-20),i<20;j--,i++)

    keywords[i] = addString[j];

        for(int i=0;i<20;i++)

            cout<< keywords[i]<< endl;


    int n = 0;

    ifstream nFile;

	nFile.open("negWord.txt");



	while(getline(nFile,nw))
	{
		strArrNeg[n]=nw;

		n++;
	}



	nFile.close();

int neg = 0;

    for(int i=0; i<20;i++)
    {

        for(int j=0;j<n;j++)
        {
            if(keywords[i]==strArrNeg[j])

            neg++;
        }
}
//cout << neg;

	int p = 0;

    ifstream pFile;

	pFile.open("posWord.txt");



	while(getline(pFile,pw))
	{
		strArrPos[p]=pw;

		p++;
	}


	pFile.close();

	int pos = 0;

    for(int i=0; i<20;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(keywords[i]==strArrPos[j])

            pos++;
        }
}
//cout << pos;

    if(pos>neg)

    cout<< "The text is positive" << endl;

    else if(pos<neg)

    cout<< "The text is negative" << endl;

    else if((pos==neg)||(pos==0)||(neg==0))

    cout<< "The text is neutral" << endl;

  return 0;
}
