  void tambahDataDepan(int dataBaru) {
  Data *baru;
  baru=(Data*) malloc(sizeof(Data));
  baru->nilai=dataBaru;
  baru->next=baru;
  if (isEmpty()){
  head=baru;
  head->next=head;
  } else {
  Data *bantu;
  bantu=head;
  while (bantu->next!=head){
  bantu=bantu->next;
  }
  baru->next=head;
  head=baru;
  bantu->next=head;
  }
  }
