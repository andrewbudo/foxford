# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Электричка проезжает по N - 1 перегону между станциями. Для каждого перегона будем хранить количество свободных мест на этом перегоне. Для определения наличия свободного места на каком-то перегоне нужно найти минимальное число мест на запрашиваемом отрезке, если оно больше 0, то место есть и билет продается. При продаже билета нужно уменьшить число свободных мест на всем отрезке пути.

Для эффективной реализации алгоритма необходимо использовать дерево отрезков с групповой операцией изменения значения на отрезке и групповым запросом.

#include<iostream>
#include<vector>

using namespace std;

struct node
{
    int left, right, min, add;
    node * child_left, * child_right;
};

const int INF = 2000000000;

node* build(int left, int right, vector<int> & values)
{
    if (left > right)
        return 0;
    node * res = new node;
    res->left = left;
    res->right = right;
    if (right == left)
    {
        res->child_left = res->child_right = 0;
        res->min = values[left];
        res->add = 0;;
    }
    else
    {
        int mid = (left + right) / 2;
        res->child_left = build(left, mid, values);
        res->child_right = build(mid + 1, right, values);
        res->min = min(res->child_left->min, res->child_right->min);
        res->add = 0;
    }
    return res;
}

int query(node * root, int left, int right)
{
    if (right < root->left || left > root->right)
        return INF;
    if (left <= root->left && right >= root->right)
        return root->add + root->min;
    int ans1 = query(root->child_left, left, right);
    int ans2 = query(root->child_right, left, right);
    return root->add + min(ans1, ans2);
}

void update(node * root, int left, int right, int delta)
{
    if (right < root->left || left > root->right)
        return;
    if (left <= root->left && right >= root->right)
        root->add += delta;
    else
    {
        update(root->child_left, left, right, delta);
        update(root->child_right, left, right, delta);
        root->min = min(root->child_left->min + root->child_left->add,
                        root->child_right->min + root->child_right->add);
    }
}

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n - 1, k);
    node * root = build(0, n - 2, a);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (query(root, x, y - 1) <= 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
            update(root, x, y - 1, -1);
        }
    }
    return 0;
}