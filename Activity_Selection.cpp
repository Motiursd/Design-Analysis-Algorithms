#include<bits/stdc++.h>
using namespace std;

 struct Activity {
   int start, Finish;
 };

 bool compare(Activity a, Activity b) {
 return(b.Finish > a.start);
 }
    int main()
    {
         Activity arr[] = {{1,3},{2,4},{4,6},{6,7}};
         int n = 4;
         sort(arr, arr+n, compare);
         cout <<"selected Activity" << endl;
         int i = 0;
         cout << i <<" ";
         for(int j = 1; j < n; j++)
         {
              cout << j <<" ";
              if(arr[j].start > arr[i].Finish) {
                    i = j;

              }
         }

    };



