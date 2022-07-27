#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct Node {
    char s[6];
    int key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST Node
struct Node* newNode(char item[],int key)
{
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    strcpy(temp->s, item);
    temp->key=key;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert
   a new Node with given key in
 * BST */
struct Node* insert(struct Node* Node, char s[],int key)
{
    /* If the tree is empty, return a new Node */
    if (Node == NULL)
        return newNode(s,key);
 
    /* Otherwise, recur down the tree */
    if (strcmp (s,Node->s)<0)
        Node->left = insert(Node->left, s,key);
    else if (strcmp(s,Node->s)>0)
        Node->right = insert(Node->right, s,key);
 
    /* return the (unchanged) Node pointer */
    return Node;
}

struct Node* trav(struct Node* Node, char s[])
{
    if (strcmp (s,Node->s)==0 || Node==NULL)
      return Node;
    /* Otherwise, recur down the tree */
    if (strcmp (s,Node->s)<0){
      return trav(Node->left, s);}
    else if (strcmp(s,Node->s)>0){
        return trav(Node->right, s);
    }
    /* return the (unchanged) Node pointer */
    return Node;
}
// Firstly we need to design the resistor for 3 different cases 1. 4 bands 2. 5 bands and 3.6 bands

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;

void newnode(int item)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    new->value = item;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

int color(struct Node* node)
{
    char color_str[8];
    printf("Enter The Color Of Resistor in Lowercase :");
    scanf("%s",color_str);
    node=trav(node,color_str);
    return node->key;
};

void clear()
{
  struct node * temp=head;
  while(head!=NULL)
    {
      temp=head;
      head=head->next;
      free(temp);
    }
}

  double net=0;
long long int sum = 0;
long long int calculate(int band)
{
  struct node *temp = head;
    int j = 0;
   while (temp->next!=NULL)
    {
        if (j < band-2)
            sum = (sum * 10) + (temp->value);
        else if (j == band-2)
        {
            int c = temp->value;
            sum = sum * (pow(10, (c)));
        }
        temp = temp->next;
        
        j++;
    }
  printf("%lld +- %d%%\n", sum, temp->value);
  return sum;
}

void resistance_value(int l,int m,int j,struct Node* root)
{

  int band = 0;
  if(j==0)
  {
    while (!(band >= 4 && band <= 5))
    {
        printf("Please Enter The Bands In Resistor : ");
        scanf("%d", &band);
    }
    int count = band;
    while (count != 0)
    {
        int color_value = color(root);
        newnode(color_value);
        count--;
    }
    calculate(band);
  }
    
  else if(j==2)
  {
    net+=calculate(band);
    
  }
    if(l==2)
  {
  net+=sum; 
    if(m==1)
      printf("The Value Of Resisotrs In Series is : %lf\n",net);
    }
  if(l==3)
  {
  if(net==(double)(0))
  {
    net=sum;
  }
    else
  {
    net=(net*sum)/(net+sum);
    printf("The Value Of Resisotrs In parallel is :%lf\n",net);
  }
  }
  
    if(j!=2)
    {
    clear();
      }
  sum=0;
};


  

int main()
{
struct Node* root = NULL;
root = insert(root,"black",0);
root = insert(root,"brown",1);
root =  insert(root,"red",2);
root =  insert(root,"orange",3);
root = insert(root,"yellow",4);
root = insert(root,"green",5);
root = insert(root,"blue",6);
root = insert(root,"violet",7);
root = insert(root,"grey",8);
root = insert(root,"white",9);
  int k;
  
  while(k!=4)
    {
      printf("Please Choose One From The following :\n1.Resistor Color Code Calculator\n2.Calculate resistances In Series\n3.Calculate resistances In Parallel\n4.End\n");
  scanf("%d",&k);
      if(k==1)
      {
        resistance_value(k,0,0,root);
      }
      else if (k==2 || k==3)
      {
        int i=0;
        resistance_value(k,0,i,root);
        while(i!=3)
          {
            printf("1.Add another Resistor with different value :\n2.Add another Resistor with same value\n3.End\n");
            scanf("%d",&i);
            if(i==3)
            {
              break;
            }
            resistance_value(k,1,i,root);
          }
        }
      else if(k==4)
      {
        break;
      }
      else{
        printf("Please Enter A Valid Code");
      }
    }
    return 0;
}