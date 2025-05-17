#include <stdio.h>
int main() {
//  ceci est un commentaire
printf("Initial\n");
int x = 5;
printf("%d\n", x);
if (x <= 5) {
	printf("OK\n");} else {
	printf("NON\n");}
if (x != 5) {
	printf("%d\n", x);} else {
	printf("%d\n", x);}
int y = x;
printf("%d\n", y);
int a = 5;
int b = 2;
int c = (a + b);
printf("%d\n", c);
printf("%d\n", (a * ((b + c))));
int r = (a % 2);
if (r == 0) {
	printf("Pair\n");} else {
	printf("Impair\n");}
int age;
char nom[256];
printf("comment t'appelles tu\n"); scanf("%255s", nom);
printf("quel age as tu ?\n"); scanf("%d", &age);
printf("%s\n", nom);
printf("%d\n", age);
for (int i = 0; i <= 10; i++) {
	printf("%d\n", i);}
int j = 10;
while (j > 0) {
	j = (j - 1);
	printf("%d\n", j);
	if (j == 5) {
		printf("cinq\n");}
	if (j == 0) {
		printf("fini\n");}}
return 0;
}
