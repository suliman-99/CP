#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector< int >   vi;
long double PI  = 3.141592653589793238;


struct Interval {
    int start, end;
};
 
// Compares two intervals
// according to starting times.
bool compareInterval(Interval i1, Interval i2){
    /// return true to put (i1) befor (i2) & false othewise
    return (i1.start < i2.start);
}


int main(){
    int n = 10;
    int a[n];

    /// inc order
    sort(a, a + n);

    /// dec order
    sort(a, a + n, greater<int>());

    /// my order on array of (Interval)
    sort(a, a + n, compareInterval);

    /// max-heap (dec order)
    priority_queue<int> q;

    /// min-heap (inc order)
    priority_queue<ii,vector<ii>,greater<ii>> q;
    
    /// --- to print (n) number after the point
    cout<<fixed<<setprecision(n)<<PI<<endl;

    do{
        /// here you have the array (a) with the current permutation
    }while(next_permutation(a,a+n));

    string str;
    /// to read a Line into string 
    getline(cin, str);

    int char_list_len = 10;
    char char_list[char_list_len];

    /// to read a Line into char list 
    cin.getline(char_list, char_list_len);

}




/*************** Type Format Specifier ***************\
|    int               =         %d            &      |
|    unsigned int      =         %u            &      |
|    ll                =         %lli          &      |
|    ull               =         %llu          &      |
|    float             =         %f            &      |
|    double            =         %lf           &      |
|    ld                =         %Lf           &      |
|    char              =         %c            &      |
|    char[]            =         %s            -      |
|    bool     ->    Use inteer then cast       -      |
\*****************************************************/





