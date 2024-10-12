seeds = []
blocks = []
user_input = []

print("Enter inputs, type 'q' to finish:\n")

while True:
    line = input()
    if line == 'q':
        break
    user_input.append(line)

user_input = "\n".join(user_input)
inputs, *blocks = user_input.split("\n\n")

nums = list(map(int, inputs.split(":")[1].split()))
for i in range(0, len(nums), 2):
    seeds.append((nums[i], nums[i] + nums[i + 1]))

for block in blocks:
    rngs = []
    for ln in block.splitlines()[1:]:
        rngs.append(list(map(int, ln.split())))

    new_stuff = []
    while len(seeds) > 0:
        x, y = seeds.pop()
        for a, b, c in rngs:
            n_start = max(x, b)
            n_end = min(y, b + c)
            if n_start < n_end:
                new_stuff.append((n_start - b + a, n_end - b + a))
                if n_start > x:
                    seeds.append((x, n_start))
                if y > n_end:
                    seeds.append((n_end, y))
                break
        else:
            new_stuff.append((x, y))

    seeds = new_stuff

print(min(seeds)[0])
