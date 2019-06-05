/* Sudoku Solver Program
 * It can Solve Any Sudoku Problem Instantly
 *
 * If incomplete Sudoku Problem Is Provided
 * It will Try to print all possible solutions
 * That's why you need to be careful
 * an empty problem has 10^23 solutions
 * it can exceed your available memory
 *
 * But with care you will enjoy 
 * the creativity
 *
 * you can use it to find total combination on a 9x9
 * empty grid (if used wisely)
 *
 * 2 mods for the solution
 * > single line = 81 numbers in a row
 * > grid = you know well
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char mat[25][9][9], ptr=0, did=0, mod;
int sol=0;

int uwrg();

void pront(){
  for(int i=0; i<81; i++){
    printf("%c",mat[ptr][i/9][i%9]);
  }
  printf("\n");
}

void print(){
  printf("\n\n\n");
  for(int i=0; i<81; i++){
     printf("%c  ",mat[ptr][i/9][i%9]);
     if(i%9 == 8) printf("\n");
     if(i%27 == 26) printf("\n");
     if(i%3==2 && i%9!=8) printf(" ");
  }
}

int solveitcap1(int pos);

int solveitcap2(int num);

int checksolved(){
  for(int i=0; i<81; i++){
    if(mat[ptr][i/9][i%9] == ' '){return i;}
  }
  return -1;
}

int checkdef(int num, int pos){
  for(int i=0; i<9; i++){
    if(mat[ptr][pos/9][i] == '0' + num) return 0;
    if(mat[ptr][i][pos%9] == '0' + num) return 0;
    if(mat[ptr][((pos/9)/3)*3 + i/3][((pos%9)/3)*3 + i%3] == '0' + num) return 0;
  }
  return 1;
}

int copymat(int pos);

void call1(){
  int t=solveitcap1(0);
  for(int i=0; i<401; i++){
    t = solveitcap1(t);
  }
}

void call2(){
  for(int i=1; i<10; i++){
    solveitcap2(i);
  }
}

int callt(){
  did=0;
  call2();
  while(did){
    did=0;
    call2();
  }
  call1();
  while(did){
    did=0;
    call1();
  }
  call2();
  while(did){
    did=0;
    call2();
  }
  if(checksolved()<0){
    sol++;
    if(mod=='2')print();
    else pront();
    did=10;
    return 1;
  }
  return 0;
}

void fckusr();

void back();

int revfck();

int main(){
  system("clear");
  printf("Choose the mod of output matrix\n");
  printf("1. single line\n2. grid\n");
  system("/bin/stty raw");
  mod = getchar();
  system("/bin/stty cooked");
  system("clear");
  char ch;
  printf("Type Your Problem Here :\n");
  for(int i=0; i < 81; i++){
    system("/bin/stty raw");
    ch = getchar();
    system("/bin/stty cooked");
    if(ch == ' ' || (ch > '0' && ch <= '9')){
      mat[ptr][i/9][i%9] = ch;
    }else i--;
    if(ch == 'q') i--;
  }
  printf("\n\nSO Your Problem is :\n");
  print();
  while(1){
    callt();
    if(uwrg() && did!=10){
      fckusr();
    }
    else{revfck();}
    if(did<0){ break;}
  }
  if(sol==0){printf("\nYou are so funny\n");}
  else printf("END<%d>\n", sol);
  return 0;
}

int solveitcap1(int pos){
  int totak, val;
  if(pos>80){
    return checksolved();
  }
  if(mat[ptr][pos/9][pos%9] != ' '){return pos + 1;}
  totak=0;
  for(int i=1; i<10; i++){
    if(checkdef(i, pos)){totak++; val=i;}
  }
  if(totak==1){
    mat[ptr][pos/9][pos%9] = '0' + val;
    did=1;
  }
  return pos + 1;
}

int solveitcap2(int num){
  int i, j, row, colm, box, valr, valc, valb;
  int chpt[9]={0,3,6,27,30,33,54,57,60};
  for(i=0; i<9; i++){
    row=0; colm=0; box=0;
    for(j=0; j<9; j++){
      if(mat[ptr][i][j] == ' '){
        if(checkdef(num, i*9 + j) == 1){
          row++; valr=j;
        }
      }
      if(mat[ptr][j][i] == ' '){
        if(checkdef(num, j*9 + i) == 1){
          colm++; valc=j;
	}
      }
      if(mat[ptr][chpt[i]/9 + j/3][chpt[i]%9 + j%3] == ' '){
        if(checkdef(num, (chpt[i]/9 + j/3)*9 + chpt[i]%9 + j%3)){
          box++; valb=j;
        }
      }
    }
    if(row==1){
      mat[ptr][i][valr] = num + '0';
      did=1;
    }
    if(colm==1){
      mat[ptr][valc][i] = num + '0';
      did=1;
    }
    if(box==1){
      mat[ptr][chpt[i]/9 + valb/3][chpt[i]%9 + valb%3] = num + '0';
      did=1;
    }
  }
  return 0;
}

int copymat(int pos){
  for(int i=0; i<81; i++){
    mat[ptr][i/9][i%9] = mat[ptr-1][i/9][i%9];
  }
  for(int i=1; i<10; i++){
    if(checkdef(i, pos)){
      mat[ptr][pos/9][pos%9] = i + '0';
      return 0;
    }
  }
  return 1;
}

int uwrg(){
  if(ptr==0) return 1;
  int r=0,c=0;
  for(int i=0; i<9; i++){
    r=0; c=0;
    for(int j=0; j<9; j++){
      if(mat[ptr][i][j] == ' ') r++;
      if(mat[ptr][j][i] == ' ') c++;
    }
    if(r==1 || c==1) return 0;
  }
  return 1;
}

int revfck(){
  int t;
  if(ptr>0){
    ptr--;
    t=checksolved();
    ptr++;
  }
  else{
    did=-1;
    return 1;
  }
  int i = mat[ptr][t/9][t%9] - '0' + 1;
  copymat(t);
  for( ; i<10; i++){
    if(checkdef(i, t)){
      mat[ptr][t/9][t%9] = i + '0';
      return 0;
    }
  }
  back();
  return 1;
}

void back(){
  if(ptr>0) ptr--;
  else { did=-1;return ;}
  revfck();
}

void fckusr(){
  int t=checksolved();
  if(t < 0){
    did=-1;
    return ;
  }
  ptr++;
  if(copymat(t)){
    ptr--;
    did=-1;
  }
}
