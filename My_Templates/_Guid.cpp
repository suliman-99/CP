#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
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
    ll n = 10;
    ll a[n];
    
    memset(a, -1, sizeof(a));

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
    int char_list_len = 10;
    char char_list[char_list_len];
    

    /// to read a word into string 
    cin>>str;

    /// to read a Line into string 
    getline(cin, str);

    /// to read a word into char list 
    cin>>char_list;
    scanf("%s", char_list);

    /// to read a Line into char list 
    cin.getline(char_list, char_list_len);
    fgets(char_list, char_list_len, stdin);
    
    str = char_list;

    // if str is integer (ll) then assing the value to a
    if(str.find_first_not_of( "0123456789+-" ) == string::npos){
        n = stoll(str);
    }

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

// -------------------------------------------------------

// Read multi line with multi value in every line 
// Unknown lines number & Unknown values number in every line

// ll n, m[100], a[100][100];
// char c;
// bool read;

// void doTest(){
//     read = true;
//     while(read){
//         while(read = (scanf("%d%c", &a[n][m[n]++], &c) == 2))
//             if(c == '\n') break;
//         n++;
//     } n--; m[n]--;
//     for(int i = 0 ; i < n ; i ++){
//         for(int j = 0 ; j < m[i] ; j ++){
//             cout<<a[i][j]<<" ";
//         } cout<<endl;
//     }
// }




