/* Sudoku Problem Creator Program
 * Create Problems with same Moderate Difficulty 
 *
 * outputs the problem in two mods 
 *  >> grid mod 
 *  >> single line*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char mat[25][9][9], ptr=0, did=0;

int uwrg();

void pront(){
  for(int i=0; i<81; i++){
    printf("%c",mat[ptr][i/9][i%9]);
  }
  printf("\n");
}

void print(){
  printf("---------------------");
  printf("\n");
  for(int i=0; i<81; i++){
    printf("%c ",mat[ptr][i/9][i%9]);
    if(i%9 == 8) printf("\n");
    if(i%27 == 26 && i<80) printf("\n");
    if(i%3==2 && i%9!=8) printf("  ");
  }
  printf("---------------------\n");
}

int wrekitcap1();

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

void create(int n);

void seclast();

void last();

void ptrt(int str);

void gtrt(int str);

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
  if(checksolved()<0) return 1;
  return 0;
}

void fckusr();

void back();

int revfck();

//needs inprovement{fckusr}
void promain(){
  while(1){
    if(callt()){break;}
    if(uwrg()){
      fckusr();
    }
    else{revfck();}
    if(did<0){ break;}
  }
  for(int i=0; i<81; i++){
    mat[0][i/9][i%9] = mat[ptr][i/9][i%9];
  }
  ptr = 0;
}

int main(){
  srand(time(0));
  for(int i=0; i<81; i++)
    mat[ptr][i/9][i%9] = ' ';
  ptrt(0);
  ptrt(30);
  ptrt(60);
//  gtrt(10);
  promain();
  create(50);
  seclast();
  last();
  last();
  printf("Your Question Boy :\n");
  print();
  pront();
  return 0;
}

void create(int n){
  int count=0;
  for(int i=0; i<n; i++){
    if(wrekitcap1()){count=0; continue;}
    i--;
    count++;
    if(count>200) break;
  }
}

void ptrt(int str){
  int t;
  for(int i=0; i<9; i++){
    t = rand()%9;
    if(mat[ptr][str/9 + t/3][str%9 + t%3]==' '){
      mat[ptr][str/9 + t/3][str%9 + t%3]='0'+i+1;
    }
    else i--;
  }
}

void gtrt(int str){
  int t, p;
  for(int i=0; i<str; i++){
    t = rand()%81;
    if(mat[ptr][t/9][t%9]!=' '){
      i--;
      continue;
    }
    p = rand()%9;
    while(1){
      if(checkdef(p+1, t)){
        mat[ptr][t/9][t%9] = '0'+p+1;
	break;
      }
      p = rand()%9;
    }
  }
}

//pos as char may be harmfull
int wrekitcap1(){
  char t, val, pos;
  while(1){
    pos = rand()%81;
    if(mat[ptr][pos/9][pos%9] == ' '){ continue;}
    val = mat[ptr][pos/9][pos%9];
    mat[ptr][pos/9][pos%9] = ' ';
    t=0;
    for(int i=1; i<10; i++){
      if(checkdef(i, pos)){t++;}
    }
    if(t==1){
      return 1;
    }
    mat[ptr][pos/9][pos%9] = val;
    return 0;
  }
}

void seclast(){
  char t, val;
  for(int i=0; i<81; i++){
    if(mat[ptr][i/9][i%9] == ' ') continue;
    val = mat[ptr][i/9][i%9];
    mat[ptr][i/9][i%9] = ' ';
    t=0;
    for(int j=1; j<10; j++){
      if(checkdef(j, i)){t++;}
    }
    if(t==1) continue;
    mat[ptr][i/9][i%9] = val;
  }
}

void last(){
  char t, val;
  did=0;
  for(int i=0; i<81; i++){
    if(mat[ptr][i/9][i%9] == ' ') continue;
    val = mat[ptr][i/9][i%9];
    mat[ptr][i/9][i%9] = ' ';
    for(int j=0; j<81; j++){
      mat[ptr+1][j/9][j%9] = mat[ptr][j/9][j%9];
    }
    ptr++;
    if(callt()==1){did=1; ptr--; continue;}
    ptr--;
    mat[ptr][i/9][i%9] = val;
  }
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
  ptr--;
  int t=checksolved();
  ptr++;
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
    return ;
  }
  ptr++;
  if(copymat(t)){
    ptr--;
    did=-1;
  }
}
