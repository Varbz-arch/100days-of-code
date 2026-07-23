    temp = head

    while temp:
        print(temp.data, end=" -> ")
        temp = temp.next

    print("None")


# ---------------- Main ----------------

head = None

n = int(input("Enter number of nodes: "))

print("Enter node values:")