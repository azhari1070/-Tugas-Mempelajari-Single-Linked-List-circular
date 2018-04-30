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
