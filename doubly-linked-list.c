/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
         singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h);

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
        - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	printf("[----- [조수현]  [2018038084] -----]\n\n");

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}


int initialize(headNode** h) 
{
	if(h != NULL)
	{
		freeList(h);
	}

	h = (heaNode**)malloc(sizeof(headNode));
	h->first = NULL;
	return 1;
}

int freeList(headNode* h)
{
	listNode *p_left = h->first;
	listNode *p_right = h->first;
	listNode *prev = NULL;

	while(p != NULL)
	{
		prev = p_left;
		p_left = p->llink;
		free(prev);

		prev = p_right;
		p_right = p->rlink;
		free(prev);
	}

	free(h);
	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) 
{
	if(h == NULL)
	{
		printf("헤드노드를 초기화 해주십시오\n\n");
		return 0;
	}

	listNode *temp;
	temp = h->first;

	if(temp->rlink == NULL)
	{
		listNode *node = (listNode*)malloc(sizeof(listNode));
		node->key = key;
		node->rlink = NULL;
		temp->rlink = node->llink;
		
		return 0;
	}
	else
	{
		while(temp->rlink != NULL)
		{
			temp = temp->rlink;
		}

		listNode *node = (listNode*)malloc(sizeof(listNode));
		node->key = key;
		node->rlink = NULL;
		temp->rlink = node->llink;

		return 0;
	}
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h)
{
	if(h == NULL)
	{
		printf("헤드노드를 초기화 해주십시오.\n\n");
		return 0;
	}

	if(h->first == NULL)
	{
		printf("지울 노드가 없습니다.\n\n");
		return 0;
	}

	listNode *temp;
	listNode *trail;
	temp = h->first;

	while(temp->rlink != NULL)
	{
		trail = temp;
		temp = temp->rlink;
	}

	trail->rlink = NULL;
	free(temp);

	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) 
{
	if(h == NULL)
	{
		printf("헤드노드를 초기화 해주십시오.\n\n");
		return 0;
	}

	listNode *node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->rlink = h->first;
	h->first = node->llink;
	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) 
{
	if(h == NULL)
	{
		printf("헤드노드를 초기화 해주십시오.\n\n");
		return 0;
	}

	if(h->first == NULL)
	{
		printf("삭제할 노드가 없습니다.\n\n");
		return 0;
	}

	listNode *temp;
	
	temp = h->first;
	h->first = h->first->llink;
	free(temp);

	return 0;
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) 
{
	if(h == NULL)
	{
		printf("헤드노드를 초기화 해주십시오.\n\n");
		return;
	}

	listNode* middle;
	listNode* trail;
	listNode* node;

	node = h->first;
	middle = NULL;

	while(node != NULL)
	{
		trail->rlink = middle->llink;
		middle->rlink = node->llink;
		node = node->rlink;
		middle->rlink = trail->llink;
	}

	h->first = middle;
	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) 
{
	if(h == NULL)
	{
		printf("헤드노드를 초기화 해주십시오\n\n");
		return 0;
	}

	listNode* temp;
	temp = h->first;

	if(h->first == NULL)
	{
		insertFirst(h, key);
		return 0;
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->rlink == NULL)
			{
				insertLast(h, key);
				return 0;
			}
			else if(key < temp->rlink->key)
			{
				listNode *node = (listNode*)malloc(sizeof(listNode));
				node->key = key;
				node->rlink = temp->rlink;
				temp->rlink = node->llink;
				return 0;
			}
			temp = temp->rlink;
		}
	}
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) 
{
	if(h == NULL)
	{
		printf("헤드노드를 초기화 해주십시오.\n\n");
		return 0;
	}

	listNode *temp;
	listNode *trail;
	temp = h->first;
	trail = temp;

	if(temp == NULL)
	{
		printf("삭제할 노드가 없습니다.\n\n");
		return 0;
	}

	while(temp != NULL)
	{
		if(temp->key == key)
		{
			if(trail == temp)
			{
				deleteFirst(h);
				return;
			}

			trail->rlink = temp->rlink;
			free(temp);
			return;
		}

		trail->rlink = temp->llink;
		temp = temp->rlink;
	}

	printf("해당 노드가 존재하지 않습니다.\n\n");
	return 0;
}