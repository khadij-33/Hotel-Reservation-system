#include <iostream>
#include <string>
using namespace std;

const int NUM_ROOMS=5;
const double RATE=100.0;
bool isOccupied[NUM_ROOMS];
string guestName[NUM_ROOMS];
int nights[NUM_ROOMS];

void listROOMS(){
cout<<"---Rooms---"<<endl;
for(int i=0;i<NUM_ROOMS;i++){
    cout<<"Room"<<i+1<<": ";
    if(isOccupied[i]){
        cout<<"Occupied by "<<guestName[i]<<"("<<nights[i]<< " nights)"<<endl;
    }
else{
cout<<"Free"<<endl;
}
}
}


bool checkIn(int room,string name,int n ){
if (room<1||room>NUM_ROOMS){
    cout<<"Invalid room number!"<<endl;
    return false;
}

if(n<=0){
    cout<<"Nights must be more than 0!"<<endl;
    return false;
}
if(isOccupied[room-1]){
    cout<<"Room is already occupied!"<<endl;
    return false;
}
isOccupied[room-1]=true;
guestName[room-1]=name;
nights[room-1]=n;
cout<<"Check-in done.Room " <<room<<"for"<<name<<endl;
return true;
}
double computeBill(int room){
return nights[room-1]*RATE;
}
void checkOut(int room){
if(room<1||room>NUM_ROOMS){
    cout<<"Invalid room number"<<endl;
return;
}

if (!isOccupied[room-1]){
    cout<<"Room is already empty"<<endl;
return;
}

cout<<"Guest:"<<guestName[room-1]<<endl;
cout<<"Nights:"<<nights[room-1]<<endl;
cout<<"Total bill:"<<computeBill(room)<<endl;

isOccupied[room-1]=false;
guestName[room-1]="";
nights[room-1]=0;
}
int findFreeRoom(){
for(int i=0;i<NUM_ROOMS;i++){
    if(!isOccupied[i])
        return i;
}
    return -1;
}
int main(){
for(int i=0;i<NUM_ROOMS;i++){
    isOccupied[i]=false;
    guestName[i]="";
    nights[i]=0;
}
int choice;

do {
    cout<<"\n---Hotel Menu---"<<endl;
    cout<<"1.Check-in"<<endl;
    cout<<"2.Check-out"<<endl;
    cout<<"3.List-Rooms"<<endl;
    cout<<"4.Find Free room"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"Choose: ";
    cin>>choice;

if(choice==1){
    int room,n;
    string name;
    cout<<"Room number (1-"<<NUM_ROOMS<<"):";
    cin>>room;
    cout<<"Guest name: ";
    cin>>name;
    cout<<"Nights:";
    cin>>n;
    checkIn(room,name,n);
}else if(choice==2){
    int room;
    cout<<"Room number:";
    cin>>room;
    checkOut(room);
}else if (choice==3){
listROOMS();
}else if(choice==4){
int r=findFreeRoom();
if(r==-1)cout<<"no free rooms."<<endl;
else cout<<"first free room: "<<r+1<<endl;
}
}
while(choice!=0);
cout<<"Goodbye!"<<endl;
return 0;

}
