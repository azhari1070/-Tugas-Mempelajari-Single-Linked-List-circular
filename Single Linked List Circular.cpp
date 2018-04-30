#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct node{
	int info;
	struct node *next;
}*start;

class single_list{
	public:
		node* create_node(int);
		void insert_begin();
		void insert_pos();
		void insert_last();
		void delete_pos();
		void display();

		single_list(){
			start = NULL;
		}
};

int main(){
	int n, node, elemen, posisi, i;
	single_list s1;
	start=NULL;
	while (1){
		cout<<"1. masukan node di depan"<<endl;
		cout<<"2. masukan node di belakang"<<endl;
		cout<<"3. hapus node depan"<<endl;
		cout<<"4. hapus node belakang"<<endl;
		cout<<"5. masukan node pada posisi tertentu"<<endl;
		cout<<"6. menghapus node tertentu"<<endl;
		cout<<"7. display linked list"<<endl;
		cout<<"8. exit"<<endl;
		cout<<"pilihan : ";
		cin>>n;
		switch(n){
			case 1:
				cout<<"Masukan node didepan"<<endl;
				s1.insert_begin();
				cout<<endl;
				break;
			case 2:
				cout<<"Masukan node di belakang"<<endl;
				s1.insert_last();
				cout<<endl;
				break;
			case 3:
				cout<<"hapus node depan"<<endl;
				break;
			case 4:
				cout<<"hapus node belakang"<<endl;
				break;
			case 5:
				cout<<"masukan node di posisi tertentu"<<endl;

				cout<<endl;
				break;
			case 6:
				cout<<"menghapus node tertentu"<<endl;
				s1.delete_pos();
				cout<<endl;
				break;
			case 7:
				cout<<"display list"<<endl;
				s1.display();
				cout<<endl;
				break;
			case 8:
				cout<<"byee"<<endl;
				return 0;
			default:
				cout<<"tidak ada pilihan";
		}
	}
}

node *single_list::create_node(int value){
	struct node *temp, *s;
	temp = new(struct node);
	if (temp==NULL){
		cout<<"Memory tidak di alokasikan"<<endl;
		return 0;
	} else {
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
	}

void single_list::insert_begin(){		
	int value;
	cout<<"Masukan value: ";cin>>value;
	struct node *temp, *p;
	temp= create_node(value);
	if (start==NULL){
		start = temp;
		start->next = NULL;
	} else {
		p = start;
		start = temp;
		start->next = p;
	}
	cout<<"Element dimasukan pada awal"<<endl;

}
void single_list::insert_last(){
	int value;
	cout<<"masukan value : ";cin>>value;
	struct node *temp, *s;
	temp = create_node(value);
	s = start;
	while (s->next != NULL){
		s=s->next;
	}
	temp->next=NULL;
	s->next = temp;
	cout<<"elemen dimasukan pada akhir"<<endl;
}

void single_list::insert_pos(){
	int value, pos, counter = 0;
	cout<<"masukan value: ";cin>>value;
	struct node *temp, *s, *ptr;
	temp = create_node(value);
	cout<<"masukan posisi yang ingin dituju";cin>>pos;
	int i;
	s = start;
	while (s!=NULL){
		s = s->next;
		counter ++;
	}
	if (pos==1){
		if (start == NULL){
		start = temp;
		start->next= NULL;
		} else {
			ptr = start;
			start = temp;
			start->next=ptr;
		}
	}
	else if (pos>1 && pos <= counter){
			s = start;
			for (i=1; i<pos;i++){
				ptr =s;
				s=s->next;
			}
			ptr->next = temp;
			temp->next = s;
		} else {
			cout<<"posisi terlalu jauh"<<endl;
		}
}

void single_list::display(){
    	struct node *temp;
	if (start==NULL) {
		cout<<"list kosong"<<endl;
		return;
	}
	temp = start;
	cout<<"elemen dari list nya adalah : "<<endl;
	while (temp != NULL){
		cout<<temp->info<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;

	getch();
}
