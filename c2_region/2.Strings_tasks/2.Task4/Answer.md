# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Если примем, что последнее слово надо обязательно стереть, то оптимальной последовательностью вывода будет просто обход DFS-ом в боре. Иначе же надо сделать последним слово, которое дольше всего стирать, то есть обходить дерево так, чтобы в это слово прийти последним

#include <iostream>

#include <cmath>

#include <vector>

#include <algorithm>

#include <cstring>

#include <stdio.h>

 

using namespace std;

 

struct node {

    node* next[26];

    long x;

    long flag;

    node() {

        x = 0;

        flag = 0;

        for (int i = 0; i < 26; i++)

            next[i] = nullptr;

    }

};

 

node head;

 

void push(string s) {

    node* v = &head;

    long sizen = s.size();

    for (int i = 0; i < s.size(); i++) {

        int c = s[i] - 'a';

        if (v -> next[c] != nullptr) {

            v = v -> next[c];

            v -> x = max(v -> x, sizen - i - 1);

            if (i == s.size() - 1)

                v -> flag = 1;

        }

        else {

            v -> next[c] = new node;

            v = v -> next[c];

            v -> x = sizen - i - 1;

            if (i == s.size() - 1)

                v -> flag = 1;

        }

    }

}

 

string ans = "";

 

void get(node* v) {

    node* v1 = &head;

    long max1 = 0, ind = -1;

    for (int i = 0; i < 26; i++) {

        if (v -> next[i] != nullptr) {

            v1 = v -> next[i];

            if (v1 -> x > max1) {

                max1 = v1 -> x;

                ind = i;

            }

        }

    }

    if (v -> flag == 1)

        ans += 'P';

    for (int i = 0; i < 26; i++) {

        if (v -> next[i] != nullptr && i != ind) {

            ans += char(i + 'a');

            v1 = v -> next[i];

            get(v1);

            ans += '-';

        }

    }

    if (ind != -1) {

        ans += char(ind + 'a');

        v1 = v -> next[ind];

        get(v1);

        ans += '-';

    }

}

 

int main() {

    long n;

    cin >> n;

    for (int i = 0; i < n; i++) {

        string s;

        cin >> s;

        push(s);

    }

    node* v = &head;

    get(v);

    int i;

    for (i = ans.size() - 1; i >= 0; i--)

        if (ans[i] != '-') break;

    printf("%d\n", i + 1);

    for (int j = 0; j <= i; j++)

        printf("%c\n", ans[j]);

}
