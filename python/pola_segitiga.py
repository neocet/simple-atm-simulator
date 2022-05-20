n = int(input("Masukkan jumlah baris: "))
s = n - 1 # for space


for i in range(0, n):
    for j in range(0, s):
        print(' ', end='')
    s -= 1
    for j in range(0, i + 1):
        print(j + 1, end=' ')
    print(' ')
