#include <bits/stdc++.h>
using namespace std;
int n;
string str;
string getstr(int i,int len) {
    string ret="";
    for (int l=0; l<len; l++) ret+=(str[i+l]);
    return ret;
}
long double getdis(long double a,long double b,long double c,long double d) {
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main() {
    ifstream myfile;
    myfile.open("Data.txt");
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
    long double x,y,k;
    int ans=0;
    cin>>x>>y>>k;
    for (int i=0; i<v.size(); i++) {
        long double dis=getdis(v[i].first,v[i].second,x,y);
        if (dis*111.123<k) ans++;
    }
    cout<<ans<<'\n';
    myfile.close();
    return 0;
}
