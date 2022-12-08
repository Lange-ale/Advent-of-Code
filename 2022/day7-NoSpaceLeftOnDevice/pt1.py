filesystem = { "/": { "files": {}, "dirs": set() } }
""" example of filesystem:
{
    "/": { 
        "files": { },
        "dirs": { "home" },
        "size": 300
    }, 
    "/home": {
        "files": { "a.txt": { "size": 100 } ,
                   "b.txt": { "size": 200 } ,
                 },
        "dirs": { },
        "size": 300
    },
}
"""

def get_dir_path(path, dir_name):
    if path == "/":
        return "/" + dir_name
    return path + "/" + dir_name
    

def init_filesystem():
    path = "/"
    with open("input.txt", "r") as file:
        lines = file.read()
    lines = lines.split("$")
    for line in lines:
        l = line.split() # example: ['ls', 'dir', 'e', '29116', 'f.txt']
        if l == []:
            continue
        command = l[0]
        if command == "cd":
            if l[1] == "..":
                path = path[:path.rfind("/")]
            elif l[1] == "/":
                path = "/"
            else:
                path = get_dir_path(path, l[1])
        elif command == "ls":
            for i in range(1, len(l), 2):
                if l[i] == "dir":
                    name = l[i+1]
                    filesystem[path]["dirs"].add(name)
                    if name not in filesystem:
                        filesystem[get_dir_path(path, name)] = { "files": {}, "dirs": set() }
                else:
                    size = int(l[i])
                    name = l[i+1]
                    filesystem[path]["files"][name] = { "size": size }


def get_size_dir(path):
    if "size" in filesystem[path]:
        return filesystem[path]["size"]
    size = 0
    for dir in filesystem[path]["dirs"]:
        size += get_size_dir(get_dir_path(path, dir))
    for file in filesystem[path]["files"]:
        size += filesystem[path]["files"][file]["size"]
    filesystem[path]["size"] = size
    return size


def sum_interested(path): # directories with a total size of at most 100000
    sum = 0
    if get_size_dir(path) <= 100000:
        sum = get_size_dir(path)
    for dir in filesystem[path]["dirs"]:
        sum += sum_interested(get_dir_path(path, dir))
    return sum


init_filesystem()    
result = sum_interested("/")
with open("output1.txt", "w") as file:
    file.write(str(result))
    