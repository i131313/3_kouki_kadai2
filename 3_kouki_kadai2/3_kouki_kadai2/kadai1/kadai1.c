#include<stdio.h>

#define N 8
/* �v�����g�̖����O���t[�s��Ƃ���0�Ԗڂ̗v�f�͎g�p���Ȃ����Ƃɂ���] */
 int m[N+1][N+1] = { {0, 0, 0, 0, 0, 0, 0, 0, 0},
					 {0, 1, 1, 1, 1, 0, 0, 0, 0},
					 {0, 1, 1, 0, 1, 0, 0, 0, 0},
					 {0, 1, 0, 1, 0, 1, 1, 0, 0},
					 {0, 1, 1, 0, 1, 0, 1, 0, 0},
					 {0, 0, 0, 1, 0, 1, 1, 1, 1},
					 {0, 0, 0, 1, 1, 1, 1, 0, 0},
					 {0, 0, 0, 0, 0, 1, 0, 1, 0},
					 {0, 0, 0, 0, 0, 1, 0, 0, 1}};

 /* �m�[�h�K��t���O0 = ���K��, 1 = �K��ς�*/
 int v[N+1];

 /* �L���[�֌W*/
 int queue[100]; // �L���[�{��
 int head = 0; // �擪�f�[�^�̃C���f�b�N�X
 int tail = 0; // �I�[�f�[�^�̃C���f�b�N�X

 void depth(int);
 void breadth(void);

int main(void)
{
	char houhou;
	printf("�T�����@��I�����Ă�������(�[��:d, ��:b):");
	scanf("%c",&houhou);

	switch(houhou)
	{
		case 'd':
			{
				int i;
				/* �K��t���O������������ */
				for(i = 1; i <= N; i++)
		     	    v[i] = 0;

				depth( 1 ); // �o���_���m�[�h 1�Ƃ��ĒT���J�n
			}
			break;

		case 'b':
			breadth();
			break;

	}
	return 0;

}

void depth(int num)
{
	int i;

	v[num] = 1; //�K��t���O��K��ς݂ɍX�V

	/* ���̏ꏊ�ɉ��炩�̕K�v�ȏ��������� */
	
	/* �S�Ẵm�[�h�ɂ��āC�K�����͂�����ʂ� */

	for( i = 0; i <= N; i++)
	{
		/* �m�[�h����o��ӂƂ��̐�̃m�[�h�̖K��󋵂��`�F�b�N */
		if( m[num][i] == 1 && v[i] == 0)
		 {
			/* ���K��ł���ΖK�₷�� */
			 printf("�m�[�h %d ����%d ��K��\n", num, i);
			 depth( i ); //depth �̍ċA�Ăяo��
		}
	}
}

void breadth(void)
{
	int i, j;

	/* �K��t���O������������*/
	for( i = 1; i <= N; i++)
		v[i] = 0;

	/* �T���J�n*/
	// �o���_�ł���m�[�h1���L���[�ɓ����
	queue[tail++] = 1;
	v[1] = 1; // �K��ς݂ɂ��Ă���

	 /* �L���[����ɂȂ�܂ŌJ��Ԃ�*/
	 do{
		 i = queue[head++]; //�L���[����1���o��

		 for( j = 1; j <= N; j++)
		 {
			 /* �m�[�h����o��ӂƂ��̐�̃m�[�h�̖K��󋵂��`�F�b�N*/
			 if( m[i][j] == 1 && v[j] == 0)
			 {
				 /* ���K��ł���L���[�ɓ����*/
				 queue[tail++] = j;
				 v[j] = 1; // �L���[�ɓ��ꂽ���_�ŖK��ς݂ɂ��Ă��܂�
			 }
		 }
		// �K��󋵂̕\��
		printf("->%d", i);
		} while ( head != tail );

	 printf("\n");
}