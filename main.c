#include <stdio.h>
#include <string.h>
enum {
    EXIT,
    INSERT,
    SEARCH,
    DELETE,
    PRINT_ALL
};
//회원정보 하나 저장할 구조체, 이름, 나이, 성별
typedef struct member{
    char name[30];
    int age;
    char gender;//M, F
}Member;
Member arr[20] ={
    {"홍길동", 22, 'F'},
    {"김철수", 32, 'M'},
    {"이학우", 12, 'F'}
};
int idx = 3; // arr 제어할 변수
void InsertMember(){
    //회원정보 하나 입력을 받아서 arr에 등
    if(idx == 20){
        printf("더이상 저장할 공간이 없습니다\n");
        return;
    }
    printf("이름 입력 : ");
    scanf(" %s",arr[idx].name);
    printf("나이 입력 : ");
    scanf(" %d",&arr[idx].age);
    printf("성별 입력 : ");
    scanf(" %c",&arr[idx].gender);
    idx++;//인덱스 번호 하나 증가
    printf("회원정보 등록 완료\n");
}
void PrintAllMember(){
    //전체 회원 정보를 출력
    printf("전체 회원정보 출력\n\n");
    for(int i=0;i<idx;i++)  
        printf("%s %d %c\n",arr[i].name, arr[i].age, arr[i].gender);  
    printf("\n");
}
void SearchMember(){
//이름하나 입력 받아서
//구조체가 가지고 있는 name과 동일한 데이터를 찾음
    char str[30];
    printf("검색할 이름 입력 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            printf("%s %d %c\n",arr[i].name, arr[i].age, arr[i].gender);  
            return;
        }
    }
    printf("검색 결과가 없습니다.\n");
}
void DeleteMember(){
    //삭제할 이름 입력을 받음
    char str[30];
    printf("삭제할 이름 입력 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            //삭제를 수행
            //배열의 내용을 한칸씩 땡김
            for(int j=i;j<idx-1;j++)
                arr[j] = arr[j+1];
            idx--;//인덱스 값 감소
            return;
        }
    }
    printf("삭제할 데이터가 없습니다.\n");
}
int main(void){
    int no = -1;

    while(no != EXIT){
        puts("--- 회원정보 관리 프로그램 ---");
        puts("1. 회원정보 등록");
        puts("2. 회원정보 검색");
        puts("3. 회원정보 삭제");
        puts("4. 전체 회원정보 등록");
        puts("0. 프로그램 종료");
        puts("원하시는 메뉴 번호 입력 : ");
        scanf("%d",&no);

        switch(no){
            case INSERT:
                InsertMember();
                break;
            case SEARCH:
                SearchMember();
                break;
            case DELETE:
                DeleteMember();
                break;
            case PRINT_ALL:
                PrintAllMember();
                break;
        }
    }

    return 0;
}