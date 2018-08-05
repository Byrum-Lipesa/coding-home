/****************************************
* Title: Student Report Card System     *
* Author: Lipesa Byrum Alusiola         *
* IDE: Code::Blocks 16.01               *
* Dated: January 10,2018                *
* Email: bymash2007@gmail.com           *
*****************************************/

//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<windows.h>
#include <ctime>
#include <ctype.h>
#include <math.h>
#include <limits>
using namespace std;
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
//bool is_present(int roll_number);
class student
{
    int rollno;
    char name[50];
    int p_marks,c_marks,m_marks,e_marks,cs_marks;
    float per;
    char grade;
    int std;
    void calculate()
    {
        per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
        if(per>=60)
            grade='A';
        else if(per>=50 && per<60)
            grade='B';
        else if(per>=33 && per<50)
            grade='C';
        else
            grade='F';
    }
public:
    void getdata(int roll_number)
    {
        rollno = roll_number;
        label1:
        cout<<"\n\n\tEnter The Name of student: ";
        cin.ignore();
        cin.getline (name,50);
        int check1 = 0;
        if (strlen(name)== 0) {
            cout << "\n\tInvalid Input. Name cannot be blank: ";
            check1 = 1;
        }
        else {
            for(int i = 0; i < strlen(name); i++){
                if(isalpha(name[i]) == 0){
                    if (name[i] == ' ')
                    {
                        check1 = 0;
                    }
                    else
                    {
                    cout << "\n\tInvalid Input. Only alphabets are allowed: ";
                    check1 = 1;
                    break;
                    }
                }
            }
        }
        if (check1 == 1)
        {
            goto label1;
        }
        cout<<"\n\n\tEnter The marks in physics out of 100: ";
        while(1)
        {
            cin>>p_marks;
            if (cin.fail() || p_marks < 0 || p_marks > 100 )
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(),'\n');
                cout << "\n\tInvalid Input...\n\tMarks should be a numerical value between 0 and 100: ";
            }
            else
                break;
        }
        cout<<"\n\n\tEnter The marks in chemistry out of 100: ";
        while(1)
        {
            cin>>c_marks;
            if (cin.fail() || c_marks < 0 || c_marks > 100 )
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(),'\n');
                cout << "\n\tInvalid Input...\n\tMarks should be a numerical value between 0 and 100: ";
            }
            else
                break;
        }
        cout<<"\n\n\tEnter The marks in maths out of 100: ";
        while(1)
        {
            cin>>m_marks;
            if (cin.fail() || m_marks < 0 || m_marks > 100 )
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(),'\n');
                cout << "\n\tInvalid Input...\n\tMarks should be a numerical value between 0 and 100: ";
            }
            else
                break;
        }
        cout<<"\n\n\tEnter The marks in english out of 100: ";
        while(1)
        {
            cin>>e_marks;
            if (cin.fail() || e_marks < 0 || e_marks > 100 )
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(),'\n');
                cout << "\n\tInvalid Input...\n\tMarks should be a numerical value between 0 and 100: ";
            }
            else
                break;
        }
        cout<<"\n\n\tEnter The marks in computer science out of 100: ";
        while(1)
        {
            cin>>cs_marks;
            if (cin.fail() || cs_marks < 0 || cs_marks > 100 )
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(),'\n');
                cout << "\n\tInvalid Input...\n\tMarks should be a numerical value between 0 and 100: ";
            }
            else
                break;
        }
        calculate();
    }

    void showdata()
    {
        cout<<"\n\tRoll number of student: "<<rollno;
        cout<<"\n\n\tName of student: "<<name;
        cout<<"\n\n\tMarks in Physics: "<<p_marks;
        cout<<"\n\n\tMarks in Chemistry: "<<c_marks;
        cout<<"\n\n\tMarks in Maths: "<<m_marks;
        cout<<"\n\n\tMarks in English: "<<e_marks;
        cout<<"\n\n\tMarks in Computer Science: "<<cs_marks;
        cout<<"\n\n\tPercentage of student is: "<<setprecision(2)<<per;
        cout<<"\n\n\tGrade of student is: "<<grade;
    }
    int aggregate_total () {
        int sum = p_marks + c_marks + m_marks + e_marks + cs_marks;
        return sum;
    }
    void show_tabular()
    {
        cout<<rollno<<setw(12)<<name<<setw(10)<<p_marks<<setw(3)<<c_marks<<setw(3)<<m_marks<<setw(3)<<e_marks<<setw(3)<<cs_marks<<setw(6)<<setprecision(3)<<per<<"   "<<grade<<endl;
        cout<<"\n";
    }

    void reportcard_template()
    {
        cout<<"\n\n\n\t_____________________________STUDENT REPORT CARD_____________________________";
        cout<<"\n\n\tSTUDENT NAME: "<<name;
        cout<<"\tSTUDENT ROLL NO: "<<rollno;
        cout<<"\tDATE:________________________";
        cout<<"\n\n\t_____________________________________________________________________________";
        cout<<"\n\n\tSUBJECT ";
        cout<<"\t\tSCORE ";
        cout<<"\t\tGRADE ";
        cout<<"\t\tCOMMENTS ";
        cout<<"\n";
        string comments = "";
        char grade;
        cout<<"\n\n\tPHYSICS ";
        cout<<"\t\t"<<p_marks;
        comments = show_comments(p_marks);
        grade = show_grades(p_marks);
        cout<<"\t\t"<<grade;
        cout<<"\t\t"<<comments;
        cout<<"\n";
        cout<<"\n\n\tCHEMISTRY ";
        cout<<"\t\t"<<c_marks;
        comments = show_comments(c_marks);
        grade = show_grades(c_marks);
        cout<<"\t\t"<<grade;
        cout<<"\t\t"<<comments;
        cout<<"\n";
        cout<<"\n\n\tMATHS ";
        cout<<"\t\t\t"<<m_marks;
        comments = show_comments(m_marks);
        grade = show_grades(m_marks);
        cout<<"\t\t"<<grade;
        cout<<"\t\t"<<comments;
        cout<<"\n";
        cout<<"\n\n\tENGLISH ";
        cout<<"\t\t"<<e_marks;
        comments = show_comments(e_marks);
        grade = show_grades(e_marks);
        cout<<"\t\t"<<grade;
        cout<<"\t\t"<<comments;
        cout<<"\n";
        cout<<"\n\n\tCOMPUTER SCIENCE ";
        cout<<"\t"<<cs_marks;
        comments = show_comments(cs_marks);
        grade = show_grades(cs_marks);
        cout<<"\t\t"<<grade;
        cout<<"\t\t"<<comments;
        cout<<"\n";
        cout<<"\t_____________________________________________________________________________";
        cout<<"\n\n\tTOTAL SCORE: ";
        cout<<"\t\t"<<aggregate_total();
        cout<<"\t\t"<<this->grade;
        cout<<"\t\tAVERAGE SCORE: "<<per;
        cout<<"\n\t_____________________________________________________________________________";
        cout<<"\n\t_____________________________________________________________________________";
        cout<<"\n\n\n\t______________________________ AVERAGE GRADE:"<<this->grade<< " ______________________________";
    }

    string show_comments (int score) {
        string comments = "";
        if (score > 59)
            comments = "EXCELLENT. KEEP IT UP";
        else if (score > 49)
            comments = "FAIR. PUT MORE EFFORT";
        else if (score > 32)
            comments = "AVERAGE. WORK HARDER";
        else
            comments = "BELOW AVERAGE. BE MORE SERIOUS";
        return comments;
    }

    char show_grades(int score) {
        char grade;
        if (score > 59)
            grade = 'A';
        else if (score > 49)
            grade = 'B';
        else if (score > 32)
            grade = 'C';
        else
            grade = 'F';
        return grade;
    }

    int  retrollno()
    {
        return rollno;
    }

};         //class ends here



