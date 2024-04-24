#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
typedef struct{
	string alarm="";
	string time="";
	string value="";
} alarmdef ;
typedef struct {
	string name="";
	alarmdef alarm[1000];
	int maxalarm=0;
} dev ;

dev devices[400];

int main(int argc, char* argv[]){
    int n, i,j,i2,j2,k,sl, wynik=0,found=0,found2=0;
    int extrainfo=0,debug=0;
    int ss=0,se=0,sto=0;
    int count=0,ddats=0,datt;
    std::size_t pos{};
    time_t now = time(0);
    int maxdev=0;
    char* dt = ctime(&now);
    string s,st,sp,spt[30];
    string time,device,alarm,value;
    std::vector<std::string> outputs;
//    cin >> s;
 //   cout <<argv[1] <<"\n";
   i=0;
	   j=0;
//	   while((std::getline (std::cin,s,'\n'))&&(i<6000)&&(!cin.eof())) {
     while((std::getline (std::cin,s,'\n'))&&(!cin.eof())) {
        // Add to the list of output strings
	sl=0;k=0;
//	cout <<j <<": "+s+'\n';
	ss=s.size();sp="";	
	while (k<ss) {
		if ((s[k]!=' ')&&(s[k]!=',')) {
			sp=sp+s[k]; };
		if (s[k]==',') {
			//cout << sl<<": "+sp+'\n';
			if (sl==0) time=sp; 
			if (sl==1) device=sp; 
			if (sl==3) alarm=sp;
			sl++;
			sp=""; }
		k++; }; 
       if (sl==4) value=sp;
// szukamy urzdzenia
	i2=0;found=0;
//	cout << device+" Maxdev=" << maxdev <<"\n";
//	cout << "linia="+time+" "+device+" "+alarm+" "+value+'\n';
	while ((i2<maxdev)&&(found==0)) {
//		cout << "step 1\n";
		if (device.compare(devices[i2].name)==0) { found=1;
			found2=0;j2=0;
			//cout << "step 1 device found id:" <<devices[i2].maxalarm <<"\n";
			while ((j2<devices[i2].maxalarm)&&(found2==0)) {
			//cout << device+" i2:j2=" << i2 <<":"<<j2 <<"\n";
			if (alarm.compare(devices[i2].alarm[j2].alarm)==0) { found2=1;
			//cout << "step found2=1 "<< i2 <<":" << j2 << "\n";
				if (value.compare(devices[i2].alarm[j2].value)!=0) {
					// jest zmiana - drukujemy
					if (debug==1) cout << "Zmiana="+time+" "+device+" "+alarm+" "+value+'\n';
					cout << "Change,"+devices[i2].alarm[j2].time+","+time+","+device+","+alarm+","+devices[i2].alarm[j2].value+'\n';
					cout << time+","+device+","+alarm+","+value+'\n';
					devices[i2].alarm[j2].value=value;
					devices[i2].alarm[j2].time=time; }
				};
				j2++; };
		if (found2==0) {
		    devices[i2].alarm[j2-1].alarm=alarm;
			devices[i2].alarm[j2-1].time=time;
			devices[i2].alarm[j2-1].value=value;
			devices[i2].maxalarm++;
			cout << time+","+device+","+alarm+","+value+'\n';
			//cout << "step found2=0 j2="<<j2 <<" " << devices[i2].alarm[j2-1].alarm +"\n" ;
			found=1;found2=1;};
		};
					
		if (found==0) i2++; };
	if (found==0) { devices[maxdev].name=device;
	        //cout << "Nowy maxdev:" <<maxdev <<"\n";
	        cout << "TS,Fqsn,Alarm,Value\n" ;
			devices[maxdev].maxalarm=1;
			devices[maxdev].alarm[0].alarm=alarm;
			devices[maxdev].alarm[0].time=time;
			devices[maxdev].alarm[0].value=value;
			cout << time+","+device+","+alarm+","+value+'\n';
			maxdev++;  };
	//cout << sl<<": "+sp+'\n';
    //cout << '\n';j++;
	   i++;
   }
   //cout <<"\n" ;
   if (extrainfo==1) {
// List of all alarms:
   i=0;
   while (i<maxdev) {
     cout <<devices[i].name + "\n";
     j=0;
     while (j<devices[i].maxalarm) {
	   cout << "No:" << j << " "+devices[i].alarm[j].alarm + " "+ devices[i].alarm[j].time+" "+devices[i].alarm[j].value+"\n"; j++; };
   i++;
        };
   };
    return 0;
}
//					 se=j; 
//					 //cout<< "se:ss"<< se <<":"<<ss<<"\n";
//					 sp=st.substr(ss+1,se-ss-1); spt[sto]=sp;  
//				  	//if ((sto==4)||(sto==8)||(sto==15)||(sto==18)) cout << sto << ":" <<sp <<"\n";  
//				  	//cout << sto <<" " << sp <<"\n"; 
//					ss=0; se=0; sto++; }; 
//				     if (((st[j]==',')||(st[j]=='}')||(st[j]==':'))&&(ss==0)) {
//					 ss=j;};
//				 j++;}
//				 if (sto>20)
//					// Wynik 
//				      //cout<< spt[18]+","+spt[15]+","+spt[8]+","+spt[4]<<"\n";
//				      dat=(stoll(spt[15],&pos)-116444736000000000)/10000000;
//				      cout<< spt[18]+";";
 //   				      time_t nnow = dat;
