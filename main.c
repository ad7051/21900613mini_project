#include "manager.h"
int main(void){
        count=0;
	curcount=0;
#ifdef DEBUG
printf("debug [main.c]: call loadData()\n");
#endif
	count=loadData(plist);
	curcount=count;
        while (1){
#ifdef DEBUG
printf("debug [main.c]: call selectMenu()\n");
#endif
                menu=selectMenu();
                if(menu==0) break;
                if(menu==1){
                        if(count>0){
#ifdef DEBUG
printf("debug [main.c]: call listProduct()\n");
#endif
                                listProduct(plist,curcount);
			}
                        else
                                printf("데이터가 없습니다!\n");
                }
                else if(menu==2){
#ifdef DEBUG
printf("debug [main.c]: call addProduct()\n");
#endif
                                addProduct(&plist[curcount++]);
                                count++;
                }
                else if(menu==3){
#ifdef DEBUG
printf("debug [main.c]: call selectDataNo()\n");
#endif
                        int no=selectDataNo(plist,curcount);
			if(no==0){
				printf("=>취소됨\n");
				continue;
			}
#ifdef DEBUG
printf("debug [main.c]: call updateProduct()\n");
#endif
			updateProduct(&plist[no-1]);
		}
                else if(menu==4){
#ifdef DEBUG
printf("debug [main.c]: call selectDataNo()\n");
#endif
			int no=selectDataNo(plist,curcount);
			if(no==0){
				printf("=> 취소됨!\n");
				continue;
			}
			int deleteok;
			printf("정말로 삭제하시겠습니까?(삭제:1)");
			scanf("%d",&deleteok);
			if(deleteok==1){
#ifdef DEBUG
printf("debug [main.c]: call deleteProduct()\n");
#endif
				deleteProduct(&plist[no-1]);
				count--;
			}
		}
		else if(menu==5){
#ifdef DEBUG
printf("debug [main.c]: call searchName()\n");
#endif
			searchName(plist,curcount);
		}
		else if(menu==6){
#ifdef DEBUG
printf("debug [main.c]: call searchStar()\n");
#endif
			searchStar(plist,curcount);
		}
		else if(menu==7){
#ifdef DEBUG
printf("debug [main.c]: call searchStdprice()\n");
#endif
			searchStdprice(plist,curcount);
		}
		else if(menu==8){
			if(count==0)
				printf("데이터가 없습니다!\n");
			else
#ifdef DEBUG
printf("debug [main.c]: call saveData()\n");
#endif
				saveData(plist,curcount);
        }
        printf("종료됨!\n");
        return 0;
}
