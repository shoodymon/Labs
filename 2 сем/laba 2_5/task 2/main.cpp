#include "pack.h"
#include "prototypes.h"


int main() {
    setlocale(0, "");
    system("chcp 1251");
    system("cls");

    int size = get_arr_size();
    vec main_vector{};
    fill_arr_with_random(main_vector);
    Actions result = { 0, 0 };

    return 0;
}