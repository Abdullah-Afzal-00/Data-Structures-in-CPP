#include <iostream>



using namespace std;

class Element{
    int i;
    int j;
    int value;

public:

    Element(){
        i = -1;
        j = -1;
        value = -1;
    }
    Element(int i , int j , int value){
        this->i = i;
        this->j = j;
        this->value = value;
    }
void setElement(int i , int j , int value){
        this->i = i;
        this->j = j;
        this->value = value;
    }
// void swapPosition(){
//     int temp = i;
//     i = j;
//     j = temp;
// }

int getRow(){
    return i;
}
int getCol(){
    return j;
}
int getVal(){
    return value;
}
void setRow(int r){
    this->i = r;
}
void setCol(int c){
    this->j = c;
}
void setVal(int v){
    value = v;
}

};

class SparseMatrix{
    int numOfRows;
    int numOfCols;
    int numofValues;
    Element* arrOfElements;

void swapElement( Element& a ,  Element& b){
    Element tempElement;
    tempElement = a;
    a = b;
    b = tempElement;
}
public:
    SparseMatrix(){
        cout<<"Enter total number Of Rows : ";
        cin>>numOfRows;

        cout<<"Enter total number Of Colunms : ";
        cin>>numOfCols;

        cout<<"Enter total number of Values : ";
        cin>>numofValues;

        arrOfElements = new Element[numofValues];

        int i,tempRow,tempCol,tempValue;
        for (i = 0 ;i < numofValues ; i++){
            cout<<"Enter the value of no. " <<i+1<<" element : ";
            cin>>tempValue;

            cout<<"Enter the row numbr of no. " <<i+1<<" element : ";
            cin>>tempRow;
            if(tempRow< 1 or tempRow>numOfRows) {
                cout<<"\n-------Enter a valid position--------\n";
                break;
            }

            cout<<"Enter the column numbr of no. " <<i+1<<" element : ";
            cin>>tempCol;
            if(tempCol< 1 or tempCol>numOfRows) {
                cout<<"\n-------Enter a valid position--------\n\n";
                break;
            }

            arrOfElements[i].setElement(tempRow-1,tempCol-1,tempValue);
            
        }
        this->sortElements();
    }

    SparseMatrix(int totalValues , int numOfr , int numOfc){
        numofValues = totalValues;
        numOfRows = numOfr;
        numOfCols = numOfc;

        arrOfElements = new Element[numofValues];
        int i;
        for(i=0;i<numofValues;i++){
            arrOfElements[i].setVal(-1);
        }

    }

void sortElements(){
    int i,j;
    for(i = 0 ; i<numofValues -1 ;i++){
        for(j=0;j<numofValues -i -1 ;j++){
            if(arrOfElements[j].getRow() > arrOfElements[j+1].getRow())   swapElement(arrOfElements[j],arrOfElements[j+1]);

            else if(arrOfElements[j].getRow() == arrOfElements[j+1].getRow()){

                if(arrOfElements[j].getCol() > arrOfElements[j+1].getCol())   swapElement(arrOfElements[j],arrOfElements[j+1]);
            }
        }
    }
}
void Transpose(){
    int i;
    int tempR;
    int tempC;
    for(i=0;i<this->numofValues;i++){
        tempC = this->arrOfElements[i].getCol();
        tempR = this->arrOfElements[i].getRow();
        this->arrOfElements[i].setRow(tempC);
        this->arrOfElements[i].setCol(tempR);
    }


    this->sortElements();
}
SparseMatrix add(SparseMatrix m1 ,SparseMatrix m2){
    if(m1.numOfRows != m2.numOfRows or m1.numOfCols != m2.numOfCols){
        cout<<"\n--------Matrices are not Suitble for Addition--------\n";
        SparseMatrix tempM(0,0,0);
        return tempM;
    }
    else{
        SparseMatrix rm(m1.numofValues+m2.numofValues , m1.numOfRows ,m1.numOfCols);

        int i=0,j=0,k=0;
        while(i<m1.numofValues and j<m2.numofValues){
        //for(k=0;k<rm.numofValues;k++){
            //if(i<m1.numofValues or j<m2.numofValues){

                if(m1.arrOfElements[i].getRow() > m2.arrOfElements[j].getRow()){
                    k++;
                    j++;
                    rm.arrOfElements[k].setRow(m2.arrOfElements[j].getRow());
                    rm.arrOfElements[k].setCol(m2.arrOfElements[j].getCol());
                    rm.arrOfElements[k].setVal(m2.arrOfElements[j].getVal());
                    cout<<rm.arrOfElements[k].getVal()<<endl;
                } 

                else if (m1.arrOfElements[i].getRow() < m2.arrOfElements[j].getRow()){
                    //rm.arrOfElements[k++] = m1.arrOfElements[i++];
                    i++;
                    k++;
                    rm.arrOfElements[k].setRow(m1.arrOfElements[i].getRow());
                    rm.arrOfElements[k].setCol(m1.arrOfElements[i].getCol());
                    rm.arrOfElements[k].setVal(m1.arrOfElements[i].getVal());
                    cout<<rm.arrOfElements[k].getVal()<<endl;
                } 

                else if (m1.arrOfElements[i].getRow() == m2.arrOfElements[j].getRow()){

                    if(m1.arrOfElements[i].getCol() < m2.arrOfElements[j].getCol())  rm.arrOfElements[k++] = m2.arrOfElements[j++];
                    else if(m1.arrOfElements[i].getCol() > m2.arrOfElements[j].getCol()) rm.arrOfElements[k++] = m1.arrOfElements[i++];
                    else if(m1.arrOfElements[i].getCol() == m2.arrOfElements[j].getCol()){
                        rm.arrOfElements[k++] = m2.arrOfElements[j++];
                        i++;
                        rm.arrOfElements[k++].setVal(m2.arrOfElements[j].getVal() + m1.arrOfElements[i].getVal());
                    }
                }
           // }
            }
        if (i>=m1.numofValues and j<m2.numofValues){
            while(j<m2.numofValues){
                rm.arrOfElements[k++] = m2.arrOfElements[j++];
            }
        }
        if (i<m1.numofValues and j>=m2.numofValues){
            while(i<m2.numofValues){
                 rm.arrOfElements[k++] = m2.arrOfElements[i++];
                }
        }
        //}
        return rm;
        //cout<<rm;
    }
    SparseMatrix tempM(0,0,0);
    return tempM;
}

friend ostream& operator << (ostream& out ,const SparseMatrix& m){
    int i,j,k=0;

    for(i=0;i<m.numOfRows;i++){
        for(j=0;j<m.numOfCols;j++){
            if(m.arrOfElements[k].getRow() == i and m.arrOfElements[k].getCol() == j) out<<m.arrOfElements[k++].getVal()<<" ";
            else out<<0<<" ";
        }
    out<<endl;
    }
    return out;
}
~SparseMatrix(){
    delete[] arrOfElements;
}

};

int main(){
    SparseMatrix s1;
    SparseMatrix s2;
    cout<<s1;

    cout<<"\n-----------------\n";

    cout<<s2;

    cout<<"\n-----------------\n";

    cout<<s1.add(s1,s2);
    // s.Transpose();
    // cout<<"-------Transpose------\n"<<s;


    return 0;
}