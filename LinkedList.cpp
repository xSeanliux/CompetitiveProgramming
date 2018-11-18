#include<iostream>
using namespace std;

struct Data
{
    int n;
    Data *next;
};

Data *head, *tail;

void show( Data *now )
{
    if( now == NULL ){
        cout << endl;
        return;
    }
    cout << now->n << " ";
    show( now->next );
}

void pop( int n ){
    for(Data *before = head; before->next != NULL; before = before->next){
        if(before->next->n == n){
            Data *tmp = before->next;
            before->next =  before->next->next;
            delete tmp;
        }
    }
    return;


}

void reverseShow(Data *a){
    if(a==NULL){
        return;
    } else{
        reverseShow(a->next);
        cout << a->n << " ";
    }
}

void push( int n )
{
    Data *a = new Data;
    a -> n=n;
    tail->next = a;
    tail = a;
    tail->next = NULL;
}


void insert(int n){
    Data *a = new Data;
    Data *p = new Data;
    a->n = n;
    if(head == tail){
        push(n);
        return;
    }
    for(p = head; p->next != NULL; p=p->next){
        if(p->n < a->n && p->next->n > a->n){
            Data *tmp = p->next;
            p->next = a;
            a->next = tmp;
            return;
        } else if(p->next->next == NULL){
            push(n);
            return;
        }
    }



}

Data* reverse(Data *now, Data *last){
    Data *original_next = now->next;
    now->next = last;

    if(original_next == NULL){
        return now;
    } else {
        return reverse(original_next, now);
    }

}


int main()
{
    //todo start
    /*
    Data *dummy = new Data;
    dummy->n = 1337;
    dummy->next = tail;
    head = tail = dummy;
    //todo end
    */
    head = new Data;
    tail = head;
    head -> next = NULL;


    insert( 5 );
    insert( 3 );
    insert( 7 );
    insert( 9 );



    show( head -> next ); // todo
    //reverseShow(head->next);
    head -> next = reverse(head -> next, NULL);
    show(head->next);
    return 0;
}
