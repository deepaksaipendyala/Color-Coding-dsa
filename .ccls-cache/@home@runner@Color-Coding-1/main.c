#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

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

int color()
{
    char color_str[8];
    printf("Enter The Color Of Resistor in Lowercase :");
    scanf("%s",color_str);
    if (strcmp(color_str, "black") == 0)
        return 0;
    else if (strcmp(color_str, "brown") == 0)
        return 1;
    else if (strcmp(color_str, "red") == 0)
        return 2;
    else if (strcmp(color_str, "orange") == 0)
        return 3;
    else if (strcmp(color_str, "yellow") == 0 )
        return 4;
    else if (strcmp(color_str, "green") == 0 || strcmp(color_str, "gold") == 0)
        return 5;
    else if (strcmp(color_str, "blue") == 0)
        return 6;
    else if (strcmp(color_str, "violet") == 0)
        return 7;
    else if (strcmp(color_str, "grey") == 0)
        return 8;
    else if (strcmp(color_str, "white") == 0)
        return 9;
    else if (strcmp(color_str, "silver") == 0)
        return 10;
    else
    {
        printf("invalid input\n");
    }
}
int main()
{
    int band = 0;
    while (!(band >= 4 && band <= 6))
    {
        printf("Please Enter The Bands In Resistor : ");
        scanf("%d", &band);
    }
    int count = band;
    while (count != 0)
    {

        int color_value = color();
        newnode(color_value);
        count--;
    }
    struct node *temp = head;
    int j = 0;
    long long int sum = 0;
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
    printf("\n%lld +- %d%%", sum, temp->value);
    return 0;
}