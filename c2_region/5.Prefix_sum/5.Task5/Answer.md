# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Решение 1: Разбейте предприятия на блоки по N^0.5 предприятий. 
Каждый блок храните в отдельном векторе. 
Теперь при любом запросе вы трогаете не больше двух блоков, 
в каждом операции удаления можно делать в лоб за длину блока. 
Но когда длина блока становится в два раза больше изначальной или становится равной нулю - 
пересчитывайте всю структуру. 
Такое будет происходить не чаще чем раз в N^0.5 операций, поэтому общая асимптотика будет N * N^0.5. 
Искомое значение можно пересчитывать наивно, мы же знаем размеры удаляемых и добавляемых предприятий.

Решение 2: Запихните предприятия в декартово дерево по неявному ключу, 
где в поддереве будет считаться искомая функция. Теперь любая операция работает за O(logN)

#include <iostream> #include <vector> #include <algorithm> #include <cmath>

using namespace std;

typedef long long ll;

int n, p; 
vector<int> a; 
vector<vector<int>> blocks; 
int blockSize;

ll summ = 0;

inline ll sqr(int a) {     
return (ll) a * a; 
}

inline void fillBlocks(int n) {     
blocks.clear();     
blockSize = sqrt(n); //i / blockSize     
for (int i = 0; i < n; ++i) {         
if (i / blockSize == blocks.size()) {             
blocks.push_back(vector<int>{});         
}         
blocks[i / blockSize].push_back(a[i]);     
} 
}

inline void recalc() {     
a.clear();     
for (auto arr : blocks) {         
for (auto el : arr) {             
a.push_back(el);         
}     
}    
n = a.size();     
fillBlocks(n); 
}

int main() {     
ios_base::sync_with_stdio(false);     
cin.tie(0);     
cin >> n >> p;     
a.resize(n);     
for (int i = 0; i < n; ++i) {         
cin >> a[i];         
summ += sqr(a[i]);     
}     
cout << summ << endl;     
fillBlocks(n);     
int k;     
cin >> k;     
for (int i = 0; i < k; ++i) {         
if (i == 19) {             
n += 0;         
}         
int type, pos;         
cin >> type >> pos;         
pos--;         
int block = 0;         
while (pos >= blocks[block].size()) {             
pos -= blocks[block].size();             
block++;         
}         
int lft = blocks[block][pos] / 2, rght = (blocks[block][pos] + 1) / 2;         
summ -= sqr(blocks[block][pos]);         
blocks[block].erase(blocks[block].begin() + pos);//pos - 1, pos         
if (type == 1) {             
int leftBlock, leftPos, rightBlock, rightPos;             
if (pos == 0) {                 
leftBlock = block - 1;                 
if (leftBlock == -1) {                     
leftPos = -1;                 
} else {                     
leftPos = blocks[leftBlock].size() - 1;                 
}             
} else {                 
leftBlock = block;                 
leftPos = pos - 1;             
}             
if (pos == blocks[block].size()) {                 
rightBlock = block + 1;                 
rightPos = 0;             
} else {                 
rightBlock = block;                 
rightPos = pos;             
}             
if (leftBlock == -1) {                 
summ -= sqr(blocks[rightBlock][rightPos]);                 
blocks[rightBlock][rightPos] += (lft + rght);                 
summ += sqr(blocks[rightBlock][rightPos]);             
} else if (rightBlock == blocks.size()) {                 
summ -= sqr(blocks[leftBlock][leftPos]);                 
blocks[leftBlock][leftPos] += (lft + rght);                 
summ += sqr(blocks[leftBlock][leftPos]);             
} else {                 
summ -= sqr(blocks[rightBlock][rightPos]);                 
blocks[rightBlock][rightPos] += rght;                 
summ += sqr(blocks[rightBlock][rightPos]);                 
summ -= sqr(blocks[leftBlock][leftPos]);                 
blocks[leftBlock][leftPos] += lft;                 
summ += sqr(blocks[leftBlock][leftPos]);             
}         
} else {//initializer_list - {1, 2, 3, 4, 5, 6}             
summ += sqr(lft);             
summ += sqr(rght);             
blocks[block].insert(blocks[block].begin() + pos, { lft, rght });         
}         
if (blocks[block].size() >= 2 * blockSize || blocks[block].size() == 0) {             
recalc();         
}         
cout << summ << endl;     
}     
system("pause");     
return 0; 
}

