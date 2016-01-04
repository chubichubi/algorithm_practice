#include <stdio.h>
#define MIN(a,b)(((a)>(b))?(b):(a))

unsigned long long arr2[32];
unsigned long long arr5[14];

int main()
{
	unsigned long long N, M, N_M;

	arr2[0] = 2;
	for (int i = 1; i <= 31; i++){
		arr2[i] = arr2[i - 1] * 2;
	}

	arr5[0] = 5;
	for (int i = 1; i <= 13; i++){
		arr5[i] = arr5[i - 1] * 5;
	}

	unsigned long long n_2, n_5;
	unsigned long long m_2, m_5;
	
	n_2 = n_5 = m_2 = m_5 = 0;

	scanf("%llu %llu", &N, &M);

	N_M = N - M;


	for (int i = 31; i >= 0; i--){
		if (N >= arr2[i]){
			unsigned long long tmp = N / arr2[i];
			n_2 += tmp;
		}
		if (M >= arr2[i]){
			unsigned long long tmp = M / arr2[i];
			m_2 += tmp;
		}
		if (N_M >= arr2[i]){
			unsigned long long tmp = N_M / arr2[i];
			m_2 += tmp;
		}
	}
	
	for (int i = 13; i >= 0; i--){
		if (N >= arr5[i]){
			unsigned long long tmp = N / arr5[i];
			n_5 += tmp;
		}
		if (M >= arr5[i]){
			unsigned long long tmp = M / arr5[i];
			m_5 += tmp;
		}
		if (N_M >= arr5[i]){
			unsigned long long tmp = N_M / arr5[i];
			m_5 += tmp;
		}
	}

	//printf("n_2:%d n_5:%d m_2:%d m_5:%d\n", n_2, n_5, m_2, m_5);

	if (m_2 > n_2 || m_5 > n_5){
		//printf("????");
		printf("%d\n", 0);
	}
	else if (n_2 >= m_2 && n_5 >= m_5){
		n_2 = n_2 - m_2;
		n_5 = n_5 - m_5;

		int ans = MIN(n_2, n_5);
		printf("%d\n", ans);
	}
	
	

	return 0;
}