#include <stdio.h>
#include <stdlib.h>

/* Bir ba�l� do�rusal listelerde listenin sonundaki d���m� keserek listenin ba��na ekleyen ve
olu�an listenin son halini geri d�nd�ren prototipi a�a��da verilmi� fonksiyonu yaz�n�z. 
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

// Listenin sonundaki d���m� keserek ba�a ekleyen fonksiyon
 node* sondanbasaekle(node* head) {
    if (head == NULL || head->next == NULL) {
        // Liste bo� veya tek bir elemandan olu�uyorsa herhangi bir i�lem yapmaya gerek yok.
        return head;
    }

    node* p = head;
    node* oncekidugum = NULL;

    // Listenin sonuna git
    while (p->next != NULL) { //p i�aret�isi listenin son eleman�ndayken oncekidugum son eleman olacag� i�in i�aretlenir
        oncekidugum = p;
        p = p->next;
    }

    // Son d���m� kes
    oncekidugum->next = NULL; //oncekidugum son eleman olur

    // Kesilen son d���m� ba�a ekle
    p->next = head;
    head = p;
    
    return head;// head ifadesini di�er k�s�mlarda kullanmak i�in sonuc olarak d�nd�r�yoruz
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
	printf("kac elemanl� bir liste olusturacaks�n�z");
	scanf("%d",&n);
	
		node *head=NULL;
	for(i=0;i<n;i++){
		printf("lutfen bir sayi giriniz");
		scanf("%d",&num);
		
	node *newnode=(node*)malloc(sizeof(node));
		newnode->number=num;
		newnode->next=NULL;
		// E�er liste bo�sa, yeni d���m� ba�a ekle
		if(head==NULL){
			head=newnode;
		}else{
			  
			node *p= head;
			while(p->next!=NULL){ // p dugumu listenin sonuna kadar gider ve durur
				p=p->next;
			}
			p->next=newnode;// Liste bo� de�ilse, son d���m�n next'ini yeni d���me ba�la
		}
	
	}
	printf("orijinal liste\n");
	yazdir(head);
     head=sondanbasaekle(head); // i�lem sonucunda ba�l� listenin ba�lang�� d���m� de�i�ebilir. Bu nedenle,head i�aret�isine atama yapt�k
	printf("guncellenmis liste");
	yazdir(head);
	
	
	
	return 0;
}
