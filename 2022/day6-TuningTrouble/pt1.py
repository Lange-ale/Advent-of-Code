with open("input.txt", "r") as file:
    queue = []
    i = 0
    while len(queue) < 4:
        char = file.read(1)
        if (char in queue):
            while (queue[0] != char):
                queue.pop(0)
            queue.pop(0)
        queue.append(char)
        i += 1
    
    with open("output1.txt", "w") as file:
        file.write(str(i))
        