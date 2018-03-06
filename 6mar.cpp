#include <iostream>
#include<fstream>
#include<string.h>

using namespace std;

	int  length,row,column,j,k,i,coun,c;

	string strArr[10000];

	string stArr[10000];

	string newString[10000];

	int m;

	char array[10000][10000];

    char array2 [10000][10000];


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
			{

				if(stArr[x] == strArr[y])
				{
						test=false;

				}


				//printf("%s", newString[m]);
			}
			if(test){

				newString[m]=stArr[x];

				m++;
			}

		}


	  	/*for (int u= 0; u < m; u++)
		{
			cout<<newString [u]<<endl;
		}*/


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


	void stringToArray(string &str, char array[10000][10000]){

	row = 0;

	column = 0;


	   for (int i = 0; i <= length; i++)
		{

		  if (str[i] ==  ' ' || str[i] <='\0' )
		{
	 row++;
		 column=0;

		}

		else
		{
			array[row][column] = str[i];

			column++;
		}
		}
	}


	void printArray(char array[10000][10000]){

	 printf ("words in an array: \n\n");

		for (int i = 0; i < row; i++)
		{
		    printf ("%s\n", array[i]);

		    }


		}


		void printFrequency(string &str, char array[10000][10000], char array2[10000][10000])
		{
			c,coun ,j,k = 0;

			int countSpace = 0;

			for(int i=0;str[i]!='\0';i++){

				if(str[i]==' '){

				    countSpace++;
			}
		}
		 //printf("Total spaces in st are %d\n", countSpace);


		 for(int i =0; i <= countSpace; i++)
		 {

		 while(j<=countSpace)
		 {
			if(i==j)
			{
				strcpy(array2[k],array[i]);

				k++;

				coun++;

				break;
			}
			else{
				    if (strcmp(array2[j],array[i]) !=0)
				    {
				    j++;

				    continue;

				    }
				else

				    break;
			}
		}
		 }
		 for(int i = 0; i < coun-1 ; i++)
		 {
			 j =0;

			 while(j <= countSpace)
		 {
			 if(strcmp(array2[i],array[j])==0)

//			 array2[j]={ -1 };
			 c++;

			 j++;

		 }

		cout << array2[i] << " --> "<< c << "time(s)" << endl;
		c=0;

		 }
		 cout<<endl;
		}


int main ()
{
	string st,sw;

	ifstream iFile;

	ifstream wFile;

	wFile.open("stopWords.txt");

	int i=0;

	while(getline(wFile,sw))
	{
		strArr[i]=sw;

		i++;
	}

	wFile.close();


	iFile.open("myfile.txt");

	int k = 0;

	while(iFile>>st){

    caseConversion(st);

    stArr[k] = st;

	k++;


	}


	iFile.close();

	removeStopword(i,k);

	string str="\0";

	for(int a=0;a<m;a++){

		str=str+newString[a];

		str=str+" ";
	}

	//cout<<str<<endl;

	length = myStrLen(str);

    cleanup(str);

    removeMultiSpaces(str);

    stringToArray(str,array);



    printArray(array);

    cout << "Frequency of the words" << endl;

    printFrequency(str,array,array2);




  return 0;
}
