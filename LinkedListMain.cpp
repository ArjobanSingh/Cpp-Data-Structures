#include "LinkedList.hpp"

int main()
{
    LinkedList<int> ll;
    cout << "size at first: " << ll.returnSize() << "\n";
    ll.addFirst(2);
    ll.addFirst(3);
    ll.addFirst(4);

    cout << "size after 3 additions: " << ll.returnSize() << "\n";
    cout << "Three elements are: ";
    ll.printList(); 
    cout << "\n";

    cout << "Deleted element is: " << ll.deleteFirst() << "\n";
    cout << "Deleted second element is: " << ll.deleteFirst() << "\n";
    cout << "Size after two deletions: " << ll.returnSize() << "\n";
    cout << "elements at last: ";
    ll.printList();
    ll.addLast(6);
    ll.addLast(7);
    cout << "\nAdded two more items, Total should be 3: " << ll.returnSize() << "\n";
    ll.printList();
    cout << "\n\n";
    cout << "Deleted last element should be 7: " << ll.deleteLast() << "\n";
    cout << "Deleted last element should be 6: " << ll.deleteLast() << "\n";
    ll.addFirst(15);
    ll.addFirst(11);
    ll.addLast(20);
    ll.addLast(22);
    cout << "Size should be 5: " << ll.returnSize() << "\n";
    ll.printList();
    cout << "\n\n";
    cout << "first element should be 11: " << ll.getFirst() << "\nlast element should be 22: " << ll.getLast() << "\n";
    cout << "Element at index 1 should be 15: " << ll.getElementAtPosition(1) << "\nelement at index 3 should be 20: "
        << ll.getElementAtPosition(3) << "\n"; 
    ll.updateElementAtPosition(50, 3);
    cout << "Now element at index 3 should be 50: " << ll.getElementAtPosition(3) << "\nsize should be same 5: " 
        << ll.returnSize() << "\n" << "All elements should be:\n";
    ll.printList();
    cout << "\n\n";
    ll.addNewElementAtPosition(100, 3);
    cout << "Now newly added element 100 should be at position 3: " << ll.getElementAtPosition(3) 
        << "\nsize should be increased by 1 reaching to 6: " << ll.returnSize() << "\n" 
        << "All elements should be:\n";
    ll.printList();    
    cout << "\n\n";
    for ( int i = 0; i < ll.returnSize(); i++)
    {
        cout << "Element at position: " << i << " is  " << ll.getElementAtPosition(i) << "\n";
    }
    return 0;
}