# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
key = int(input())

n, a, b, c = map(int, input().split())

m = min(a, b, c)

if key == 2:

    print(m)

else:

    #x = 2 * n - (a + b + c - m)    

    #print(max(0,m - x))

    if m == a:

        x = m - (n-b) - (n-c)

    elif m == b:

        x = m - (n-a) - (n-c)

    else:

        x = m - (n-a) - (n-b)

    print(max(x, 0))
