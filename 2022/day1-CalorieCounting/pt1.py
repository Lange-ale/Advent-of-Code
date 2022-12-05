greater = 0
with open("input.txt", "r") as file:
    actual = 0
    for line in file:
        if line == "\n":
            greater = max(greater, actual)
            actual = 0
        else:
            actual += int(line)    
            
with open("output1.txt", "w") as file:
    file.write(str(greater))