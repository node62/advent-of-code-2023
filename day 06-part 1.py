print("Enter your inputs:")

inputs = [input(), input()]

times = []
distances = []

for line in inputs:
    if "Time" in line:
        times = list(map(int, line.split(":")[1].split()))
    elif "Distance" in line:
        distances = list(map(int, line.split(":")[1].split()))

res = 1

for t, d in zip(times, distances):
    count = 0
    for hold in range(t):
        if hold * (t - hold) > d:
            count += 1
    res *= count

print(res)
