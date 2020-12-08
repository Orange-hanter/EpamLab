#include <vector>
using std::vector;

template< typename T>
void merge_sort(T& array, int begin, int end) {

    if (begin == end) {
        return;
    }

    int mid = (begin + end) / 2;

    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);

    T t;
    for (int i = begin, j = mid + 1; i <= mid || j <= end;) {
        if (i > mid) {
            pushBack(t, array[j++]);
        } else if (j > end) {
            pushBack(t, array[i++]);
        } else if (array[i] <= array[j]) {
            pushBack(t, array[i++]);
        } else {
            pushBack(t, array[j++]);
        }
    }

    for (int i = 0; i < t.size(); i++) {
        array[begin + i] = t[i];
    }
}

//template<typename Container, typename T>
//void pushBack(Container& container, T& value);

template<typename T>
void pushBack(vector<T>& container, T& value){
    container.push_back(value);
}
