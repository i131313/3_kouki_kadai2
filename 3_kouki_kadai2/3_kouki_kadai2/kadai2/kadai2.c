 #include<stdio.h>
 #define M 99999 //�@�ł��傫�Ȑ�
 #define N 6 //�m�[�h�̑���

 /* �v�����g�̖����O���t[�s��Ƃ���0�Ԗڂ̗v�f�͎g�p���Ȃ����Ƃɂ���] */
 //�אڂ��Ă��Ȃ��v�f�ɂ͒萔M �����Ă���
 //�אڂ���v�f�ɂ͏d�݂����Ă���
 //�������g��1
 int m[N+1][N+1] = { {0, 0, 0, 0, 0, 0, 0},
					 {0, 1, 12, 28, M, M, M},
					 {0, 12, 1, 10, 13, M, M},
					 {0, 28, 10, 1, 11, 7, M},
					 {0, M, 13, 11, 1, M, 9},
					 {0, M, M, 7, M, 1, 4},
					 {0, M, M, M, 9, 4, 1}};

 int main(void)
 {
	/* �m�[�h�m��t���O0 = ���m��, 1 = �m��*/
	int v[N+1];

	int x[N+1];

	 /* �m�[�h�܂ł̋���*/
	 int dist[N+1];
	 int i, j, point, start,finish, min;

	 printf("�n�_�́H");
	 scanf("%d", &start);
	 printf("�I�_�́H");
	 scanf("%d",&finish);
	 printf("\n");

	 /* �m��t���O�C�����z�������������*/
	 for( i = 1; i <= N; i++ )
	 {
		 v[i] = 0; // ���m��ŏ�����
		 dist[i] = M; // �ł��傫���l�ŏ�����
	}

	 dist[start] = 0; //�n�_����n�_�ւ̋�����0

	 for( i = 1; i <= finish; i++ )
	 {
		 /* �ŏ��̃m�[�h��T��*/
		 min = M;
		 for( j = 1; j <= finish; j++ )
		 {
			 if( v[j] == 0 && dist[j] < min )
			 {
			 point = j;
			 min = dist[j];
			 }
		 }
		 v[point] = 1; //�ŏ��̃m�[�h���m��
		 /* point ���o�R����j �Ɏ��钷��������܂ł̍ŒZ������菬������΍X�V*/
		 for( j = 1; j <= finish; j++ )
		 {
			 if( (dist[point] + m[point][j]) < dist[j] )
			 {
				dist[j] = dist[point] + m[point][j];
				x[j] = point;
			 }
			
		  }
		 printf("%d  ->  %d  �܂ł̍ŒZ������  %d  ", start, i, dist[i] );
		 if(i != 1)
		   printf("���O�̃m�[�h�� %d\n",x[i]);
		 else printf("\n");
		      
	   }
	  /* �ŒZ�����̏o��*/
	 /*for( i = 1; i <= N; i++)
	 printf("%d  ->  %d  �܂ł̍ŒZ������  %d\n", start, i, dist[i]);*/
	 printf("\n�ŒZ�o�H��  ");
	 for(i = 1; i<= finish; i++)
	 {
		if(x[i] != x[i-1]) printf("%d  ->  ",x[i]);
	 }
	 printf("%d\n\n",finish);
	 return 0;
	}