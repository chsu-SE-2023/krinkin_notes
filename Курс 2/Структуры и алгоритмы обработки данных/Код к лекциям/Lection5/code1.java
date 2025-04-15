public int makeWave(int a, int b) {
    int path[] = new int[size+1];
    for (int i = 1; i <= size; i++) path[i] = -1 // Заполнение путей -1;
    path[a] = 0; // Начальная метка
    int num = 1, i = 1; // num - номер текущей метки
    boolean f = false, f1 = true; // f - флаг посещения, f1 - существуют ли непосещённые
    do {
        while (i <= size && path[i] != num-1) i++; // Поиск предыдущей метки
        if (i <= size) {
            f = true;
            for (int j = 1; j <= size; j++)
                // gr - матрица смежности, path - массив меток
                if (gr[i][j] == 1 & path[j] == -1) path[j] = num; // Присвоение метки
            i++;
        }
        else {
            if (f) {i = 1; f = false; num++;} else f1 = false;
        }
    }
    while (f1);
    return path[b];
}