#include "manager.h"

void listProduct(Product *p,int count){
	printf("*********\n");
	printf("=========================\n");
	printf("  중량   가격 표준가격  별점  이름\n");
	for(int i=0;i<count;i++){
		if(p[i].price==-1)
			continue;
		printf("%d ",i+1);
		readProduct(p[i]);
	}
	printf("\n");
}

int selectDataNo(Product *p,int count){
	int no;
	listProduct(p,count);
	printf("번호는 (취소:0)? ");
	scanf("%d",&no);
	return no;
}
