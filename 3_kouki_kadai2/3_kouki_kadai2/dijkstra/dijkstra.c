 #include<stdio.h>
 #define M 99999 //　最も大きな数
 #define N 6 //ノードの総数

 /* プリントの無向グラフ[行列ともに0番目の要素は使用しないことにする] */
 //隣接していない要素には定数M を入れておく
 //隣接する要素には重みを入れておく
 //自分自身は1
 int m[N+1][N+1] = { {0, 0, 0, 0, 0, 0, 0},
					 {0, 1, 12, 28, M, M, M},
					 {0, 12, 1, 10, 13, M, M},
					 {0, 28, 10, 1, 11, 7, M},
					 {0, M, 13, 11, 1, M, 9},
					 {0, M, M, 7, M, 1, 4},
					 {0, M, M, M, 9, 4, 1}};

 int main(void)
 {
	/* ノード確定フラグ0 = 未確定, 1 = 確定*/
	int v[N+1];

	 /* ノードまでの距離*/
	 int dist[N+1];
	 int i, j, point, start, min;

	 printf("始点は？");
	 scanf("%d", &start);

	 /* 確定フラグ，距離配列を初期化する*/
	 for( i = 1; i <= N; i++ )
	 {
		 v[i] = 0; // 未確定で初期化
		 dist[i] = M; // 最も大きい値で初期化
	}

	 dist[start] = 0; //始点から始点への距離は0

	 for( i = 1; i <= N; i++ )
	 {
		 /* 最小のノードを探す*/
		 min = M;
		 for( j = 1; j <= N; j++ )
		 {
			 if( v[j] == 0 && dist[j] < min )
			 {
			 point = j;
			 min = dist[j];
			 }
		 }
		 v[point] = 1; //最小のノードを確定
		 /* point を経由してj に至る長さがそれまでの最短距離より小さければ更新*/
		 for( j = 1; j <= N; j++ )
		 {
			 if( (dist[point] + m[point][j]) < dist[j] )
			 dist[j] = dist[point] + m[point][j];
			 }
		 
		 }
	 /* 最短距離の出力*/
	 for( i = 1; i <= N; i++)
	 printf("%d  ->  %d  までの最短距離は  %d\n", start, i, dist[i]);
	 return 0;
	}