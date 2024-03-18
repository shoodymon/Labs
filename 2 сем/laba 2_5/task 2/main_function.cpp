﻿#include "pack.h"
#include "prototypes.h"

void main_function(vec& main_vector,arr& sort_array)
{
	Actions actions{};
	
	main_vector.resize(get_arr_size());
	fill_arr_with_random(main_vector);
	set_sort(sort_array);

	int answer{};
	do
	{
		std::cout
			<< "1) Выбрать сортировку\n"
			<< "2) Я хочу вывести матрицу\n"
			<< "3) Я хочу выйти\n\n"
			<< "Выбор: ";
		std::cin >> answer;

		switch (answer)
		{
		case(SORT):		sorting(main_vector,sort_array,actions);	 break;
		case(PRINT):	print_sorted_arr(main_vector);				 break;
		case(EXIT):													 break;
		}	

	} while (answer != EXIT);
}