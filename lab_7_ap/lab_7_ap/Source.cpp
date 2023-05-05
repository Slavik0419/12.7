#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string surname;
    string diagnosis;
    int queueTime;
};

struct Elem {
    Patient info;
    Elem* link;
};

void enqueue(Elem*& first, Elem*& last, Patient value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = nullptr;
    if (last != nullptr)
        last->link = tmp;
    last = tmp;
    if (first == nullptr)
        first = tmp;
}

Patient dequeue(Elem*& first, Elem*& last) {
    Elem* tmp = first->link;
    Patient value = first->info;
    delete first;
    first = tmp;
    if (first == nullptr)
        last = nullptr;
    return value;
}

int main() {
    Elem* first = nullptr;
    Elem* last = nullptr;

    // ���������� ����� ��������
    int interval = 5; // �������� ������� �������� � ��������
    int processingTime = 15; // ��� �������������� ������� �������� � ��������
    int maxWaitingTime = 0; // ������������ ��� ���������� �������� � ����
    int maxQueueLength = 0; // ����������� ������� ����� � ����
    int currentTime = 0;
    
    for (int i = 0; i < 4; i++) {
        Patient p;
        cout << "Enter patient's surname: ";
        cin >> p.surname;
        cout << "Enter patient's diagnosis: ";
        cin >> p.diagnosis;
        p.queueTime = currentTime;
        enqueue(first, last, p);
        currentTime += interval;
    }


    // �������������� �������� �� ���������� ������������� ���� ���������� �� ����������� ������� ����� � ����
    while (first != nullptr) {
        Patient p = dequeue(first, last);
        int waitingTime = currentTime - p.queueTime;
        if (waitingTime > maxWaitingTime) {
            maxWaitingTime = waitingTime;
        }
        if (last != nullptr && last != first) {
            int queueLength = 1;
            Elem* tmp = first;
            while (tmp != last) {
                queueLength++;
                tmp = tmp->link;
            }
            if (queueLength > maxQueueLength) {
                maxQueueLength = queueLength;
            }
        }
        currentTime += processingTime;
        cout << "Processed patient: " << p.surname << " (" << p.diagnosis << "), wait time: " << waitingTime << " minutes" << endl;
    }

    // ��������� ����������
    cout << "Max waiting time: " << maxWaitingTime << " minutes" << endl;
    cout << "Max queue length: " << maxQueueLength << endl;

    return 0;
}

