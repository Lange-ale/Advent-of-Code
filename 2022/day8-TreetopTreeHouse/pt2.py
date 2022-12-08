with open("input.txt") as file:
    grid = file.read()
grid = grid.split()
N = len(grid)


def visible_trees (direction, pos, start_height):
    pos = { 'x': pos['x'] + direction['x'], 'y': pos['y'] + direction['y'] }
    if pos['x'] < 0 or pos['x'] >= N or pos['y'] < 0 or pos['y'] >= N:
        return 0
    if int(grid[pos['y']][pos['x']]) >= start_height:
        return 1
    return 1 + visible_trees(direction, pos, start_height)
    
    
def scenic_score(pos):
    return visible_trees( { 'x': 1, 'y': 0 } , pos , int(grid[pos['y']][pos['x']])) * \
           visible_trees( { 'x': -1, 'y': 0 } , pos , int(grid[pos['y']][pos['x']])) * \
           visible_trees( { 'x': 0, 'y': 1 } , pos , int(grid[pos['y']][pos['x']])) * \
           visible_trees( { 'x': 0, 'y': -1 } , pos , int(grid[pos['y']][pos['x']]))


max_score = 0
for i in range(N):
    for j in range(N):
        max_score = max(max_score, scenic_score({ 'x': i, 'y': j }))    

with open("output2.txt", "w") as file:
    file.write(str(max_score))
    