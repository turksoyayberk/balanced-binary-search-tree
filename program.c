#include<stdio.h>
#include<stdlib.h>
//Ayberk Türksoy 150119919
struct TNode
{
	int data;
	struct TNode* left;
	struct TNode* right;
};
struct TNode* newNode(int data);
typedef struct TNode tree;
int a=0;
int a2=0;
int *dizi;
int *arr1;
int i=0;
int min=0;
int n=0;
struct TNode* sortedArrayToBalancedTree(int arr[], int start, int end)
{
	if (start > end)
	return NULL;
	
	int mid = (start + end)/2;
	
	struct TNode *root = newNode(arr[mid]);
	
	root->left = sortedArrayToBalancedTree(arr, start, mid-1);

	root->right = sortedArrayToBalancedTree(arr, mid+1,end);
	
	return root;
}
struct TNode* newNode(int data)
{
	struct TNode* node = (struct TNode*)malloc(sizeof(struct TNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	dizi[a]=node->data;
	a++;
	return node;
}
tree *ekle (tree *agac,int x)
{
	if(agac==NULL)
	{
		tree *root =(tree*)malloc(sizeof(tree));
		root->left=NULL;
		root->right=NULL;
		root->data=x;
		return root;
	}
	if(agac->data<x)
	{
			agac->right=ekle(agac->right,x);
		return agac;
	}
	agac->left=ekle(agac->left,x);
	return agac;
}
int findDepthLevel(tree* root)
{
	if(root==NULL)
		return 0;
	else
	{
		int ldl=findDepthLevel(root->left);
		int rdl=findDepthLevel(root->right);
		if(ldl>rdl)
			return(ldl+1);
		else
			return(rdl+1);
	}
}
int findLevelProcess( tree *root,  int data, int element)
{
    if (root == NULL)
        return 0;
 
    if (root->data == data)
        return element;

	
    int level = findLevelProcess(root->left,data, element+1);
    if (level != 0)
        return level;
 
    level = findLevelProcess(root->right, data, element+1);
    return level;
}
int findLevel( tree *node, int data)
{
    return findLevelProcess(node,data,1);
}
void selectionSort(int arr[], int n)
{
	int i=0,j=0,min;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i;j<n;j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		int carry=arr[i];
		arr[i]=arr[min];
		arr[min]=carry;
	}
	arr1=arr;
}
void deleteBST(tree* root)
{
    if (root == NULL) 
		return;
		
    deleteBST(root->left);
    deleteBST(root->right);
   
    free(root);
}
int depthCount;
int main()
{
	FILE *file=fopen("input.txt","r+");
	int ic;
	int input[100000];
	int n=0;
	int control=1;
	int p;

	  ic = getc(file);
	  while (1) {
	    while (ic == ' ')
	      ic = getc(file);
	    if (ic == EOF)
	      break;
	    if (!isdigit(ic))
	    {
	    	control=0;
	    	break;
		}
	    unsigned total = 0;
	    do {
	      total *= 10;
	      total += ic - '0';
	       if(total==0)
		  {
		  	control=0;
		  }
	      ic = getc(file);
	    } while (isdigit(ic));
	    input[n]=total;
	
	     n++;
	  }
	  fclose(file);
	  
	if(control==0)
	 {
	 	printf("You entered a negative value or another invalid value. Please change your file.");
	 }
	 else if(n<16)
	 {
	 	printf("You must enter at least 16 numbers.");
	 }
	 else
	 {
	 	int inputNumber=1;
		arr1=(int*)malloc(sizeof(int)*n);
		int b=0;
		for(b=0;b<n;b++)
		{
			arr1[b]=input[b];
		}
		selectionSort(arr1,n);
		int four=4;

		for(p=0;p<1000;p++ )
		{
			four *=4;
			
			if(four<=n && four*4>n)
			{
				break;		
			}	
		}

		int dortussu=4;
		for(p=2;p<1000;p++)
		{
			dortussu *=4;
			if(dortussu==four)
			{
				break;
			}
		}

	 	int depthlevel=3*p;

		dizi=(int*)malloc(sizeof(int)*n);

		tree* iter=NULL;
		tree* iter2=NULL;

		struct TNode *root = sortedArrayToBalancedTree(arr1, 0 ,n-1);
		
		int ornek=0;
		min=1;

		if(findDepthLevel(root)!=depthlevel)
		{
			if(dortussu>=n)
			{
				min*=2;
			}

		for(ornek=0;ornek<n;ornek++)
			{
				min++;
				a=0;
				i=0;
				free(dizi);
				dizi=(int*)malloc(sizeof(int)*n);
				root=sortedArrayToBalancedTree(arr1,min ,n-1);
				iter=sortedArrayToBalancedTree(arr1,0,min-1);
				deleteBST(iter2);
				iter2=NULL;
				while(i<n)
				{
					
					iter2=ekle(iter2,dizi[i]);
					i++;
				}	
				if(findDepthLevel(iter2)==depthlevel)
				{
					
					break;
				}
			}
		}
		else
		{
			iter2=root;
		}
		printf("Depth level of BST is  %d",findDepthLevel(iter2));
		int x;
		int *elementCountArr;
		depthCount=p*3;
		int elementCount=0;
		elementCountArr=(int*)malloc(sizeof(int)*depthCount);
		
	
		for(x=0;x<depthCount;x++)
		{
			elementCountArr[x]=0;
		}
		
		for (x = 0; x <n; x++)
	    {
	      elementCount = findLevel(iter2, dizi[x]);
	
			elementCountArr[elementCount-1]+=1;
	    }
	    printf("\n");

	    for(x=0;x<depthCount;x++)
	    {
	    	printf("Depth level %d %d\n",x,elementCountArr[x]);
		}
		while(1)
		{
			printf("\nKey value to be searched (Enter 0 to exit) : ");
			
			scanf("%d",&inputNumber);
			if(inputNumber==0)
			{
				printf("Exit");
				break;
			}
			else
			{
				int depthLevel1=findLevel(iter2,inputNumber)-1;
				int element=1;
				if(depthLevel1==-1)
					printf("%d is not found in BST",inputNumber);
					
				else
				{	
					for (x = 0; x <n; x++)
				    {
				      	int elementCount = findLevel(iter2, dizi[x]);
				      
					    if (elementCount)
					    {
					    	if((depthLevel1+1==elementCount)&&(inputNumber>dizi[x]))
					    		element++;

					    	elementCountArr[elementCount-1]+=1;
						}
				    }
					if(element==1)
						printf("At Depth level %d, 1st element",depthLevel1);
						
					else if(element==2)
						printf("At Depth level %d, 2nd element",depthLevel1);
						
					else if(element==3)
						printf("At Depth level %d, 3rd element",depthLevel1);
						
					else
					 	printf("At Depth level %d, %dth element",depthLevel1,element);
					 	
					element=0;
				}
			}
		}
	}
	return 0;
}
