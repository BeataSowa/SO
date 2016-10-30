#include <iostream>
#include <pthread.h>

using namespace std;
pthread_mutex_t blokada;
int z= 0;


void* test(void* t)
{
	pthread_mutex_lock(&blokada);
	
	int* k = (int*)t;
	cout<< *k << endl;
	(*k)++;
	
	pthread_mutex_unlock(&blokada);
	
	pthread_exit(NULL);	
	
}

int main()
{
	int n;
	cout <<"Podaj ile wątków: ";
	cin >>n;
	pthread_t watki[n];
	
	for ( int i=0; i<n; i++)
	{
		//int pthread create(pthread t *id, const pthread attr t *attr, void* (fun*)(void*), void* arg)
		pthread_create(&watki[i], NULL, test, &z);
	}
	
	for(int i=0; i<n; i++)
	{
		pthread_join(watki[i],NULL);
	}
	
	cout<<"Hello"<<endl;

  return 0;
}
