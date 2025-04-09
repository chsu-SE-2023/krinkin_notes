// Заполнить двумерный квадарный массив размером N числами от одного до n квадат по спирали

// Не трудно заметить что циклически повторяется процесс заполнения - вправо, вниз, влево, вверх. Единственное что меняеся - от какого до какого элемента осуществлять проход.
// Для этого заведём четыре переменные left, right, up, down. 
// Влево всегда движемся по строке с номером up от left до right
// Вниз движемся по столбцу right от up до down и тд
// Когда проходим одну из строк или столбцов, одну из границ требуется изменить

#include <iostream>

int main(){
    const int n=10;
    int left=0, right=n-1, up=0, down=n-1;

    int arr[n][n];
    int num=1;
    while (num<=n*n) {
        for (int j=left;j<=right;j++)
            arr[up][j]=num++;
        up++;
        for (int i=up;i<=down;i++)
            arr[i][right]=num++;
        right--;
        for (int j=right;j>=left;j--)
            arr[down][j]=num++;
        down--;
        for (int i=down;i>=up;i--)
            arr[i][left]=num++;
        left++;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            std::cout.width(4);
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}