import sys

# args = sys.argv

# left = []
# operand = None
# right = []

# i = 1
# while (args[i] not in ['&&', '||', '|']):
#     left.append(args[i])
#     i += 1
# operand = args[i]
# for i in range(i + 1, len(args)):
#     right.append(args[i])
#     i += 1

# print("Left side ", left)
# print("operand ", operand)
# print("Right side", right)

class   Node:
    left = None
    right = None
    name = ""
    type = 1


def my_recursion(args: list) -> Node:
    # if len(args) <= 1:
    #     ret = Node()
    #     ret.name = args[0]
    #     return ret
    
    ret = Node()
    left = []
    right = []
    i = 0
    while (i < len(args) and args[i] not in ['&&', '||', '|']):
        if args[i] == '(':
            i += 1
            while args[i] != ')':
                left.append(args[i])
                i += 1
            i += 1
        else:
            left.append(args[i])
            i += 1

    if i == len(args):
        ret.type = 1
        ret.name = str(left)
        return ret
    if (args[i] == "&&"):
        ret.type = 2
    elif (args[i] == "||"):
        ret.type = 3
    elif (args[i] == "|"):
        ret.type = 4

    ret.name = args[i]
    for i in range(i + 1, len(args)):
        right.append(args[i])
        i += 1
    
    ret.left = my_recursion(left)
    ret.right = my_recursion(right)
    return ret

def my_printer(data: Node):
    if data.left is None:
        print (data.name, end="")
        return
    
    print ("{ ", end="")
    my_printer(data.left)
    print (" }", end="")

    print(" ~", data.name, "~ ", end="")

    print ("{ ", end="")
    my_printer(data.right)
    print (" }", end="")

args = sys.argv[1:]

printer = my_recursion(args)
my_printer(printer)