//***************************************************************
//      global declaration for stream object, object
//****************************************************************

fstream fp;
student st;

//***************************************************************
//      function prototypes
//****************************************************************

bool is_present(int roll_number);
void entry_menu();

//***************************************************************
//      function to write in file
//****************************************************************

void write_student()
{
    system("cls");
    int roll_number;
    char choice;
    cout<<"\n\n\n\t____________________________DATA ENTRY FORM___________________________";
    cout<<"\n\n\tEnter The roll number of student: ";
    while(1)
    {
        cin>>roll_number;
        if (cin.fail() || roll_number < 1 )
        {
            system("cls");
            cout<<"\n\n\n\t____________________________DATA ENTRY FORM___________________________";
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(),'\n');
            cout << "\n\n\tInvalid Input...\n\tPlease Enter a Roll No. greater than or equal to 1: ";
        }
        else
            break;
    }
    bool exists = is_present(roll_number);
    if (exists) {
        cout<<"\n\tA student with the same roll number already exists, to proceed: ";
        cout<<"\n\n\t____________________CHOOSE ANY OF THE OPTIONS BELOW___________________";
        cout<<"\n\n\t1.RETRY ONE MORE TIME";
        cout<<"\n\n\t2.BACK TO PARENT MENU";
        cout<<"\n\n\t3.BACK TO MAIN MENU";
        cout<<"\n\n\tEnter Choice (1-3)? ";
        choice = getche();
        switch(choice)
        {
        case '1':
            write_student();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            break;
        default:
            cout<<"\a";
            write_student();
        }
    }
    else {
        fp.open("student.dat",ios::out|ios::app);
        st.getdata(roll_number);
        fp.write((char*)&st,sizeof(student));
        fp.close();
        cout<<"\n\tStudent record has been created successfully, to proceed: ";
        cout<<"\n\n\t____________________CHOOSE ANY OF THE OPTIONS BELOW___________________";
        cout<<"\n\n\t1.CREATE ANOTHER RECORD";
        cout<<"\n\n\t2.BACK TO PARENT MENU";
        cout<<"\n\n\t3.BACK TO MAIN MENU";
        cout<<"\n\n\tEnter Choice (1-3)? ";
        choice = getche();
        switch(choice)
        {
        case '1':
            write_student();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            break;
        default:
            cout<<"\a";
            write_student();
        }
    }
}


