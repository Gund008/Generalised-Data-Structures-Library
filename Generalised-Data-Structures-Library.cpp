/*
    This Program contains Generic code for all types of linked list as
    1 - Singly Linear Linked list
    2-  Singly Circular Linear Linked list
    3-  Doubly Linear Linked List
    4-  Doubly Circular Linear Linked list
    5-  Linked List Using Stack
    6-  Linked List Using Queue

*/
#include<iostream>
using namespace std;

//Structure of Singly Linear And Singly Circular Linked List
    
template<class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

//Structure of Doubly Linear And Doubly Circular Linked List

template<class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

//Structure of Queue in Linked List

template<class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};


////////////////////////////////////////////////////////////////////////

//Class Name-Singly Linear Linked List
//Description-This Class Represents Singly Linear Linked list

////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyLL
{
    //Characteristics
    public:
    struct nodeS<T> *First;

    SinglyLL();
    //Behaviour
    void InsertFirst(T iNo);   
    void Display();
    int Count();
    void InsertLast(T iNo); 
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int iPos,T iNo);
    void DeleteAtPos(int iPos);
    int SearchFirstOcc(T iNo);
    int SearchLastOcc(T iNo);
};

////////////////////////////////////////////////////////////////////////

//Class Name-Doubly Linear Linked List
//Description-This Class Represents Doubly Linear Linked list

////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLL
{
    public:
    struct nodeD<T> *First;

    DoublyLL();
    void InsertFirst(T iNo);   
    void Display();
    int Count();
    void InsertLast(T iNo);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int iPos,T iNo);
    void DeleteAtPos(int iPos);
};


////////////////////////////////////////////////////////////////////////

//Class Name-Singly Circular Linked List
//Description-This Class Represents Singly Circular Linked list

////////////////////////////////////////////////////////////////////////


template<class T>
class SinglyCL
{
    public:
    struct nodeS<T> *First;
    struct nodeS<T> *Last;

    SinglyCL();
    void InsertFirst(T iNo);
    void Display();
    int Count();
    void InsertLast(T iNo);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int iPos,T iNo);
    void DeleteAtPos(int iPos);
};

////////////////////////////////////////////////////////////////////////

//Class Name-Doubly Circular Linked List
//Description-This Class Represents Doubly Circular Linked list

////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyCL
{
    public:
    struct nodeD<T> *First;
    struct nodeD<T> *Last;

    DoublyCL();
    void InsertFirst(T iNo);
    void Display();
    int Count();
    void InsertLast(T iNo);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int iPos,T iNo);
    void DeleteAtPos(int iPos);
};

////////////////////////////////////////////////////////////////////////

//Class Name-Stack
//Description-This Class Represents  Linked list Using Stack

////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    public:
    struct nodeS<T> *First;
    int iCount;

    Stack();

    bool IsStackEmpty();
    void push(T);   
    T Pop();
    void Display();
};

////////////////////////////////////////////////////////////////////////

//Class Name-Queue
//Description-This Class Represents  Linked list Using Queue

////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    public:
    struct nodeQ<T> *First;
    int iCount;

    Queue();

    bool IsQueueEmpty();
    void EnQueue(T);   
    T Dequeue();
    void Display();
};

////////////////////////////////////////////////////////////////////////

//Function Name:Singly linear Linked list
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//        This is Constructor of class Singly Linear Linked list.
//Input:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
SinglyLL<T>::SinglyLL()
{
    First=NULL;
}


////////////////////////////////////////////////////////////////////////

//Function Name:InsertFirst
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:
//        This is InsertFirst of class Singly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
    struct nodeS<T> *newn=NULL;
    newn=new struct nodeS<T>;
    
    newn->data=iNo;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
}

////////////////////////////////////////////////////////////////////////

//Function Name:Display
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//         Display of Node Used in class Singly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Linked list Elements are:\n";
    struct nodeS<T> *temp=First; 

    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"\n";
}


////////////////////////////////////////////////////////////////////////

//Function Name:Count
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//          Count of Node Using in class Singly Linear Linked list.
//Return:integer

////////////////////////////////////////////////////////////////////////


template<class T>
int SinglyLL<T>::Count()
{
    int iCnt=0;
    struct nodeS<T> *temp=First; 

    while(temp!=NULL)
    {
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}


////////////////////////////////////////////////////////////////////////

//Function Name:InsertLast
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:
//        This is  InsertLast of class Singly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLL<T>:: InsertLast(T iNo)
{
    struct nodeS<T> *temp=First;
    struct nodeS<T> *newn=NULL;

    newn=new struct nodeD<T>;   

    newn->data=iNo;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
       int iCnt=0;
       while(temp->next!=NULL)
       {
          temp=temp->next;
       }
       temp->next=newn;
    }
}


