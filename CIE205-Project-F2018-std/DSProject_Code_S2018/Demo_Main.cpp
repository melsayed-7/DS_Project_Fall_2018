#include "Battle.h"
#include "GUI\GUI.h"


int main()

{
	
	//// this is a test and demo for how to use the input function
	//Queue<int*> *enemy_queue = get_file_2_queue();
	//int*print_vector = new int[7];
	//int size = enemy_queue->getsize();

	//for (int i = 0; i < size; i++)
	//{
	//	print_vector = enemy_queue->deque();
	//	for (int i = 0; i < 7; i++)
	//	{
	//		cout << print_vector[i] << " ";
	//	}
	//	cout << endl;
	//}

	Battle* pGameBattle = new Battle;
	pGameBattle->RunSimulation();
	//delete pGameBattle;
	
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

