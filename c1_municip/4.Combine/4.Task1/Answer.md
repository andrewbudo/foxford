# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Будем решать задачи в порядке увеличения количества требуемого умения. Если мы не можем решить текущую задачу, то и все последующие точно не можем. Отсортируем задачи и будем по очереди проверять.

def first(n):

    return n[0]

 

koll,a=map(int,input().split())

b=[]

for i in range(0,koll,1):

    b.append(list(map(int,input().split())))

b.sort(key=first)

lenB=len(b)

i=0

while(a>=b[i][0]):

    if(i<lenB-1):

        a+=b[i][1]

        i+=1

    else:

        i+=1

        break

print(i)