#include<stdio.h>
#include<stdlib.h>
#define K 1024
#define M 1048576
#define post_length 1792
static int count=0;
static int total_posts=0;

struct post
{
	char post_message[508];
	int likes;
	char comments[10][128];
};
struct index_id
{
	
	int post_id;
	int post_index;
	int user_id;
};
struct metadata
{
	int userid;
	char name[40];
	char password[40];
	int friendslist[10];
	int indexblock;
};
FILE * get10mbfile(FILE *fp)
{
	int i;
	for(i=0;i<10*1024*1024;i++)
		fputc('\0',fp);
	return fp;
}
int print_post_person(FILE *fp, struct index_id index_add)
{
	FILE *pt=fp;
	char buffer[40];
	int res;
	res=fseek(pt,(index_add.user_id-1)*128+4,0);
	//printf("%d",ftell(pt));
	if(res!=0)
	{
		printf("error in print_post_person\n");
		return;
	}
	res=fread(&buffer,40,1,pt);
	if(res!=1)
	{
		printf("error in print_post_person 2\n");
		return 1;
	}
	printf("\n\n%s posted a post with post id %d\n\n",buffer,index_add.post_id);
	return 0;
//	fflush(stdin);

	//fflush(pt);
}
int strcmp(char *str)
{
	if(str_cmp(str,"post")==0)
		return 1;
	else if(str_cmp(str,"like")==0)
		return 2;
	else if(str_cmp(str,"comment")==0)
		return 3;
	else if(str_cmp(str,"add")==0)
		return 4;
	else if(str_cmp(str,"logout")==0)
		return 5;
	else if(str_cmp(str,"news")==0)
		return 6;
	else if(str_cmp(str,"myfriends")==0)
		return 7;
	else if(str_cmp(str,"tag")==0)
		return 8;
	else
		return 0;
}
int get_friend_index_block(FILE *fp,int friend_id)
{
	int index=0;
	fseek(fp,friend_id*sizeof(struct metadata)-sizeof(int),0);
	fread(&index,sizeof(int),1,fp);
	return index;
}
int add_post(FILE *fp,struct metadata md)
{
	int index,res,friend_id;
	int i,j;
	struct metadata md1;
	struct index_id index_add,i1;
	FILE *pt=fp;
	index=ftell(fp)-post_length;
	index_add.post_id=total_posts;
	index_add.post_index=index;
	index_add.user_id=md.userid;
	fseek(fp,(md.userid-1)*sizeof(struct metadata),0);
	fread(&md,sizeof(struct metadata),1,fp);
	res=fseek(pt,md.indexblock,0);
	if(res!=0)
	{
		printf("error in add post\n");
		return 1;
	}
	while(1)
	{
		res=fread(&i1,sizeof(struct index_id),1,pt);
		if(res!=1)
		{
			printf("error in add post 2\n");
			return 1;
		}
		if(i1.post_id==NULL)
		{
			res=fseek(pt,-sizeof(struct index_id),1);
			printf("%d",ftell(pt));
			res=fwrite(&index_add,sizeof(struct index_id),1,pt);
			fflush(stdin);
			fflush(pt);
			if(res!=1)
			{
				printf("error in add post 3\n");
				return;
			}
			break;
		}
		
	}
	i=0;
	while(1)
	{
		friend_id=md.friendslist[i];
		if(friend_id==0)
			break;
		index=get_friend_index_block(pt,friend_id);
		printf("%d\n",index);
		res=fseek(pt,index,0);
		if(res!=0)
		{
			printf("error in somewhere\n");
			return;
		}

		while(1)
		{
			res=fread(&i1,sizeof(struct index_id),1,pt);
			if(res!=1)
			{
				printf("error in add post 2\n");
				return 1;
			}
			if(i1.post_id==0)
			{
				res=fseek(pt,-sizeof(struct index_id),1);
				res=fwrite(&index_add,sizeof(struct index_id),1,pt);
				fflush(stdin);
				fflush(pt);
				if(res!=1)
				{
					printf("error in add post 3\n");
					return;
				}
				break;
			}
		
		}
		i++;
	}


}
void make_a_post(FILE *fp,struct metadata md)
{
	struct post pt;
	int res,i=0;
	printf("enter the post\n");
	fflush(stdin);
	gets(pt.post_message);
	pt.likes=0;
	for(i=0;i<10;i++)
	{
		pt.comments[i][0]='\0';
	}

	res=fseek(fp,M+post_length*total_posts,0);
	if(res!=0)
	{
		printf("error in make a post\n");
		return;
	}
	printf("%d",ftell(fp));
	res=fwrite(&pt,post_length,1,fp);
	fflush(fp);
	if(res==1)
	{
		printf("posted sussessfully\n");
		total_posts++;
		res=add_post(fp,md);
		

		return;
	}
	printf("error in make a post 2\n");
	return;
}
void like_a_post(FILE *fp,int postid)
{
	int res,val;
	res=fseek(fp,0,0);
	if(res!=0)
	{
		printf("error in like a post\n");
		return ;
	}
	res=fseek(fp,M+(postid-1)*post_length+508,0);
	fread(&val,4,1,fp);
	val=val+1;
	fseek(fp,-4,1);
	res=fwrite(&val,4,1,fp);
	if(res!=1)
	{
		printf("error in like a post 2\n");
		return;
	}
	printf("\nliked the post \n");
}
void comment_a_post(FILE *fp,int postid)
{
	char buffer[128];
	int res,count=0;
	char c;
	printf("enter the comment\n");
	fflush(stdin);
	gets(buffer);
	res=fseek(fp,0,0);
	if(res!=0)
	{
		printf("error in comment a post\n");
		return ;
	}
	res=fseek(fp,M+(postid-1)*post_length+512,0);
	c=fgetc(fp);
	while(c!=NULL&&count<9)
	{
		count++;
		fseek(fp,sizeof(struct metadata)-1,1);
		c=fgetc(fp);
	}
	if(count==9)
	{
		printf("no more comments possible\n");
		return;
	}
	fseek(fp,-1,1);
	res=fwrite(buffer,sizeof(buffer),1,fp);
	if(res!=1)
	{
		printf("error in comment post 2\n");
		return;
	}
	printf("comment written successfully\n");
	return;

}
void make_friend(FILE *fp,int friend1_id,int friend2_id)
{
	FILE *pt=fp;
	int i=0,val;
	fseek(pt,0,0);
	fseek(pt,(friend2_id-1)*sizeof(struct metadata)+84,0);
	while(i<10)
	{
		fread(&val,4,1,pt);
		if(val==0)
		{
			fseek(pt,-4,1);
			fwrite(&friend1_id,4,1,pt);
			fflush(stdin);
			fflush(pt);
			break;
		}
		if(val==friend1_id)
		{
			printf("u r already friend with him/her \n");
			return;
		}

		i++;
	}
	printf("%d is friend with %d\n",friend1_id,friend2_id);
	return;
}
void add_friend(FILE *fp,struct metadata md)
{
	FILE *pt=fp;
	struct metadata md1;
	int res,friend_id=0;
	fseek(fp,(md.userid-1)*sizeof(struct metadata),0);
	fread(&md,sizeof(struct metadata),1,fp);
	fseek(pt,0,0);
	printf("user id\tname\n\n");
	while(1)
	{
		fread(&md1,sizeof(struct metadata),1,pt);
		if(md1.userid==NULL)
			break;
		printf("%d\t%s\n",md1.userid,md1.name);
	}
	printf("type the user id in the above users to make him/her as ur friend\n");
	fflush(stdin);
	scanf("%d",&friend_id);
	make_friend(fp,friend_id,md.userid);
	make_friend(fp,md.userid,friend_id);

}
void my_friends(FILE *fp,struct metadata md)
{
	struct metadata md1[128],md2;
	int i=0,j,fid;
	fseek(fp,0,0);
	fread(&md1,sizeof(struct metadata)*128,1,fp);
	j=md.userid-1;
	printf("friend id\t name\n\n");
	while(1)
	{
		fid=md1[j].friendslist[i];
		if(fid==0)
			break;
		i++;
		fid--;
		printf("%d\t%s\n",md1[fid].userid,md1[fid].name);
	}

}
void tag_friends(FILE *fp,struct metadata md)
{

}

