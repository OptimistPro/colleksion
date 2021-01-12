#include <iostream>

using namespace std;


class Col_person {

    struct __MyStruct

    {
        string  name="";

        string f_name="";

        int age;
        __MyStruct* next;

        __MyStruct* prev;

    };

private:

    __MyStruct* first;

    __MyStruct* last;

    __MyStruct* poisk;

    int count = 0;

public:
    Col_person() {

        first = NULL; 

        last = NULL;

        poisk = NULL;
    }

    void Insert(int nomer, string name, string f_name,int age) {
        __MyStruct* ptr_preson;
        ptr_preson = new struct __MyStruct;
        ptr_preson->age = age;
        ptr_preson->name = name;
        ptr_preson->f_name = f_name;

        
        if (first==NULL){
            ptr_preson->next = NULL;
            ptr_preson->prev = NULL;
            first = ptr_preson;
        }
        else if (last == NULL) {
            ptr_preson->next = NULL;
            ptr_preson->prev = first;
            last = ptr_preson;
            first->next = last;
        }
        else {
            if (nomer < count) {
                poisk = first;
                for (int i = 0; i < nomer; i++) {
                    poisk = poisk->next;
                }
                ptr_preson->next = poisk;
                ptr_preson->prev = poisk->prev;
                poisk->prev = ptr_preson;
                if (nomer <= 0) {
                    first = ptr_preson;
                }
            }
            else {
                ptr_preson->next = NULL;
                ptr_preson->prev = last;
                last->next = ptr_preson;
                last = ptr_preson;
            }
        }
        count++;  
    }

    void delet(int index) {
        if (index < count) {
            poisk = first;
            for (int i = 0; i < index; i++) {
                poisk = poisk->next;
            }
            poisk->prev->next = poisk->next;
            poisk->next->prev = poisk->prev;
            delete poisk;
        }
        else {
            last = last->prev;
            delete last->next;
            last->next= NULL;
        }
        count--;
    }

    __MyStruct* get(int index) {
        if (index < count) {
            poisk = first;
            for (int i = 0; i < index; i++) {
                poisk = poisk->next;
            }
            return poisk;
        }
        else {
            return NULL;
        }
        
    }

    bool set(int index, string name ="", string f_name="",int age=0) {
        if (index < count) {
            poisk = first;
            for (int i = 0; i < index; i++) {
                poisk = poisk->next;
            }
            if (name != "") {
                poisk->name = name;
            }
            if (f_name != "") {
                poisk->f_name = f_name;
            }
            if (age != 0) {
                poisk->age = age;
            }
            return true;
        }
        else {
            return false;
        }
        
    }

    int Count() {
        return count;
    }
};

int main()
{
    //Тесты
    Col_person col;

    //добавляем элементы
    col.Insert(0, "test1", "test1", 120);
    col.Insert(1, "test2", "test2", 3);
    col.Insert(2, "test3", "test3", 5);
    col.Insert(7, "test4", "test4", 7);
    col.Insert(-1, "test5", "test5", 8);

    cout << "Source collection" << endl;

    for (int i = 0; i < col.Count(); i++) {
        cout << col.get(i)->name << " " << col.get(i)->f_name << " " << col.get(i)->age << endl;
    }

    //удаляем элемент
    col.delet(1);

    cout << "Collection after deletion" << endl;
    for (int i = 0; i < col.Count(); i++) {
        cout << col.get(i)->name << " " << col.get(i)->f_name << " " << col.get(i)->age << endl;
    }

    //заменяем данные
    col.set(1, "zamen","zamen");

    cout << "Collection after set function" << endl;
    for (int i = 0; i < col.Count(); i++) {
        cout << col.get(i)->name << " " << col.get(i)->f_name << " " << col.get(i)->age << endl;
    }
}