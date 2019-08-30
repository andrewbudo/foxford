# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Просто моделируем процесс игры. Если после миллиона шагов игра не закончилась — выводим botva.

def move(k1, k2):

    card1 = k1.pop(0)

    card2 = k2.pop(0)

    if card1 > card2:

        if(card1 - card2 > 8):

            k2.append(card1)

            k2.append(card2)

        else:

            k1.append(card1)

            k1.append(card2)   

    else: 

        if(card2 - card1 > 8):

            k1.append(card1)

            k1.append(card2)

        else:

            k2.append(card1)

            k2.append(card2)

 

def pyan(s1, s2):

    n = 0

    k1 = list(map(int, s1.split()))

    k2 = list(map(int, s2.split()))

    while(len(k1) * len(k2) != 0) and n < 1000000:

        move(k1, k2)

        n+=1

    if(len(k1) == 0):

        print('second', n)

        return

    if(len(k2) == 0):

        print('first', n)

        return

    print('botva')

 

pyan(input(), input())

 