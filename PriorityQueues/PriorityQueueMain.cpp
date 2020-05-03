#include "MaxPQ.hpp"

int main() {
    int arr[] = {1,2,32,53, 0, 9, 29, 87,42,3,4};
    MaxPQ<int> test(arr, 11);
    test.print();
    cout << "is it empty should be false " << test.isEmpty() << "\nSize of PQ should be 11" << test.size() << "\nMax element should be 87: " << test.max();
    test.insert(78);
    test.insert(121);
    test.insert(3);
    cout << "\nSize should be 14: " << test.size() << "\nMax element should be 121 " << test.max() << "\n";
    test.print();
    cout << "removed element should be 121: " << test.deleteMax() << "\nnow 87: " << test.deleteMax() << "\nSize should be 12: " << test.size() << "\n";

    MaxPQ<int> testAgain;
    testAgain.print();
    testAgain.insert(76);
    testAgain.insert(23);
    testAgain.insert(455);
    testAgain.insert(34);
    testAgain.insert(87);
    testAgain.insert(56);

    cout << "is it empty should be false " << testAgain.isEmpty() << "\nSize of PQ should be 6: " << testAgain.size() << "\nMax element should be 455: " << testAgain.max();
    testAgain.insert(78);
    testAgain.insert(1521);
    testAgain.insert(3);
    cout << "\nSize should be 9: " << testAgain.size() << "\nMax element should be 1521 " << testAgain.max() << "\n";
    testAgain.print();
    cout << "removed element should be 1521: " << testAgain.deleteMax() << "\nnow 455: " << testAgain.deleteMax() << "\nSize should be 7: " << testAgain.size() << "\n";
}