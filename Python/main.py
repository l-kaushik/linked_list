
class Node:
    def __init__(self, data = None) -> None:
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, data):
        ''' insert a single value at the end of the linked list'''
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def display(self):
        current = self.head
        while current:
            print(current.data, end=' -> ')
            current = current.next
        print("NULL")

if __name__ == "__main__":
    l = LinkedList()
