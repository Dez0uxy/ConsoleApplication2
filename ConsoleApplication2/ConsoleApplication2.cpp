#include <iostream>

#include <cstdlib>

#include <ctime>


void randarr(int* arr, const int size) {

    for (int i = 0; i < size; i++) {

        arr[i] = rand() % 20 - 10;

    }

}


void printarr(int* arr, const int size) {

    for (int i = 0; i < size; i++) {

        std::cout << arr[i] << "\t";

    }

    std::cout << std::endl;

}


int product(int* arr, const int size) {

    int result = 1;

    for (int i = 0; i < size; i++) {

        if (arr[i] > 0) {

            result *= arr[i];

        }

    }

    return result;

}


int sum_first_second_null(int* arr, const int size) {

    int index_first = -1;

    int index_second = -1;

    int sum = 0;

    for (int i = 0; i < size; i++) {

        if (arr[i] == 0) {

            index_first = i;

            break;

        }

    }

    if (index_first == -1) {

        std::cout << "Нулi не знайдено" << std::endl;

        return 0;

    }

    else {

        for (int i = size - 1; i > index_first; i--) {

            if (arr[i] == 0) {

                index_second = i;

                break;

            }

        }

        if (index_second == -1) {

            std::cout << "Тiльки один нуль" << std::endl;

            return 0;

        }

    }

    for (int i = index_first + 1; i < index_second; i++) {

        sum += arr[i];
       
    }

    return sum;


}


void sort(int* arr, const int size) {

    int temp;

    for (int i = 0; i < size; i++) {

        if (arr[i] >= 0) {

            for (int j = 0; j < i; j++) {

                if (arr[j] < 0) {

                    temp = arr[i];

                    arr[i] = arr[j];

                    arr[j] = temp;

                }

            }

        }

    }

}


int main() {

    srand(time(NULL));

    setlocale(LC_ALL, "Ukrainian");

    int size;

    std::cout << "Введiть розмiр: ";

    std::cin >> size;

    int* arr = new int[size];

    randarr(arr, size);

    printarr(arr, size);

    sort(arr, size);

    printarr(arr, size);


    std::cout << "Сума елементiв мiж першим i останнiм нульовим елементом = " << sum_first_second_null(arr, size) << std::endl;

    std::cout << "Добуток = " << product(arr, size);

    delete[] arr;

    return 0;

}