//Too boring; the code isn't written by me

#include "iostream"
#include "string.h"
#include <stdio.h>
using namespace std;
char Haab_month[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char Tzolkin_month[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main()
{
  int n,year,day,mon,t;
  char s[10];
  cin>>n;
 cout<<n<<endl;
 while(n--)
   {
     cin>>day;
     getchar();//skip the dot
     getchar();//skip the enter
     //scanf("%d. %s %d",&day,s,&year);or we could use this statement to skip the dot
     cin>>s>>year;
     for(mon=0;mon<19;mon++)
       if(strcmp(Haab_month[mon],s)==0)
	 break;
     t=365*year+mon*20+day;//Haab is counted from 0 day,the statement is 
     //to sum the wholl days
     cout<<1+t%13<<" "<<Tzolkin_month[t%20]<<" "<<t/260<<endl;//first one is begun with 1
   }
 return 0;
}
