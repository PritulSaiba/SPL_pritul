
#include <bits/stdc++.h>

using namespace std;

//int count, cnt;

int main ()
{
	string st,sw;

	char array[250][250];
    char arr [500][500];


	ifstream iFile;

	ofstream oFile;


	iFile.open("myfile.txt");

	while(getline(iFile,st)){

	int length = 0;

	  while (st[length] != '\0')
		{
		  length++;
		}


	char removePunctuation[] = "$#*'\"=+-&,.!\;\{}[]/():?";

  	for (int i = 0; i < length; i++)
    {
      	for (int j = 0; j < 25; j++)
		{
	  		if (st[i] ==  removePunctuation[j])

	    	st[i] = ' ';
		}
    }





 int count = 0;

  int j = 0;

  for (int i = 1; i <= length; i++)
    {

      if ((st[i] >=  'a' && st[i] <='z') || (st[i] >=  '0' && st[i] <='9'))
	{

   array[count][j] = st[i];


#include <bits/stdc++.h>

using namespace std;

//int count, cnt;

int main ()
{
	string st,sw;

	char array[250][250];
    char arr [500][500];


	ifstream iFile;

	ofstream oFile;


	iFile.open("myfile.txt");

	while(getline(iFile,st)){

	int length = 0;

	  while (st[length] != '\0')
		{
		  length++;
		}


	char removePunctuation[] = "$#*'\"=+-&,.!\;\{}[]/():?";

  	for (int i = 0; i < length; i++)
    {
      	for (int j = 0; j < 25; j++)
		{
	  		if (st[i] ==  removePunctuation[j])

	    	st[i] = ' ';
		}
    }





 int count = 0;

  int j = 0;

  for (int i = 1; i <= length; i++)
    {

      if ((st[i] >=  'a' && st[i] <='z') || (st[i] >=  '0' && st[i] <='9'))
	{

   array[count][j] = st[i];
	 j++;
	}
      else if(st[i] >=  'A' && st[i] <='Z')
	{

	  array[count][j] = st[i]+32;

	  j++;

	}
	else{
    count++;
     j=0;
    }
	}


  printf ("words in an array:\n");
for (int i = 0; i < count; i++)
    {
     printf ("%s\n", array[i]);
    //puts(array);
    }
    //printf("%s", array[1][2]);
	}

  /*ifstream myFile;

	ofstream myoFile;

	myFile.open("stopWords.txt");

	while(getline(myFile,sw)){
	int len = 0;

	  while (sw[len] != '\0')
		{
		  len++;
		}

  int j, cnt;

  cnt = 0;

  j = 0;

  for (int i = 0; i <= len; i++)
    {

      if (sw[i] == '\0')
	{

	  arr[cnt][j] = '\0';

	  cnt++;

	  j = 0;

	}
      else
	{

	  arr[cnt][j] = sw[i];

	  j++;

	}
    }



  for (int i = 0; i < cnt; i++)
    {
      printf ("%s\n", arr[i]);
    }
	}

	 int count = 30, cnt =15;
for(int i=0;i<count;i++){
    for(int j=0;j<cnt;j++){
        if(st[i]==sw[j])
            st[i][0]='\0';
            break;

    }
}
    for (int i = 0; i < count; i++)
    {
      printf ("%s\n", array[i]);
    }*/


  return 0;
}
