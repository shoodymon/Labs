#include "prototypes.h"
#include "pack.h"

void bubble_sort(vec& main_vector, Actions& result) {
   steady_clock::time_point start_time = start_timer();

    for (int i = 0; i < main_vector.size() - 1; i++) {
        for (int j = 0; j < main_vector.size() - i - 1; j++) {
            result.comparisons++;
            if (main_vector.at(j) > main_vector.at(j + 1)) {
                swap(main_vector.at(j), main_vector.at(j + 1));
                result.swaps++;
            }
        }
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "����� ����������� ����������: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
    reset(result);
}

void shaker_sort(vec& main_vector,  Actions& result) {
    steady_clock::time_point start_time = start_timer();

    bool swapped = true;
    int start = 0;
    int end = main_vector.size() - 1;

    while (swapped) {
        swapped = false;

        // ������ ����� �������
        for (int i = start; i < end; ++i) {
            if (main_vector.at(i) > main_vector.at(i + 1)) {
                swap(main_vector.at(i), main_vector.at(i + 1));
                swapped = true;
                result.swaps++;
            }
            result.comparisons++;
        }

        if (!swapped) // ���� �� ���� ������������, �� ������ ��� ������������
            break;

        swapped = false;

        // ��������� ������ �������
        --end;

        // ������ ������ ������
        for (int i = end - 1; i >= start; --i) {
            if (main_vector.at(i) > main_vector.at(i + 1)) {
                swap(main_vector.at(i), main_vector.at(i + 1));
                swapped = true;
                result.swaps++;
            }
            result.comparisons++;
        }

        // ����������� ����� �������
        ++start;
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "����� ��������� ����������: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
    reset(result);
}

void dwarves_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    int index = 0;  while (index < main_vector.size()) {
        if (index == 0)
            index++;
        if (main_vector[index] >= main_vector[index - 1]) {
            index++;
            result.comparisons++;
        }

        else {
            swap(main_vector[index], main_vector[index - 1]);
            index--;
            result.swaps++;
        }
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "����� ������� ����������: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
    reset(result);
}

void inserts_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    for (int i = 1; i < main_vector.size(); i++) {
        int key = main_vector.at(i);
        int j = i - 1;
        while (j >= 0 && main_vector.at(j) > key) {
            main_vector.at(j + 1) = main_vector.at(j);
            j--;
            result.comparisons++;
            result.swaps++;
        }
        main_vector.at(j + 1) = key;
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "����� ���������� ���������: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
    reset(result);
}

void selection_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    for (int i = 0; i < main_vector.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < main_vector.size(); j++) {
            if (main_vector.at(j) < main_vector.at(min_index)) {
                min_index = j;
                result.comparisons++;
            }
        }
        swap(main_vector.at(i), main_vector.at(min_index));
        result.swaps++;
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "����� ���������� �������: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
    reset(result);
}

void shell_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();

    for (int step = main_vector.size() / 2; step > 0; step /= 2) {
        for (int i = step; i < main_vector.size(); i++) {
            for (int j = i; j >= step && main_vector.at(j - step) > main_vector.at(j); j -= step) {
                swap(main_vector[j], main_vector[j - step]);
                result.swaps++;
                result.comparisons++;
            }
        }
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "����� ���������� �����: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
    reset(result);
}

void recursive_sort(vec& main_vector, int left, int right, Actions& result) {
    int pivot; // ����������� �������
    int index; // ������ ������������ ��������
    int l_hold = left; // ����� �������
    int r_hold = right; // ������ �������
    pivot = main_vector.at(left);

    // ���� ������� �� ���������
    while (left < right) {
        while ((main_vector.at(right) > pivot) && (left < right)) {
            result.comparisons++; // ����������� ������� ���������
            right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
        }

        // ���� ������� �� ����������
        if (left != right) {
            main_vector.at(left) = main_vector.at(right); // ���������� ������� [right] �� ����� ������������
            result.swaps++; // ����������� ������� ������������
            left++; // �������� ����� ������� ������
        }

        while ((main_vector.at(left) < pivot) && (left < right)) {
            result.comparisons++; // ����������� ������� ���������
            left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
        }

        // ���� ������� �� ����������
        if (left != right) {
            main_vector.at(right) = main_vector.at(left); // ���������� ������� [left] �� ����� [right]
            result.swaps++; // ����������� ������� ������������
            right--; // �������� ������ ������� �����
        }
    }

    main_vector.at(left) = pivot; // ������ ����������� ������� �� �����
    index = left;
    left = l_hold;
    right = r_hold;

    if (left < index) // ���������� �������� ���������� ��� ����� � ������ ����� �������
        recursive_sort(main_vector, left, index - 1, result);
    if (right > index)
        recursive_sort(main_vector, index + 1, right, result);
}

void recursive_sort_with_timer(vec& main_vector,  Actions& result) {
    steady_clock::time_point start_time = start_timer();
    recursive_sort(main_vector, 0, main_vector.size() - 1, result);
    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "����� ����������� ����������: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
    reset(result);
}

void hoara_sort(vec& main_vector, int first, int last, Actions& result) {
    int i = first, j = last;
    int pivot = main_vector.at((first + last) / 2); // ����� �������� �������� ���������� �������

    do {
        // ����� �������� � ����� �����, ������� ������ ��� ����� ��������
        while (main_vector.at(i) < pivot) {
            i++;
            result.comparisons++;
        }

        // ����� �������� � ������ �����, ������� ������ ��� ����� ��������
        while (main_vector.at(j) > pivot) {
            j--;
            result.comparisons++;
        }

        // ���������� ����� ���������
        if (i <= j) {
            if (i < j) {
                swap(main_vector.at(i), main_vector.at(j));
                result.swaps++;
            }
            i++;
            j--;
        }
    } while (i <= j);

    // ����������� ����� ��� ���������� ������ ����� �������
    if (i < last)
        hoara_sort(main_vector, i, last, result);

    // ����������� ����� ��� ���������� ����� ����� �������
    if (first < j)
        hoara_sort(main_vector, first, j, result);
}

void hoara_sort_with_timer(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();
    hoara_sort(main_vector, 0, main_vector.size() - 1, result);
    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "����� ���������� �����: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
    reset(result);
}

void merge(vec& main_vector, int left, int middle, int right, Actions& result) {
    // ��������� ������� ���� �����������
    int size1 = middle - left + 1;
    int size2 = right - middle;

    // ������� ��������� ������� ��� �������� ������ � ������� �����������
    vector<int> left_arr(size1), right_arr(size2);

    // �������� ������ �� ��������� ������� �� ��������� �������
    for (int i = 0; i < size1; i++)
        left_arr.at(i) = main_vector.at(left + i);
    for (int j = 0; j < size2; j++)
        right_arr.at(j) = main_vector.at(middle + 1 + j);

    // ������� ��� ������ ������, ������� � ��������� ��������
    int i = 0, j = 0, k = left;

    // ������� ���� ��������� �������� � ���� �������� ������
    while (i < size1 && j < size2) {
        result.comparisons++;
        if (left_arr.at(i) <= right_arr.at(j)) {
            main_vector.at(k) = left_arr.at(i);
            i++;
            result.swaps++;
        }
        else {
            main_vector.at(k) = right_arr.at(j);
            j++;
            result.swaps++;
        }
        k++;
    }

    // ���������� ���������� �������� �� ������ ���������� �������, ���� ����� ����
    while (i < size1) {
        main_vector.at(k) = left_arr.at(i);
        i++;
        k++;
        result.swaps++;
    }

    // ���������� ���������� �������� �� ������� ���������� �������, ���� ����� ����
    while (j < size2) {
        main_vector.at(k) = right_arr.at(j);
        j++;
        k++;
        result.swaps++;
    }
}

void merging_sort(vec& main_vector, Actions& result) {
    steady_clock::time_point start_time = start_timer();
    int len = main_vector.size();

    int current_size;
    int left_start;

    // ���� �� ����������� ��������� �������
    for (current_size = 1; current_size <= main_vector.size() - 1; current_size = 2 * current_size) {
        // ���� �� ����������� �������� �������
        for (left_start = 0; left_start < main_vector.size() - 1; left_start += 2 * current_size) {
            // ������� �������� � ����� ������� ����������
            int middle = min(left_start + current_size - 1,len - 1);
            int right_end = min(left_start + 2 * current_size - 1, len - 1);

            // �������� ������� ������� ��� ������� �����������
            merge(main_vector, left_start, middle, right_end, result);
        }
    }

    steady_clock::time_point end_time = end_timer();
    print_sorted_arr(main_vector);
    cout << "����� ���������� ��������: " << duration_time(start_time, end_time) << " �����������" << endl;
    cout << "���������: " << result.comparisons << endl;
    cout << "������������: " << result.swaps << endl;
    reset(result);
}

void null_sort(vec& main_vector, Actions& result)
{

}

void set_sort(arr& sort_array)
{
    sort_array = 
    {
        null_sort,
        bubble_sort,
        shaker_sort,
        dwarves_sort,
        inserts_sort,
        selection_sort,
        shell_sort,
        recursive_sort_with_timer,
        hoara_sort_with_timer,
        merging_sort
    };
}

void sorting(vec& main_vector, arr& sort_array, Actions actions)
{
    int choice{};
    do
    {
        print_sorted_arr(main_vector);

        cout << "\n\t�������� ������� ����������:" << endl;
        cout << "\t1. ���������� ���������" << endl;
        cout << "\t2. ��������� ����������" << endl;
        cout << "\t3. ������ ����������" << endl;
        cout << "\t4. ���������� ���������" << endl;
        cout << "\t5. ���������� �������" << endl;
        cout << "\t6. ���������� �����" << endl;
        cout << "\t7. ����������� ����������" << endl;
        cout << "\t8. ���������� �����" << endl;
        cout << "\t9. ���������� ��������" << endl;
        cout << "\t10. ����� � ����" << endl;
        cout << "\t������� ����� (1-9): \t";

        std::cin >> choice;

        if (choice > 0 and choice < sort_array.size())
        {
            Sort_func fcn = sort_array.at(choice);
            fcn(main_vector, actions);
        }
        else if (choice == 10)
            break;
        else std::cout << "�������� ������!";

        fill_arr_with_random(main_vector);

    } while (choice != 10);
}






