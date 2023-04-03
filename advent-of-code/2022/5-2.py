data = {
    0 : ['V','J','B','D'],
    1 : ['F', 'D', 'R', 'W', 'B', 'V', 'P'],
    2 : ['Q', 'W', 'C', 'D', 'L', 'F', 'G', 'R'],
    3 : ['B', 'D', 'N', 'L', 'M', 'P', 'J', 'W'],
    4 : ['Q', 'S', 'C', 'P', 'B', 'N', 'H'],
    5 : ['G', 'N', 'S', 'B', 'D', 'R'],
    6 : ['H', 'S', 'F', 'Q', 'M', 'P', 'B', 'Z'],
    7 : ['F', 'L', 'W'],
    8 : ['R', 'M', 'F', 'V', 'S']
}

def update(n,fro,to):
    fro-=1
    to-=1
    added = data[fro][0:n]
    data[fro] = data[fro][n:]
    data[to]= added + data[to]

def solve():
    for i in range(9):
        print(data[i][0], end="")

with open('input.txt', 'r') as f:
    lines = f.readlines()
for inp in lines:
    inp = inp.split()
    n = int(inp[1])
    fro = int(inp[3])
    to = int(inp[5])
    update(n,fro,to)
solve()
