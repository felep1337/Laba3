
        set xlabel "������ �������"
        set ylabel "����� (�������)"
        set title "��������� ������� ������ ����������"
        set key top right
        set style data linespoints
		set logscale x 10
    	set logscale y 10

        # ������ ������ �� �����
        plot "data.txt" using 1:2 with linespoints title "sort", \
             "data.txt" using 1:3 with linespoints title "merge", \
             "data.txt" using 1:4 with linespoints title "comb"
		pause -1
    