//***************************************************************
//      function to read all records from file
//****************************************************************


void display_all()
{
    int rec_count = 0;
    system("cls");
    cout<<"\n\n\n\t_________________________DISPLAY ALL RECORDS_________________________\n\n";
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        ++rec_count;
        st.showdata();
        cout<<"\n\n\t====================================\n";
        cout<<"\n\n\t====================================\n";
        if (rec_count % 2 == 0) {
            cout<<"\n\n\n\t______________________PRESS ANY KEY TO VIEW MORE_____________________";
            getch();
            cout<<"\n\n";
        }
    }
    fp.close();
    cout<<"\n\n\n\t_________________________________END_________________________________";
    getch();
}


//***************************************************************
//      function to read specific record from file
//****************************************************************


void display_sp(int n)
{
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(st.retrollno()==n)
        {
            st.showdata();
            flag=1;
            cout<<"\t";
        }
    }
    fp.close();
    if(flag==0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(),'\n');
        cout<<"\n\n\tThe record was not found";
    }
    //getch();
}

//***************************************************************
//      function to display report card template
//****************************************************************

void display_reportcard(int rollnumber)
{
    bool is_found = is_present(rollnumber);
    if (is_found) {
        fp.open("student.dat",ios::in);
        while(fp.read((char*)&st,sizeof(student)))
        {
            if(st.retrollno()==rollnumber)
            {
                st.reportcard_template();
            }
        }
        fp.close();
    }
    else {
        cout<<"\n\n\tThe record was not found";
    }
    getch();
}

//***************************************************************
//      function to check if record is present
//****************************************************************

