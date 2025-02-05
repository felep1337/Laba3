        set xlabel "Размер массива"
        set ylabel "Время (секунды)"
        set title "Сравнение времени работы сортировок"
	  	set logscale x 10
    		set logscale y 10

        # Чтение данных из файла
        plot "data.txt" using 1:2 with linespoints title "std::sort", \
             "data.txt" using 1:3 with linespoints title "qsort", \
             "data.txt" using 1:4 with linespoints title "Bubble Sort"
		pause -1
    