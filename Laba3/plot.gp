        set xlabel "������ �������"
        set ylabel "����� (�������)"
        set title "��������� ������� ������ ����������"
	  	set logscale x 10
    		set logscale y 10

        # ������ ������ �� �����
        plot "data.txt" using 1:2 with linespoints title "std::sort", \
             "data.txt" using 1:3 with linespoints title "qsort", \
             "data.txt" using 1:4 with linespoints title "Bubble Sort"
		pause -1
    