////////////////////////////////////////////////////////////////////////

//Function Name:DeleteFirst
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//        This is  DeleteFirst of class Singly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLL<T>:: DeleteFirst()
{
    struct nodeS<T> *temp=First;
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete(First);
        First=NULL;
    }
    else
    {
        First=First->next;
        delete(temp);
    }
}

////////////////////////////////////////////////////////////////////////

//Function Name:DeleteLast
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//        This is  DeleteLast of class Singly Linear Linked list.
//Return:NONE


////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLL<T>:: DeleteLast()
{
    struct nodeS<T> *temp=First;
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete(First);
        First=NULL;
    }
    else
    {
       while(temp->next->next!=NULL)
       {
          temp=temp->next;
       }
       delete(temp->next);
       temp->next=NULL;
    }
}


/////////////////////////////////////////////////////////////////////////


//Function Name:InsertAtPosition
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Position ,Number
//Description:
//        This is InsertAtPosition of class Singly Linear Linked list.
//Return:Depends Which data type used in Input


////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyLL<T>::InsertAtPos(int iPos,T iNo)
{
    int iNodeCnt=0;
    iNodeCnt=Count();

    struct nodeS<T> *temp=First;
    
    if((iPos<1)||(iPos>iNodeCnt+1))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==iNodeCnt+1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct nodeD<T> *newn=new struct node<T>;
        newn->data=iNo;
        newn->next=NULL;

        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

//////////////////////////////////////////////////////////////////////////

//Function Name:DeleteAtPosition
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Position
//Description:
//        This is  DeleteAtPosition of class Singly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iNodeCnt=0;
    iNodeCnt=Count();

    struct nodeS<T> *temp=First;
    struct nodeS<T> *temp1=NULL;
    
    if((iPos<1)||(iPos>iNodeCnt))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iNodeCnt+1)
    {
        DeleteLast();
    }
    else
    {
        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=temp1->next;
        delete(temp1);
    }
}

////////////////////////////////////////////////////////////////////////

//Function Name:SearchFirstOcc
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Template
//Description:
//        This is  SearchFirstOcc of class Singly Linear Linked list.
//Return:Depends

////////////////////////////////////////////////////////////////////////


template<class T>
T SinglyLL<T>::SearchFirstOcc(T no)
{
    int iCnt=0;

    while(temp!=NULL)
    {
           if(temp->Data==no)
           {
              break;
           }
           temp=temp->Next;
           iCnt++; 
    }
    return iCnt+1;
}


/////////////////////////////////////////////////////////////////////////

//Function Name:SearchLastOcc
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Template
//Description:
//        This is  SearchLastOcc of class Singly Linear Linked list.
//Return:Depends

////////////////////////////////////////////////////////////////////////

template<class T>
T SinglyLL<T>::SearchLastOcc(T iNo)
{
    PNODE temp=Head;
    int iCnt=0,i=0;

    while(temp!=NULL)
    {
        if(temp->Data==iNo)
        {
            iCnt=i;
        }
        temp=temp->Next;
        i++;
    }
    return iCnt+1;
}


////////////////////////////////////////////////////////////////////

//Function Name:Doubly linear Linked list
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is Constructor of class Doubly Linear Linked list.
//Input:NONE

//////////////////////////////////////////////////////////////////////

template<class T>
DoublyLL<T>::DoublyLL()
{
    First=NULL;
}

///////////////////////////////////////////////////////////////////////

//Function Name:InsertFirst
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:
//        This is InsertFirst of class Doubly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    struct nodeD<T> *newn=NULL;
    newn=new struct nodeD<T>;   

    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;
    }
}


/////////////////////////////////////////////////////////////////////////

//Function Name:Display
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//        This is Display of Node Using in Doubly Linear Linked list.
//Return:NONE


////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::Display()
{
    cout<<"Linked list Elements are:\n";
    struct nodeD<T> *temp=First; 

    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp=temp->next;
    }
    cout<<"\n";
}


//////////////////////////////////////////////////////////////////////////

//Function Name:Count
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//        Display Count of Node Using in Doubly Linear Linked list.
//Return:Integer

/////////////////////////////////////////////////////////////////////////////////////


