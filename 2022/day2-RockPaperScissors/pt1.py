moves = {
    "A": {
        "val": 1,
        "win": "C",
    },
    "B": {
        "val": 2,
        "win": "A",
    },
    "C": {
        "val": 3,
        "win": "B",
    },
}

replace = {
    "X": "A",
    "Y": "B",
    "Z": "C",
}

points = 0
with open("input.txt", "r") as file:
    for line in file:
        opponent, my_choice = line.split()
        my_choice = replace[my_choice]
        points += moves[my_choice]["val"]
        if opponent == my_choice:
            points += 3
        elif opponent == moves[my_choice]["win"]:
            points += 6
            
            
with open("output1.txt", "w") as file:
    file.write(str(points))