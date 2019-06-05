// Meant to be played on Terminal not 'command prompt'
//
// Simple Model of typing master program
//
// Maximum Custom Keys Size is 500

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>

int scoreNT;

char all[500];

void doitcap(char *ch){
  int len = strlen(ch), i;
  for(i=0; i<len; i++){
    all[i] = ch[i];
  }
  all[i] = '\0';
}

void home(){
  char ch[16] = "asdf g h jkl;'j";
  doitcap(ch);
}

void bttm(){
  char ch[16] = "zxcvbn m ,./ ";
  doitcap(ch);
}

void topd(){
  char ch[20] = "qwe rtyu iop ";
  doitcap(ch);
}

void nmbr(){
  char ch[20] = "1234 56789 0-= ";
  doitcap(ch);
}

void hobo(){
  char ch[] = "asdf ghjk l;'z xcvbn m,./";
  doitcap(ch);
}

void hoto(){
  char ch[] = "asdf ghjkl;'qw ertyu io p[]";
  doitcap(ch);
}

void boto(){
  char ch[] = "z xcvbn m,./qw ertyu iop[]";
  doitcap(ch);
}

void honu(){
  char ch[] = "as dfghj kl;'123 45678 90-=";
  doitcap(ch);
}

void altr(){
  char ch[] = "asdfg hjkl zxcv bnm qwe rtyuio p";
  doitcap(ch);
}

void arws(){
  char ch[] = "z xcvb nm,./a sdf ghjk l;'qw ert yuio p[]1 234 567 890-=";
  doitcap(ch);
}

void custom(int i){
  system("clear");
  char c;
  if(!i)printf("Press Your keys to play with\n");
  else printf("You Are in onthespot customize mode\n");
  printf("press escape key to end your input\n\n");
  while(1){
    system("/bin/stty raw");
    c = getchar();
    system("/bin/stty cooked");
    if(c == 27){all[i] = '\0'; break;}
    all[i++] = c;
  }
  system("clear");
  printf("Now Play The Game :)\n\n");
}

void about();

void tricks();

int increaseString(char* str);

char interface();

void PlayNT();

int main(){
  system("clear");
  char choice;
  while(1){
    choice = interface();
    switch(choice){
      case '0': home();PlayNT();break;
      case '1': bttm();PlayNT();break;
      case '2': topd();PlayNT();break;
      case '3': nmbr();PlayNT();break;
      case '4': hobo();PlayNT();break;
      case '5': hoto();PlayNT();break;
      case '6': boto();PlayNT();break;
      case '7': honu();PlayNT();break;
      case '8': altr();PlayNT();break;
      case '9': arws();PlayNT();break;
      case 'c':
      case 'C': custom(0);PlayNT();break;
      case 'h': tricks();break;
      case 'q':
      case 'x':
      case 'Q':
      case 'X': return 0;
      default : break;
    }
  }
  return 0;
}

char interface(){
  printf("+----------------------------+\n\n");
  printf("To Improve Your Typing Skills.\n\n");
  printf("We Present Letter Typing Program.\n\n");
  printf("Press escape key to leave the game at any point\n\n");
  printf("Wrong key leads to negative marks\n\n");
  printf("Press any of these keys as your choice\n");
  printf("==> 0. Home Row\n");
  printf("==> 1. Bottom Row\n");
  printf("==> 2. Top Row\n");
  printf("==> 3. Number Row\n");
  printf("==> 4. 0 & 1\n");
  printf("==> 5. 0 & 2\n");
  printf("==> 6. 1 & 2\n");
  printf("==> 7. 0 & 3\n");
  printf("==> 8. All Letters\n");
  printf("==> 9. All Rows\n");
  printf("==> c. custom random keys\n");
  printf("==> h. geeky tricks\n");
  printf("==> Q or X to exit\n");
  char input;
  system("/bin/stty raw");
  input = getchar();
  system("/bin/stty cooked");
  system("clear");
  return input;
}

void PlayNT(){
  scoreNT = 0;
  char str[15], input, lenall=strlen(all);
  int get;
  str[14] = '\0';
  srand(time(0));
  for(int i=0; i<14; i++)
    str[i] = all[rand()%lenall];
  while(1){
    printf("Score : '%d'\n\n", scoreNT);
    printf("%s\n", str);
    system("/bin/stty raw");
    input = getchar();
    system("/bin/stty cooked");
    system("clear");
    if(input == str[0]){
      scoreNT++;
      get = increaseString(str);
      str[13] = all[get%lenall];
    }else{
      printf("==> Scored : %d\n\n", scoreNT);
      if(input == 27){scoreNT = 0; return ;}
      scoreNT--;
      if(input == 127){custom(lenall); lenall=strlen(all);}
      else{
        system("clear");
        printf("WRONG!!!\n\n");
      }
    }
  }
}

int increaseString(char* str){
  for(int i=1; i<14; i++)
    str[i - 1] = str[i];
    struct timeval time; 
  gettimeofday(&time,NULL);
  srand((time.tv_sec * 100) + (time.tv_usec / 100));
//  srand(time(0));
  int a = rand()%26 , b = rand()%10;
  return a*(2*b + 1);
}

void tricks(){
  char ch;
  printf("NOTE: This game is only designed to be played with all TEN fingers\n");
  printf("     It's Just to improve your typing skill\n");
  printf("   small finger or ring finger becomes useless in typing (beginers)\n");
  printf("\n1. You can press 'backspace' key anywhere in the game.\n");
  printf("   And You will be able to customize Your Keys on the spot.\n");
  printf("2. In customization Edit mode repeating the same key, will\n");
  printf("   increase it's chances as many times in the game.\n");
  printf("3. customize keys to 'zaqw.;p' and try to play only with your small\n");
  printf("   fingers :).DO IT for any fingers which you feel useless in typing\n");
  printf(" ");
  printf("\npress '0' to know about the gamemaker\n");
  printf("press anyother key to return\n");
  system("/bin/stty raw");
  ch = getchar();
  system("/bin/stty cooked");
  system("clear");
  if(ch == '0') about();
}

void about(){
  char ch;
  printf("         V 1.0\n");
  printf("\n -->Vivek Kumar Gupta<--\n");
  printf("--->vivekgt@iitk.ac.in<---\n");
  printf("--->B.Tech 1stYear cse<---\n");
  printf("       IIT KANPUR\n");
  printf("\nPress any key to return game.\n");
  system("/bin/stty raw");
  ch = getchar();
  system("/bin/stty cooked");
  system("clear");
}