template<class T>
int DoublyLL<T>::Count()
{
    int iCnt=0;
    struct nodeD<T> *temp=First; 

    while(temp!=NULL)
    {
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}


////////////////////////////////////////////////////////////////////////

//Function Name:InsertLast
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:
//        This is InsertLast of class Doubly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    struct nodeD<T> *temp=First;
    struct nodeD<T> *newn=NULL;

    newn=new struct nodeD<T>;   

    newn->data=iNo;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
       int iCnt=0;
       while(temp->next!=NULL)
       {
          temp=temp->next;
       }
       temp->next=newn;
       newn->prev=temp;
    }
}

////////////////////////////////////////////////////////////////////////

//Function Name:DeleteFirst
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//        This is DeleteFirst of class Doubly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>:: DeleteFirst()
{
    struct nodeD<T> *temp=First;
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete(First);
        First=NULL;
    }
    else
    {
        First=First->next;
        delete(temp);
        First->prev=NULL;
    }
}


////////////////////////////////////////////////////////////////////////

//Function Name:DeleteLast
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//        This is DeleteLast of class Doubly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeD<T> *temp=First;
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete(First);
        First=NULL;
    }
    else
    {
       while(temp->next->next!=NULL)
       {
          temp=temp->next;
       }
       delete(temp->next);
       temp->next=NULL;
    }
}


////////////////////////////////////////////////////////////////////////

//Function Name:InsertAtPos
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Position ,Number
//Description:
//        This is InsertAtPosition of class Doubly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::InsertAtPos(int iPos,T iNo)
{
    int iNodeCnt=0;
    iNodeCnt=Count();
    struct nodeD<T> *temp=First;
    
    if((iPos<1)||(iPos>iNodeCnt+1))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==iNodeCnt+1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct node<T> *newn=new struct node<T>;
        newn->data=iNo;
        newn->next=NULL;

        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
    }
}


////////////////////////////////////////////////////////////////////////

//Function Name:DeleteAtPos
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Position
//Description:
//        This is DeleteAtPosition of class Doubly Linear Linked list.
//Return:NONE

////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int iNodeCnt=0;
    iNodeCnt=Count();
    struct nodeD<T> *temp=First;
    struct nodeD<T> *temp1=NULL;
    
    if((iPos<1)||(iPos>iNodeCnt))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iNodeCnt+1)
    {
        DeleteLast();
    }
    else
    {
        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=temp1->next;
        temp1->next->prev=temp;
        delete(temp1);
    }
}

///////////////////////////////////////////////////////////////////////////

//Function Name:Singly Circular Linear Linked list
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is Constructor of class Singly Circular Linear Linked list.
//Input:NONE

///////////////////////////////////////////////////////////////////////////


template<class T>
SinglyCL<T>::SinglyCL()
{
    First=NULL;
    Last=NULL;
}


////////////////////////////////////////////////////////////////////////////

//Function Name:InsertFirst
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:This is InsertFirst of class Singly Circular Linear Linked list.
//Return: NONE

///////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    struct nodeS<T> *newn=NULL;
    newn=new struct nodeS<T>;

    newn->data=iNo;
    newn->next=NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First=newn;
        Last=newn;
        (Last)->next=First;
    }
    else
    {
        newn->next=First;
        First=newn;
        (Last)->next=First;
    }  
}


/////////////////////////////////////////////////////////////////////////

//Function Name:Display
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:Display Node of class Singly Circular Linear Linked list.
//Return: NONE

///////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of circular Linked list:\n";
    struct nodeS<T> *temp=First;

    do 
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }while(temp!=(Last->next));
    cout<<"\n";
}


////////////////////////////////////////////////////////////////////////////


//Function Name:Count
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:Count Node of class Singly Circular Linear Linked list.
//Return:Integer


///////////////////////////////////////////////////////////////////////////


template<class T>
int SinglyCL<T>::Count()
{
    struct nodeS<T> *temp=First;
    int iCnt=0;
    do 
    {
        iCnt++;
        temp=temp->next;
    }while(temp!=(Last->next));
    return iCnt;
}


///////////////////////////////////////////////////////////////////////////


//Function Name:InsertLast
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:
//         This is InsertLast of class Singly Circular Linear Linked list.
//Return:NONE


///////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::InsertLast(T iNo)
{
    struct nodeS<T> *newn=NULL;
    newn=new struct nodeS<T>;

    newn->data=iNo;
    newn->next=NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
        Last->next=newn;
        Last=newn;
        Last->next=First;
    }
}

////////////////////////////////////////////////////////////////////////////


