#include <stdio.h>

typedef struct table{

	int Mnum;
	char Mad[20];
	char Msoyad[20];
	
}table;

typedef struct table2{

	int num;
	int link;
	char ad[20];
	char soyad[20];
	
}table2;


int hashFonk(int numara,int boyut){
	
	return numara%boyut;
	
}


void tabloyaekle2(table2 row[100],int numara,char isim[20],char soyisim[20],int boyut,int hashind){
	int c=0,d=0;
	
	if(row[hashind].num==-1){
		
	row[hashind].num=numara;
	
	while(isim[c] !='\0'){
		row[hashind].ad[c]=isim[c];
		++c;
	
	}	
		
	
	while(soyisim[d] !='\0'){
		
		row[hashind].soyad[d]=soyisim[d];
		++d;
	}
	
	} else{
		int temp,gecici;
		
		gecici=hashind;
		
		hashind=0;
		
		while(row[hashind].num!=-1){
			hashind++;
			if(hashind>10){
			
			printf("TABLO DOLU!!!");
			
			return;
		}
			
		}	
   
	
	row[hashind].num=numara;//************
	

	while(isim[c] !='\0'){
		
		row[hashind].ad[c]=isim[c];
		c++;
	}	
		
	
	while(soyisim[d] !='\0'){
		
		row[hashind].soyad[d]=soyisim[d];
		d++;
	}
	
		if(row[gecici].link==-1){
			
			row[gecici].link=row[hashind].num;
			
		}else{
				temp=0;
			while(row[gecici].link!=row[temp].num){
				temp++;	
			}
			
			row[temp].link=row[hashind].num;
		}
	
	}//ELSE BÝTÝYOR
		c=0,d=0;
	
	
}


void listele2(table2 row[100],int boyut){
	


	for(int i=0;i<=boyut;i++){
		int a=0,b=0;
		
		printf("\n%d\t" , row[i].num);
		
		
		if(row[i].num!=-1){
		
		
		while(row[i].ad[a] != '\0'){
		printf("%c" , row[i].ad[a]);
		a++;
		}
		printf("\t");
		
		while(row[i].soyad[b] != '\0'){
		printf("%c" , row[i].soyad[b]);
		b++;
		}
		
		a=0,b=0;	
		
	}
		printf("\t\t%d" , row[i].link);
	}	
	
}

int arama2(table2 row[100],int boyut,int aranacak){
		int sayici=1,arahash,temp=0,gecici=0;
		
		while(row[gecici].num!=aranacak){
			gecici++;
			
			if(gecici>10) return-1;
		}
		
		arahash=hashFonk(aranacak,boyut);
		if(row[arahash].num==aranacak){
			
			return sayici;
		}else {
			
			if(row[arahash].link==aranacak){
				sayici++;
				return sayici;
			}else{
				
				while(row[temp].link==-1&&row[temp].num==aranacak){
					sayici++;
					temp++;
					if(temp>10)return -1;
				}
				return sayici;
			}
		
		}
		return -1;
}

void tabloyaekle(table satir[100],int numara,char isim[20],char soyisim[20],int boyut,int hashind){

		int c=0,d=0;

	if(satir[hashind].Mnum==-1){
		
	satir[hashind].Mnum=numara;
	
	while(isim[c] !='\0'){
		satir[hashind].Mad[c]=isim[c];
		++c;
	
	}	
		
	
	while(soyisim[d] !='\0'){
		
		satir[hashind].Msoyad[d]=soyisim[d];
		++d;
	}
	
	
	} else {//EÐER TABLODA DOLU SATIRA EKLEME YAPILMAYA CALISILIYORSA
		
		while(satir[hashind].Mnum!=-1){
			hashind++;
			if(hashind>10){
			
			printf("TABLO DOLU!!!");
			
			return;
		}
	}
		
		
		
		satir[hashind].Mnum=numara;//************
	
	while(isim[c] !='\0'){
		satir[hashind].Mad[c]=isim[c];
		c++;
	
	}	
		
	
	while(soyisim[d] !='\0'){
		
		satir[hashind].Msoyad[d]=soyisim[d];
		d++;
	}
		
	}//ELSE BÝTÝYOR 
		
		c=0,d=0;
	}	
	

