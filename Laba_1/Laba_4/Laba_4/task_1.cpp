/*
�������:
� ��������� �������� ������ �� 15 ��������� ���� integer � ���������������� ������, ����������� ��������� �������, ����������������� �� �����������������:
    - ���������� ��������� ����������������� ����������: void input(arr, LEN)
    - ����� �������� �������: void print(arr, LEN)
    - ���������� ������������ ��������: int min(arr, LEN)
    - ���������� ������������� ��������: int max(arr, LEN)
    - ���������� ������� (�������������): void sort(arr, LEN)
    - ������� ����� �������� ��������� �������: int sum(arr, LEN)
    - ���������� �������� �������� ��������� �������: float sr(arr, LEN)
*/

#include <iostream>

using namespace std;


void input(int arr[], int LEN);
void print(int arr[], int LEN);
int min(int arr[], int LEN);
int max(int arr[], int LEN);
void sort(int arr[], int LEN);
int sum(int arr[], int LEN);
float sr(int arr[], int LEN);


int main() {

    setlocale(0, "");

    const int LEN = 15;
    int arr[LEN] = {}; // ������������� ������� ������

    input(arr, LEN);
    print(arr, LEN);

    cout << "����������� ��������: " << min(arr, LEN) << endl;
    cout << "������������ ��������: " << max(arr, LEN) << endl;

    sort(arr, LEN);
    cout << "��������������� ������: ";
    print(arr, LEN);

    int sumValue = sum(arr, LEN);
    cout << "����� ��������: " << sumValue << endl;

    float avgValue = sr(arr, LEN);
    cout << "������� ��������: " << avgValue << endl;

    return 0;
}

// ���� ���������������� ��������
void input(int arr[], int LEN) {
    cout << "������� " << LEN << " ��������� �������: " << endl;
    for (int i = 0; i < LEN; i++) {
        cin >> arr[i];
    }
}

// ����� �������� ������� 
void print(int arr[], int LEN) {
    cout << "�������� �������: ";
    for (int i = 0; i < LEN; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ���������� ������������ �������� � �������
int min(int arr[], int LEN) {
    int min = arr[0];
    for (int i = 1; i < LEN; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// ���������� ������������� �������� � �������
int max(int arr[], int LEN) {
    int max = arr[0];
    for (int i = 1; i < LEN; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// C�������� ������, ��������� �������� "�����������" ����������
void sort(int arr[], int LEN) {
    for (int i = 0; i < LEN - 1; i++) {
        for (int j = 0; j < LEN - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ��������� ����� �������� ��������� �������
int sum(int arr[], int LEN) {
    int sum = 0;
    for (int i = 0; i < LEN; i++) {
        sum += arr[i];
    }
    return sum;
}

// ��������� ������� �������� ��������� �������
float sr(int arr[], int LEN) {
    return (float)sum(arr, LEN) / LEN;
}
