#include <iostream>
using namespace std;

struct Film{
  string judul;
  int durasi, harga;

  Film *next;
};

Film *head, *tail, *newNode, *cur, *del;

void createCircularSingleLinkedList(string judul, int durasi, int harga){

  head = new Film();
  head->judul = judul;
  head->durasi = durasi;
  head->harga = harga;
  tail = head;
  tail->next = head;

}

void addFirst(string judul, int durasi, int harga){
  if(head == NULL){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new Film();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast(string judul, int durasi, int harga){
  if(head == NULL){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new Film();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string judul, int durasi, int harga, int posisi){
  if(head == NULL){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    if(posisi == 1){
      cout << "Posisi satu bukan posisi tengah!!!" << endl;
    }else{
      newNode = new Film();
      newNode->judul = judul;
      newNode->durasi = durasi;
      newNode->harga = harga;

      int nomor = 1;
      cur = head;
      while(nomor < posisi - 1){
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

void removeFirst(){
  if(head == NULL){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

void removeLast(){
  if(head == NULL){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = tail;
    cur = head;
    while(cur->next != tail){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

void removeMiddle(int posisi){
  if(head == NULL){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    int nomor = 1;
    cur = head;
    while(nomor < posisi - 1){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}

void printCircular(){
  if(head == NULL){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    cout << "Data Film " << endl;
    cout << "________________________________________________________________" << endl; 
    cout << "| Judul\t\t\t| Durasi\t| Harga\t\t|" << endl;
    cout << "________________________________________________________________" << endl; 
    cur = head;
    while(cur->next != head){
      cout << "| " << cur->judul << "\t| " << cur->durasi << "\t| " << cur->harga << "\t\t|" << endl;
      cur = cur->next;
    }
    cout << "| " << cur->judul << "\t| " << cur->durasi << "\t| " << cur->harga << "\t\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}

int main(){
  createCircularSingleLinkedList("Superman", 160, 90000);

  printCircular();

  addFirst("Monster", 90, 50000);

  printCircular();

  addLast("Hunter", 140, 60000);

  printCircular();

  addMiddle("Train To Busan", 90, 50000, 2);

  printCircular();

  removeMiddle(3);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}