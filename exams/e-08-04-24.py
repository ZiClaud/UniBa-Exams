def traccia3(x, r: float):
    if r < 0 or r > 1:
        print("Error")
        return -1
    x0: float = -1
    k: int = -1
    y = []
    curry = []
    currk: int = 0

    for currx in x:
        curry = []
        for currval in x:
            if abs(currval - currx) < r:
                curry.append(currval)

        if len(curry) > len(y):
            y = curry
            x0 = currx
            k = currk
        currk += 1

    return x0, k, y

print(traccia3([0, 0.8, 0.1, 0.12, 0.71, 0.73, 0.13, 0.7, 0.16, 0.3, 0.5, 0.68, 0.2, 0.69, 0.9], 0.05))
