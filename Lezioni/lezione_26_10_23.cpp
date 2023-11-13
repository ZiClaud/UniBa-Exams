#include <iostream>

using namespace std;

int main() {
    List_vector<int> list1, list2;
    List_vector<int>::position iter; // Definisce il tipo position

    int x;

    /* inserting three elements into the list list1 */
    x = 1;
    list1.insert(x, list1.begin());
    x = 2;
    list1.insert(x, list1.begin());
    x = 3;
    list1.insert(x, list1.begin());
    x = 4;
    list1.insert(x, list1.begin());

    /* visualizing the list list1 */
    cout << "list1=";
    cout << list1;

    /*
     * assigning the list list1 to the list list2.
     * Here we are using the operator =
     */
    list2 = list1;

    cout << "list2=";
    cout << list2;

    /// STUFF?

    if (list1 == list2) {
        cout << "list1 == list2" << endl;
    } else {
        cout << "list1 != list2" << endl;
    }
}