void news_feed(FILE *fp,struct metadata md)
{
	int max_posts=10,flag=0;
	int counter=0;
	int i=0,j=0,res,temp;
	struct index_id index_add;
	struct post post_data;
	char option[10];
	FILE *pt;
	pt=fp;
	 
	while(1)
	{
		res=fseek(fp,md.indexblock+counter*sizeof(struct index_id),0);
		counter++;
		if(res!=0)
		{
			printf("error in news feed\n\n");
			return ;
		}
		res=fread(&index_add,12,1,fp);
		pt=fp;
		if(res!=1)
		{
		printf("error in news feed in while\n\n");
		return ;
		}
		if(index_add.post_id==NULL)
		{
			printf("no more posts to display\n\n");
			break;
		}
		else if(index_add.post_index>=1048576)
		{
			res=fseek(pt,index_add.post_index,0);
			if(res!=0)
			{
				printf("error in news feed, while, else if\n\n");
				return;
			}
			res=fread(&post_data,sizeof(struct post),1,pt);
			if(res!=1)
			{
				printf("error in news feed, while, else if 2\n\n");
				return;
			}
			res=print_post_person(pt,index_add);
			if(res!=0)
			{
				printf("error\n");
				return;
			}

			printf("post: %s\n\n",post_data.post_message);
			if(post_data.likes>0)
				printf("%d likes\n\n",post_data.likes);
			j=0;
			while(j<10)
			{
				if(post_data.comments[j][0]!=NULL)
				printf("comment %d : %s\n\n",j+1,post_data.comments[j]);
				else 
					break;
				j++;
			}
		}
	}
	while(1)
	{
		printf("\n--------------------------------------------------------------\n");
	printf("type  post like  comment  add  news  myfriends  tag  logout  \n\n");
	fflush(stdin);
	scanf("%s",option);
	res=strcmp(option);
	switch(res)
	{
	case 1:
		make_a_post(fp,md);
		break;
	case 2:
		printf("enter post id\n");
		scanf("%d",&temp);
		like_a_post(fp,temp);
		break;
	case 3:
		printf("enter post id\n");
		scanf("%d",&temp);
		comment_a_post(fp,temp);
		break;
	case 4:
		add_friend(fp,md);
		break;
	case 5:
		exit(0);
		break;
	case 6:
		news_feed(fp,md);
		break;
	case 7:
		my_friends(fp,md);
		break;
	case 8:
		tag_friends(fp,md);
		break;
	case 0:
		printf("\nenter correct input\n");
		break;
	}

	}
}

