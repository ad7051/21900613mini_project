#include"product.h"
#include<string.h>
void addProduct(Product *p){
	printf("이름은?");
	getchar();
	fgets(p->name,sizeof(p->name),stdin);
	printf("중량은?(g)");
	scanf("%d",&p->weight);
	printf("가격은(원)?");
	scanf("%d",&p->price);
	p->stdPrice=p->price/p->weight;
	printf("별점은?");
	scanf("%d",&p->star);
}

void readProduct(Product p){
	printf("%d   %d    %d        %d   %s",p.weight,p.price,p.stdPrice,p.star,p.name);
}

void updateProduct(Product *p){
	printf("새 이름은?");
	getchar();
	fgets(p->name,sizeof(p->name),stdin);
	printf("새 중량은?(g)");
	scanf("%d",&p->weight);
	printf("새 가격은(원)?");
	scanf("%d",&p->price);
	p->stdPrice=p->price/p->weight;
	printf("새 별점은?");
	scanf("%d",&p->star);
	printf("=>수정성공!\n");
}

void deleteProduct(Product *p){
	p->price=-1;
	printf("=> 삭제됨!\n");
}

int selectMenu(){
	int menu;
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 제품명으로 검색\n");
	printf("6. 별점으로 검색\n");
	printf("7. 표준가격으로 검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는?");
	scanf("%d",&menu);
	return menu;
}

void searchName(Product *p,int count){
    int scount=0;
    char search[20];

    printf("검색할 이름? ");
    getchar();
    fgets(search,sizeof(search),stdin);
	printf("  중량   가격 표준가격  별점  이름\n");
    printf("=================================\n");
    for(int i=0;i<count;i++){
        if(p[i].price !=-1){
            if(strstr(p[i].name,search)){
                printf("%2d ",i+1);
                readProduct(p[i]);
                scount++;
            }
        }
    }
}

void searchStar(Product *p,int count){
    int scount=0;
    int search;

    printf("검색할 별점? ");
    scanf("%d", &search);
	printf("  중량   가격 표준가격  별점  이름\n");
    printf("=================================\n");
    for(int i=0;i<count;i++){
        if(p[i].price!=-1){
            if(p[i].star==search){
                printf("%2d ",i+1);
                readProduct(p[i]);
                scount++;
            }
        }
    }
}

void searchStdprice(Product *p,int count){
    int scount=0;
    int search;

    printf("검색할 표준 가격?(이하) ");
    scanf("%d", &search);
	printf("  중량   가격 표준가격  별점  이름\n");
    printf("=================================\n");
    for(int i=0;i<count;i++){
        if(p[i].price!=-1){
            if(p[i].stdPrice<=search){
                printf("%2d ",i+1);
                readProduct(p[i]);
                scount++;
            }
        }
    }
}

void saveData(Product *p, int count){
	FILE *fp;
	fp=fopen("product.txt","wt");
		for(int i=0;i<count;i++){
			if(p[i].price!=-1){
				fprintf("%d   %d    %d        %d   %s",p[i].weight,p[i].price,p[i].stdPrice,p[i].star,p[i].name);
			}
		}
	fclose(fp);
	printf("저장됨!");
}

int loadData(Product p[]){
    int count =0;
    FILE *fp;
    fp=fopen("product.txt","rt");
    if(fp==NULL){
        printf("=> 파일 없음\n");
        return 0;
    }
    for(; ; count++){
        fscanf(fp,"%d %d %d %d",&p[i].weight,&p[i].price,&p[i].stdPrice,&p[i].star);
        fgets(p[count].name,sizeof(p[count].name),fp);
        if(feof(fp))
            break;
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return count;
}
