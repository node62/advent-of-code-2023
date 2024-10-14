print("Enter the times and distances lines:")

inp_times = input() 
inp_distances = input()  

times = [int("".join(inp_times.split(":")[1].split()))]
distances = [int("".join(inp_distances.split(":")[1].split()))]

result = 1

for t, d in zip(times, distances):
    counter = 0
    for h in range(t):
        if h * (t - h) > d:
            counter += 1
    result *= counter

print(result)
