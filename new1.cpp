#include <bits/stdc++.h>

using namespace std;

int  length,row,column,j,k,i,coun,c;



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

void stringToArray(string &str, char array[250][250]){

row = 0;

column = 0;


   for (int i = 0; i <= length; i++)
    {

      if (str[i] ==  ' ' || str[i] <='\0' )
	{
 row++;
     column=0;

	}

	else{
    array[row][column] = str[i];
	 column++;
    }
	}
}

void printArray(char array[250][250]){

 printf ("words in an array: \n\n");

    for (int i = 0; i < row; i++)
    {
        printf ("%s\n", array[i]);

        }


    }

    void printFrequency(string &str, char array[250][250], char array2[500][500]){
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

while(j<=countSpace){
    if(i==j){
        strcpy(array2[k],array[i]);
        k++;
        coun++;
        break;
    }
    else{
            if (strcmp(array2[j],array[i]) !=0){
            j++;
            continue;
        }
        else
            break;
    }
}
 }
 for(int i =0; i < coun; i++)
 {
     j =0;
     while(j <= countSpace)
 {
     if(strcmp(array2[i],array[j])==0)
     c++;
     j++;

 }

cout << array2[i] << " --> "<< c<< "times" << endl;
c=0;

 }
 cout<<endl;
    }
int main ()
{
	string st,sw;

    vector<string>myVect;


	char array[250][250];

    char array2 [500][500];


	ifstream iFile;

	ofstream oFile;


	iFile.open("myfile.txt");

	while(getline(iFile,st)){

    caseConversion(st);

    length = myStrLen(st);

    cleanup(st);

    removeMultiSpaces(st);

    stringToArray(st,array);

    printArray(array);
 //printArray(array2);
    cout << "frequency of the words" << endl;

    printFrequency(st,array,array2);
	}

  return 0;
}
