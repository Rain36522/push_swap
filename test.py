import random

def generate_int(quantity):
    x = 'INPUT = '
    i = 0
    min_value = -2147483648
    max_value = 2147483647

    while (i < quantity):
        j = random.randint(min_value, max_value + 1)
        if str(j) + ' ' not in x:
            x = x + str(j) + ' '
            i += 1

    print(x)

n = int(input("Entrez nombre a generer : "))
generate_int(n)