#include<stdio.h>
#include<conio.h>

#define N 8
 
 /* ノード訪問フラグ0 = 未訪問, 1 = 訪問済み*/
 int v[N+1];

 /* キュー関係*/
 int queue[100]; // キュー本体
 int head = 0; // 先頭データのインデックス
 int tail = 0; // 終端データのインデックス

 void depth(int, int a[][N+1]);
 void breadth(int[][N+1]);

int main(void)
{
	char houhou;
	int i,j;
	int a[N+1][N+1];
   
	printf("グラフを隣接行列表現で入力してください\n(i×j行列 辺(i,j)が存在すれば1,そうでなければ0）\n");
	printf("ノードは8個です\n\n");
	printf("※1行目と1列目は「0」がすでに入力されています");
	//do{
	for(i = 0; i <= N; i++) 
	{
		a[0][i] = 0;
		a[i][0] = 0;
	}
	
	
    for(i=1;i<=N;i++){
	 modoru:   printf("\n\n%dつ目のノードについて入力してください\n",i);
    for(j=1;j<=N;j++){
        a[i][j] = getche();
	    if(a[i][j] == 48) a[i][j] = 0;
	    else if(a[i][j] == 49) a[i][j] = 1;
	    else 
	    {
		 printf("入力しなおしてください"); goto modoru;
	    }
	}
	}
	
	//}while(i<N);
	printf("\n\n探索するグラフの隣接行列表現\n");
	for(i=0; i<=N; i++)
	{
		for(j = 0; j<=N;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	printf("探索方法を選択してください(深さ:d, 幅:b):");
	scanf(" %c",&houhou);

	switch(houhou)
	{
		case 'd':
			{
				int i,start;
				printf("どのノードから探索しますか？:");
				scanf("%d",&start);
				/* 訪問フラグを初期化する */
				for(i = 1; i <= N; i++)
		     	    v[i] = 0;

				depth( start , a); // 出発点をノード 1として探索開始
			}
			break;

		case 'b':
			breadth(a);
			break;

	}
	printf("\n");
	return 0;

}

void depth(int num, int a[][N+1])
{
	int i;

	v[num] = 1; //訪問フラグを訪問済みに更新

	/* この場所に何らかの必要な処理を書く */
	
	/* 全てのノードについて，必ず一回はここを通る */

	for( i = 0; i <= N; i++)
	{
		/* ノードから出る辺とその先のノードの訪問状況をチェック */
		if( a[num][i] == 1 && v[i] == 0)
		 {
			/* 未訪問であれば訪問する */
			 printf("ノード %d から%d を訪問\n", num, i);
			 depth( i, a ); //depth の再帰呼び出し
		}
	}
}

void breadth(int a[][N+1])
{
	int i, j,start;

	printf("どのノードから探索しますか？:");
	scanf("%d",&start);

	/* 訪問フラグを初期化する*/
	for( i = 1; i <= N; i++)
		v[i] = 0;

	/* 探索開始*/
	// 出発点であるノードをキューに入れる
	queue[tail++] = start;
	v[start] = 1; // 訪問済みにしておく

	 /* キューが空になるまで繰り返す*/
	 do{
		 i = queue[head++]; //キューから1つ取り出す

		 for( j = 1; j <= N; j++)
		 {
			 /* ノードから出る辺とその先のノードの訪問状況をチェック*/
			 if( a[i][j] == 1 && v[j] == 0)
			 {
				 /* 未訪問であれキューに入れる*/
				 queue[tail++] = j;
				 v[j] = 1; // キューに入れた時点で訪問済みにしてしまう
			 }
		 }
		// 訪問状況の表示
		printf("%d  ", i);
		if(i!=N) printf("-> ");
		} while ( head != tail );

	 printf("\n");
}