#include <iostream>
#include<locale.h> 
# define PARA 2
using namespace std;

int *dizi,*d1,*d2,*d3,b1,b2,b3,t1,t2,t3,toplam_para,size,sahte_para=0,ilerleme=0,terazi=0,deger,sira,sonuc,check=0;

void giris(){
	bas:
	cout<<"Toplam para miktarý:";
	cin>>toplam_para;
	if(toplam_para<=2){
		cout<<"en az 3 adet para girmelisiniz"<<endl;
		goto bas;
	}
	cout<<endl;
	size=toplam_para;
	cout<<"paranýz aðýr mý hafif mi. 1 Aðýr 2 Hafif:";
	cin>>deger;
	cout<<endl;
	cout<<"sahte paranýn sýrasý:";
	cin>>sira;
	cout<<endl;
	dizi=new  int[toplam_para];
	for(int i=0;i<toplam_para;i++){
		dizi[i]=PARA;
	}
	if(deger==1){
		dizi[sira-1]=3;
	}else{
		dizi[sira-1]=1;
	}
	
}

void parcala(){
	
	b1=0;
	b2=0;
	b3=0;
	
	b1=size/3;
	b2=(size-b1)/2;
	b3=size-b1-b2;
	
	d1=new int[b1];
	d2=new int[b2];
	d3=new int[b3];
	
	for(int i=0;i<b1;i++){
		d1[i]=dizi[i];
	}
	for(int i=b1;i<b1+b2;i++){
		d2[i-b1]=dizi[i];
	}
	for(int i=b1+b2;i<size;i++){
		d3[i-b1-b2]=dizi[i];
	}
	delete dizi;	
}


void diziye_ata(int kosul){
	if(kosul==1){
		delete dizi;
		dizi=new int [b1];
		for(int i=0;i<b1;i++){
			dizi[i]=d1[i];
		}
		delete d1,d2,d3;
		size=b1;
	}else if(kosul==2){
		ilerleme+=b1;
		delete dizi;
		dizi=new int [b2];
		for(int i=0;i<b2;i++){
			dizi[i]=d2[i];
		}
		delete d1,d2,d3;
		size=b2;	
	}else if(kosul==3){
		ilerleme+=b1+b2;
		delete dizi;
		dizi=new int [b3];
		for(int i=0;i<b3;i++){
			dizi[i]=d3[i];
		}
		delete d1,d2,d3;
		size=b3;		
	}else{
		cout<<"dizye ata da hata var";
	}	
}
   
//1 aðýr 2 hafif//ilk baþta sahte paranýn aðýr yada hafif mi oduðunu buluyoruz.
void hafif(){
	if(sahte_para==0){
		if(t1==t3){
			sahte_para=1;
			terazi++;
		}else{
			sahte_para=2;
			terazi++;
		}
	}
	if(sahte_para==1){
		diziye_ata(2);
	}else if(sahte_para==2){
		diziye_ata(1);
	}else{
		cout<<"\n\n\nhafifte hata var \n\n\n";
	}
}


void agir(){
	if(sahte_para==0){
		if(t2==t3){
			sahte_para=1;
			terazi++;
		}else{
			sahte_para=2;
			terazi++;
		}
	}
	if(sahte_para==1){
		diziye_ata(1);
	}else if(sahte_para==2){
		diziye_ata(2);
	}else {
		cout<<"\n\n\n aðirda hata var \n\n\n";
	}
}


void tart(){
	t1=0;
	t2=0;
	t3=0;
	sonuc=0;
	
	for(int i=0;i<b1;i++){
		t1+=d1[i];
	}
	for(int i=0;i<b2;i++){
		t2+=d2[i];
	}
	for(int i=0;i<b3;i++){
		t3+=d3[i];
	}
	
	if(b1<b3){
		t1+=PARA;
	}
	if(b2<b3){
		t2+=PARA;
	}
	
	if(t1==t2){
		terazi++;
		diziye_ata(3);
	}else if(t1<t2){
		terazi++;
		hafif();
	}else if(t1>t2){
		terazi++;
		agir();
	}else{
		cout<<"\n\n------tart da hata var\n\n\n";
	}
}

//1 aðýr 2 hafif
void kalan(){
		cout<<"Paranýz dizideki sýrasý :"<<ilerleme+1<<", kullanýlan terazi iþlem sayýsý:"<<terazi<<" ve paranýzýn durumu:";
		if(sahte_para==1){
			cout<<"aðýrdýr"<<endl;
		}else{
			cout<<"hafiftir"<<endl;
		}
}

int main(){
	setlocale(LC_ALL, "Turkish"); 
	giris();
	
	while(1){
	if(size<=1){
		cout<<"terazi:"<<terazi<<" ilerleme:"<<ilerleme<<" size:"<<size<<endl;
		kalan();
		break;
	}	
	parcala();
	tart();
	}
	return 0;
}
