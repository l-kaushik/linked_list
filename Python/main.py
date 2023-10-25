
class Node:
    def __init__(self, data = None) -> None:
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self, input_string = None):
        self.head = None
        self.size = 0

        if input_string:
            for char in input_string:
                self.append(char)
    
    # Insertion Operations

    def append(self, data):
        ''' insert a single value at the end of the linked list'''
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.size += 1
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
            self.size += 1
    
    def prepend(self, data):
        ''' insert a single value at first index of the linked list'''
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.size += 1
        else:
            new_node.next = self.head
            self.head = new_node
            self.size += 1
    
    def insert(self, index, data):
        ''' insert a single value at a given position or index of the linked list'''
        index = self._format_index(index)

        if index == 0:
            self.prepend(data)
            return
        
        counter = 0
        current = self.head
        prev = current
        new_node = Node(data)
        
        while(counter < index):
            if not current:
                prev.next = new_node
                new_node.next = current
                self.size += 1
                return
            else:
                prev = current
                current = current.next
                counter = counter + 1

        new_node.next = current
        prev.next = new_node
        self.size += 1
    
    def extend(self, _list):
        ''' append elements of a list or tuple at the end of the linked list'''
        new_node = Node(_list[0])
        # if head is None
        if not self.head:
            self.head = new_node
            self.size += 1
            current = self.head
            for i in range(1,len(_list)):
                current.next = Node(_list[i])
                current = current.next
                self.size += 1
        # if head is not None then traverse to last node then start appending 
        else:
            current = self.head
            while current.next:
                current = current.next
            for element in _list:
                current.next = Node(element)
                current = current.next
                self.size += 1

    # Deletion Operations
    def removeFirst(self) -> int:
        data = self.head.data
        self.head = self.head.next
        self.size -= 1
        return data

    def removeAt(self, index) -> int:
        index = self._format_index(index)
        counter = 0
        current = self.head
        prev = current

        if(index == 0):
            return self.removeFirst()

        while(counter < index):
            if not current:
                raise IndexError("Index out of range")
            else:
                prev = current
                current = current.next
                counter += 1
        data = current.data
        prev.next = current.next
        return data
    
    def removeLast():
        pass
    
    def _format_index(self,index: int) -> int:
        if index < 0:
            index = self.size + index
            if index < 0:
                raise IndexError("Index out of range")
        return index

    def _generate_output(self) -> str:
        '''This function will generate output string of the linked list'''
        current = self.head
        elements = ''
        while current:
            elements = elements + str(current.data) + ' -> '
            current = current.next
        elements = elements + 'None'
        return elements

    def display(self):
        print(self._generate_output())

    # Dunder methods
    def __str__(self):
        return self._generate_output()
    
    # making linked list subscriptable
    def __setitem__(self, index, value):
        self.insert(index, value)

    def __getitem__(self, index):
        index = self._format_index(index)
        counter = 0
        current = self.head
        while(counter < index):
            if not current.next:
                return current.data
            current = current.next 
            counter += 1
        return current.data

if __name__ == "__main__":
    l = LinkedList()
    l.append(33)
    l.extend([1,2,3,4,5,6,7,8])
    l.prepend(999)
    l[-1] = 1023
    print(l.removeAt(345))
    l.display()