public class Deikstra {
    int[][] gr; // Матрица смежности
    int size;
    class Metka {
        int volume, type;
    }
    Metka[] m; // Массив меток
}

public int findPath(int a, int b) {
    m[a].volume = 0;
    m[a].type = 1;
    int i = a;
    // ^ Начальная метка

    for (int j = 1; j <= size; j++)
        if (j != i) { // Установка бесконечных меток
            m[j].volume = Integer.MAX_VALUE;
            m[j].type = 0;
        }
        while (i != b) {
            for (int j = 1; j <= size; j++) 
                if (gr[i][j] != 0 && m[j].type == 0) // Если путь есть и метка временная
                    if(m[j].volume > m[i].volume+gr[i][j]) {
                        m[j].volume = m[i].volume+gr[i][j]; // Пересчёт
                    }
            int min = Integer.MAX_VALUE, nmin = 0;
            for (int j = 1; j <= size; j++) 
                // Поиск минимальной метки
                if (m[j].volume < min && m[j].type == 0) {
                    min = m[j].volume;
                    nmin = j;
                }
            m[nmin].type = 1;
            i = nmin;
        }

    return m[b].volume;
}