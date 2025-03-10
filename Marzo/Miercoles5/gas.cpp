#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int seleccion(vector<pair<int,int>> &gas,int e,int pos)
{
   int elegida=e+1;
   for(int i=e+1;i<gas.size();i++)
   {
      if(gas[i].first<=pos && gas[i].second>pos) //comienza antes y termina despues
      {
         if(gas[i].second> gas[elegida].second)
            elegida=i;
      }
   }
   if(gas[elegida].first>pos)
      return -1;
   return elegida;
}

int main() {
   int L,G;
   cin>>L>>G;
   vector<pair<int,int>> gas;
   for(int i=0;i<G;i++)
   {
      int x,r;
      cin>>x>>r;
      gas.push_back(make_pair(x-r,x+r));
   }
   sort(gas.begin(),gas.end());
   int pos=0;
   int e=-1;
   int cont=0;
   while(pos<L)
   {
      int e=seleccion(gas,e,pos);
      pos=gas[e].second;
      cont++; 
   }
   cout<<G-cont<<endl;
}