#include "Battle.h"
#include "GUI\GUI.h"
#include "Data_strutres_in_use/heap/Heap.h"
#include"Data_strutres_in_use/Queue/Queue.h"
int main()

{
	
	Battle* pGameBattle = new Battle;
	pGameBattle->RunSimulation();
	
	delete pGameBattle;
	
	return 0;
}





// heap test
//Heap<int> *h = new Heap<int>;
//for (int i = -50; i < 0; i++)
//{
//	h->Enqueue(i, i);
//}
//for (int i = -50; i < 0; i++)
//{
//	h->Enqueue(i, i);
//}
//for (int i = -50; i < 0; i++)
//{
//	cout << h->Dequeue()->getdata() << endl;
//}
//for (int i = -50; i < 0; i++)
//{
//	cout << h->Dequeue()->getdata() << endl;
//}

