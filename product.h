#include <stdio.h>
typedef struct{
    char name[50];
    int weight;
    int price;
    int stdPrice;
    int star;
} Product;
int count, menu;
void addProduct(Product *p);
void readProduct(Product p);
void updateProduct(Product *p);
void deleteProduct(Product *p);
void searchName(Product *p,int count);
void searchPrice(Product *p,int count);
void searchStdprice(Product *p,int count);
void searchStar(Product *p,int count);
int selectMenu();
int loadData(Product p[]);
void saveData(Product *p, int count);