bool is_present(int roll_number)
{
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(st.retrollno()== roll_number)
            flag=1;
    }
    fp.close();
    if(flag==0)
      return false;
    else
      return true;
}

//***************************************************************
//      function to modify record of file
//****************************************************************

void modify_student()
{
    int no,found=0;
    cout<<"\n\n\tTo Modify record, enter the roll number of student: ";
    cin>>no;
    bool exists = is_present(no);
    if (exists) {
        fp.open("student.dat",ios::in|ios::out);
        while(fp.read((char*)&st,sizeof(student)))
        {
            if(st.retrollno()==no)
            {
                st.showdata();
                cout<<"\n\n\tPress any key to proceed";
                getche();
                st.getdata(no);
                int pos=-1*sizeof(st);
                fp.seekp(pos,ios::cur);
                fp.write((char*)&st,sizeof(student));
                cout<<"\n\n\n\tRecord updated successfully";
            }
        }
        fp.close();
    }
    else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(),'\n');
        cout<<"\n\n\tRecord was not found ";
    }
    getch();
}


//***************************************************************
//      function to delete record of file
//****************************************************************


void delete_student(int no)
{
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(st.retrollno()!=no)
        {
            fp2.write((char*)&st,sizeof(student));
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    //getch();
}


//***************************************************************
//      function to display all students grade report
//****************************************************************

void class_result()
{
    system("cls");
    fp.open("student.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
        cout<<"\n\n\n Program is closing ....";
        getch();
        exit(0);
    }

    //cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
    cout<<"\n\n\n\t_________________________ALL STUDENTS RESULTS_________________________";
    cout<<"\n\n\t====================================================";
    cout<<"\n\n\tLN Roll No. Name         P  C  M  E CS  %age Grade";
    cout<<"\n\n\t====================================================\n\n\t\0.5t";
    int l_number = 1;
    while(fp.read((char*)&st,sizeof(student)))
    {
        cout<<l_number<<". ";
        l_number++;
        st.show_tabular();
        cout<<"\t";
    }
    fp.close();
    cout<<"\n\n\t________________________________THE END_______________________________";
    getch();
}




//***************************************************************
//      function to display result menu
//****************************************************************

void result()
{
    int ans,rno;
    char ch, to_continue, choice;
    system("cls");
    cout<<"\n\n\n\t_____________________________RESULTS MENU_____________________________";
    cout<<"\n\n\t1.CLASS RESULT";
    cout<<"\n\n\t2.STUDENT REPORT CARD";
    cout<<"\n\n\t3.BACK TO MAIN MENU";
    cout<<"\n\n\tEnter Choice (1-3)? ";
    ch=getche();
    labelResult:
    switch(ch)
    {
    case '1' :
        class_result();
        cout<<"\n\n\tThe proceed further: ";
        cout<<"\n\n\t____________________SELECT ANY OF THE OPTIONS BELOW___________________";
        cout<<"\n\n\t1.BACK TO PARENT MENU";
        cout<<"\n\n\t2.BACK TO MAIN MENU";
        cout<<"\n\n\tEnter Choice (1-2)? ";
        choice = getche();
        switch(choice)
        {
        case '1':
            result();
            break;
        case '2':
            break;
        default:
            cout<<"\a";
            goto labelResult;
            break;
        }

        break;
    case '2' :
    {
        do
        {
            system("cls");
            cout<<"\n\n\n\t____________________________REPORT CARDS SECTION_____________________________";
            cout<<"\n\n\tEnter Roll Number Of Student : ";
            while(1)
            {
                cin>>rno;
                if (cin.fail() || rno < 1 )
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize> :: max(),'\n');
                    cout << "\n\tInvalid Input. Use the correct input format: ";
                }
                else
                    break;
            }
            display_reportcard(rno);
            cout<<"\n\n\tDo you want to see other report cards (y/n)? ";
            to_continue = getche();
        }
        while(to_continue=='y'||to_continue=='Y');
        break;
    }
    case '3':
        break;
    default:
        cout<<"\a";
        result();
    }
}
//***************************************************************
//      function to shift cursor position
//****************************************************************

