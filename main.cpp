#include <bits/stdc++.h>
using namespace std;
int n;
string str;
string getstr(int i,int len) {
    string ret="";
    for (int l=0; l<len; l++) ret+=(str[i+l]);
    return ret;
}
int main() {
    ifstream myfile;
    myfile.open("C:\\Users\\aaron\\Desktop\\Data.txt");
    getline(myfile,str);
    n=str.size();
    vector<pair<long double,long double> > v;
    for (int i=0; i<n-10; i++) {
        string x=getstr(i,11);
        if (x=="Longitude\":") {
            int ind=i+11,neg=0;
            if (str[ind]=='-') {neg=1; ind++;}
            long double lon=0,dec=1;
            while ((int)(str[ind])>=48 and (int)(str[ind])<58) {
                lon*=10; lon+=(int)(str[ind])-48;
                ind++;
            }
            ind++;
            while ((int)(str[ind])>=48 and (int)(str[ind])<58) {
                dec/=10.0; lon+=(dec*(long double)((int)(str[ind])-48));
                ind++;
            }
            if (neg) lon*=(-1);
            v.back().second=lon;
            i=ind-1;
        }
        x=getstr(i,10);
        if (x=="Latitude\":") {
            int ind=i+10,neg=0;
            if (str[ind]=='-') {neg=1; ind++;}
            long double lat=0,dec=1;
            while ((int)(str[ind])>=48 and (int)(str[ind])<58) {
                lat*=10; lat+=(int)(str[ind])-48;
                ind++;
            }
            ind++;
            while ((int)(str[ind])>=48 and (int)(str[ind])<58) {
                dec/=10.0; lat+=(dec*(long double)((int)(str[ind])-48));
                ind++;
            }
            if (neg) lat*=(-1);
            v.push_back({lat,0});
            i=ind-1;
        }
    }
    for (int i=0; i<v.size(); i++) {
        cout<<fixed<<setprecision(8)<<v[i].first<<' '<<v[i].second<<'\n';
    }
    myfile.close();
    return 0;
}
