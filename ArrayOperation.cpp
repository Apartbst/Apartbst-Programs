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
				cout << "请输入" << Length << "不重复的数字。" << endl << endl;
			} 
		}
	}
}
	

int InputArray(int *A,int *B){
	cout << "请输入" << Length << "个不重复的A集合中的数:" << endl;
	for(int i=0;i<Length;i++){
		cin >> A[i];	
	} 	
	RankAndJudge(A,Length);
	cout << "请输入" << Length << "个不重复的B集合中的数:" << endl;
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
    cout<<"A∩B = {";
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
	cout<<"A∪B= {";
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
	cout << "A集合中的数字为：" << endl;
	for(int i=0;i<Length;i++){
		cout << "A[" << i+1 << "] = " << A[i] << "; ";
	}
	cout << endl;
	cout << "B集合中的数字为：" << endl;
	for(int i=0;i<Length;i++){
		cout << "B[" << i+1 << "] = " << B[i] << "; "; 
	}
	cout << endl;
}
	
main(){
	do{
		int A[Length],B[Length];
		cout << "请首先输入集合A与B，然后选择你想进行A与B集合之间的计算：" << endl;
		cout << "*****1.输入集合A与B。********************" << endl;
		cout << "*****2.求集合A∩B。**********************" << endl;
		cout << "*****3.求集合A∪B。**********************" << endl;
		cout << "*****4.求集合A - B。*********************" << endl;
		cout << "*****5.查看集合A与B的数字。**************" << endl;
		cout << "*****6.输入负数离开界面。****************" << endl;
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
			cout << "你将会离开本程序。" << endl;
			exit(0);
		}
		else{
			cout << "请输入正确的数字。" << endl;
		}
	}while(1);
	return 0;
}
