# Code goes here
print('\nsegitiga sama kaki\n')
a = 6
s = a - 1 # untuk spasinya
def new_func():
    print(' \n ')

for i in range(0, a):
    for j in range(0, s):
        print(' ', end='')
    s -= 1
    for j in range(0, i + 1):
        print('* ', end='')
 
    print(' ')
print('\n')
