# // Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop.
# // Internally, a variable pos is used to denotes the position of the node where the cycle starts, but it is not passed as a parameter.
# // The linked list remains as it is if there is cycle in the list.
# // The output will be "true" if your code works according to expectations, otherwise "false". 
# // Examples:
# // Input: head = 1 -> 3 -> 4, pos = 2
# // Output: true
# // Explanation: The linked list looks like
# // A loop is present in the list, and it is removed.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Insert at end
def insert(head, data):
    newNode = Node(data)

    if head is None:
        return newNode

    temp = head
    while temp.next:
        temp = temp.next

    temp.next = newNode
    return head


# Create loop at given position (1-based index)
def createLoop(head, pos):
    if pos == 0:
        return

    loopNode = None
    temp = head
    count = 1

    while temp.next:
        if count == pos:
            loopNode = temp
        temp = temp.next
        count += 1

    temp.next = loopNode


# Remove loop
def removeLoop(head):

    if head is None or head.next is None:
        return

    slow = head
    fast = head

    # Detect loop
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            break

    # No loop
    if fast is None or fast.next is None:
        return

    # Move slow to head
    slow = head

    # Loop starts at head
    if slow == fast:
        while fast.next != slow:
            fast = fast.next

        fast.next = None
        return

    # Loop starts elsewhere
    while slow.next != fast.next:
        slow = slow.next
        fast = fast.next

    fast.next = None


# Print list
def printList(head):
    temp = head

    while temp:
        print(temp.data, end=" -> ")
        temp = temp.next

    print("None")


# ---------------- Main ----------------

head = None

n = int(input("Enter number of nodes: "))

print("Enter node values:")
for _ in range(n):
    x = int(input())
    head = insert(head, x)

pos = int(input("Enter loop position (0 for no loop): "))

createLoop(head, pos)

removeLoop(head)

print("\nLinked List after removing loop:")
printList(head)