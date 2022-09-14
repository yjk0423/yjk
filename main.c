#include <stdio.h>
#include <string.h>

enum doWhat{
    INSERT = 1, SEARCH, DELETE, UPDATE, QUIT
};

typedef struct tel {
    char name[11];
    int number;
}Tel;

int idx = 0;
struct tel arr[10] = { 0 };

void InsertTel(){
    printf("이름을 입력해주세요 : ");
    scanf("%s", arr[idx].name);
    printf("번호를 입력해주세요 : ");
    scanf("%d", &arr[idx].number);
    idx++;
    printf("등록 완료");
}
void SearchTel(){
    char str[11];
    printf("검색할 이름 입력 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            printf("%s %d\n",arr[i].name, arr[i].number);
            return;
        }
    }
    printf("검색 결과가 없습니다.\n");
}
void DeleteTel(){
    char str[11];
    printf("삭제할 이름 입력 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            for(int j=i;j<idx-1;j++)
                arr[j] = arr[j+1];
            idx--;
            return;
        }
    }
    printf("삭제할 데이터가 없습니다.\n");
}
void UpdateTel(){
    char str[11];
    printf("수정할 이름 입력 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            printf("수정할 번호 입력 : ");
            scanf("%d",arr[i].number);
            return;
        }
    }
    printf("검색 결과가 없습니다.\n");
}

int main(void) {
    int no=0;

    while (no != QUIT) {
        printf("원하는 기능을 입력해주세요.\n");
        printf("연락처 등록 : 1\n");
        printf("연락처 검색 : 2\n");
        printf("연락처 삭제 : 3\n");
        printf("연락처 수정 : 4\n");
        printf("종료 : 5\n");
        scanf("%d", &no);
        switch (no)
        {
        case INSERT:
            InsertTel();
            break;
        case SEARCH:
            SearchTel();
            break;
        case DELETE:
            DeleteTel();
            break;
        case UPDATE:
            UpdateTel();
            break;
        default:
            break;
        }
    }

    return 0;
}