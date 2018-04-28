void hapusDepan () {
if ( !is Empty()) {
if (head->next! = head) {
Data *hapus;
hapus=head;
Data *bantu;
bantu=head;

while (bantu->next!=head)  {
bantu=bantu->next;
}
bantu->next=head->next;
head=head->next;
delete hapus;
}
else awal ();
}
}
