#include <iostream>
#include<fstream>
#include <sstream>
#include<string.h>
#include<math.h>

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

	int newL;


	int m,n;

	string array[1000000],unique[1000000];

	double tf[1000000];

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
			//cout << newString[i] << " freq is " << tf[n-1] << endl;
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

	    //printFreq();
}

void countidf()
{

    int nCount =0;
    for(int i,j=0;i<2*m,j<m;i++,j++)
    {
        if (addString[i] == newString1[j])
        nCount++;

        if (addString[i]==newString2[j])
         nCount++;

        else

        nCount =0;
    idf[i] = log10(2/nCount);
    }

    //idf[i] = log10(2/nCount);

for(int i =0;i<2*m; i++)
    cout << idf[i] << endl;

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

	for(int i=0;i<m;i++)
    {
        newString1[i] = newString[i];

        firstArrCount++;
	}
	cout << firstArrCount;

	cout << m;

	for(int i=0;i<m;i++)
    {
       //cout <<   newString1[i] << endl;

	}


    readFile("myfile2.txt",i);

    for(int i=0;i<m;i++)
    {
        newString2[i] = newString[i];
	}

	for(int i=0;i<m;i++)
    {
     //cout <<   newString2[i] << endl;

	}

    for(int i=0;i<m;i++)
    {
        addString[i] = newString1[i];
	}

    for(int i=m,j=0;i<(2*m),j<m;i++,j++)
    {
       addString[i] = newString2[j];
	}

    for(int i=0;i<2*m;i++){
       //cout <<   addString[i] << endl;

	}


	//.re

	/*str="\0";

	for(int a=0;a<m;a++){

		str=str+newString[a];

		str=str+" ";
	}

	cout<<str<<endl;*/

	/*length = myStrLen(str);

    removeMultiSpaces(str);

    cout << str << endl;*/
    //stringToArray(str);
	//cout << array[m-1] << endl;
    //printArray();
    //cout << "Frequency of the words" << endl;

    //countidf();
    int n = 0;

    ifstream nFile;

	nFile.open("negWord.txt");



	while(getline(nFile,nw))
	{
		strArrNeg[n]=nw;

		n++;
	}

	nFile.close();

	int p = 0;

    ifstream pFile;

	pFile.open("posWord.txt");



	while(getline(pFile,pw))
	{
		//strArrPos[p]=pw;

		p++;
	}


	pFile.close();


   /* for(int i=0;i<5000;i++)

    {
    cout << strArrNeg[i] << endl;
    }
    */
  return 0;
}
