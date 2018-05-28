#include<iostream>

using namespace std;

void merge(int a[],int startElement, int endElement, int middleEliment)
{
    int i, j, k, temp[endElement-startElement+1];

    i= startElement;

    k= 0;

    j = middleEliment+1;

        while(i <= middleEliment && j <= endElement)
        {

            if(a[i]<a[j])
            {
                temp[k] = a[i];

                k++;

                i++;
            }

            else
            {
                temp[k] = a[j];

                k++;

                j++;
            }

        }

        while(i <= middleEliment)
        {
            temp[k] = a[i];

            k++;

            i++;
        }

        while(j <= endElement)
        {
            temp[k] = a[j];

            k++;

            j++;
        }

        for(i = startElement; i<= endElement; i++)
        {
            a[i] = temp[i-startElement];
        }
}

void mergeSort(int a[], int startElement,int  endElement)
{
    int middleEliment;

        if(startElement < endElement)
        {
            middleEliment = (startElement+endElement)/2;

            mergeSort(a,startElement,middleEliment);

            mergeSort(a,middleEliment+1,endElement);

            merge(a,startElement,endElement,middleEliment);

        }
}

int main()
{
    int arrayElement;

    cin >> arrayElement;

    int array[arrayElement];

        for(int i =0; i < arrayElement ; i++)
        {
            cin >> array[i];
        }

    mergeSort(array, 0, arrayElement-1);

        for(int i=0;i <arrayElement; i++)

            cout << array[i] << endl;

    return 0;
}

