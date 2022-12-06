import itertools

sum = 0 
with open("input.txt", "r") as file:
    for first, second, third in itertools.zip_longest(*[file]*3): #reads 3 lines at the time
        first = set( first[:-1] ) # [:-1] to remove the newline character
        second = set( second[:-1] )
        third = set( third[:-1] )
        common = first.intersection(second).intersection(third)
        for c in common:
            ASCII_value = ord(c)
            if (c >= 'a'):
                sum += 1 + ASCII_value - ord('a')
            else: 
                sum += 1 + 26 + ASCII_value - ord('A')
            
with open("output2.txt", "w") as file:
    file.write(str(sum))