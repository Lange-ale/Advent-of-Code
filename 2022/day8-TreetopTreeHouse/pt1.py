with open("input.txt") as file:
    grid = file.read()
grid = grid.split()
N = len(grid)

visible_trees = { i:set() for i in range(0, N) }

def find_visible_trees (direction, pos, tallest): #watching from the a edge of the grid
    if pos['x'] < 0 or pos['x'] >= N or pos['y'] < 0 or pos['y'] >= N:
        return 
    if int(grid[pos['x']][pos['y']]) > tallest:
        visible_trees[pos['x']].add(pos['y'])
    find_visible_trees( direction , 
        { 'x': pos['x'] + direction['x'], 'y': pos['y'] + direction['y'] } , 
        max(tallest, int(grid[pos['x']][pos['y']])) )    


for i in range(0, N):
    find_visible_trees( { 'x': 1, 'y': 0 } , { 'x': 0, 'y': i } , -1 )
    find_visible_trees( { 'x': -1, 'y': 0 } , { 'x': N - 1, 'y': i } , -1 )
    find_visible_trees( { 'x': 0, 'y': 1 } , { 'x': i, 'y': 0 } , -1 )
    find_visible_trees( { 'x': 0, 'y': -1 } , { 'x': i, 'y': N - 1 } , -1 )

total_visible_trees = 0
for i in range(0, N):
    total_visible_trees += len(visible_trees[i])
    
with open("output1.txt", "w") as file:
    file.write(str(total_visible_trees))
    