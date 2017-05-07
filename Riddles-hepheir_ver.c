#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int corrects = 0;

int quest (char q[], char a[], char e1[], char e2[], char e3[]) {
    printf("\n\n다음 문제 입니다.\n%s\n\n", q);

    srand(time(NULL));
    int r = rand()%4,
        user_submission,
        answer_num,
        //보기 순서를 랜덤으로 출력하면서 중복되지 않게 하기위해 각 보기의 출력 여부를 저장하는 변수 선언
        status[4] = {0, 0, 0, 0};

    for (int i = 1; i <= 4; i++) {
        //지금 출력하려는 보기의 출력 여부 체크
        while (status[r] != 0) {
            r = rand()%4;
        }
        status[r] = 1;
        if(r == 0) {
            answer_num = i;
        }
        switch (r) {
            case 0:
                printf("%d. %s\n", i , a);
                break;
            case 1:
                printf("%d. %s\n", i , e1);
                break;
            case 2:
                printf("%d. %s\n", i , e2);
                break;
            case 3:
                printf("%d. %s\n", i , e3);
                break;
            default:
                printf("..bug?");
        }
    }
    printf("\n답: ");
    scanf("%d", &user_submission);
    
    if (user_submission == answer_num) {
        printf("\n정답!!\n");
        corrects++;
    } else {
        printf("\n땡!!!!! \n");
        printf("\n지금 까지 내가 맞힌 정답 갯수: %d\n\n종료하려면 아무 값이나 입력해 주십시오.", corrects);
        scanf("%d", &corrects); //System("pause");같은 용도
        exit(1);
    }
    return 0;
}

int main (void) {
    int level;

    printf("=======================\n");
	printf("*     CQP ver 1.1     *\n");
    printf("=======================\n");

    while (level != 1 && level != 2 && level != 3) {
        printf("\n난이도를 설정해 주십시오.\n[ 쉬움 : 1, 중간 : 2, 어려움 : 3 ]\n");
        scanf("%d", &level);
    }

    // quest함수 입력값 순서 : quest(질문, 정답, 보기1, 보기2, 보기3);
    if (level == 1) {
        printf("난이도를 '쉬움' 으로 설정하셨습니다. \n");
        quest("할아버지와 손자가 길을 걷다가 산불을 보고 손자가 할아버지에게 한 말은?", "산타할아버지", "할아버지 가을이네요!", "캠프파이어다!!!", "물 어딨지?");
        quest("수박 한통에 5000원이다. 그럼 수박 두통엔?", "타이레놀", "10000원", "씨없는수박", "노란수박");
        quest("원숭이를 화로에 넣었다 빼면 어떻게 될까요?", "구운몽", "원숭이 바비큐", "훈제원숭이", "MC몽");
        quest("걸을 때마다 검은 가루를 흘리며 가는 것은?", "후추통", "연필", "지우개", "박명수");
        quest("짧은 개가 사는 집은?", "단독주택", "아파트", "개집", "연립주택");
        quest("손바닥으로 움켜쥐면 한 웅큼이요, 두 팔로 껴안으면 한 아름 되는 것은", "솥뚜껑", "방석", "재떨이", "맷돌");
        quest("1년에 일곱 달은 31일 , 네 달은 30일이 있습니다. 그렇다면 28일 은 몇 번 있을까요", "1년에 12번", "없다", "4년에 1번", "1번");
        quest("깨뜨리고 칭찬 받는 것은?", "신기록", "접시", "액자", "유리잔");
        quest("사과 반쪽과 닮은것은??", "남은 사과 반쪽", "얼굴", "수박", "참외");
    } else if (level == 2) {
        printf("난이도를 '중간' 으로 설정하셨습니다. \n");
        quest("삼포세대는 경제불황 때문에 생긴 말로 연애, 결혼 그리고 이것을 포기한 세대를 뜻한다. 이것은?", "출산", "취업", "여가", "효도");
        quest("손버릇이 나쁘다를 영어로 'have 이것 finfgers'라고 하는데 이것은?", "sticky(끈적거리는)", "bad(나쁜)", "smelly(냄새나는)", "smooth(매끈한)");
        quest("다음 중 사람 이름인것은?", "에펠탑의 '에펠'", "피사의 사탑의 '피사'", "오르세 미술관의 '오르세'", "모아이 석상의 '모아이'");
        quest("토익의 최고 점수는 990점이다. 그렇다면 최저는??", "10", "20", "0", "5");
        quest("'사람이 차에 치였다.' 를 줄이면?", "붕어빵", "소보루빵", "으앙듀금", "찹살떡");
        quest("남자쇼트트랙 계주에 있는 종목은?", "5000m", "3000m", "4000m", "6000m");
        quest("동요 뽀뽀뽀에서 뽀뽀뽀는 몇번??", "7번", "5번", "6번", "8번");
        quest("네트가 없는 경기는?", "피구", "배구", "탁구", "축구");
        quest("태평양에서는 우리나라 인물을 딴 지명이 있다. 그 인물은?", "장보고", "이순신", "세종", "사도세자");
        quest("가축이 아닌 것은?", "귀뚜라미", "지렁이", "개", "꿀벌");

    } else {
        printf("난이도를 '어려움' 으로 설정하셨습니다. \n");
        quest("메이저리그에서 최초로 영구결번을 선물받은 선수와 등번호는?", "뉴욕 양키스의 '루게릭' 4번", "뉴욕 양키스의 '베이스 루스' 3번", "뉴욕 양키스의 '조 디마지오' 5번", "뉴욕 양키스의 '요기베라' 8번");
        quest("다음 중 맞춤법에 맞는 표현의 갯수는? \n '어따 대고/ 얻다 대고' 에서 얻다 대고 \n '설레임/ 설렘' 에서 설레임 \n '왠지 / 웬지'에서 왠지", "2", "0", "1", "3");
        quest("바둑판 한가운데의 점 또는 그 자리에 놓은 바둑돌을 일컫는 말은?", "천원", "십원", "백원", "만원");
        quest("단돈 한푼도 없다라는 표현은 영어로 <not have a (   ) cent>라고 쓴다. 빈칸은??", "red", "blue", "black", "yellow");
        quest("피사의 사탑의 계단수는?", "297개", "294개", "300개", "303개");
        quest("모차렐라 치즈가 처음 만들어진 것으로 알려진 12세기경에는 이것의 젖으로 만들었는데 이것은?", "물소", "낙타", "염소", "사슴");
        quest("다음중에서 <부치는>것은?", "짐", "우표", "밥풀", "불");
        quest("감정을 유발하여 경쟁의식을 유발하는 효과는??", "메기 효과", "쉬리 효과", "뱀장어 효과", "꼼장어 효과");
        quest("한국 대통령의 아호중 어리석은 집이라는 별칭을 가진 대통령은?", "노태우", "김영삼", "이명박", "박근혜");
        //남극 세종기지면 한글창제한 자 아닌가..?
        quest("펭귄이 사는 곳에 있는 과학기지는?", "목민심서를 쓴 자", "한글 창제한 자", "청해진과 관련된 자", "거중기를 만든 자");
    }

    printf("\n내가 맞힌 정답 갯수: %d\n\n종료하려면 아무 값이나 입력해 주십시오.", corrects);
    scanf("%d", &corrects); //System("pause");같은 용도
    return 0;
}