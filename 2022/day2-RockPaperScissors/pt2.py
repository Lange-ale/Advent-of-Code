moves = {
    "A": {
        "val": 1,
        "win": "C",
        "lose": "B",
    },
    "B": {
        "val": 2,
        "win": "A",
        "lose": "C",
    },
    "C": {
        "val": 3,
        "win": "B",
        "lose": "A",
    },
}

value = {
    "X": 0,
    "Y": 3,
    "Z": 6,
}

points = 0
with open("input.txt", "r") as file:
    for line in file:
        opponent, round_result = line.split()
        points += value[round_result]
        if round_result == "X":
            my_choise = moves[opponent]["win"]
        elif round_result == "Y":
            my_choise = opponent
        else:
            my_choise = moves[opponent]["lose"]
        points += moves[my_choise]["val"]
            
            
with open("output2.txt", "w") as file:
    file.write(str(points))