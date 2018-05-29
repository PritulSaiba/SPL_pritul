#include<iostream>

using namespace std;

void merge(double a[],int startElement, int endElement, int middleEliment,string addString[])
{
    int i, j, k;
    double temp[endElement-startElement+1];
    string tempStr[endElement-startElement+1];

    i= startElement;

    k= 0;

    j = middleEliment+1;

        while(i <= middleEliment && j <= endElement)
        {

            if(a[i]<a[j])
            {
                temp[k] = a[i];
                tempStr[k] = addString[i];

                k++;

                i++;
            }

            else
            {
                temp[k] = a[j];
                tempStr[k] = addString[j];
                k++;

                j++;
            }

        }

        while(i <= middleEliment)
        {
            temp[k] = a[i];
            tempStr[k] = addString[i];
            k++;

            i++;
        }

        while(j <= endElement)
        {
            temp[k] = a[j];
            tempStr[k] = addString[j];
            k++;

            j++;
        }

        for(i = startElement; i<= endElement; i++)
        {
            a[i] = temp[i-startElement];
            addString[i] = tempStr[i-startElement];
        }
}

void mergeSort(double a[], int startElement,int  endElement,string addString[])
{
    int middleEliment;

        if(startElement < endElement)
        {
            middleEliment = (startElement+endElement)/2;

            mergeSort(a,startElement,middleEliment,addString);

            mergeSort(a,middleEliment+1,endElement,addString);

            merge(a,startElement,endElement,middleEliment,addString);

        }
}

int splmerge(double array[],int arrayElement,string addString[])
{

	cout << endl << endl;

    mergeSort(array, 0, arrayElement-1,addString);

        for(int i=0;i <arrayElement; i++)

            cout << "The most important words" << addString[i] << " tfidf " << array[i] << endl;




    return 0;
}