//Function Name:DeleteFirst
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//         This is DeleteFirst of class Singly Circular Linear Linked list.
//Input:NONE


///////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCL<T>::DeleteFirst()
{
    struct nodeS<T> *temp=First;

    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
       First=First->next;
       delete temp;
       (Last)->next=First;
    }
}


///////////////////////////////////////////////////////////////////////////


//Function Name:DeleteLast
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:
//         This is DeleteLast of class Singly Circular Linear Linked list.
//Return:NONE


///////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeS<T> *temp=First;

    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        while(temp->next!=(Last))
        {
            temp=temp->next;
        }
        delete temp->next;
        Last=temp;
        Last->next=First;
    }
}


///////////////////////////////////////////////////////////////////////////////

//Function Name:InsertAtPosition
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Position,Number
//Description:
//         This is InsertAt Position of class Singly Circular Linear Linked list.
//Return:NONE


///////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCL<T>::InsertAtPos(int iPos,T iNo)
{
    int iNodeCnt=0;
    iNodeCnt=Count();

    struct nodeS<T> *temp=First;
    
    if((iPos<1)||(iPos>iNodeCnt+1))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==iNodeCnt+1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct node<T> *newn=new struct node<T>;
        newn->data=iNo;
        newn->next=NULL;

        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}


////////////////////////////////////////////////////////////////////////////


//Function Name:DeleteAtPosition
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Position
//Description:
//         This is Delete At Position of class Singly Circular Linear Linked list.
//Return:NONE


///////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int iNodeCnt=0;
    iNodeCnt=Count();

    struct nodeS<T> *temp=First;
    struct nodeS<T> *temp1=NULL;
    
    if((iPos<1)||(iPos>iNodeCnt))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iNodeCnt+1)
    {
        DeleteLast();
    }
    else
    {
        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=temp1->next;
        delete(temp1);
    }
}


//////////////////////////////////////////////////////////////////////////////////

//Function Name:Doubly Circular Linear Linked list
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is Constructor of class Doubly Circular Linear Linked list.
//Input:NONE

//////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCL<T>::DoublyCL()
{
    First=NULL;
    Last=NULL;
}

////////////////////////////////////////////////////////////////////////////////////

//Function Name:InsertFirst
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:This is InsertFirst of class Doubly Circular Linear Linked list.
//Input:NONE


//////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
    struct nodeD<T> *newn=NULL;
    newn=new struct nodeD<T>;

    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
        newn->next=First;
        First->prev=newn;   
        First=newn;  
    } 
    Last->next=First;
    First->prev=Last;   
}


//////////////////////////////////////////////////////////////////////////////////

//Function Name:Display
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is Display of class Doubly Circular Linear Linked list.
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCL<T>::Display()
{
    struct nodeD<T> *temp=First;
    cout<<"Elements of circular Linked list:\n";
    do 
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp=temp->next;
    }while(temp!=(Last->next));
    cout<<"\n";
}


//////////////////////////////////////////////////////////////////////////////////

//Function Name:Count
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is Count of class Doubly Circular Linear Linked list.
//Return:Integer

//////////////////////////////////////////////////////////////////////////////////


template<class T>
int DoublyCL<T>::Count()
{
    struct nodeD<T> *temp=First;
    int iCnt=0;
   
    do 
    {
        iCnt++;
        temp=temp->next;
    }while(temp!=(Last->next));
    return iCnt;
}


/////////////////////////////////////////////////////////////////////////////////

//Function Name:InsertLast
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:This is InsertLast of class Doubly Circular Linear Linked list.
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCL<T>::InsertLast(T iNo)
{
    struct nodeD<T> *newn=NULL;
    newn=new struct nodeD<T>;
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First=newn;
        Last=newn;
    }
    else
    {
        Last->next=newn;
        newn->prev=Last;
        Last=newn;
        Last->next=First;
        First->prev=Last;
    }
}


//////////////////////////////////////////////////////////////////////////////////////

//Function Name:DeleteFirst
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is DeleteFirst of class Doubly Circular Linear Linked list.
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCL<T>::DeleteFirst()
{
    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
       First=First->next;
       delete Last->next;
       Last->next=First;
       First->prev=Last;
    }
}


///////////////////////////////////////////////////////////////////////////////////

//Function Name:DeleteLast
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is DeleteLast of class Doubly Circular Linear Linked list.
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCL<T>::DeleteLast()
{
    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        Last=Last->prev;
        delete(First)->prev;

        (Last)->next=First;
        First->prev=Last;
    }
}


