// Simple bag problem to understand generic programming and overloading concepts.


#include <iostream>
using namespace std;

template <class T>
class Bag
{
    T *item;
    int size;                        //current size of the Bag
    int maxSize;                     //maximum size of the Bag
    int getIndexOf(const T &number); //returns either the index of item that contains the given target or -1
public:
    Bag(int maxSize = 10);
    /*The Bag is empty with a maximum size given by the parameter.
    The insert function will work efficiently (without allocating new memory) until this capacity is reached.*/

    void resize(int newSize);
    /*The Bag's current capacity is  changed to new_capacity (but not less than the number of items currently in
    the Bag). The insert function will work efficiently without allocating new memory) until the maximum size is
    reached.*/

    void add(const T &newEntry);
    /*A new entry is added to the Bag. */

    void remove(const T &anEntry);
    /*If the entry is in the Bag, then one copy of the entry is removed from the Bag; otherwise the Bag is
    unchanged.*/

    int getFrequencyOf(const T &anEntry);
    /*returns the number of occurrences of the entry in the Bag.*/

    Bag<T> operator+(const Bag<T> &addend);
    /*returns the merged Bags*/

    void displayBag();

    ~Bag();
};

template <class T>
Bag<T>::Bag(int maxSize)
{
    this->maxSize = maxSize;
    item = new T[maxSize];
    this->size = 0;
}

template <class T>
int Bag<T>::getIndexOf(const T &number)
{
    for (int i = 0; i < size; i++)
        if (item[i] == number)
            return i;
    return -1;
}

template <class T>
void Bag<T>::resize(int newSize)
{
    if (newSize > maxSize)
    {
        T *temp = new T[newSize];
        for (int i = 0; i < maxSize; i++)
            temp[i] = item[i];
        delete []item;
        item = temp;
    }
    maxSize = newSize;
}

template <class T>
void Bag<T>::add(const T &newEntry)
{
    resize(++size);
    item[size-1] = newEntry;
}

template <class T>
void Bag<T>::remove(const T &anEntry)
{
    int index = getIndexOf(anEntry);
    if (index == -1)
        return;
    for (int i = index; i < size - 1; i++)
        item[i] = item[i + 1];
    size--;
}

template <class T>
int Bag<T>::getFrequencyOf(const T &anEntry)
{
    int frequency = 0;
    for (int i = 0; i < size; i++)
        if (anEntry == item[i])
            frequency++;
    return frequency;
}

template <class T>
Bag<T> Bag<T>:: operator+(const Bag<T> &addend)
{
    int finalSize = size + addend.size;
    resize(finalSize);
    for (int i = 0; i < addend.size; i++)
        item[i+size] = addend.item[i];
    size = finalSize;
}

template <class T>
void Bag<T>::displayBag()
{
    for (int i = 0; i < size; i++)
        cout << item[i] << "\t";
    cout << "\n\n";
}

template <class T>
Bag<T>::~Bag()
{
    delete []item;
}

int main()
{
    int i, choice, num;
    float ele;
    Bag<float> bag[2];
    cout << "Start filling the bag.\nType zero to exit\n";
    for (i = 0; i < 2; i++)
    {
        cout << "Bag " << i + 1 << endl;
        while (1)
        {
            cin >> ele;
            if (ele == 0)
                break;
            bag[i].add(ele);
        }
    }
    cout << "The elements in each bag\n\n";
    for (int i = 0; i < 2; i++)
    {
        cout << "Bag " << i + 1 << ":\t";
        bag[i].displayBag();
    }
    while (1)
    {
        cout << "1. To add an item to the bag" << endl
             << "2. To remove an item from the bag" << endl
             << "3. To find the frequency of an item in the bag" << endl
             << "4. To merge two bags" << endl
             << "5. To exit" << endl
             << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the bag number and the item to be added\n";
            cin >> num >> ele;
            cout << "After adding\n";
            bag[num - 1].add(ele);
            bag[num - 1].displayBag();
            break;

        case 2:
            cout << "Enter the bag number and the item to be removed\n";
            cin >> num >> ele;
            cout << "After removing\n";
            bag[num - 1].remove(ele);
            bag[num - 1].displayBag();
            break;

        case 3:
            cout << "Enter the bag number and the item to find its frequency\n";
            cin >> num >> ele;
            cout << ele << " is found " << bag[num - 1].getFrequencyOf(ele) << " times\n\n";
            break;

        case 4:
            cout << "After merging\n";
            bag[0] + bag[1];
            bag[0].displayBag();
            break;

        case 5:
            return 0;
            break;
        default:
            cout << "Invalid Choice!!\n";
            break;
        }
    }
}
