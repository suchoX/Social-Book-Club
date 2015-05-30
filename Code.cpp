#include<cstdio>
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<dirent.h>

using namespace std;

int minKey(int[], bool[], int);

int main()
{
	char user_name[50],password[50],temp_password[50],name[100],dob[12],temp[100],dir_temp[100];
	int i=0,choice;
	char ch='a';
	printf("\n1.New User\n2.Existing User\n3.Exit\n\nEnter Choice-");
	cin>>choice;
	if(choice==1)
	{
		//getchar();
		printf("\nEnter Name-");
		//scanf("%s",name);
		getchar();
		cin.getline( name,99);
		printf("Enter Date of Birth (dd/mm/yyyy)-");
		//scanf("%s",dob);
		cin>>dob;
		while(1)
		{
			printf("Enter User Name (Only Characters a-z, A-Z, 0-9 allowed)-");
			cin>>user_name;
			int flag=0;
			fstream usernames;
			fstream no_of_usernames;
			strcpy(dir_temp,getcwd(NULL,0));
			strcat(dir_temp,"/Users/Number of Users.txt");
			no_of_usernames.open(dir_temp,ios::in);		//Number of users from Number of Users.txt
			char no[100];
			no_of_usernames>>no;
			int n=atoi(no);
			no_of_usernames.close();
			int temp_n=n;
			strcpy(dir_temp,getcwd(NULL,0));
			strcat(dir_temp,"/Users/User Names.txt");
			usernames.open(dir_temp,ios::in);
			while(n--)
			{
				usernames>>temp;
				if(strcmp(temp,user_name)==0)
				{
					printf("User Name already exists...Please enter another UserName\n");
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				flag=0;
				usernames.close();
				continue;
			}
			usernames.close();
			break;
		}
		while(1)
		{
			printf("Enter Password-");
			getchar();
			cin.getline(password,49);
			printf("Confirm Password-");
			cin.getline(temp_password,49);
			if(strcmp(password,temp_password)==0) 
				break;
			else
			{
				printf("Passwords Don't Match....Enter Password again!\n");
				continue;
			}
		}
		//CLEAR SCREEN CODE
		printf("Confirm Following Data\n1.Name-%s\n2.Date of Birth-%s\n3.User Name-%s\n(y/n)",name,dob,user_name);
		scanf("%c",&ch); 
		if(ch=='y' || ch=='Y')
		{
			fstream Newuser;				//New User Data File

			strcpy(dir_temp,getcwd(NULL,0));
			strcat(dir_temp,"/Users/User Names.txt");
			Newuser.open(dir_temp,ios::out|ios::app);		//Adding New user name to the User Name.txt
			Newuser<<user_name<<endl;
			Newuser.close();

			fstream no_of_usernames;
			strcpy(dir_temp,getcwd(NULL,0));
			strcat(dir_temp,"/Users/Number of Users.txt");
			no_of_usernames.open(dir_temp,ios::in);		//Number of users increased
			char no[100];
			no_of_usernames>>no;
			int n=atoi(no);
			n++;
			no_of_usernames.close();
			strcpy(dir_temp,getcwd(NULL,0));
			strcat(dir_temp,"/Users/Number of Users.txt");
			no_of_usernames.open(dir_temp,ios::out|ios::trunc);
			no_of_usernames<<n<<endl;
			no_of_usernames.close();

			strcpy(temp,getcwd(NULL,0));
			strcat(temp,"/Users/");
			strcat(temp,user_name);
			strcat(temp,".txt");
			Newuser.open(temp,ios::out|ios::trunc);
			Newuser<<password<<endl;
			Newuser<<name<<endl;
			Newuser<<dob<<endl;
			Newuser<<"END"<<endl;
			Newuser.close();

			strcpy(temp,getcwd(NULL,0));
			strcat(temp,"/Users/");
			strcat(temp,user_name);
			strcat(temp,"_follow.txt");
			Newuser.open(temp,ios::out|ios::trunc);
			Newuser.close();

			strcpy(dir_temp,getcwd(NULL,0));
			strcat(dir_temp,"/Users/User Index.txt");
			Newuser.open(dir_temp,ios::out|ios::app);
			Newuser<<user_name<<" "<<n<<endl;
		}
		printf("\nLOGIN:\n");
		choice=2;
	}
	if(choice==3)
		return 0;
	getchar();
	if(choice==2)
	{
		while(1)
		{
			printf("\nEnter User Name-");
			cin.getline(user_name,49);
			fstream file;
			strcpy(temp,getcwd(NULL,0));
			strcat(temp,"/Users/");
			strcat(temp,user_name);
			strcat(temp,".txt");
			file.open(temp,ios::in);
			if(file.fail())
			{
				printf("User Not found...Enter UserName Again\n");
				file.close();
				continue;
			}
			printf("Enter Password-");
			cin.getline(password,49);
			file>>temp_password;
			if(strcmp(password,temp_password)!=0)
			{
				printf("Wrong Password!!...Enter Again\n");
				continue;
			}
			file.close();
			break;
		}
		printf("\nWhat do you want to do?\n1.Read a Book\n2.Give a Rating\n3.Follow a User\n4.Exit\n\nEnter your choice-");
		scanf("%d",&choice);
		if(choice==1)
		{
			int ch;
			printf("\n1.Enter Book Name\n2.Enter Author Name\n3.**SUGGEST ME**\n\nEnter your choice-");
			scanf("%d",&ch);
			if(ch==1)			//Entering Book Name
			{
				char book_name[100],temp_book_name[100];
				int flag=0;	
				fstream file;		//Displaying all the Books Available
				file.open("All Books.txt",ios::in);
				printf("\nThe Books Available are-\n");
				while(1)
				{
					file>>book_name;
					if(strcmp(book_name,"END")==0)
						break;
					if(strcmp(book_name,"`")==0)
					{
						printf("\n");
						continue;
					}
					printf("%s ",book_name);
				}
				file.close();
				while(1)
				{
					getchar();
					printf("\nEnter Book Name-");
					cin.getline(book_name,99);
					strcpy(temp_book_name,getcwd(NULL,0));
					strcat(temp_book_name,"/Books/");
					strcat(temp_book_name,book_name);
					strcat(temp_book_name,".txt");
					file.open(temp_book_name,ios::in);
					if(file.fail())
					{
						printf("Book Not found...Enter Book Name Again\n");
						file.close();
						continue;
					}
					char ch='n';
					char summary[100];
					i=0;
					printf("\nSummary of %s-\n",book_name);
					while(1)//Showing the Summary from the book_file
					{
						i++;
						file>>summary;
						if(strcmp(summary,"END")==0)
							break;
						printf("%s ",summary);
						if(i==15)
							printf("\n");
					}
					file.close();
					printf("\n\nWant to Add this book to your Library? (y/n)-");
					scanf("%c",&ch);
					if(ch=='y' || ch=='Y')
					{
						fstream user;			//Adding Book to User's File
						user.open(temp,ios::out|ios::app);
						user<<book_name<<" `"<<endl;
						user.close();

						file.open(temp_book_name,ios::out|ios::app);	//Adding User to Book's File
						file<<user_name<<endl;
						file.close();
						printf("\nBook Added to your Library!\n");
						break;
					}
					if(ch=='n' || ch=='N')
					{
						file.close();
						printf("\nPress Enter to Exit...");
						getchar();
					return 0;
					}
				}
			}
			if(ch==2)			//Entering Author Name
			{
				char author_name[100],temp_author_name[100],book_name[100],temp_book_name[100];
				int flag=0;	
				fstream file;		//Displaying all the Authors Available
				printf("\nThe Authors Available are-\n");
				file.open("All Authors.txt",ios::in);
				while(1)
				{
					file>>author_name;
					if(strcmp(author_name,"END")==0)
						break;
					if(strcmp(author_name,"`")==0)
					{
						printf("\n");
						continue;
					}
					printf("%s ",author_name);
				}
				getchar();
				while(1)
				{
					printf("\nEnter Author-");
					file.close();
					cin.getline(author_name,99);

					strcpy(temp_author_name,getcwd(NULL,0));
					strcat(temp_author_name,"/Authors/");
					strcat(temp_author_name,author_name);
					strcat(temp_author_name,".txt");
					file.open(temp_author_name,ios::in);
					if(file.fail())
					{
						printf("\nAuthor Not found...Enter Author Name Again\n");
						file.close();
						continue;
					}
					printf("\nAll the Books written by %s-\n",author_name);
					while(1)	//Printing all books by the Author
					{
						file>>author_name;
						if(strcmp(author_name,"END")==0)
							break;
						if(strcmp(author_name,"`")==0)
						{
							printf("\n");
							continue;
						}
						printf("%s ",author_name);
					}
					file.close();
					while(1)
					{
						printf("\nEnter Book Name-");
						//getchar();
						cin.getline(book_name,99);

						strcpy(temp_book_name,getcwd(NULL,0));
						strcat(temp_book_name,"/Books/");
						strcat(temp_book_name,book_name);
						strcat(temp_book_name,".txt");
						file.open(temp_book_name,ios::in);
						if(file.fail())
						{
							printf("\nBook Not found...Enter Book Name Again\n");
							file.close();
							continue;
						}
						char ch='n';
						char summary[100];
						i=0;
						printf("\nSummary of %s-\n",book_name);
						while(1)//Showing the Summary from the book_file
						{
							i++;
							file>>summary;
							if(strcmp(summary,"END")==0)
								break;
							printf("%s ",summary);
							if(i==15)
								printf("\n");
						}
						file.close();
						printf("\n\nWant to Add this book to your Library? (y/n)-");
						scanf("%c",&ch);
						if(ch=='y' || ch=='Y')
						{
							fstream user;			//Adding Book to User's File
							user.open(temp,ios::out|ios::app);
							user<<book_name<<" `"<<endl;
							user.close();

							file.open(temp_book_name,ios::out|ios::app);	//Adding User to Book's File
							file<<user_name;
							file.close();
							printf("\nBook Added to your Library!\n");
							break;
						}
					}
					if(ch=='n' || ch=='N')
					{
						file.close();
						printf("Press Enter to Exit...");
						getchar();
					return 0;
					}
					break;
				}
			}
			//**SUGGEST ME**
			if(ch==3)
			{
				/*On basis of users you are folowing*/
				int graph[100][100];
				int i=0,j=0,num,self_num;
				char temp_user_name[100],temp[100],temp2[100];
				char index[100][100];
				fstream filex;

				strcpy(dir_temp,getcwd(NULL,0));
				strcat(dir_temp,"/Users/User Index.txt");
				filex.open(dir_temp,ios::in);
				while(filex>>temp)			//Getting Index of User and the users who hs follows
				{
					if(strcmp(temp,user_name)==0)
					{
						strcpy(temp_user_name,temp);
						filex>>temp;
						self_num=atoi(temp);
						strcpy(index[self_num-1],user_name);
						continue;
					}
					if(i%2==0)
						strcpy(temp_user_name,temp);
					if(i%2!=0)
						strcpy(index[atoi(temp)-1],temp_user_name);
					i++;
				}
				filex.close();

				strcpy(temp_user_name,getcwd(NULL,0));
				strcat(temp_user_name,"/Users/");
				strcat(temp_user_name,user_name);
				strcat(temp_user_name,"_follow.txt");
				filex.open(temp_user_name,ios::in);
				fstream temp_user;
				while(filex>>temp)
				{
					num=atoi(temp);
					graph[self_num-1][num-1]=1;
					graph[num-1][self_num-1]=1;

					strcpy(temp,getcwd(NULL,0));
					strcat(temp,"/Users/");
					strcat(temp,index[num-1]);
					strcat(temp,"_follow.txt");
					temp_user.open(temp,ios::in);
					while(temp_user>>temp2)
					{
						graph[num-1][atoi(temp2)-1]=1;
						graph[atoi(temp2)-1][num-1]=1;
					}
					temp_user.close();
				}
				filex.close();


				fstream no_of_usernames;
				strcpy(dir_temp,getcwd(NULL,0));
				strcat(dir_temp,"/Users/Number of Users.txt");
				no_of_usernames.open(dir_temp,ios::in);		//Number of users from Number of Users.txt
				char no[100];
				no_of_usernames>>no;
				int n=atoi(no);
				no_of_usernames.close();

				//Remove Comments to see the 2D Graph Representation
				/*for(i=0 ; i<n ; i++)
				{
					for(j=0 ; j<n ;j++)
						printf("%d ",graph[i][j]);
					printf("\n");
				}*/

				/*Prim's Minimun Spanning Tree*/
				int parent[100];
     			int key[100];
     			bool mstSet[100];
    			for (i=0; i<n; i++)
    			{
        			key[i]=199;
        			mstSet[i]=false;
        		}
    			key[0]=0;
    			parent[0] = -1;
    			for (int count=0; count<n-1; count++)
    			{
        			int u=minKey(key, mstSet,n);
        			mstSet[u] = true;

        			for (int v=0; v<n; v++)
        			{
          				if (graph[u][v] && mstSet[v] == false && graph[u][v] <=  key[v])
          				{
            				parent[v]  = u;
            				key[v] = graph[u][v];
            			}
            		}
     			}

     			printf("\nSuggestion according to the users you follow, and the users follwed by the users you follow-\n");
				int check[100]={0};
     			for(i=1 ; i<n ; i++)
     			{
     				check[self_num-1]=1;
     				if(check[parent[i]]==0)
     				{
     					check[parent[i]]=1;

     					strcpy(temp_user_name,getcwd(NULL,0));
						strcat(temp_user_name,"/Users/");
						strcat(temp_user_name,index[parent[i]]);
						strcat(temp_user_name,".txt");
     					filex.open(temp_user_name,ios::in);
     					while(filex>>temp)
     					{
     						if(strcmp(temp,"END")==0)
     						{
     							while(filex>>temp)
     							{
     								if(strcmp(temp,"`")==0)
									{
										printf("\n");
										continue;
									}
									printf("%s ",temp);
								}
								break;
     						}
     					}
     					filex.close();
     				}
     				if(check[i]==0)
     				{
     					check[i]=1;
     					strcpy(temp_user_name,getcwd(NULL,0));
						strcat(temp_user_name,"/Users/");
						strcat(temp_user_name,index[i]);
						strcat(temp_user_name,".txt");
     					filex.open(temp_user_name,ios::in);
     					while(filex>>temp)
     					{
     						if(strcmp(temp,"END")==0)
     						{
     							while(filex>>temp)
     							{
     								if(strcmp(temp,"`")==0)
									{
										printf("\n");
										continue;
									}
									printf("%s ",temp);
								}
								break;
     						}
     					}
     					filex.close();
     				}
        		}
        		while(1)
        		{
        			printf("\n Enter The Name of the Book you want to Read-\n");
        			getchar();
        			cin.getline(temp,99);

        			strcpy(temp2,getcwd(NULL,0));
					strcat(temp2,"/Books/");
					strcat(temp2,temp);
					strcat(temp2,".txt");
        			filex.open(temp2,ios::in);
        			if(filex.fail())
        			{
        				printf("\nBook not Found...Enter name again\n");
        				filex.close();
        				continue;
        			}

					char ch='n';
					char summary[100];
					i=0;
					printf("\nSummary of %s-\n",temp);
					while(1)//Showing the Summary from the book_file
					{
						i++;
						filex>>summary;
						if(strcmp(summary,"END")==0)
							break;
						printf("%s ",summary);
						if(i==15)
							printf("\n");
					}
					filex.close();

					strcpy(temp_user_name,getcwd(NULL,0));
					strcat(temp_user_name,"/Users/");
					strcat(temp_user_name,user_name);
					strcat(temp_user_name,".txt");
					printf("\n\nWant to Add this book to your Library? (y/n)-");
					scanf("%c",&ch);
					if(ch=='y' || ch=='Y')
					{
						fstream userx;			//Adding Book to User's File
						userx.open(temp_user_name,ios::out|ios::app);
						userx<<temp<<" `"<<endl;
						userx.close();

						fstream filexx;
						filexx.open(temp2,ios::out|ios::app);	//Adding User to Book's File
						filexx<<user_name<<endl;
						filexx.close();
						printf("\nBook Added to your Library!\n");
						break;
					}
					if(ch=='n' || ch=='N')
					{
						filex.close();
						printf("\nPress Enter to Exit...");
						getchar();
					return 0;
					}
        		}
			}
		}
		if(choice==2)
		{
			int flag=0;
			char books[100],temp_books[100];

			strcpy(temp,getcwd(NULL,0));
			strcat(temp,"/Users/");
			strcat(temp,user_name);
			strcat(temp,".txt");
			fstream user;
			user.open(temp,ios::in);
			printf("\nThe Books you have Read-\n");		//Printing all the books read by the User
			while(1)
			{
				user>>books;
				//printf("%s\n",books);
				if(strcmp(books,"END")==0)
				{
					while(user>>books)
					{
						if(strcmp(books,"`")==0)
						{
							printf("\n");
							continue;
						}
						printf("%s ",books);
					}
					break;
				}
			}
			user.close();
			getchar();
			while(1)
			{
				float rating;
				int flag=0;
				printf("\nEnter the Name of the book you want to Rate-");
				cin.getline(books,99);
				fstream file1;
				strcpy(temp_books,getcwd(NULL,0));
				strcat(temp_books,"/Books/");
				strcat(temp_books,books);
				strcat(temp_books,".txt");
				file1.open(temp_books,ios::in);
				if(file1.fail())
				{
					printf("\nYou Have not Read the Entered Book...Please Enter the Name of the Book again!\n");
					file1.close();
					continue;
				}
				printf("\nEnter your rating out of 10-");
				cin>>rating;

				fstream temp;
				temp.open("temp.txt",ios::out|ios::trunc);
				while(file1>>books)
				{
					if(strcmp(books,"END")==0)
					{
						flag=1;
						temp<<endl<<books<<endl;
						continue;
					}
					if(strcmp(books,user_name)==0)
					{
						temp<<books<<" - "<<rating<<endl;
						continue;
					}
					if(flag==0)
						temp<<books<<" ";
					else
						temp<<books<<endl;
				}
				flag=0;
				file1.close();
				temp.close();
				remove(temp_books);
				rename("temp.txt",temp_books);
				printf("\nRating Added\n");
				break;
			}
		}

		if(choice==3)
		{
			i=0;
			char users[100],temp_users[100],tempx[100];
			fstream file2;
			strcpy(dir_temp,getcwd(NULL,0));
			strcat(dir_temp,"/Users/User Names.txt");
			file2.open(dir_temp,ios::in);
			while(file2>>users)
			{
				if(strcmp(users,user_name)==0)
					continue;
				printf("%d.%s\n",++i,users);
			}
			file2.close();
			printf("\nEnter The User Name you want to follow-");
			getchar();
			while(1)
			{
				cin.getline(tempx,99);
				strcpy(temp_users,getcwd(NULL,0));
				strcat(temp_users,"/Users/");
				strcat(temp_users,tempx);
				strcat(temp_users,".txt");
				file2.open(temp_users,ios::in);
				if(file2.fail())
				{
					printf("\nUser Not Found...Enter Again\n");
					file2.close();
					continue;
				}
				file2.close();
				strcpy(dir_temp,getcwd(NULL,0));
				strcat(dir_temp,"/Users/User Index.txt");
				file2.open(dir_temp,ios::in);
				while(file2>>temp_users)
				{
					if(strcmp(temp_users,tempx)==0)
					{
						file2>>temp_users;
						fstream file3;
						strcpy(users,getcwd(NULL,0));
						strcat(users,"/Users/");
						strcat(users,user_name);
						strcat(users,"_follow.txt");
						file3.open(users,ios::out|ios::app);
						file3<<temp_users<<endl;
						printf("\nYou are Now Following %s\n",tempx);
						file3.close();
					}
				}
				break;
			}
		}
		if(choice==4)
			return 0;
	}
	return 0;
}

int minKey(int key[], bool mstSet[],int n)
{
	int min = 199, min_index;
	for (int v = 0; v < n; v++)
	{
    	if (mstSet[v] == false && key[v] <= min)
    	{
    		min = key[v];
    		min_index = v;
    	}
    }
	return min_index;
}