void listele(table satir[100],int boyut){
	


	for(int i=0;i<=boyut;i++){
		int a=0,b=0;
		
		printf("\n%d\t" , satir[i].Mnum);
		
		if(satir[i].Mnum!=-1){
		
		
		while(satir[i].Mad[a] != '\0'){
		printf("%c" , satir[i].Mad[a]);
		a++;
		}
		printf("\t");
		
		while(satir[i].Msoyad[b] != '\0'){
		printf("%c" , satir[i].Msoyad[b]);
		b++;
		}
		
		a=0,b=0;	
		
	}
	
	}	
	
}




int arama(table satir[100],int boyut,int aranacak){
		int sayici=1,arahash;
		arahash=hashFonk(aranacak,boyut);
	if(satir[arahash].Mnum==aranacak){
		
		return sayici;
	}else {
		
		while(satir[arahash].Mnum!=aranacak){
			arahash++;
			sayici++;
			if(sayici>10)return -1;
			
			
		}
		return sayici;
	}
	
	
}



int main(){
	int boyut,hashdeger,secim,aranacak,arasonuc;
	printf("tablonun boyutunu girin: ");
	scanf("%d" , &boyut);
	
	char isim[20],soyisim[20];	
	int numara;
	
	table satir[boyut];
	table2 row[boyut];
	
	for(int i=0;i<=boyut;i++){
		
		satir[i].Mnum=-1;
		satir[i].Mad[0]='\0';
		satir[i].Msoyad[0]='\0';	
	}
	for(int i=0;i<=boyut;i++){
		
		row[i].num=-1;
		row[i].link=-1;
		row[i].ad[0]='\0';
		row[i].soyad[0]='\0';	
	}
	
printf("\n1. tabloya eklemek icin: 1\n1. tabloyu listelemek icin: 2\n1. tabloda aramak icin 3\n2. tabloya eklemek icin: 4\n2. tabloyu listelemek icin: 5\n2. tabloda aramak icin:6\ncikmak icin: 7\n");
do{
	printf("\nseciminizi girin:");
	scanf("%d" , &secim);
	switch(secim){
case 1:
	printf("\n\nnumara girin: ");
	scanf("%d" , &numara);
	printf("isim girin: ");
	scanf("%s" , isim);
	printf("soyisim girin: ");
	scanf("%s" , soyisim);
	
	hashdeger=hashFonk(numara,boyut);
	
	tabloyaekle(satir,numara,isim,soyisim,boyut,hashdeger);
	break;
case 2:
	listele(satir,boyut);
	break;
case 3:
	printf("\naranacak numarayi girin: ");
	scanf("%d" , &aranacak);
	arasonuc=arama(satir,boyut,aranacak);
	if(arasonuc==-1){
		
		printf("\ndeger bulunamadi");
	}else{
		printf("%d seferde bulundu." , arasonuc);
		
	}
	break;
case 4:
	printf("\n\nnumara girin: ");
	scanf("%d" , &numara);
	printf("isim girin: ");
	scanf("%s" , isim);
	printf("soyisim girin: ");
	scanf("%s" , soyisim);
	
	hashdeger=hashFonk(numara,boyut);
	
	tabloyaekle2(row,numara,isim,soyisim,boyut,hashdeger);
	break;

case 5:
	listele2(row,boyut);
	
	break;
	
	
case 6:
		printf("\naranacak numarayi girin: ");
	scanf("%d" , &aranacak);
	arasonuc=arama2(row,boyut,aranacak);
	if(arasonuc==-1){
		
		printf("\ndeger bulunamadi");
	}else{
		printf("%d seferde bulundu." , arasonuc);
		
	}	
	break;
}
}while(secim!=7);



	
}
