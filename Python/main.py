
class Node:
    def __init__(self, data = None) -> None:
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self, input_string = None):
        self.head = None
        if input_string:
            for char in input_string:
                self.append(char)
    
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
    
    def extend(self, _list):
        ''' append elements of a list or tuple at the end of the linked list'''
        new_node = Node(_list[0])
        # if head is None
        if not self.head:
            self.head = new_node
            current = self.head
            for i in range(1,len(_list)):
                current.next = Node(_list[i])
                current = current.next
        # if head is not None then traverse to last node then start appending 
        else:
            current = self.head
            while current.next:
                current = current.next
            for element in _list:
                current.next = Node(element)
                current = current.next

    def _generate_output(self):
        current = self.head
        elements = ''
        while current:
            elements = elements + str(current.data) + ' -> '
            current = current.next
        elements = elements + 'None'
        return elements

    def display(self):
        print(self._generate_output())

    # dunder methods
    def __str__(self):
        return self._generate_output()

if __name__ == "__main__":
    l = LinkedList()
    l.append(33)
    l.extend([1,2,3,4,5,6,7,8])
    l.display()
    print(LinkedList("hello"))