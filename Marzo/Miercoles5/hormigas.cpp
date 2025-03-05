#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {
   int casos,h,p;
   cin>>casos;
   for(int c=0;c<casos;c++)
   {
      cin>>p>>h;
      vector<int> H(h);
      for(int i=0;i<h;i++)
         cin>>H[i];
      sort(H.begin(),H.end());
      int m=p/2;
      //cout<<m<<endl;
      vector<int>::iterator it;
      it=lower_bound(H.begin(),H.end(),m); //tomo la mitad 
      int h1=it-H.begin();
      int h2=(--it)-H.begin();
      int elegida;
      if(abs(m-H[h1])<abs(m-H[h2]))
         elegida=h1;
      else
         elegida=h2;
      if(H[elegida]<p-H[elegida])
         cout<<H[elegida]<<" ";
      else
         cout<<p-H[elegida]<<" ";
      h1=0;
      h2=h-1;
      if(H[h1]<p-H[h2])
         cout<<p-H[h1]<<endl;
      else
         cout<<H[h2]<<endl;        
   }
}