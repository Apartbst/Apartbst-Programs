#define Length 5
#include<iostream>
#include<stdlib.h>
#include<cstdio>
using namespace std;

void InputArray();

void RankAndJudge(int *p,int length){
	for(int i=1;i<length;i++){
		for(int j=0;j<length-i;j++){
			if(p[j]>p[j+1]){
				int temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
			else if(p[j]==p[j+1]){
				system("cls");
				cout << "������" << Length << "���ظ������֡�" << endl << endl;
			} 
		}
	}
}
	

int InputArray(int *A,int *B){
	cout << "������" << Length << "�����ظ���A�����е���:" << endl;
	for(int i=0;i<Length;i++){
		cin >> A[i];	
	} 	
	RankAndJudge(A,Length);
	cout << "������" << Length << "�����ظ���B�����е���:" << endl;
	for(int i=0;i<Length;i++){
		cin >> B[i];
	} 
	RankAndJudge(B,Length);
}

void ArrayIntersection(int *A,int *B){
	int C[2*Length];
	int n=0;
	for(int i=0;i<Length;i++){
        for(int j=0;j<Length;j++){
            if(A[i]==B[j]){
                C[n++]=A[i];
            }
        }
    }
    cout<<"A��B = {";
    for(int i=0;i<n;i++)
    {
        cout << C[i]<<",";
    }
    cout << "}."<< endl;
}

void ArrayUnion(int *A,int *B){
	int C[2*Length];
	int i=0,j=0,n=0;
	do{
		if(A[i]<B[j]){
			C[n]=A[i];
			i++;
		}
		else if(A[i]==B[j]){
			C[n]=A[i];
			i++;
			j++;
		}
		else{
			C[n]=B[j];
			j++;
		}
		n++;
	}while(i<Length && j<Length);
	if(i<Length){
		do{
			C[n]=A[i];
			n++;
			i++;	
		}while(i<Length);
	}
	else{
		do{
			C[n]=B[j];
			n++;
			j++;	
		}while(j<Length);
	}
	cout<<"A��B= {";
	for(i=0;i<n;i++){
		cout << C[i]<<",";	
	}
	cout << "}."<< endl;
}

void ArraySoustraction(int *A,int *B){
	int C[Length];
	int n=0;
	for(int i=0;i<Length;i++){
		int time=0;
		for(int j=0;j<Length;j++){
			if(A[i]==B[j]){
				break;
			}
			else{
				time++;
			}			
		}
		if(time==Length){
			C[n]=A[i];
			n++;
		}
	}
	cout<<"A-B = {";
    for(int i=0;i<n;i++)
    {
        cout << C[i]<<","; 
    }
    cout << "}."<< endl;
}

void OutputArray(int *A,int *B){
	cout << "A�����е�����Ϊ��" << endl;
	for(int i=0;i<Length;i++){
		cout << "A[" << i+1 << "] = " << A[i] << "; ";
	}
	cout << endl;
	cout << "B�����е�����Ϊ��" << endl;
	for(int i=0;i<Length;i++){
		cout << "B[" << i+1 << "] = " << B[i] << "; "; 
	}
	cout << endl;
}
	
main(){
	do{
		int A[Length],B[Length];
		cout << "���������뼯��A��B��Ȼ��ѡ���������A��B����֮��ļ��㣺" << endl;
		cout << "*****1.���뼯��A��B��********************" << endl;
		cout << "*****2.�󼯺�A��B��**********************" << endl;
		cout << "*****3.�󼯺�A��B��**********************" << endl;
		cout << "*****4.�󼯺�A - B��*********************" << endl;
		cout << "*****5.�鿴����A��B�����֡�**************" << endl;
		cout << "*****6.���븺���뿪���档****************" << endl;
		int select;
		cin >> select;
		if(select==1){
			InputArray(A,B);
		}
		else if(select==2){
			ArrayIntersection(A,B);
		}
		else if(select==3){
			ArrayUnion(A,B);
		}
		else if(select==4){
			ArraySoustraction(A,B);
		}
		else if(select==5){
			OutputArray(A,B);
		}
		else if(select<0){
			cout << "�㽫���뿪������" << endl;
			exit(0);
		}
		else{
			cout << "��������ȷ�����֡�" << endl;
		}
	}while(1);
	return 0;
}
