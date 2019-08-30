# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Надо честно расписать все условия и не забыть все нюансы

n = int(input())

if n < 1896:

    print("nothing")

elif 1896 <= n < 1924:

    if n % 4 == 0 and n != 1916 or n == 1906:

        print("summer")

    else:

        print("nothing")

elif 1924 <= n <= 1992:

    if n % 4 == 0 and n != 1940 and n != 1944:

        print("winter summer")

    else:

        print("nothing")

else:

    if (n - 2) % 4 == 0:

        print("winter")

    elif n % 4 == 0:

        print("summer")

    else:

        print("nothing")  