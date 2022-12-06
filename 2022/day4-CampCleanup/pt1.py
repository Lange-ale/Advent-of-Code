pairs = 0 
with open("input.txt", "r") as file:
    for line in file:
        line = line.split() [0] # remove the newline character
        p1, p2 = [ pair.split("-") for pair in line.split(",") ] # p1 = ["2", "4"], p2 = ["6", "8"]
        p1 = [int(i) for i in p1] #cast to int the elements
        p2 = [int(i) for i in p2]
        if (p1[0] <= p2[0] and p2[1] <= p1[1]) or (p2[0] <= p1[0] and p1[1] <= p2[1]):
            pairs += 1
            
with open("output1.txt", "w") as file:
    file.write(str(pairs))