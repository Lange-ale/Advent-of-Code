crates = [ [] for i in range(10)]

def parse_crates(file):
    for line in file:
        if "1" in line:
            return
        line = line [:-1] # remove the newline character
        for i in range(1, len(line), 4):
            if line[i] != " ":
                crates[1+((i-1)//4)].insert(0, line[i])
            

with open("input.txt", "r") as file:
    parse_crates(file)
    for line in file:
        line = line.split()
        if len(line) == 0: 
            continue
        for i in range(int(line[1])):
            crates[int(line[5])].append(crates[int(line[3])].pop())
    
       
with open("output1.txt", "w") as file:
    for c in crates:
        if len(c) != 0:
            file.write(c.pop())