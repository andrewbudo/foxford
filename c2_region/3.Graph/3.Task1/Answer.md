# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Положим в очередь bfs-а сразу все единички и запустим его. Тогда в каждый нолик запишется расстояние до ближайшей единички

#include <iostream>

#include <queue>

using namespace std;

queue <int> qi;

queue <int> qj;

int a[501][501];

bool used[501][501];

int main()

{

    int n,m;

    short int k;

    int max=0;

    cin>>n>>m;

    for(short int i=1;i<=n;i++)

    {

    for(short int j=1;j<=m;j++)

{

bool num;

cin>>num;

if(num==1)

{

        used[i][j]=1;

          qi.push(i);

        qj.push(j);

}

}

}

    while(!qi.empty() && !qj.empty())

    {

        int vi=qi.front(),vj=qj.front();

        qi.pop();

        qj.pop();

        if(a[vi][vj]>max)

        max=a[vi][vj];

        used[vi][vj]=1;

        if(vi+1<=n && !used[vi+1][vj])

        {

            a[vi+1][vj]=a[vi][vj]+1;

            used[vi+1][vj]=1;

            qi.push(vi+1);

            qj.push(vj);

        }

        if(vi-1>0 && !used[vi-1][vj])

        {

            a[vi-1][vj]=a[vi][vj]+1;

            used[vi-1][vj]=1;

            qi.push(vi-1);

            qj.push(vj);

        }

        if(vj+1<=m && !used[vi][vj+1])

        {

            a[vi][vj+1]=a[vi][vj]+1;

            used[vi][vj+1]=1;

            qi.push(vi);

            qj.push(vj+1);

        }

        if(vj-1>0 && !used[vi][vj-1])

        {

            used[vi][vj-1]=1;

            a[vi][vj-1]=a[vi][vj]+1;

            qi.push(vi);

            qj.push(vj-1);

        }

    }

for(int i=1;i<=n;i++)

    {

        for(int j=1;j<=m;j++)

        {

            cout<<a[i][j]<<' ';

        }

        cout<<endl;

    }

    //cout<<max<<endl;

    return 0;

}
