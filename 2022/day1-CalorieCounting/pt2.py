greaters = [0, 0, 0]
with open("input.txt", "r") as file:
    actual = 0
    for line in file:
        if line == "\n":
            greaters.sort()
            greaters[0] = max(greaters[0], actual)
            print(greaters)
            actual = 0
        else:
            actual += int(line)    
            
with open("output2.txt", "w") as file:
    file.write(str(sum(greaters)))