#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int iSize = 0, iSub = 0, iEsize = 0;
bool arr[100][100];


  void   intersection(int firstSet,int secSet,string sUniversal []){
   cout<<"<";
    for(int i=0;i<iSize;i++)
        if(arr[firstSet][i] && arr[secSet][i]) cout<<sUniversal[i]<<", ";
    cout<<">"<<endl;
  }

  void _union (int firstSet,int secSet,string sUniversal []){
      cout<<"<";
     for(int i=0;i<iSize;i++)
        if(arr[firstSet][i] || arr[secSet][i]) cout<<sUniversal[i]<<", ";
    cout<<">"<<endl;
  }
  void difference (int firstSet,int secSet,string sUniversal []){
      cout<<"<";
     for(int i=0;i<iSize;i++)
        if(arr[firstSet][i] && !arr[secSet][i]) cout<<sUniversal[i]<<", ";
    cout<<">"<<endl;
  }


int main(int argc, char const *argv[])
{
    cout << setw(5) << "Starting programm...\n";

    // UNIVERSAL SECTION TOKEN
  do{  cout << "Enter the number of elements in the universel set -> ";
    cin >> iSize; }
    while(iSize<0);
    string sUniversal[iSize];
    cout << "Now enter your universal elements: \n";
    for(int i = 0; i < iSize; ++i)
        cin >> sUniversal[i];
    sort(sUniversal, sUniversal + iSize);

    // SUBSETS SECTION
  do{  cout << "Enter your number of subsets -> ";
    cin >> iSub;
    cout << "\n";}
    while(iSub<0);
    for(int i = 0; i < iSize; ++i)
        arr[0][i] = 1;
    for(int i = 0; i < iSub; ++i) {
        iEsize = 0;
        cout << "Enter your subset size -> ";
        cin >> iEsize;
        while(iEsize > iSize || iEsize<0 ) {
            cout << "size should be >=0 and <= universal size  ";
            cin >> iEsize;
        }
        string sTemp[iEsize];
        cout << "Enter your elements: \n";
        for(int j = 0; j < iEsize; ++j)
            cin >> sTemp[j];
        sort(sTemp, sTemp + iEsize);
        int k, x;
        for(x = 0, k = 0; x < iSize && k < iEsize;)
            if(sTemp[k] != sUniversal[x])
                ++x;
            else
                arr[i+1][x] = 1, ++x, ++k;
        if(k != iEsize) {
            cout << " there is an element isn't exist in the universal set\n";
            cout << "Enter your  subset again\n";
            for(x = 0; x < iSize; ++x)
                arr[i+1][x] = 0;
            --i;
            continue;
        }
    }

    // OPERATIONS SECTION
    while(1) {
            int iOne, iTwo;char x;
        string exp = "";
        cout << "/**\nEnter YOUR EXPRESSION seperated by spaces. <<But take care>> \n enter \"^\" for \"intersection\" \n \"+\" for \"union\" \n \"-\" for \"diff\"\n";
     do{   cout << "And your subSet are numbered from 1 to n containing universal as number 0\n";

        cin >> iOne >> x >> iTwo; }
     while (iOne<0 || iOne >iSub || iTwo<0 || iTwo>iSub);
        switch(x) {
            case '^':
                intersection(iOne, iTwo,sUniversal);
                break;
          case '+':
                _union(iOne, iTwo,sUniversal);
                break;
            default:
                difference(iOne, iTwo,sUniversal);
        }

    }
    return 0;
}
