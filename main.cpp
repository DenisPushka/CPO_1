#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

struct Home {
    string street;
    double all_square;
    int number_of_tenants;
};

void initialization(int n, Home ar_home[]);

void print(int n, Home ar_home[]);

void print_in_txt(int n, Home ar_home[]);

/*list<Home> *selection_of_the_list_hours(int n, double s, Home ar_h[]);*/

// Home *convert(list<Home> l);

Home *need_initialization() {
    static Home need_ar[3];
    need_ar[0].street = "40 лет победы";
    need_ar[0].all_square = 4444.4444;
    need_ar[0].number_of_tenants = 444;
    need_ar[1].street = "10 лет октября";
    need_ar[1].all_square = 123.321;
    need_ar[1].number_of_tenants = 3;
    need_ar[2].street = "50 лет победы";
    need_ar[2].all_square = 444;
    need_ar[2].number_of_tenants = 4;
    return need_ar;
}

int main() {
    system("chcp 65001");

    /* auto brigade_number = 0;
     // cin >> brigade_number; // будем писать проверки?
     string array_student[] = {"Анисимов", "Барановский Д.А.", "Зверев"};

     cout << "\n\tБригада №" << brigade_number << endl;
     for (auto i: array_student)
         cout << "\t" << i << endl;

     printf("\t Бригада №%d\n", brigade_number);
     for (string i: array_student)
         printf_s("\t%s\n", i.data());


     int mas[] = {1, 2, 3};
     int mmm[] = {4, 5, 6};

     for (auto m: mas)
         printf(" %d,", m);
     for (auto m: mmm)
         printf(" %d,", m);*/

    auto count = 3;
    auto array_home = need_initialization();//new Home[count];
    // initialization(count, array_home);
    print(count, array_home);

    auto zx = 0;
    auto s = 0;
    cout << "\n\tЖилая площадь на одного жильца менее s, введите переменную s - ";
    cin >> s;

    auto list_hours = new list<Home>;
    for (auto i = 0; i < count; i++)
        if ((array_home[i].all_square / array_home[i].number_of_tenants) < s)
            list_hours->push_back(array_home[i]);

    Home ar[list_hours->size()];
    auto i = 0;
    for (auto l: *list_hours) {
        ar[i] = l;
        i++;
    }

    print(i, ar);
    print_in_txt(i, ar);
    delete[]array_home;
    // delete[]ar;
    return 0;
}

void initialization(int count, Home array_home[]) {
    for (auto i = 0; i < count; ++i) {
        printf("Дом %i. Введите улицу: ", i + 1);
        getline(cin, array_home[i].street);
        cout << "\n\tПлощадь квартиры: ";
        cin >> array_home[i].all_square;
        cout << "\n\tКол-во соседей: ";
        cin >> array_home[i].number_of_tenants;
        cin.ignore(32767, '\n');
    }
}

void print(int count, Home array_home[]) {
    for (auto i = 0; i < count; i++)
        printf("Дом: %d,\n\tулица: %s, площадь: %e, количество соседей: %i\n",
               i + 1, array_home[i].street.data(), array_home[i].all_square, array_home[i].number_of_tenants);
}

void print_in_txt(int n, Home ar_home[]) {
    ofstream fout("newFile.txt");
    for (auto i = 0; i < n; i++)
        fout << "Дом: " << i + 1
        << "\n\tулица: " << ar_home[i].street.data()
        << ", площадь: " << ar_home[i].all_square
        << ", количество соседей: " << ar_home[i].number_of_tenants << endl;
    fout.close();
}

/*Home *convert(list<Home> list){
    Home ar[list.size()];
    auto i = 0;
    for (auto l: list) {
        ar[i] = l;
        i++;
    }
    return ar;
}*/
/*
list<Home> *selection_of_the_list_hours(int count, int s, Home ar_h[]) {
    auto cnt = 0;
    auto list_hours = new list<Home>;
    for (auto i = 0; i < count; i++)
        if (s > (ar_h[i].all_square / ar_h[i].number_of_tenants)) {
            list_hours->push_back(ar_h[i]);
            cnt++;
        };
    return list_hours;
}*/