void gotoxy (int x, int y)
{

COORD coord;
coord.X = x;
coord.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//***************************************************************
//      function to display current date and time
//****************************************************************

void time()
{
	//  FOR current time and date
    time_t now;
	time (&now);
	cout << "Current Date & Time is: "<<ctime(&now);;         // For Displaying Date and Time
	// Creating Object of Time

}
//***************************************************************
//      function to display loading progress
//****************************************************************

void loading()
{
 system("color 01");
 cout<<"\n\n\n\t\t\t\tPlease wait while loading...\n\n";
 char a=177, b=219;
 cout<<"\t\t\t\t";
 for (int i=0;i<=15;i++)
 cout<<a;
 cout<<"\r";
 cout<<"\t\t\t\t";
 for (int i=0;i<=15;i++)
 {
  cout<<b;
  for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
 }
}

//***************************************************************
//      function to display the exit message
//****************************************************************

void show_exitmsg()
{
    gotoxy(32,7);
    string msg = "THANK YOU FOR USING THIS APPLICATION";
    for( int i = 0; msg[i] != '\0'; i++ ) {
        if( msg[i] == ' ' )
            Sleep(150 + rand() % 100);
        else {
            Sleep(200 + rand() % 100);
            Beep(200, 100);
        }
        cout << msg[i];
    }
    gotoxy(45,14);
    msg = "GOODBYE!";
    for( int i = 0; msg[i] != '\0'; i++ ) {
        if( msg[i] == ' ' )
            Sleep(150 + rand() % 100);
        else {
            Sleep(200 + rand() % 100);
            Beep(200, 100);
        }
        cout << msg[i];
    }
    Sleep(1000);
    system("cls");
    cout<<"\a\a\a";
}

//***************************************************************
//      INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
    system("cls");
    gotoxy(12,4);
    cout << "_________________________STUDENT REPORT CARD SYSTEM_________________________";
    gotoxy(35,7);
    cout<<"MADE BY : Code::Blocks with C++";
    gotoxy(35,9);
    cout<<"AUTHOR : Lipesa Byrum Alusiola";
    gotoxy(35,11);
    cout<<"CONTACT : bymash2007@gmail.com";
    gotoxy(27,14);
    time();
    gotoxy(35,30);
    cout<<"Press any key to continue..";
    getch();

}




