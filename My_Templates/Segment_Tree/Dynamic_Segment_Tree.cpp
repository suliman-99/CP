#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int cnt;

  Node *lf ,*rg;

  Node(): cnt(0) ,lf(nullptr) ,rg(nullptr) {}
};

map<int , Node*> time_machine;

void UPD(Node *& cur ,int v ,int t ,int L ,int R)
{
  if( !cur ){
    cur = new Node();
  }

  if( L == R ){
    cur -> cnt += v;
    return;
  }

  if( t <= ((L + R) >> 1) ){
    UPD(cur -> lf ,v ,t ,L ,(L + R) >> 1);
  } else {
    UPD(cur -> rg ,v ,t ,((L + R) >> 1) + 1 ,R);
  }

  cur -> cnt = 0;
  if( cur -> lf ) cur -> cnt += cur -> lf -> cnt;
  if( cur -> rg ) cur -> cnt += cur -> rg -> cnt;
}

int QRY(Node *cur ,int i ,int j ,int L ,int R)
{
  if( !cur || R < i || L > j ) return 0;

  if( i <= L && R <= j ) return cur -> cnt;

  return QRY(cur -> lf ,i ,j ,L ,(L + R) >> 1) + QRY(cur -> rg ,i ,j ,((L + R) >> 1) + 1 ,R);
}

int main()
{
  int q;
  scanf("%d" ,&q);

  while( q-- )
  {
    int a ,t ,x;
    scanf("%d%d%d" ,&a ,&t ,&x);

    if( !time_machine.count(x) ){
      time_machine[x] = new Node();
    }

    if( a == 1 ){
      UPD(time_machine[x] ,+1 ,t ,1 ,int(1e9));
    } else if( a == 2 ) {
      UPD(time_machine[x] ,-1 ,t ,1 ,int(1e9));
    } else {
      printf("%d\n" ,QRY(time_machine[x] ,1 ,t ,1 ,int(1e9)));
    }
  }
  return 0;
}