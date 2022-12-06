sum = 0 
with open("input.txt", "r") as file:
    for line in file:   
        first_half = line[:len(line)//2]
        second_half = line[len(line)//2:]
        common = set(first_half).intersection(set(second_half))
        for c in common:
            ASCII_value = ord(c)
            if (c >= 'a'):
                sum += 1 + ASCII_value - ord('a')
            else: 
                sum += 1 + 26 + ASCII_value - ord('A')
            
with open("output1.txt", "w") as file:
    file.write(str(sum))