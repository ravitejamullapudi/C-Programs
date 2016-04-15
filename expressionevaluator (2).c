#include<stdio.h>
#include<stdlib.h>

int removeunwanted(char *);
void initialise(int *);
int evaluate(struct node *);
int getexp(char *,int *,int *);
//struct node * construct(struct node *,struct node *,struct node *,int *,int*);

struct node 
{
	int value;
	struct node *left,*right;

};


main()
{
	
	char str[100],c;
	int res,var[26],val[26],j,i=0;
	
	initialise(var);

	while(1)
	{
	printf("\n>");
	i=0;
	while((c=getchar())!='\n')
		str[i++]=c;
	str[i]='\0';


	//scanf("%s",str);
	res=removeunwanted(str);
	if(res==0)
	{
		printf("enter correct string");
		continue;
	}
	else
	{
		//printf("%s",str);
		res=getexp(str,var,val);
		if(res==0)
		{
		printf("enter correct string");
		continue;
		}
		else
		{
		for(j=0;j<26;j++)
		{
			if(var[j]==1)
			{
				printf("%c=%d,",(j+'a'),val[j]);
			}

		}
		}
	}
	
	
	}
	getch();
}

void initialise(int *var)
{ int i=0;
	for(;i<26;i++)
	{
		*(var+i)=0;
	}

}


int removeunwanted(char *str)
{
	int i=3,j=2,val;

	if(*(str)<'a'||*str>'z'||*str=='\0')
		return 0;
	if(*(str+1)!='='||*(str+1)=='\0')
		return 0;
	
	if(*(str+2)=='\0'||*(str+2)=='+'||*(str+2)=='-'||*(str+2)=='*'||*(str+2)=='/')
		return 0;
	if(*(str+2)==' ')
		val=0;
	else if(*(str+2)>='a'&&*(str+2)<='z')
		val=1;
	else if(*(str+2)>='0'&&*(str+2)<='9')
		val=2;

	while(*(str+i)!='\0')
	{
		if(*(str+i)==' ')
			i++;
		else if(*(str+i)=='+'||*(str+i)=='-'||*(str+i)=='*'||*(str+i)=='/')
		{
			 if(val==1||val==2)
			 {
				 j++;
				 *(str+j)=*(str+i);
				 val=3;
				 i++;
			 }
			 else
				 return 0;

		}
		else if(*(str+i)>='0'&&*(str+i)<='9')
		{
			if(val==0)
			{
				 *(str+j)=*(str+i);
				 val=2;
				 i++;
			}

			else if(val==3||*(str+j)==*(str+i-1))
			 {
				 //if(*(str+j)!=' ')
				 j++;
				 
				 *(str+j)=*(str+i);
				 val=2;
				 i++;
			 }
			 else
				 return 0;

		}

		else if(*(str+i)>='a'&&*(str+i)<='z')
		{
				 if(val==0||val==3)
				 {
					 if(*(str+j)!=' ')
					 j++;
					 *(str+j)=*(str+i);
					 val=1;
					 i++;
				 }
				 else
					 return 0;
		}
		else 
			return 0;

	}
	if(val!=1&&val!=2)
		return 0;
	*(str+j+1)='\0';
	

}

int getexp(char *str,int *var,int *val)
{
	struct node *root=NULL,*parent=NULL,*child=NULL,*temp=NULL;
	 int i=2,x,flag=0,result;
	 while(*(str+i)!=NULL)
	 {
		 if(*(str+i)>='0'&&*(str+i)<='9')
		 {
			 if(root==NULL)
			 {
				 temp=(struct node *)malloc(sizeof(struct node));
				 temp->value=*(str+i)-'0';
				 temp->left=NULL;
				 temp->right=NULL;
				 root=temp;
				 parent=temp;
				 child=temp;
			 }
			 else if(child->value>=0)
			 {
				 child->value=child->value*10+(*(str+i)-'0');
			 }
			 else
			 {
				 temp=(struct node *)malloc(sizeof(struct node));
				 temp->value=*(str+i)-'0';
				 temp->left=NULL;
				 temp->right=NULL;
				 child->right=temp;
				 parent=child;
				 child=temp;
				 
			 }
		 }
		 else if(*(str+i)=='+'||*(str+i)=='-'||*(str+i)=='*'||*(str+i)=='/')
		 {
			 
			 temp=(struct node *)malloc(sizeof(struct node));
			 if(*(str+i)=='+')
				 x=-1;
			 else if(*(str+i)=='-')
				 x=-2;
			 else if(*(str+i)=='*')
				 x=-3;
			 else 
				 x=-4;
				 
				 temp->value=x;
				 temp->left=NULL;
				temp->right=NULL;

			 if(root==child&&flag==0)
			 {
				 temp->left=child;
				 root=temp;
				 parent=temp;
				 child=temp;
				 if(x==-1||x==-2)
					 flag=1;
			 }
			 else if((x==-1||x==-2)||((root->value==-3||root->value==-4)&&(x==-3||x==-4)))
			 {
				 temp->left=root;
				 root=temp;
				 parent=root;
				 child=root;
				 flag=1;

			 }

			 else
			 {
				 parent->right=temp;
				 temp->left=child;
				 child=temp;
				 if(flag==0)
					 root=temp;
			 }
			 if(x==-1||x==-2)
			 flag=1;

		 }
		 else
		 {
			 if(var[*(str+i)-'a']==0)
				 return 0;
			 temp=(struct node *)malloc(sizeof(struct node));
				 temp->value=val[*(str+i)-'a'];
				 temp->left=NULL;
				 temp->right=NULL;
				 if(root==NULL)
				 {
					 root=temp;
					 parent=root;
					 child=root;
				 }
				 else 
				 {
				 child->right=temp;
				 parent=child;
				 child=temp;
				 }
		 }

		 i++;
	 }

	 result=evaluate(root);
	 val[*str-'a']=result;
	 var[*str-'a']=1;
	 return 1;
}

int evaluate(struct node *root)
{
	int l,r;
	if(root==NULL)
		return 0;
	else 
	{
		l=evaluate(root->left);
		r=evaluate(root->right);
		if(root->value==-1)
			return l+r;
		else if(root->value==-2)
			return l-r;
		else if(root->value==-3)
			return l*r;
		else if(root->value==-4)
			return l/r;
		else 
			return root->value;
	}

}
