#include <iostream>

using namespace std;

void towerOfHanoi(int n, char sourceRod, char auxiliaryRod, char destinationRod) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << sourceRod << " to rod " << destinationRod << endl;
        return;
    }
    
    // Move n-1 disks from source to auxiliary rod using destination as the auxiliary
    towerOfHanoi(n - 1, sourceRod, destinationRod, auxiliaryRod);
    
    // Move the nth disk from source to destination rod
    cout << "Move disk " << n << " from rod " << sourceRod << " to rod " << destinationRod << endl;
    
    // Move the n-1 disks from auxiliary to destination rod using source as the auxiliary
    towerOfHanoi(n - 1, auxiliaryRod, sourceRod, destinationRod);
}

int main() {
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;
    
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    
    return 0;
}
