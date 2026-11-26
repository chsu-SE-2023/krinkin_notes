#include <mpi.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <chrono>

const int ARRAY_SIZE = 2380240;
const int MAX_STR_LEN = 32;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (ARRAY_SIZE % size != 0) {
        if (rank == 0) {
            std::cerr << "ARRAY_SIZE (" << ARRAY_SIZE << ") не делится нацело на число процессов (" << size << ")\n";
        }
        MPI_Finalize();
        return 255;
    }

    int chunk_size = ARRAY_SIZE / size;

    MPI_Datatype str_type;
    MPI_Type_contiguous(MAX_STR_LEN, MPI_CHAR, &str_type);
    MPI_Type_commit(&str_type);

    MPI_Datatype chunk_type;
    MPI_Type_vector(chunk_size, 1, 1, str_type, &chunk_type);
    MPI_Type_commit(&chunk_type);

    std::vector<char> flat_array; // Массив символов всех строк
    std::vector<char> local_flat_chunk(chunk_size * MAX_STR_LEN, '\0'); // Буфер для процесса
    char target_buf[MAX_STR_LEN] = {0}; // Буфер для искомого
    auto start = std::chrono::high_resolution_clock::now();

    int pack_size = 0;
    if (rank == 0) {
        std::vector<std::string> students_ = {
            "Смирнов", "Иванов", "Кузнецов", "Соколов", "Попов", "Лебедев", "Козлов", "Новиков", "Морозов", "Петров", "Волков", "Соловьёв", "Васильев", "Зайцев", "Павлов",
            "Семёнов", "Голубев", "Виноградов", "Богданов", "Воробьёв", "Фёдоров", "Михайлов", "Беляев", "Тарасов", "Белов", "Комаров", "Орлов", "Киселёв", "Макаров",
            "Андреев", "Ковалёв", "Ильин", "Гусев", "Титов", "Кузьмин", "Кудрявцев", "Баранов", "Куликов", "Алексеев", "Степанов", "Яковлев", "Сорокин", "Сергеев",
            "Романов", "Захаров", "Борисов", "Королёв", "Герасимов", "Пономарёв", "Григорьев", "Лазарев", "Медведев", "Ершов", "Никитин", "Соболев", "Рябов", "Поляков",
            "Цветков", "Данилов", "Жуков", "Фролов", "Журавлёв", "Николаев", "Крылов", "Максимов", "Сидоров", "Осипов", "Белоусов", "Федотов", "Дорофеев", "Егоров",
            "Матвеев", "Бобров", "Дмитриев", "Калинин", "Анисимов", "Петухов", "Антонов", "Тимофеев", "Никифоров", "Веселов", "Филиппов", "Марков", "Большаков", "Суханов",
            "Миронов", "Ширяев", "Александров", "Коновалов", "Шестаков", "Казаков", "Ефимов", "Денисов", "Громов", "Фомин", "Давыдов", "Мельников", "Щербаков", "Блинов",
            "Колесников", "Карпов", "Афанасьев", "Власов", "Маслов", "Исаков", "Тихонов", "Аксёнов", "Гаврилов", "Родионов", "Котов", "Горбунов", "Кудряшов", "Быков",
            "Зуев", "Третьяков", "Савельев", "Панов", "Рыбаков", "Суворов", "Абрамов", "Воронов", "Мухин", "Архипов", "Трофимов", "Мартынов", "Емельянов", "Горшков",
            "Чернов", "Овчинников", "Селезнёв", "Панфилов", "Копылов", "Михеев", "Галкин", "Назаров", "Лобанов", "Лукин", "Беляков", "Потапов", "Некрасов", "Хохлов",
            "Жданов", "Наумов", "Шилов", "Воронцов", "Ермаков", "Дроздов", "Игнатьев", "Савин", "Логинов", "Сафонов", "Капустин", "Кириллов", "Моисеев", "Елисеев",
            "Кошелев", "Костин", "Горбачёв", "Орехов", "Ефремов", "Исаев", "Евдокимов", "Калашников", "Кабанов", "Носков", "Юдин", "Кулагин", "Лапин", "Прохоров",
            "Нестеров", "Харитонов", "Агафонов", "Муравьёв", "Ларионов", "Федосеев", "Зимин", "Пахомов", "Шубин", "Игнатов", "Филатов", "Крюков", "Рогов", "Кулаков",
            "Терентьев", "Молчанов", "Владимиров", "Артемьев", "Гурьев", "Зиновьев", "Гришин", "Кононов", "Дементьев", "Ситников", "Симонов", "Мишин", "Фадеев",
            "Комиссаров", "Мамонтов", "Носов", "Гуляев", "Шаров", "Устинов", "Вишняков", "Евсеев", "Лаврентьев", "Брагин", "Константинов", "Корнилов", "Авдеев", "Зыков",
            "Бирюков", "Шарапов", "Никонов", "Щукин", "Дьячков", "Одинцов", "Сазонов", "Якушев", "Красильников", "Гордеев", "Самойлов", "Князев", "Беспалов", "Уваров",
            "Шашков", "Бобылёв", "Доронин", "Белозёров", "Рожков", "Самсонов", "Мясников", "Лихачёв", "Буров", "Сысоев", "Фомичёв", "Русаков", "Стрелков", "Гущин"
        };
        std::vector<std::string> students;
        students.reserve(ARRAY_SIZE);

        for (int i = 0; i < 5001; i++) {
            students.insert(students.end(), students_.begin(), students_.end());
        }
        students.push_back("Савкина");
        for (int i = 0; i < 5000; i++) {
            students.insert(students.end(), students_.begin(), students_.end());
        }
        students.push_back("Яичков");

        std::string target;
        std::cout << "Введите фамилию:\n";
        std::cin >> target;
        std::strncpy(target_buf, target.c_str(), MAX_STR_LEN - 1);

        flat_array.resize(ARRAY_SIZE * MAX_STR_LEN, '\0');
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            std::strncpy(&flat_array[i * MAX_STR_LEN], students[i].c_str(), MAX_STR_LEN - 1);
        }

        std::cout << "Поиск " << size << " процессами...\n";
        start = std::chrono::high_resolution_clock::now();

        // Оцениваем верхнюю границу размера упакованного буфера:
        // 1 элемент str_type (искомая фамилия) + ARRAY_SIZE элементов str_type (все строки)
        int s1 = 0, s2 = 0;
        MPI_Pack_size(1, str_type, MPI_COMM_WORLD, &s1);
        MPI_Pack_size(ARRAY_SIZE, str_type, MPI_COMM_WORLD, &s2);
        pack_size = s1 + s2;
    }

    // Сообщаем всем процессам размер упакованного буфера
    MPI_Bcast(&pack_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

    std::vector<char> packed_buf(pack_size);
    int position = 0;

    if (rank == 0) {
        // Упаковываем искомое слово и весь массив строк в единый буфер
        MPI_Pack(target_buf, 1, str_type, packed_buf.data(), pack_size, &position, MPI_COMM_WORLD);
        MPI_Pack(flat_array.data(), ARRAY_SIZE, str_type, packed_buf.data(), pack_size, &position, MPI_COMM_WORLD);
    }

    // Передаём упакованный буфер всем процессам как единый блок MPI_PACKED
    MPI_Bcast(packed_buf.data(), pack_size, MPI_PACKED, 0, MPI_COMM_WORLD);

    // Распаковываем у каждого процесса: сначала целевую строку
    position = 0;
    MPI_Unpack(packed_buf.data(), pack_size, &position, target_buf, 1, str_type, MPI_COMM_WORLD);
    std::string local_target(target_buf);

    // Пропускаем в упакованном потоке блоки строк до своего rank (каждый блок — 1 chunk_type)
    std::vector<char> skipped_chunk(chunk_size * MAX_STR_LEN);
    for (int r = 0; r < rank; ++r) {
        MPI_Unpack(packed_buf.data(), pack_size, &position, skipped_chunk.data(), 1, chunk_type, MPI_COMM_WORLD);
    }
    // Распаковываем свой собственный блок строк размером 1 chunk_type
    MPI_Unpack(packed_buf.data(), pack_size, &position, local_flat_chunk.data(), 1, chunk_type, MPI_COMM_WORLD);

    int local_index = -1;
    for (int i = 0; i < chunk_size; ++i) {
        std::string current_word(&local_flat_chunk[i * MAX_STR_LEN]);

        if (current_word == local_target) {
            local_index = (rank * chunk_size) + i;
            break;
        }
    }

    std::vector<int> results_by_rank;
    if (rank == 0) {
        results_by_rank.resize(size);
    }

    MPI_Gather(&local_index, 1, MPI_INT,
               results_by_rank.data(), 1, MPI_INT,
               0, MPI_COMM_WORLD);

    if (rank == 0) {
        bool found = false;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        for (int proc_rank = 0; proc_rank < size; ++proc_rank) {
            if (results_by_rank[proc_rank] != -1) {
                std::cout << "Процесс " << proc_rank << " нашёл по индексу: " << results_by_rank[proc_rank] << " за " << duration.count() << " микросек\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "Не найдено за " << duration.count() << " микросек\n";
        }
    }

    MPI_Type_free(&chunk_type);
    MPI_Type_free(&str_type);
    MPI_Finalize();
    return 0;
}
