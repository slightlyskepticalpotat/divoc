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
long double todouble(char* a) {
    char* ind=a;
    int neg=0;
    if (ind!=NULL and *ind=='-') {neg=1; ind++;}
    long double lon=0,dec=1;
    while (ind!=NULL and ((int)(*ind)>=48 and (int)(*ind)<58)) {
        lon*=10; lon+=(int)(*ind)-48;
        ind++;
    }
    if (ind==NULL or (*ind)!='.') return lon;
    ind++;
    while (ind!=NULL and (int)(*ind)>=48 and (int)(*ind)<58) {
        dec/=10.0; lon+=(dec*(long double)((int)(*ind)-48));
        ind++;
    }
    if (neg) lon*=(-1);
    return lon;
}
int main(int argc,char* argv[]) {
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
    x=todouble(argv[1]); y=todouble(argv[2]); k=todouble(argv[3]);
    x*=1000; x=(int)(x); x/=1000; y*=1000; y=(int)(y); y/=1000; k*=1000; k=(int)(k); k/=1000;
    for (int i=0; i<v.size(); i++) {
        long double dis=getdis(v[i].first,v[i].second,x,y);
        if (dis*111.123<k) ans++;
    }
    myfile.close();
    cout << "There are " << ans << " cases near you.\n";
    return ans;
}
