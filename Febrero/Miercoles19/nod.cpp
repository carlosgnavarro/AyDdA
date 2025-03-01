#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
   vector<int> NOD(1000001,1);
   for(int i=2;i<=1000000;i++)
      for(int x=i;x<=1000000;x+=i)
         NOD[x]++;

   vector<int> S;
   int ni=1;
   S.push_back(1);
   do
   {
      ni=ni+NOD[ni];
      S.push_back(ni);
   } while (ni<=1000000);
   int casos,a,b;
   cin>>casos;
   for(int i=0;i<casos;i++)
   {
      cin>>a>>b;
      vector<int>::iterator ita,itb;
      ita=lower_bound(S.begin(),S.end(),a);
      itb=upper_bound(S.begin(),S.end(),b);
      itb--;
      cout<<itb-ita+1<<endl;
   }
}