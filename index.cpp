#include<iostream>
#include<fstream>

using namespace std;

//PROJECT NAME : DMART BILLING SYSTEM USING C++
//NAME : IJARUL HAQUE ANSARI
//USN : 20BTRCS186

class shopping
{
	private:
		int pcode;//prodect code
		float price; //product price
		float dis; //discount on product
		string pname; //product name
		
		public:
			void menu(); //main menu of DMART	
			void administrator();//only admin can access
			void buyer();//for customer
			void add();//adding product
			void edit();//edidting product
			void rem();//removing product
			void list();//show list of the product
			void receipt();//at last receipt print
			
};

void shopping :: menu()//:: used becaz shopping class the public
{
	m://for goto m: uesd to jumped
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t         DMART Main Menu              \n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t|  1) Administrator   |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  2) Buyer           |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  3) Exit            |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\n\t\t\t Please select!";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email   \n";
			cin>>email;
			cout<<"\t\t\t Password       \n";
			cin>>password;
			
			if(email=="ijarulansari12345@gmail.com" && password=="ijarul@123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid email/password";
			}
			break;
	
	
	case 2:
		{
			buyer();
			
		}
	
	case 3:
		{
			exit(0);
		}
		
		default :
			{
				cout<< "Please select from the given options";
				
			}
			
	
}
goto m;//GOTO USED TO directly jumped to main menu
}

void shopping:: administrator()
{
	m://jumped into main menu
	int choice;
	cout<<"\n\n\n\t\t\t Administrator Menu";
	cout<<"\n\t\t\t|_____1) Add the product_____|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____2) Modify the product__|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____3) Delete the product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to main menu___|";
    
    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    		add();//ADD NEW PRODUCT
    		break;
    		
    	case 2:
    		edit();//EDIT THE PRODUCT
    		break;
    		
    	case 3:
    		rem();//REMOVE /DELETE THE PRODUCCT
    		break;
    		
    	case 4:
    		menu();//GOING TO MAIN MENU
    		break;
    		
    	default :
    		cout<<"Invalid choice!";
    		
	}
	goto m; //JUMPED
}

void shopping:: buyer()
{
	m: //JUMPED
	int choice;
	cout<<"\t\t\t   Buyer       \n";
	cout<<"\t\t\t_____________  \n";
	cout<<"                     \n";
	cout<<"\t\t\t1) Buy product \n";
	cout<<"\t\t\t_____________  \n";
	cout<<"                     \n";
	cout<<"\t\t\t2) Go back     \n";
	cout<<"\t\t\t_____________  \n";
	cout<<"\t\t\t Enter your choice : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			
		default :
			
			cout<<"invalid choice";
			
	}
	
	goto m;//JUMPED TO MAIN MENU
	
	
}

void shopping ::add()
{
	m:
	fstream data;//FILE STREAM/FILE HANDLING
	int c; //CODE OF PRODUCT
	int token=0; //COUNT THE SAME PRODUCT
	float p; //PRICE
	float d; //DISCOUNT
	string n;// NAME 
	
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product ";
	cin>>pcode;
	cout<<"\n\n\t Name of the product ";
	cin>>pname;
	cout<<"\n\n\t Price of the product";
	cin>>price;
	cout<<"\n\n\t Discount on product";
	cin>>dis;
	
	data.open("database.txt",ios::in); //USING DATABASE IN TEXT FORM (IOS:: IN ->READING MODE)
	
	if(!data)//IF DATA NOT PRESENT
	{
		data.open("database.txt", ios::app|ios::out);//IF FILE EXIST IT WILL OPENED AND IF NOT IT WILL CREATE
		//ios::app->APPEND AT THE END OF FILE NOT OVERWRITE
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";//THIS WIIL CONCATINATE THIS ALL VALUE IN DATA BASE
		data.close();//CLOSING DATA
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c ==pcode)//CODE IS ALREADY EXIST TOKEN COUNT INCREASE
			{
				token++;
				
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		
		
	
	
	if(token==1)
	 goto m;//IF TOKEN ALREADY FOUND JUMPED TO MAIN MENU
	else{
		data.open("database.txt", ios::app|ios::out);//IF FILE EXIST IT WILL OPENED AND IF NOT IT WILL CREATE
		//ios::app->APPEND AT THE END OF FILE NOT OVERWRITE
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";//THIS WIIL CONCATINATE THIS ALL VALUE IN DATA BASE
		data.close();
		
	}
}
	cout<<"\n\n\t\t Record inserted !";
}