int login_into_account(FILE *fp)
{
	int i,res,count1=1;
	struct metadata md,md1;
	printf("enter user name");
	scanf("%s",md.name);
	printf("enter password");
	scanf("%s",md.password);
	res=fseek(fp,0,0);
	if(res!=0)
	{
		printf("error occured\n");
		return 1;
	}
	while(1)
	{
		res=fread(&md1,sizeof(struct metadata),1,fp);
		if(res!=1)
		{
			printf("error in login \n");
			return 1;
		}
		if(md1.userid==NULL)
		{
			printf("the given name does not exists\n");
			return 1;
		}
		if(str_cmp(md1.name,md.name)==0&&str_cmp(md1.password,md.password)==0)
		{

		//	printf("login is successful\n");
			
			news_feed(fp,md1);
			return 0;
		}
		count++;
		if(count==128)
		{
			printf("the given name does not exists \n");
			return 1;
		}

	}
}

int str_cmp(char *str1,char *str2)
{
	int i=0;
	while(str1[i]!='\0')
	{
		if(str1[i]!=str2[i])
		{
			return 1;
		}
		i++;
	}
	if(str2[i]!='\0')
		return 1;
	return 0;
}
int register_a_user(FILE *fp)
{
	int i,res,count1=1;
	struct metadata md,md1;
	printf("enter a new user name");
	scanf("%s",md.name);
	printf("enter a new password");
	scanf("%s",md.password);
	res=fseek(fp,0,0);
	if(res!=0)
	{
		printf("error occured\n\n");
		return 1;
	}
	while(1)
	{
		res=fread(&md1,sizeof(struct metadata),1,fp);
		if(res!=1)
		{
			printf("error \n\n");
			return 1;
		}
		if(md1.userid==NULL)
		{
			md.userid=count1;
			md.indexblock=16*K+(count1-1)*4*K;
			for(i=0;i<10;i++)
			{
				md.friendslist[i]=0;
			}

			res=fseek(fp,-sizeof(struct metadata),1);
			if(res!=0)
			{
				printf("error\n\n");
				return;
			}
			res=fwrite(&md,sizeof(struct metadata),1,fp);
			if(res==1)
			{
				return 0;
			}
			count++;
		}
		else if(str_cmp(md.name,md1.name)==0)
		{
			printf("user name exists try with other name\n\n");
			return 1;
		}
		count1++;
		if(count1==128)
		{
			printf("no more reg is available\n\n");
			return 1;
		}
	}
}
void get_total_posts(FILE *fp)
{
	int res;
	char c;
	FILE *pt=fp;
	fseek(pt,M,0);
	c=fgetc(pt);
	total_posts=0;
	while(c!=NULL)
	{
		total_posts++;
		fseek(pt,post_length-1,1);
		c=fgetc(pt);
	}
	return;
}

main()
{
	FILE *fp;
	int res;
	struct metadata md;
	char input[20];
	fp=fopen("fbdata.txt","rb+");
	if(fp==NULL)
	{
		fp=fopen("fbdata.txt","wb+");
		fp=get10mbfile(fp);
	}
	get_total_posts(fp);
	while(1)
	{
	printf("type reg  login display \n");
	scanf("%s",input);
	if(str_cmp(input,"reg")==0)
	{
		res=register_a_user(fp);
		if(res==0)
			printf("account has been created\n\n");
		else
			printf("error in account creation \n\n");
		continue;
	}
	else if(str_cmp(input,"login")==0)
	{
		res=login_into_account(fp);
		if(res==0)
			printf("login successfully\n\n");
		else 
			printf("login failed\n\n");
	}
	else if(str_cmp(input,"display")==0)
	{
		fseek(fp,0,0);
		printf("\n--------------------------------------------------\n");
		printf("user id \tuser name\t password\tindexblock\n");
		printf("--------------------------------------------------\n");
		while(1)
		{
			fread(&md,sizeof(struct metadata),1,fp);
			if(md.userid==NULL)
				break;
			printf("%d\t\t%s\t\t%s\t%d\n",md.userid,md.name,md.password,md.indexblock	);
		}

	}


	}
	fclose(fp);
	getch();
}

