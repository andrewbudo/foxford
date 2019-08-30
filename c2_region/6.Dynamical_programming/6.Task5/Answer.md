# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Первый параметр - сколько вершин уже рассмотрели. Второй - сколько раз использовали мост. Теперь когда смотрим на некоторое состояние мы либо использовали до него мост, либо нет. Если не использовали, то все просто. Если использовали - перебираем вершину с которой мост начался. Надо проверять что длина моста не превышает заданного ограничения и что мост не пересекает горы. Последнее можно посчитать заранее для всех пар вершин.

#include <iostream>

#include<cstdio>

#include<cmath>

#include<vector>

#include<algorithm>

#include<iomanip>

using namespace std;

 

typedef pair<double,double> ll;

 

double sqr(double a)

{

return a*a;

}

 

int N,K;

int i,j,h;

long long R;

vector<ll > points;

double mas[101][101];

double ways[101][101];

double NA=1e15;

double eps=1e-7;

int x,y;

 

int main()

{

freopen("g.in","r",stdin);

freopen("g.out","w",stdout);

 

cin>>N>>K>>R;

points.resize(N+1);

for(i=1;i<=N;i++)

{

scanf("%d%d",&x,&y);

points[i]=ll(x,y);

}

 

for(i=1;i<=N;i++)

for(j=1;j<=N;j++)

if (abs(i-j)<2)

ways[i][j]=sqrt(1.0*sqr(points[i].first-points[j].first)+sqr(points[i].second-points[j].second));

else

ways[i][j]=NA;

 

for(i=1;i<=N-2;i++)

for(j=i+2;j<=N;j++)

{

double x1,y1,x2,y2;

double a,b,c;

double k,d;

x1=points[i].first;

y1=points[i].second;

 

x2=points[j].first;

y2=points[j].second;

 

a=y2-y1;

b=x1-x2;

c=-a*x1-b*y1;

k=-(double)a/b;

d=-(double)c/b;

 

bool ok = true;

for(h=i+1;h<j;h++)

if (points[h].second>eps+d+k*points[h].first)

ok=false;

 

if (ok)

{

d=sqrt(1.0*sqr(points[i].first-points[j].first)+sqr(points[i].second-points[j].second));

if (d<R+eps)

ways[i][j]=ways[j][i]=d;

}

}

 

for(i=0;i<=N;i++)

for(j=0;j<=K;j++)

mas[i][j]=NA;

mas[1][0]=0;

for(i=1;i<N;i++)

for(j=0;j<=K;j++)

if (mas[i][j]<NA-1000)

for(h=i+1;h<=N;h++)

if (h==i+1)

{

if (mas[h][j]>mas[i][j]+ways[i][h])

mas[h][j]=mas[i][j]+ways[i][h];

}

else

{

if (mas[h][j+1]>mas[i][j]+ways[i][h])

mas[h][j+1]=mas[i][j]+ways[i][h];

}

 

double d=NA;

for(i=0;i<=K;i++)

if (d>mas[N][i])

d=mas[N][i];

 

 

cout<<setprecision(10)<<d<<endl;

 

fclose(stdin);

fclose(stdout);

return 0;

}