void shopping ::edit()
{
	fstream data,data1;
	int pkey;//NEW PRODUCT CODE/KEY
	int token=0;//COUNT
	int c; //PRODUCT CODE
	float p;//PRICE OF PRODUCT
	float d;//DISCOUNT ON PRODUCT
	string n;//NAME OF PRODUCT
	
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	
	data.open("database.txt",ios::in);//OPEND DATABASE
	if(!data) //IF DATA IS NULL
	{
		cout<<"\n\nFile doesn't exist! ";//DISPLAY
	}
	else{
		
		data1.open("database1.txt", ios::app|ios::out);//IF FILE EXIST IT WILL OPENED AND IF NOT IT WILL CREATE
		//ios::app->APPEND AT THE END OF FILE NOT OVERWRITE
		
		data>>pcode>>pname>>price>>dis;//THIS WIIL CONCATINATE THIS ALL VALUE IN DATA BASE
		while(!data.eof())//WHILE DATA IS AT END OF FILE
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited ";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";//CONCATINATES
				
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");//DELETING PREVIOUS DATASET(DATA)
		rename("database1.txt","database.txt");//RENEMING NEW DATA TO PREVIOUS/ORIGINAL DATABASE
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}
	
	
	
}
void shopping::rem()
{
	
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code :";
	cin>>pkey;
	data.open("database.txt", ios::in);//OPEN DATABASE IN READYING MODE
	if(!data)//IF DATA IS NULL
	{
		cout<<"File doesnt exist";
		
	}
	
	else{
		data1.open("database1.txt",ios::app|ios::out);//IF FILE EXIST IT WILL OPENED AND IF NOT IT WILL CREATE
		//ios::app->APPEND AT THE END OF FILE NOT OVERWRITE
		data>>pcode>>pname>>price>>dis;//THIS WIIL CONCATINATE THIS ALL VALUE IN DATA BASE
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");//DELETING PREVIOUS DATASET(DATA)
		rename("database1.txt","database.txt");//RENEMING NEW DATA TO PREVIOUS/ORIGINAL DATABASE
		
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|___________________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|___________________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
		
	}
	data.close();//FILE CLOSE
}

void shopping::receipt() 
	{
		system("cls");//CLARE THE CONSOLE SCREEN
		fstream data;
		
		int arrc[100],arrq[100]; //C= ARRAY OF CODE OF PRODUCT AND Q= ARRAY OF QUANTITY OF PRODUCT
		char choice;
		int c=0; //COUNT
		float amount=0; //PRICE
		float dis=0;//DISCOUNT
		float total=0; //TOTAL PRICE
		cout<<"\n\n\t\t\t Receipt ";
		data.open("database.txt",ios::in);//OPEN DATABASE IN READYING MODE
		if(!data)//DATA IS NULL
		{
			cout<<"\n\n Empty database";
		}
		else
		{
			data.close();  //CLOSE FILE                                 
			list();
			cout<<"\n____________________________\n";
			cout<<"\n|                            |";
			cout<<"\n|    Please place the order  |";
			cout<<"\n|____________________________|\n";
			do
			{
				m:
				cout<<"\n\n Product Code : ";
				cin>>arrc[c];
				cout<<"\n Product Quantity : ";
				cin>>arrq[c];
				for(int i=0;i<c;i++)
				{
					if(arrc[c] == arrc[i])
					{
						cout<<"\n\n Duplicate Product Code. Please try again!";
						goto m; //JUMPED TO STARTING DO LOOP
					}
				}
				c++;             
				cout<<"\n\n Want to buy another product? Press Y for yes and N for no : ";
				cin>>choice;	
			}
			
			while(choice == 'y');
			system("cls");//CLEAR THE CONSOLE SCREEEN
			
			cout<<"\n\n\t\t\t__________****RECEIPT****______________\n";
			cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";
			
			
			for(int i=0;i<c;i++) 
			{
				data.open("database.txt",ios::in);//OPEND FILE IN READING MODE
				data>>pcode>>pname>>price>>dis;//CONCATINATE
				while(!data.eof())//UNTIL END OF FILE
				{
					if(pcode == arrc[i])   
					{
						amount = price*arrq[i];//PRICE * QUANTITY 
						dis = amount - (amount*dis/100); //DISCOUNT FORMULA
						total =total+ dis;
						cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;	
					}
					   data>>pcode>>pname>>price>>dis;  
				}
				data.close();
			}
			cout<<"\n\n----------------------------------------";
			cout<<"\n Total Amount : "<<total;
		}
	}
int main()
{
	shopping s;//SHOPPING CLASS CALLING
	s.menu();
}

