 #include<stdio.h>
 #define M 99999 //　最も大きな数
 #define N 8 //ノードの総数

 /* プリントの無向グラフ[行列ともに0番目の要素は使用しないことにする] */
 //隣接していない要素には定数M を入れておく
 //隣接する要素には重みを入れておく
 //自分自身は1
 int m[N+1][N+1] = { {0, 0, 0, 0, 0, 0, 0, 0, 0},
					 {0, 1, 3, 4, 1, M, M, M, M},
					 {0, 3, 1, M, 2, M, M, M, M},
					 {0, 4, M, 1, M, 5, 3, M, M},
					 {0, 1, 2, M, 1, M, 2, M, M},
					 {0, M, M, 5, M, 1, 1, 6, 10},
					 {0, M, M, 3, 2, 1, 1, M, M},
					 {0, M, M, M, M, 6, M, 1, M},
					 {0, M, M, M, M, 10, M, M, 1}};

 int main(void)
 {
	/* ノード確定フラグ0 = 未確定, 1 = 確定*/
	int v[N+1];

	int x[N+1];

	 /* ノードまでの距離*/
	 int dist[N+1];
	 int i, j, point, start,finish, min;
	 printf("始点と終点を入力して，最短距離と最短経路を求めます\n\n");
	 printf("探索するグラフの隣接行列表現\n");
	 for(i=0; i<=N; i++)
	 {
		for(j = 0; j<=N;j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
 	 }
	 printf("\n\n");

	 printf("始点は？");
	 scanf("%d", &start);
	 printf("終点は？");
	 scanf("%d",&finish);
	 printf("\n");

	 /* 確定フラグ，距離配列を初期化する*/
	 for( i = 1; i <= N; i++ )
	 {
		 v[i] = 0; // 未確定で初期化
		 dist[i] = M; // 最も大きい値で初期化
	}

	 dist[start] = 0; //始点から始点への距離は0

	 for( i = 1; i <= finish; i++ )
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
			 {
				dist[j] = dist[point] + m[point][j];
				x[j] = point;
			 }
		  }
		 /* 最短距離の出力*/
		 printf("%d  ->  %d  までの最短距離は  %d  ", start, i, dist[i] );
		 if(i != start)
		 {
		   printf("直前のノードは %d\n",x[i]);
		 }
		 else printf("\n");  
	   }

	 printf("\n結果のゴール地点のノードから遡ると最短経路がわかる\n\n");
	 return 0;
	}