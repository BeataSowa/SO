#include <iostream>
#include <pthread.h>

using namespace std;
void* test(void* t)
{
	cout<<"HELLO";
	return NULL;	
	
}

int main()
{
	int n;
	cout <<"Podaj ile wątków";
	cin >>n;
	pthread_t watki[n];
	
	for (int i=0; i<n; i++)
		//int pthread create(pthread t *id, const pthread attr t *attr, void* (fun*)(void*), void* arg)
		pthread_create(&watki[i], NULL, test, NULL);

  return 0;
}
