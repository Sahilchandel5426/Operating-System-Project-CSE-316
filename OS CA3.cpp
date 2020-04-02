#include <stdio.h>
#include <semaphore.h>
#include <string.h>
sem_t left;
sem_t right;
sem_t waitingForRight;
sem_t waitingForLeft;

void LeaveShop (char s[])
{
 if (strcmp (s, "LEFT") == 0)
  {
   sem_post (&left);
  }
 else if (strcmp (s, "RIGHT") == 0)
  {
   sem_post (&right);
  }
   
  return;
}

void ShopForAWhile()
{
	
 //some statements
 return;
 
}

void EnterShop (char s[])
{

 if (strcmp (s, "LEFT") == 0)
  {

   sem_wait (&waitingForRight);
   int i = 0;
   int j = 0;
   int k = 0;
   while ((i > 0) && (j == 1) && (k == 1))
{
	
 sem_getvalue (&waitingForLeft, &i);
 sem_getvalue (&left, &j);
 sem_getvalue (&right, &k);
 
};

   sem_wait (&left);
   sem_post (&waitingForRight);
   ShopForAWhile ();
   LeaveShop ("LEFT");
   
  }

 else if (strcmp (s, "RIGHT") == 0)
  {

   sem_wait (&waitingForLeft);
   int l = 0;
   int m = 0;
   int n = 0;
   while ((l > 0) && (m == 1) && (n == 1))
   
{
	
 sem_getvalue (&waitingForRight, &l);
 sem_getvalue (&left, &m);
 sem_getvalue (&right, &n);
 
};

   sem_wait (&right);
   sem_post (&waitingForLeft);
   ShopForAWhile ();
   LeaveShop ("RIGHT");
   
  }
   
  return;
}



int main ()
{

 sem_init (&left, 0, 0);
 sem_init (&right, 0, 0);
 sem_init (&waitingForRight, 0, 0);
 sem_init (&waitingForLeft, 0, 0);
 
 return 0;
}


