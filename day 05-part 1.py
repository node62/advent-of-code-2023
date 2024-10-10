firstInput = input("Enter input(end by inputting q in new line): ")
seeds = []
if firstInput.startswith("seeds: "):
    firstInput = firstInput[len("seeds: "):]
    seeds = firstInput.split(" ")
    seeds = [int(i) for i in seeds]

print(seeds)

st = ""
m = []
while st!='q':
    st = input()
    if not st:
        continue
    f = st[0]
    if f.isalpha():
        m.append('X')
    elif f.isdigit():
        a, b, c = st.split(" ")
        a, b, c = int(a), int(b), int(c)
        m.append((a, b, c))

final = []
for seed in seeds:
    k = 1
    n = seed
    for tup in m:
        if tup == 'X':
            k = 1
            continue
        a, b, c = tup
        if b <= n < b + c and k == 1:
            n = a + n - b
            k = 0
    final.append(n)

print("min: "+str(min(final)))