/////////////////////////////////////////////////////////////////////////////////

//Function Name:InsertAtPos
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Position,Number
//Description:This is InsertAtPos of class Doubly Circular Linear Linked list.
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCL<T>::InsertAtPos(int iPos, T iNo)
{
    int iNodeCnt=0;
    iNodeCnt=Count();
    struct nodeD<T> *temp=First;
    
    if((iPos<1)||(iPos>iNodeCnt+1))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==iNodeCnt+1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct nodeD<T> *newn=new struct nodeD<T>;
        newn->data=iNo;
        newn->next=NULL;

        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;

        temp->next=newn;
        newn->prev=temp;
    }
}


//////////////////////////////////////////////////////////////////////////////////////

//Function Name:DeleteAtPos
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Position
//Description:This is DeleteAtPos of class Doubly Circular Linear Linked list.
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    int iNodeCnt=0;
    iNodeCnt=Count();
    struct nodeD<T> *temp=First;
    struct nodeD<T> *temp1=NULL;
    
    if((iPos<1)||(iPos>iNodeCnt))
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iNodeCnt+1)
    {
        DeleteLast();
    }
    else
    {
        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=temp1->next;
        temp1->next->prev=temp;
        delete(temp1);
    }
}


//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////

//Function Name:Stack
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is Constructor of class Stack
//Input:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
Stack<T>::Stack()
{
    First=NULL;
    iCount=0;
}

//////////////////////////////////////////////////////////////////////////////////

//Function Name:IsStackEmpty
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is IsStackEmpty of class Stack
//Return:True or False

//////////////////////////////////////////////////////////////////////////////////


template<class T>
bool Stack<T>::IsStackEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//////////////////////////////////////////////////////////////////////////////////

//Function Name:Push
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:This is Push of class Stack
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void Stack<T>::push(T no)
{
    struct nodeS<T>  *newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
    iCount++;

    cout<<"gets pushed in the stack succesfully"<<"\n";
}


//////////////////////////////////////////////////////////////////////////////////

//Function Name:Pop
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is Pop of class Stack
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T>::Pop()
{
  if(First==NULL)
  {
    cout<<"Unable to pop the elements as stack is empty:"<<"\n";
    return -1;
  }
  else
  {
    T value=First->data;
    struct nodeS<T> *temp=First;

    First=First->next;
    delete temp;

    iCount--;

    return value;
  }
}


/////////////////////////////////////////////////////////////////////////////////////

//Function Name:Display
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:Display  Linked List Using Stack 
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void Stack<T>:: Display()
{
    if(First==NULL)
    {
        cout<<"Stack is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of stack are:"<<"\n";

        struct nodeS<T> *temp=First;

        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}


//////////////////////////////////////////////////////////////////////////////////

//Function Name:Queue
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is Constructor of class Queue
//Return:NONE


//////////////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T>::Queue()
{
    First=NULL;
    iCount=0;
}

//////////////////////////////////////////////////////////////////////////////////

//Function Name:IsQueueEmpty
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is QUEUE of class Queue
//Return:TRUE/FALSE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
bool Queue<T>::IsQueueEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//////////////////////////////////////////////////////////////////////////////////

//Function Name:EnQueue
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:Number
//Description:This is EnQueue of class Queue
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void Queue<T>::EnQueue(T no)
{
    struct nodeQ<T>  *newn=new struct nodeD<T>;

    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        struct node<T> *temp=First;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iCount++;

    cout<<"gets pushed in the Queue succesfully"<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////

//Function Name:DeQueue
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:This is DeQueue of class Queue
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
T Queue<T>::Dequeue()
{
  if(First==NULL)
  {
    cout<<"Unable to pop the elements as Queue is empty:"<<"\n";
    return -1;
  }
  else
  {
    T value=First->data;
    struct nodeQ<T> *temp=First;

    First=First->next;
    delete temp;

    iCount--;

    return value;
  }

}

///////////////////////////////////////////////////////////////////////////////////

//Function Name:Display
//Function Date: 08/2/2023
//Function Author: Sukanya Hanumant Gund.
//Parameters:NONE
//Description:Display Linked Using Queue
//Return:NONE

//////////////////////////////////////////////////////////////////////////////////


template<class T>
void Queue<T>:: Display()
{
    if(First==NULL)
    {
        cout<<"Queue is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of Queue are:"<<"\n";

        struct nodeQ<T> *temp=First;

        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }

}

////////////////////////////////////////////////////////////////////////////////////////

//Entry Point Function
int main()
{

    return 0;

}

