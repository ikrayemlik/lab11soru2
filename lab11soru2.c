#include <stdio.h>
#include <stdlib.h>

/* Bir baðlý doðrusal listelerde listenin sonundaki düðümü keserek listenin baþýna ekleyen ve
oluþan listenin son halini geri döndüren prototipi aþaðýda verilmiþ fonksiyonu yazýnýz. 
struct node* cutlastaddhead(struct node* head);
struct node {
int number;
struct node * next;
};  */
struct nodes{
	int number;
	struct nodes * next;
};
typedef struct nodes node;

// Listenin sonundaki düðümü keserek baþa ekleyen fonksiyon
 node* sondanbasaekle(node* head) {
    if (head == NULL || head->next == NULL) {
        // Liste boþ veya tek bir elemandan oluþuyorsa herhangi bir iþlem yapmaya gerek yok.
        return head;
    }

    node* p = head;
    node* oncekidugum = NULL;

    // Listenin sonuna git
    while (p->next != NULL) { //p iþaretçisi listenin son elemanýndayken oncekidugum son eleman olacagý için iþaretlenir
        oncekidugum = p;
        p = p->next;
    }

    // Son düðümü kes
    oncekidugum->next = NULL; //oncekidugum son eleman olur

    // Kesilen son düðümü baþa ekle
    p->next = head;
    head = p;
    
    return head;// head ifadesini diðer kýsýmlarda kullanmak için sonuc olarak döndürüyoruz
}
 void yazdir(node *head){
 	node *p=head;
 	while(p!=NULL){
 	printf("%d",p->number);
 	p=p->next;
	 }
	 printf("\n");
 }


int main() {
	int n,i;
    int num;
	printf("kac elemanlý bir liste olusturacaksýnýz");
	scanf("%d",&n);
	
		node *head=NULL;
	for(i=0;i<n;i++){
		printf("lutfen bir sayi giriniz");
		scanf("%d",&num);
		
	node *newnode=(node*)malloc(sizeof(node));
		newnode->number=num;
		newnode->next=NULL;
		// Eðer liste boþsa, yeni düðümü baþa ekle
		if(head==NULL){
			head=newnode;
		}else{
			  
			node *p= head;
			while(p->next!=NULL){ // p dugumu listenin sonuna kadar gider ve durur
				p=p->next;
			}
			p->next=newnode;// Liste boþ deðilse, son düðümün next'ini yeni düðüme baðla
		}
	
	}
	printf("orijinal liste\n");
	yazdir(head);
     head=sondanbasaekle(head); // iþlem sonucunda baðlý listenin baþlangýç düðümü deðiþebilir. Bu nedenle,head iþaretçisine atama yaptýk
	printf("guncellenmis liste");
	yazdir(head);
	
	
	
	return 0;
}