//***************************************************************
//      ENTRY / EDIT MENU FUNCTION
//****************************************************************
void entry_menu()
{
    system("cls");
    int rollno;
    bool exists;
    char ch2, choice;
    cout<<"\n\n\n\t_________________________ENTRY MENU_________________________";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
    cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
    ch2=getche();
    switch(ch2)
    {
    case '1':
        system("cls");
        cout<<"\n\n\n\t_________________________STUDENT REGISTRATION_________________________";
        write_student();
        break;
    case '2':
        cout<<"\n\n\n\t_________________________DISPLAY STUDENTS INFO_________________________";
        display_all();
        break;
    case '3':
        label3:
        system("cls");
        cout<<"\n\n\n\t_________________________DISPLAY STUDENT INFO_________________________";
        cout<<"\n\n\tPlease Enter The roll number: ";
        while(1)
        {
            cin>>rollno;
            if (cin.fail() || rollno < 1 )
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(),'\n');
                cout << "\n\tInvalid Input. Use the correct input format: ";
            }
            else
                break;
        }
        exists = is_present(rollno);
        if (exists) {
            display_sp(rollno);
            cout<<"\n\n\tThe record was found, to proceed: ";
            cout<<"\n\n\t____________________SELECT ANY OF THE OPTIONS BELOW___________________";
            cout<<"\n\n\t1.VIEW ANOTHER RECORD";
            cout<<"\n\n\t2.BACK TO PARENT MENU";
            cout<<"\n\n\t3.BACK TO MAIN MENU";
            cout<<"\n\n\tEnter Choice (1-3)? ";
            choice = getche();
            switch(choice)
            {
            case '1':
                goto label3;
                break;
            case '2':
                entry_menu();
                break;
            case '3':
                break;
            default:
                cout<<"\a";
                goto label3;
                break;
            }
        }
        else {
            cout<<"\n\tThe record was not found, to proceed: ";
            cout<<"\n\n\t____________________SELECT ANY OF THE OPTIONS BELOW___________________";
            cout<<"\n\n\t1.RETRY ONE MORE TIME";
            cout<<"\n\n\t2.BACK TO PARENT MENU";
            cout<<"\n\n\t3.BACK TO MAIN MENU";
            cout<<"\n\n\tEnter Choice (1-3)? ";
            choice = getche();
            switch(choice)
            {
            case '1':
                goto label3;
                break;
            case '2':
                entry_menu();
                break;
            case '3':
                break;
            default:
                cout<<"\a";
                goto label3;
                break;
            }
        }
        break;
    case '4':
        system("cls");
        cout<<"\n\n\n\t__________________________MODIFY STUDENT INFO_________________________";
        modify_student();
        break;
    case '5':
        label5:
        system("cls");
        cout<<"\n\n\n\t____________________________DELETE STUDENT RECORD____________________________";
        cout<<"\n\n\tEnter The roll number of student You Want To Delete: ";
        while(1)
        {
            cin>>rollno;
            if (cin.fail() || rollno < 1 )
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(),'\n');
                cout << "\n\tInvalid Input. Use the correct input format: ";
            }
            else
                break;
        }
        exists = is_present(rollno);
        if (exists) {
            delete_student(rollno);
            cout<<"\n\n\tThe record is successfully deleted, to proceed: ";
            cout<<"\n\n\n\t_______________________SELECT ANY OF THE OPTIONS BELOW_______________________";
            cout<<"\n\n\t1.DELETE ANOTHER RECORD";
            cout<<"\n\n\t2.BACK TO PARENT MENU";
            cout<<"\n\n\t3.BACK TO MAIN MENU";
            cout<<"\n\n\tEnter Choice (1-3)? ";
            choice = getche();
            switch(choice)
            {
            case '1':
                goto label5;
                break;
            case '2':
                entry_menu();
                break;
            case '3':
                break;
            default:
                cout<<"\a";
                goto label5;
                break;
            }
        }
        else {
            cout<<"\n\tThe record was not found, to proceed: ";
            cout<<"\n\n\t_______________________SELECT ANY OF THE OPTIONS BELOW_______________________";
            cout<<"\n\n\t1.RETRY ONE MORE TIME";
            cout<<"\n\n\t2.BACK TO PARENT MENU";
            cout<<"\n\n\t3.BACK TO MAIN MENU";
            cout<<"\n\n\tEnter Choice (1-3)? ";
            choice = getche();
            switch(choice)
            {
            case '1':
                goto label5;
                break;
            case '2':
                entry_menu();
                break;
            case '3':
                break;
            default:
                cout<<"\a";
                goto label5;
                break;
            }
        }
        break;
    case '6':
        break;
    default:
        cout<<"\a";
        entry_menu();
    }
}


//***************************************************************
//      THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
    char ch;
    loading();
    system("color 0A");
    intro();
    do
    {
        system("cls");
        cout<<"\n\n\n\t_________________________MAIN MENU_________________________";
        cout<<"\n\n\t1. RESULT MENU";
        cout<<"\n\n\t2. ENTRY/EDIT MENU";
        cout<<"\n\n\t3. EXIT";
        cout<<"\n\n\tPlease Select Your Option (1-3) ";
        ch=getche();
        switch(ch)
        {
        case '1':
            system("cls");
            result();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            system("cls");
            show_exitmsg();
            exit(0);
        default :
            cout<<"\a";
        }
    }
    while(ch!='3');
    cout<<"\t";
    return 0;
}

//***************************************************************
//                      END OF PROJECT
//***************************************************************
