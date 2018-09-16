#include <iostream>

using namespace std;

int MatrixSM(int a[],int num, int edge){//Матрица смежности
cout << "MatrixSM: " << endl;
int C[num][num];
for (int i=0;i<num;i++)
    for (int j=0;j<num;j++)
     C[i][j]=0;
for(int i=0;i<edge;i++){
    int k= a[i]/10;
    int f= a[i]%10;
    C[k-1][f-1]=1;
    C[f-1][k-1]=1;
    }
for (int i=0;i<num;i++){
    for (int j=0;j<num;j++)
     cout<<C[i][j]<<' ';
     cout<<endl;
}
}

int ListSM(int a[],int num, int edge){ //Список смежности
cout << "ListSM: " << endl;
int C[num];
for (int i=0;i<num;i++)
        C[i]=0;
for (int i=0;i<edge;i++){
    int k = a[i]/10;
    int f = a[i]%10;
    C[k-1]=C[k-1]*10+f;
    C[f-1]=C[f-1]*10+k;
}
for (int i=0;i<num;i++)
        cout<<i+1<<":["<<C[i]<<"]"<<endl;
}

int MatrixIC(int a[],int num, int edge){ //Матрица инцидентности
cout << "MatrixIC: " << endl;
int C[num][edge];
for (int i=0;i<num;i++)
    for (int j=0;j<edge;j++)
     C[i][j]=0;
for(int i=0;i<edge;i++){
  int k= a[i]/10;
  int f= a[i]%10;
  C[k-1][i]=1;
  C[f-1][i]=1;
}
  for (int i=0;i<num;i++){
    for (int j=0;j<edge;j++)
     cout<<C[i][j]<<' ';
     cout<<endl;

}
}


int main(){ // Забиваем список
    int num,edge;
    cout << "Enter the number of vertexes" << endl;
    cin>>num;
    cout << "Enter the number of edges" << endl;
    cin>>edge;
    int A[edge];
    cout<<"Enter list of edges,e.g.: 12,34,56 etc."<<endl;
    for(int i=0;i<edge;i++)
        cin>> A[i];
    MatrixSM(A,num,edge) ;
    cout << endl;
    ListSM(A,num,edge);
    cout << endl;
    MatrixIC(A,num,edge);
    }