//				      tm *dt = localtime(&nnow);
//				      datt=1900+dt->tm_year;times=std::to_string(datt);
//				      if (1+dt->tm_mon<10) { 
//				      			datt=dt->tm_mon+1;times=times+"-0"+std::to_string(datt); }
//				      if (1+dt->tm_mon>9) { 
//				      			datt=dt->tm_mon+1;times=times+"-"+std::to_string(datt); }
//				      if (dt->tm_mday<10) { 
////				      			datt=dt->tm_mday;times=times+"-0"+std::to_string(datt); }
//				      if (dt->tm_mday>9) { 
//				      			datt=dt->tm_mday;times=times+"-"+std::to_string(datt); }
//				      if (dt->tm_hour<10) { 
//				      			datt=dt->tm_hour;times=times+" 0"+std::to_string(datt); }
//				      if (dt->tm_hour>9) { 
//				      			datt=dt->tm_hour;times=times+" "+std::to_string(datt); }
//				      if (dt->tm_min<10) { 
//				      			datt=dt->tm_min;times=times+":0"+std::to_string(datt); }
//				      if (dt->tm_min>9) { 
//				      			datt=dt->tm_min;times=times+":"+std::to_string(datt); }
//				      if (dt->tm_sec<10) { 
//				      			datt=dt->tm_sec;times=times+":0"+std::to_string(datt); }
////				      if (dt->tm_sec>9) { 
//				      			datt=dt->tm_sec;times=times+":"+std::to_string(datt); }
//
//				      cout <<1900+dt->tm_year<<"-0"<< 1+dt->tm_mon<< "-" << dt->tm_mday << " 0"<<  dt->tm_hour <<":"<< dt->tm_min <<":"<< dt->tm_sec ;
//				      cout<< times <<";"+spt[0]+";"+spt[8]+";"<<spt[4]<<";"<< spt[15] <<";" << dat << "\n";
//				      cdat0++;cdat10++;cdat100++;
//				      if (dat>dat0) { cout << "stat0;"+times+";" << cdat0 <<";\n"; cdat0=0 ;dat0=dat;};
//				      if (dat>dat10+9) { cout << "stat10;"+times+";" << cdat10 <<";\n";  cdat10=0 ;dat10=dat;};
//				      if (dat>dat100+99) { cout << "stat100;"+times+";" << cdat100 <<";\n";  cdat100=0;dat100=dat;};
//				      //if (dat>dat0) { cout << "stat0;"+times+";" << cdat0 <<";"<<dt<<";\n"; cdat0=0 ;};
//				      if (dat0==0) { dat0=dat; dat10=dat; dat100=dat; };
//				      
//
////
//				 //cout << st <<"\n"; cout <<  "\n" << sp << " \n" ; 
//				 st="" ;};
//	   i++;
