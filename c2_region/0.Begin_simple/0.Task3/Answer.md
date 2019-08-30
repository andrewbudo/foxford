# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
floors, k, on_k, other = map(int, input().split())

porch = (floors // k) * on_k + (floors - floors // k) * other

k_floor = on_k + (k - 1) * other

req = int(input())

request = list(map(int, input().split()))

for elem in request:

    elem %= porch

    if elem == 0:

        print(floors)

    elif elem % k_floor == 0:

        print(k * (elem // k_floor))

    else:

        curr = (elem // k_floor) * k

        elem %= k_floor

        if elem // other >= k:

            print(curr + k)

        elif elem % other == 0:

            print(curr + elem // other)

        else:

            print(curr + elem // other + 1)
