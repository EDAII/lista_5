import numpy as np
import random


def select_nth(n, items):
    pivot = random.choice(items)

    lesser = items[np.where(items < pivot)]
    if len(lesser) > n:
        return select_nth(n, lesser)
    n -= len(lesser)
    numequal = list(items).count(pivot)
    if numequal > n:
        return pivot
    n -= numequal

    greater = items[np.where(items > pivot)]
    return select_nth(n, greater)


def myMedian(items):
    if len(items) % 2:
        return select_nth(len(items) // 2, items)

    else:
        left = select_nth((len(items) - 1) // 2, items)
        right = select_nth((len(items) + 1) // 2, items)

        return (left + right) / 2


vetor = []
tam = int(input("insira o tamanho do vetor \n"))
for i in range(tam):
    vetor.append(
        int(input("insira o valor do vetor na posicao " + str(i) + "\n")))
print(vetor)
vetor = np.array(vetor)
split_5 = np.array_split(vetor, 5)
split_5 = np.sort(split_5)
medianas = split_5[:, 2]

# mom = np.median(medianas)
mom = myMedian(medianas)
print("essa é a mediana das medianas", mom)
